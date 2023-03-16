#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "seance.h"
#include <QMessageBox>
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
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
              ui->type_5->setValidator(new QRegExpValidator(QRegExp ("[a-zA-Z]+"),this));
        ui->duree_5->setValidator(new QRegExpValidator(QRegExp ("[0-9][0-9]"),this));


ui->tableView->setModel(ss.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_5_clicked()
{//int id_seance=ui->id_seance->text().toInt();
    int id_exp=ui->id_exp->currentText().toInt();
   // int id_equi=ui->id_equi->text().toInt();
    QString type=ui->type->text();
     QString duree=ui->duree->text();
      QString date=ui->date->text();
      Seance ss(id_exp,type,duree,date);
      bool test =ss.ajouter();
      if (test)
      {
          ui->tableView->setModel(ss.afficher());
QMessageBox::information(nullptr ,QObject ::tr ("OK"),
     QObject::tr("ajout avec succés\n"
                 "Click cancel to exit"), QMessageBox::Cancel);
      }
      else{
          if(id_exp==NULL ||type.isEmpty()||duree.isEmpty())
          {QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
                                 QObject::tr("Veuillez remplir tous les champs\n"
                                             "Click cancel to exit"), QMessageBox::Cancel); }
          else


{QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
     QObject::tr("ajout echoué\n"
                 "Click cancel to exit"), QMessageBox::Cancel);}
      }
          }



/*void MainWindow::on_supprimer_clicked()
{
    int id=ui->id_seance_5->text().toInt();
    bool test=ss.supprimer(id);
    if (test)
    {  ui->tableView->setModel(ss.afficher());
QMessageBox::information(nullptr ,QObject ::tr ("OK"),
   QObject::tr("Suppression avec succés\n"
               "Click cancel to exit"), QMessageBox::Cancel);
    }
    else
{QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
   QObject::tr("Suppression echoué\n"
               "Click cancel to exit"), QMessageBox::Cancel);}


}*/
void MainWindow::on_supprimer_clicked()
{QSqlQuery query2;
     int id=ui->id_seance_5->text().toInt();
    query2.prepare("select id_seance from seances where id_seance=:id");

    query2.bindValue(":id",id);
    bool test=(query2.exec()) && (query2.next());


    if (test)
    {
        ss.supprimer(id);
         ui->tableView->setModel(ss.afficher());
QMessageBox::information(nullptr ,QObject ::tr ("OK"),
   QObject::tr("Suppression avec succés\n"
               "Click cancel to exit"), QMessageBox::Cancel);


    }
    else
{
        if(id==NULL)
        {QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
                               QObject::tr("Veuillez entrer l'ID\n"
                                           "Click cancel to exit"), QMessageBox::Cancel); }
        else
        QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
   QObject::tr("ID inexistant\n"
               "Click cancel to exit"), QMessageBox::Cancel);}


}



void MainWindow::on_modifier_clicked()
{


    int id=ui->id_seance_5->text().toInt();
      int idexpert=ui->id_exp_5->text().toInt();
      QString duree=ui->duree_5->text();
      QString date=ui->date_5->text();
      QString type=ui->type_5->text();


Seance s(idexpert,type,duree,date);
if(type.isEmpty()||duree.isEmpty()||id==NULL||idexpert==NULL)
{QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
                       QObject::tr("Veuillez remplir tous les champs\n"
                                   "Click cancel to exit"), QMessageBox::Cancel); }

else{
    if(s.modifier(id))
       {ui->tableView->setModel(ss.afficher());
           QMessageBox::information(nullptr,QObject::tr("Ok"),QObject::tr("Modification effectue.\n""Click Cancel to exit."),QMessageBox::Cancel);
       }
    else


{QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
QObject::tr("Modification echouée\n Id introuvable\n"
           "Click cancel to exit"), QMessageBox::Cancel);}
}
}

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
               ui->type_5->setText(query.value(4).toString());
               ui->duree_5->setText(query.value(2).toString());
               ui->date_5->setDateTime(query.value(3).toDateTime());
}}

       }








