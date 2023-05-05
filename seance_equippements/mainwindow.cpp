#include "mainwindow.h"
#include "equipement.h"
#include "ui_mainwindow.h"
#include "seance.h"
#include <QMessageBox>
#include <QtDebug>
#include <QSqlQuery>
#include <QTimer>
#include <QSqlQueryModel>
#include "arduino.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    int ret=A.connect_arduino();
        switch(ret){
        case(0):qDebug()<<"arduino is available and connected to : "<<A.getarduino_port_name();
        break;
        case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
        break;
        case(-1):qDebug()<<"arduino is not available";
        }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));







    QSqlQueryModel *model=new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select ID_EXPERT from EXPERTS");
        query.exec();
        model->setQuery(query);
        ui->id_exp->setModel(model);
        ui->id_seance_5->setValidator(new QIntValidator(1,1000, this));

    ui->id_exp->setValidator(new QIntValidator(1,200, this));
            ui->type->setValidator(new QRegExpValidator(QRegExp ("[a-zA-Z]+"),this));
      ui->duree->setValidator(new QRegExpValidator(QRegExp ("[0-9][0-9]"),this));
      ui->id_exp_5->setValidator(new QIntValidator(1,200, this));
             // ui->type_5->setValidator(new QRegExpValidator(QRegExp ("[a-zA-Z]+"),this));
        ui->duree_5->setValidator(new QRegExpValidator(QRegExp ("[0-9][0-9]"),this));


ui->tableView->setModel(ss.afficher());
ui->stats->addWidget(ss.stats());
alwayscheck();
QTimer *timer = new QTimer(this);

    // Connect the timer's timeout signal to the checkForNewRows slot
    connect(timer, &QTimer::timeout, this, &MainWindow::alwayscheck);

    // Start the timer to check every minute
    timer->start(30000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::alwayscheck()
{
    // Prepare a query to select rows with the current date
    QSqlQuery query , query2;
    query.prepare("SELECT * FROM seances  WHERE  date = TO_CHAR(CURRENT_DATE, 'DD/MM/YYYY') AND heure = TO_CHAR(SYSDATE + INTERVAL '10' MINUTE, 'HH12:MI') || CASE WHEN TO_CHAR(SYSDATE + INTERVAL '10' MINUTE, 'HH24') >= 12 THEN ' PM' ELSE ' AM' END;");
    query.exec();
    QSqlQueryModel *model=new QSqlQueryModel();
          QSqlQuery query3;
          query3.prepare("select ID_EQU from EQUIPPEMENTS where DUREE_VIE>0");
          query3.exec();
          model->setQuery(query3);

          ui->id_equ->setModel(model);


    // Create a QSystemTrayIcon object and show it
    QSystemTrayIcon* trayIcon = new QSystemTrayIcon;
    trayIcon->setIcon(QIcon("C:/Users/FAROUK/Documents/activite/logo.png"));
    trayIcon->show();

    // Loop through the query results and show a message for each row
    while (query.next()) {
        int id = query.value(1).toInt();
        query2.prepare("SELECT prenom , nom FROM experts WHERE id_expert = :id");
        query2.bindValue(":id", id);
        query2.exec();

        if (query2.next()) {
            QString prenom = query2.value(0).toString();
            QString nom = query2.value(1).toString();
            QString message = "Mr/Mme " + prenom + " " + nom +" vous avez une seance de "+query.value(4).toString()+ " dans moins de 10 minutes";
            trayIcon->showMessage("New row", message, QSystemTrayIcon::Information, 15000);
        }
    }
}

void MainWindow::on_ajouter_5_clicked()
{

  Equipements E;


        int id_exp = ui->id_exp->currentText().toInt();
        int id_equi = ui->id_equ->currentText().toInt();
        QString type = ui->type->currentText();
        QString duree = ui->duree->text();
        QString date = ui->date->text();
        QString heure = ui->heure->text();
        Seance ss(id_exp, id_equi, type, duree, date, heure);
     // int ID_EQUIPP = ss.ajouter(); // store the ID_EQUIPP value returned by the ajouter() function
   //  int i=  E.checkOutOfStockEquipments(id_equi);
        if ( id_equi >0 ) { // check if the ID_EQUIPP value is valid
            ui->tableView->setModel(ss.afficher());
            QLayoutItem* item;
            while ((item = ui->stats->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
            ui->stats->addWidget(ss.stats());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("ajout avec succès\nClick Cancel to exit"), QMessageBox::Cancel);
E.updateID_SEANCE(id_equi);
            // update ID_SEANCE and duree_vie values in EQUIPPEMENTS table
            int i = E.checkDureeVie(id_equi);

if (i==1) { QMessageBox::information(nullptr, QObject::tr("Warning"), QObject::tr("That was the last one"));}
           QString message = QString::number(i);
            if (i==1) {


                QSqlQuery query1;
                            query1.prepare("select NOMEQUIP from EQUIPPEMENTS where id_equ=:num");
                            query1.bindValue(":num", id_equi);
                            query1.exec();

                            if (query1.next())
                            {
                                QString nom = query1.value(0).toString();


                                    qDebug() <<"query.value(0).toString()";

                                        QByteArray nomm = nom.toUtf8();

                                                A.write_to_arduino(nomm);



               /* QString message = "on ";

                // Convert the message to a QByteArray
                QByteArray messageBytes = message.toUtf8();

                // Send the message to the Arduino
                A.write_to_arduino(messageBytes);
                             }



                //  QString nom="helloworld";*/





            // success
            ui->tableView->setModel(ss.afficher());

            QMessageBox::information(nullptr, QObject::tr("Ok"), QObject::tr("Ajout effectue.\nClick Cancel to exit."), QMessageBox::Cancel);
        } else {
            // failure
            QMessageBox::critical(nullptr, QObject::tr("Not okay"), QObject::tr("ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
        }
    }

}}





void MainWindow::on_supprimer_clicked()
{ int id=ui->id_seance_5->text().toInt();


bool test=ss.verifier(id);
    if (test)
    {
        ss.supprimer(id);
         ui->tableView->setModel(ss.afficher());
         QLayoutItem* item;
         while ((item = ui->stats->takeAt(0)) != nullptr) {
             delete item->widget();
             delete item;
         }
         ui->stats->addWidget(ss.stats());
QMessageBox::information(nullptr ,QObject ::tr ("OK"),
   QObject::tr("Suppression avec succés\n"
               "Click cancel to exit"), QMessageBox::Cancel);


    }
    else
{
        if(id==0)
        {QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
                               QObject::tr("Veuillez entrer l'ID\n"
                                           "Click cancel to exit"), QMessageBox::Cancel); }
        else
        QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
   QObject::tr("ID inexistant\n"
               "Click cancel to exit"), QMessageBox::Cancel);}


}



/*void MainWindow::on_modifier_clicked()
{


    int id=ui->id_seance_5->text().toInt();
      int idexpert=ui->id_exp_5->text().toInt();

      QString duree=ui->duree_5->text();
      QString date=ui->date_5->currentText();
      QString type=ui->type_5->text();
      QString heure=ui->heure_2->text();
bool test=ss.verifier(id);

Seance s(idexpert,id_equi,date,duree,type,heure);

if(type.isEmpty()||duree.isEmpty()||id==0||idexpert==0)
{QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
                       QObject::tr("Veuillez remplir tous les champs\n"
                                   "Click cancel to exit"), QMessageBox::Cancel); }

else{
    if(test &&s.modifier(id))
       {ui->tableView->setModel(ss.afficher());
        QLayoutItem* item;
        while ((item = ui->stats->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        ui->stats->addWidget(ss.stats());
           QMessageBox::information(nullptr,QObject::tr("Ok"),QObject::tr("Modification effectue.\n""Click Cancel to exit."),QMessageBox::Cancel);
       }
    else
{ QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
QObject::tr("Modification echouée\n Id introuvable\n"
           "Click cancel to exit"), QMessageBox::Cancel);}
}
}*/

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString clicked=ui->tableView->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("select * from SEANCES where ID_SEANCE=:clicked ");
       query.bindValue(":clicked",clicked);
       if (query.exec())
       {while (query.next())
           {ui->id_seance_5->setText(query.value(0).toString());
               ui->id_exp_5->setText(query.value(1).toString());
               //ui->type_5->setText(query.value(4).toString());
               ui->duree_5->setText(query.value(2).toString());
              // ui->date_5->setDate(query.value(3).toDate());
                ui->heure_2->setTime(query.value(5).toTime());
} }

       }









void MainWindow::on_tri_2_clicked()
{
    ui->tableView->setModel(ss.trier());
}






void MainWindow::on_rechetxt_cursorPositionChanged()
{QString r=ui->rechetxt->text();
    ui->tableView->setModel(ss.rechercher(r));

}



void MainWindow::on_pdf_clicked()
{
    ss.pdf();
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    QSqlQuery query,query2;
    query.prepare("SELECT typee, heure FROM seances WHERE date = :date");
    QString d = date.toString("dd/MM/yyyy");
    std::string ch = d.toStdString().substr(0, 10);
    QString x = QString::fromStdString(ch);
    query.bindValue(":date", x);
    qDebug()<< x;
    query.exec();
    query.first();
    QSqlQueryModel *mod=new QSqlQueryModel();
    mod->setQuery(query);
    ui->tableView_2->setColumnWidth(0, 130);
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("type"));
ui->tableView_2->setColumnWidth(0, 130);
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("heure"));

    ui->tableView_2->setModel(mod);

    query2.prepare("SELECT evenement FROM calendrier WHERE datev = :date");
    QString d1 = date.toString("dd/MM/yyyy");
    std::string ch1 = d1.toStdString().substr(0, 10);
    QString x1 = QString::fromStdString(ch1);
    query2.bindValue(":date", x1);
    query2.exec();
    query2.first();
    QSqlQueryModel *mod1=new QSqlQueryModel();
    mod1->setQuery(query2);
    //mod1->setHeaderData(0,Qt::Horizontal,QObject::tr("evenement"));
    ui->tableView_3->setModel(mod1);
    ui->tableView_3->setColumnWidth(0, 280); // set the width of the first column to 200 pixels
    mod1->setHeaderData(0, Qt::Horizontal, QObject::tr("evenement"));
}



void MainWindow::on_pushButton_clicked()
{  arduino A;
    A.connect_arduino();


    QByteArray data="h";
    A.write_to_arduino(data);

}
