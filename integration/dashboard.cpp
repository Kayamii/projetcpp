#include "dashboard.h"
#include "ui_dashboard.h"
#include "dashboard.h"
#include "equipement.h"
#include "adherent.h"
#include "ui_dashboard.h"
#include "seance.h"
#include <QMessageBox>
#include <QtDebug>
#include <QSqlQuery>
#include <QTimer>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QBuffer>
#include <QSqlRecord>
#include "dashboard.h"
#include<QDebug>
#include "ui_dashboard.h"
#include "adherent.h"
#include <QMessageBox>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QIntValidator>
#include <QMessageBox>
#include <QTextStream>
#include <QTextDocument>
#include <QPainter>
#include <QSystemTrayIcon>
#include <QtDebug>



#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QDateTime>
#include <QTextStream>

#include<QRegularExpression>


#include <QString>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include "connection.h"
#include "QDebug"
#include <QRegExpValidator>
#include "dashboard.h"


#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QVBoxLayout>

#include <QMenu>
#include <QAction>
#include <QFileDialog>

#include <QString>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>

#include <vector>
#include "connection.h"
#include <QFont>
#include "qrcode.h"
#include "qrwidget.h"
#include "QWidget"
#include <QFile>
#include <QPainter>
#include <string>
#include <QtSvg>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

#include <QIntValidator>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPushButton>
#include <QPdfWriter>
#include <QPainter>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QFileDialog>

dashboard::dashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
    ui->tableView_e->setModel(Etmp.afficher());
    QSqlQueryModel *model=new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select ID_EXPERT from EXPERTS");
        query.exec();
        model->setQuery(query);
        ui->id_exp->setModel(model);


        QSqlQueryModel *model1=new QSqlQueryModel();
              QSqlQuery query3;
              query3.prepare("select ID_EQU from EQUIPPEMENTS where DUREE_VIE>0");
              query3.exec();
              model1->setQuery(query3);
              ui->id_equ->setModel(model1);

        //mehdi
          QSqlQueryModel *model2=new QSqlQueryModel();
        QSqlQuery query1;
        query1.prepare("select ID from ADHERENTS");
        query1.exec();
        model2->setQuery(query1);
        ui->le_id_2->setModel(model2);
        ui->delete2->setModel(model2);
        ui->tableView_4->setModel(Etmp1.afficher());
        ui->tableView_7->setModel(Etmp1.affichert1());
        ui->tableView_8->setModel(Etmp1.affichert2());
        ui->tableView_6->setModel(Etmp1.affichert3());
        ui->statlayout->addWidget(Etmp1.stat());


        ui->nomEquip->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
        ui->nomEquip_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));

        ui->quantite->setValidator(new QIntValidator(1,99, this));
        ui->quantite_2->setValidator(new QIntValidator(1,99, this));
        ui->idSeance->setValidator(new QIntValidator(1,999999, this));
        ui->idSeance_2->setValidator(new QIntValidator(1,999999, this));
        ui->ID_EQU->setValidator(new QIntValidator(1,99999, this));
        ui->ID_EQU_2->setValidator(new QIntValidator(1,99999, this));
        ui->prixEquip->setValidator(new QIntValidator(1,9999, this));
        ui->prixEquip_2->setValidator(new QIntValidator(1,9999, this));


        ui->id_seance_5->setValidator(new QIntValidator(1,1000, this));


            ui->id_exp->setValidator(new QIntValidator(1,200, this));
            ui->type->setValidator(new QRegExpValidator(QRegExp ("[a-zA-Z]+"),this));
            ui->duree->setValidator(new QRegExpValidator(QRegExp ("[0-9][0-9]"),this));
            ui->id_exp_5->setValidator(new QIntValidator(1,200, this));
             // ui->type_5->setValidator(new QRegExpValidator(QRegExp ("[a-zA-Z]+"),this));
            ui->duree_5->setValidator(new QRegExpValidator(QRegExp ("[0-9][0-9]"),this));





ui->tableView->setModel(ss.afficher());
ui->tableView_9->setModel(ex.listExpert());
ui->stats->addWidget(ss.stats());
ui->statlayout_e->addWidget(Etmp.stat());
ui->statlayout_ex->addWidget(ex.stat());

alwayscheck();
QTimer *timer = new QTimer(this);

    // Connect the timer's timeout signal to the checkForNewRows slot
    connect(timer, &QTimer::timeout, this, &dashboard::alwayscheck);

    // Start the timer to check every 30secondes
    timer->start(30000);
}


dashboard::~dashboard()
{
    delete ui;
}

void dashboard::alwayscheck()
{
    // Prepare a query to select rows with the current date
    QSqlQuery query , query2;
    query.prepare("SELECT * FROM seances  WHERE  datee = TO_CHAR(CURRENT_DATE, 'DD/MM/YYYY') AND heure = TO_CHAR(SYSDATE + INTERVAL '10' MINUTE, 'HH24:MI') ");
    query.exec();
    //query.next();



    // Create a QSystemTrayIcon object and show it
    QSystemTrayIcon* trayIcon = new QSystemTrayIcon;
   // trayIcon->setIcon(QIcon("C:/Users/FAROUK/Documents/activite/logo.png"));
    trayIcon->show();

    // Loop through the query results and show a message for each row
    while (query.next()) {
        int id = query.value(1).toInt();
        qDebug()<< query.value(0).toString();
        qDebug()<< "idexp"<<query.value(1).toString();
        qDebug()<<"expert"<<id;
        query2.prepare("SELECT prenom , nom FROM experts WHERE id_expert = :id");
        query2.bindValue(":id", id);
        query2.exec();

        if (query2.next()) {

            QString prenom = query2.value(0).toString();
            QString nom = query2.value(1).toString();

            QString message = "Mr/Mme " + prenom + " " + nom +" vous avez une seance de "+query.value(4).toString()+ " dans moins de 10 minutes";
            qDebug()<<"Mr/Mme " + prenom + " " + nom +" vous avez une seance de "+query.value(4).toString()+ " dans moins de 10 minutes";
            trayIcon->showMessage("New row", message, QSystemTrayIcon::Information, 15000);
        }
    }
}

void dashboard::on_ajouter_5_clicked()
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
        if ( ss.ajouter()) { // check if the ID_EQUIPP value is valid
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
          //  qDebug()<<i;

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

                                                //A.write_to_arduino(nomm);
            ui->tableView->setModel(ss.afficher());

            QMessageBox::information(nullptr, QObject::tr("Ok"), QObject::tr("Ajout effectue.\nClick Cancel to exit."), QMessageBox::Cancel);
        } else {
            // failure
            QMessageBox::critical(nullptr, QObject::tr("Not okay"), QObject::tr("ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
        }
    }

}}


void dashboard::on_supprimer_clicked()
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





void dashboard::on_tableView_activated(const QModelIndex &index)
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
}}

       }









void dashboard::on_tri_2_clicked()
{
    ui->tableView->setModel(ss.trier());
}






void dashboard::on_rechetxt_cursorPositionChanged()
{QString r=ui->rechetxt->text();
    ui->tableView->setModel(ss.rechercher(r));

}



void dashboard::on_pdf_clicked()
{
    ss.pdf();
}

void dashboard::on_calendarWidget_clicked(const QDate &date)
{
    QSqlQuery query,query2;
    query.prepare("SELECT typee, heure FROM seances WHERE datee = :date");
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


void dashboard::on_modifier_clicked()
{

    int id=ui->id_seance_5->text().toInt();
      int id_exp=ui->id_exp_5->text().toInt();
         int id_equi = ui->ideq->text().toInt();

      QString duree=ui->duree_5->text();
      QString date=ui->type_5->text();
      QString type=ui->date_5->currentText();
      QString heure=ui->heure_2->text();
bool test=ss.verifier(id);

Seance s(id_exp,id_equi,date,duree,type,heure);

if(type.isEmpty()||duree.isEmpty()||id==0||id_exp==0)
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
}

void dashboard::on_pushButton_clicked()
{
ui->tableView_e->setModel(Etmp.trier());
}

void dashboard::on_btnAjouterEquip_clicked()
{

        int ID_EQU = ui->ID_EQU->text().toInt();
        int PRIX = ui->prixEquip->text().toInt();
        QString DUREE_VIE = ui->DUREE_VIE->text();
        int QUANTITE = ui->quantite->text().toInt();
        QString NOMEQUIP = ui->nomEquip->text();
        QByteArray imageData;

        // set ID_SEANCE to 0
        int ID_SEANCE = 0;



        QString imagePath = QFileDialog::getOpenFileName(this, "Select Image", ".", "Image Files (*.png *.jpg *.jpeg *.bmp)");
        QFile file(imagePath);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, "Error", "Could not open file");
            return;
        }
        QByteArray image = file.readAll();
        file.close();




        // create Equipements object and set image data
       Equipements E(ID_EQU, QUANTITE, PRIX, ID_SEANCE, DUREE_VIE, NOMEQUIP, image);

        // insert Equipements object into database table
        if (E.ajouter())
        {
            // success
            ui->tableView_e->setModel(E.afficher());

            QMessageBox::information(nullptr, QObject::tr("Ok"), QObject::tr("Ajout effectue.\nClick Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            // failure
            QMessageBox::critical(nullptr, QObject::tr("Not okay"), QObject::tr("Ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
        }

        if (ID_EQU == 0 || PRIX == 0 || DUREE_VIE.isEmpty() || NOMEQUIP.isEmpty() || QUANTITE == 0)
        {
            QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("One or more columns are empty or have invalid values"), QMessageBox::Cancel);
            return;
        }



        QPixmap pixmap;
        pixmap.loadFromData(image);
        ui->imageLabel->setPixmap(pixmap);
    }


void dashboard::on_btnModifierEquip_clicked()
{
    int ID_EQU = ui->ID_EQU_2->text().toInt();
        bool test = Etmp.verifier(ID_EQU);

        int PRIX = ui->prixEquip_2->text().toInt();
        QString DUREE_VIE = ui->DUREE_VIE_2->text();
        int QUANTITE = ui->quantite_2->text().toInt();
        QString NOMEQUIP = ui->nomEquip_2->text();
        int ID_SEANCE = ui->idSeance_2->text().toInt();

        QByteArray image;
        QPixmap pixmap;

        QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
        if (!fileName.isEmpty()) {
            pixmap.load(fileName);
            pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
            QBuffer buffer(&image);
            buffer.open(QIODevice::WriteOnly);
            pixmap.toImage().save(&buffer, "JPEG");
        }

        Equipements E(ID_EQU, QUANTITE, PRIX, ID_SEANCE, DUREE_VIE, NOMEQUIP, image);
        if (ID_EQU == 0 || PRIX == 0 || DUREE_VIE.isEmpty() || NOMEQUIP.isEmpty() || QUANTITE == 0 || ID_SEANCE == 0) {
            QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("One or more columns are empty or have invalid values"), QMessageBox::Cancel);
            return;
        }
        if (E.modifier(ID_EQU, image) & test) {
            QMessageBox::information(nullptr, QObject::tr("Ok"), QObject::tr("Modification effectue.\n""Click cancel to exit."), QMessageBox::Cancel);
        }
}

void dashboard::on_pushButton_2_clicked()
{
    Equipements E;
        bool test= E.genererPDFact();
        if(test){
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("PDF Géneré. \n"
                                                 "click Cancel to exist."),QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not OK"),
                        QObject::tr(" non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void dashboard::on_pushButton_4_clicked()
{
    int id=ui->lineEdit_IDS->text().toInt();
            bool test=Etmp.verifier(id);

            if (id== 0) {
                        QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Column id is empty or contains invalid option"), QMessageBox::Cancel);
                        return;}

            if (test)
                 {
                Etmp.supprimer(id);
                ui->tableView_e->setModel(Etmp.afficher());
           QMessageBox::information(nullptr ,QObject ::tr ("OK"),
                QObject::tr("suprrimé avec succés\n"
                            "Click cancel to exit"), QMessageBox::Cancel);
                 }
                 else
           QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
                QObject::tr("supression echoué\n"
                            "Click cancel to exit"), QMessageBox::Cancel);
}

void dashboard::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QString id=ui->lineEdit->text();
            ui->tableView_e->setModel(Etmp.rechercher(id));
}


void dashboard::on_idimage_cursorPositionChanged(int arg1, int arg2)
{
    QString id = ui->idimage->text();
        QSqlQueryModel *model = Etmp.rechercher1(id);
        ui->tableView_im->setModel(model);

        if (model->rowCount() > 0) {
            // Get the image data for the first row in the model
            QByteArray imageData = model->record(0).value("image").toByteArray();

            // Load the image data into a QPixmap object
            QPixmap pixmap;
            pixmap.loadFromData(imageData);

            // Display the pixmap in the imageLabel
            ui->imageimage->setPixmap(pixmap.scaledToHeight(ui->imageLabel->height()));
        }
}

void dashboard::on_pb_ajouter_clicked()
{
    int age=ui->le_age->text().toInt();
    int type=ui->le_type->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString sexe=ui->le_sexe->text();

    Adherent A(age,type,nom,prenom,sexe);

   bool test=A.ajouter();

   if ( age == 0 || type == 0 || nom.isEmpty() || prenom.isEmpty() || sexe.isEmpty()) {
       QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("One or more columns are empty or have invalid values"), QMessageBox::Cancel);
       return;
   }
   if (test)
        {
       ui->tableView_4->setModel(Etmp1.afficher());
       ui->tableView_7->setModel(Etmp1.affichert1());
       ui->tableView_8->setModel(Etmp1.affichert2());
       ui->tableView_6->setModel(Etmp1.affichert3());
       QLayoutItem* item;
                 while ((item = ui->statlayout->takeAt(0)) != nullptr) {
                     delete item->widget();
                     delete item;
                 }
                 ui->statlayout->addWidget(Etmp1.stat());



  QMessageBox::information(nullptr ,QObject ::tr ("OK"),
       QObject::tr("ajouté avec succés\n"
                   "Click cancel to exit"), QMessageBox::Cancel);
        }
        else
  QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
       QObject::tr("ajout echoué\n"
                   "Click cancel to exit"), QMessageBox::Cancel);


}

void dashboard::on_deleteb2_clicked()
{
    int id=ui->delete2->currentText().toInt();
   bool test=Etmp1.verifier(id);

    if (id == 0) {
            QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Column id is empty or contains invalid option"), QMessageBox::Cancel);
            return;}
    if (test)
         {
        Etmp1.supprimer(id);
        ui->tableView_4->setModel(Etmp1.afficher());
        ui->tableView_7->setModel(Etmp1.affichert1());
        ui->tableView_8->setModel(Etmp1.affichert2());
        ui->tableView_6->setModel(Etmp1.affichert3());
        QLayoutItem* item;
                  while ((item = ui->statlayout->takeAt(0)) != nullptr) {
                      delete item->widget();
                      delete item;
                  }
                  ui->statlayout->addWidget(Etmp1.stat());


   QMessageBox::information(nullptr ,QObject ::tr ("OK"),
        QObject::tr("suprrimé avec succés\n"
                    "Click cancel to exit"), QMessageBox::Cancel);
         }
         else
   QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
        QObject::tr("supression echoué\n"
                    "Click cancel to exit"), QMessageBox::Cancel);

}

void dashboard::on_Tri_clicked()
{
     ui->tableView_4->setModel(Etmp1.trier());

}

void dashboard::on_PDF_button_clicked()
{
    Adherent A;
bool test= A.genererPDFact();
if(test){
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("PDF Géneré. \n"
                                         "click Cancel to exist."),QMessageBox::Cancel);

}
else
{
    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                QObject::tr("ECHEC !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

}

void dashboard::on_liner_2_cursorPositionChanged(int arg1, int arg2)
{
    QString id=ui->liner_2->text();
    ui->tableView_4->setModel(Etmp1.rechercher(id));

}

void dashboard::on_qr_clicked()
{
    // Check if a row is selected in the table view
    if(ui->tableView_4->currentIndex().row()==-1)
    {
        // Display a message box if no row is selected
        QMessageBox::critical(nullptr, QObject::tr("INVALID"), QObject::tr("Veuillez Choisir un adherent du tab.\nClick Ok to exit."), QMessageBox::Ok);
    }
    else
    {
        // Get the data for the selected row as a string
        QString row_data = "";
        QModelIndexList selectedIndexes = ui->tableView_4->selectionModel()->selectedIndexes();
        for (int i = 0; i < selectedIndexes.size(); ++i) {
            row_data += selectedIndexes.at(i).data().toString();
            if (i < selectedIndexes.size() - 1) {
                row_data += ",";
            }
        }
        std::string row_data_str = row_data.toStdString();

        // Generate a QR code using the qrcodegen library
        const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(row_data_str.c_str(), qrcodegen::QrCode::Ecc::LOW);

        // Write the QR code to an SVG file
        std::ofstream myfile;
        myfile.open ("C:/Users/LEGION/Desktop/seance equippements/qrcode.svg") ;
        myfile << qr.toSvgString(1);
        myfile.flush();
        myfile.close();

        // Render the SVG file using Qt
        QSvgRenderer svgRenderer(QString("C:/Users/LEGION/Desktop/seance equippements/qrcode.svg"));
        QPixmap pix( QSize(90, 90) );
        QPainter pixPainter( &pix );
        svgRenderer.render(&pixPainter);

        // Display the QR code in a label
        ui->label_qr->setPixmap(pix);
    }

}

void dashboard::on_pb_ajouter_2_clicked()
{
    int id=ui->le_id_2->currentText().toInt();
    bool test=Etmp1.verifier(id);
    int age=ui->le_age_2->text().toInt();
    int type=ui->le_type_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString sexe=ui->le_sexe_2->text();
    Adherent a(age,type,nom,prenom,sexe);

    if (nom.isEmpty() || prenom.isEmpty() || sexe.isEmpty() || age == 0 || type == 0 || id==0) {
           QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("One or more columns are empty !"), QMessageBox::Cancel);
           return;
       }

    if(a.modifier(id) & test)
    {

        QMessageBox::information(nullptr,QObject::tr("Ok"),QObject::tr("Modification effectue.\n""Click cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),QObject::tr("Modification non effectue.\n""Click cancel to exit"),QMessageBox::Cancel);
    }
    ui->tableView_4->setModel(Etmp1.afficher());
    ui->tableView_7->setModel(Etmp1.affichert1());
    ui->tableView_8->setModel(Etmp1.affichert2());
    ui->tableView_6->setModel(Etmp1.affichert3());
    ui->statlayout->addWidget(Etmp1.stat());
    QLayoutItem* item;
              while ((item = ui->statlayout->takeAt(0)) != nullptr) {
                  delete item->widget();
                  delete item;
              }
              ui->statlayout->addWidget(Etmp.stat());

}

void dashboard::on_pushButton_5_clicked()
{

    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString specialite=ui->specialite->text();
   //  QString sexe=ui->sexe->text();
    QString sexe=ui->comboBox->currentText();
    int age =ui->age->text().toInt();
    expert exx(id,prenom,nom,specialite,sexe,age);
    bool test = exx.ajoutExpert();

    if(test)
       {
              ui->tableView_9->setModel(ex.listExpert());
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("add successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ex.writeLog(ui->id->text().toInt(),"expert has been added by id :");

    }
       else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("add failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void dashboard::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(arg1=="1")
          ui->tableView_10->setModel(ex.listAdherants(1));
    else if(arg1=="2")
        ui->tableView_10->setModel(ex.listAdherants(2));
    else if (arg1=="3")
        ui->tableView_10->setModel(ex.listAdherants(3));
    else // cas: par defaut->vider table view
    {
       QSqlQueryModel *emptyModel = new QSqlQueryModel();
       emptyModel->clear();
       ui->tableView_10->setModel(emptyModel);
    }
}

void dashboard::on_pushButton_6_clicked()
{
    int id,age;
           QString prenom,nom,specialite,sexe;
            bool test=false;
           id=ui->id->text().toInt();
           prenom=ui->prenom->text();
           nom=ui->nom->text();
            specialite=ui->specialite->text();
            sexe=ui->comboBox->currentText();
            age=ui->age->text().toInt();


          test=ex.modifierExpert(id,prenom,nom,specialite,sexe,age);
          if(test)
          {
                 ui->label_7->setText("Ajouter expert");
                 ui->id->setText("");
                   ui->nom->setText("");
                     ui->prenom->setText("");
                       ui->comboBox->setCurrentText("H");
                         ui->specialite->setText("");
                           ui->age->setText("");
                            //ui->pushButton_6->setVisible(false);



                 ui->tableView_9->setModel(ex.listExpert());
              QMessageBox::information(nullptr, QObject::tr("database is open"),
                          QObject::tr("Updated successfully .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
              ex.writeLog(ui->id->text().toInt(),"expert has been updated succesfully :");


       }
          else
              QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                          QObject::tr("Update failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


}

void dashboard::on_pushButton_8_clicked()
{
    expert e;
bool test= e.genererPDFact();
if(test){
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("PDF Géneré. \n"
                                         "click Cancel to exist."),QMessageBox::Cancel);

}
else
{
    QMessageBox::critical(nullptr, QObject::tr("not OK"),
                QObject::tr("tri non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void dashboard::on_pushButton_7_clicked()
{
 ui->tableView_9->setModel(ex.trier());
}

void dashboard::on_supp_clicked()
{
    int id=ui->id_supp->text().toInt();
    bool test = ex.deletExpert(id);
    if(test)
       {
              ui->tableView_9->setModel(ex.listExpert());
              ui->id_supp->setText("");
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("Deleted successfully .\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ex.writeLog(ui->id->text().toInt(),"expert has been deleteed by id :");


    }
       else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("delete failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void dashboard::on_id_2_cursorPositionChanged(int arg1, int arg2)
{
    QString id=ui->id_2->text();
    ui->tableView_9->setModel(ex.rechercher(id));
}

void dashboard::on_pushButton_11_clicked()
{
    QString filename="C:/Users/LEGION/Desktop/seance equippements/txt.txt";
          QFile file(filename);
          if(!file.exists()){
              qDebug() << "file doesnt exist "<<filename;
          }else{
              qDebug() << filename<<" file found...";
          }

          QString line;
          ui->history->clear();
          if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
              QTextStream stream(&file);
              while (!stream.atEnd()){
                 line = stream.readLine();
                  ui->history->setText(ui->history->toPlainText()+line+"\n");
                  qDebug() << "linea: "<<line;
              }
          }
          file.close();

}


void dashboard::on_pushButton_17_clicked()
{
    int id=ui->le_id_mo->text().toInt();
    QString nom=ui->le_nom_mo->text();
    QString prenom=ui->le_prenom_mo->text();
    QString cin=ui->le_cin_mo->text();
    QString email=ui->le_email_mo->text();
    QString role=ui->comboBox_role_mo->currentText();
    QString mdp=ui->le_mdp_mo->text();

    /*User U(id,nom,prenom,cin,email,role,mdp);
    bool test=U.ajouter();

    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectue\n"
                                 "Click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_users->setModel(U.afficher());

    }
    else QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                  QObject::tr("Ajout non effectue\n"
                                  "Click Cancel to exit"),QMessageBox::Cancel);*/

    QRegularExpression emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,}\\b", QRegularExpression::CaseInsensitiveOption);
        QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
        ui->le_email_mo->setValidator(emailValidator);
            QRegularExpressionMatch match = emailRegex.match(ui->le_email_mo->text());
            bool isValid = match.hasMatch();
            bool cinvalid =true;
            if(cin.size()!=8)
            {
                cinvalid=false;



            }
            if (nom.isEmpty() || prenom.isEmpty() || cin.isEmpty() || role.isEmpty() || email.isEmpty() || mdp.isEmpty()) {
                QMessageBox::critical(nullptr, QObject::tr("Empty"),
                            QObject::tr("Please Fill all labels.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            } else
            {
            if (isValid&&cinvalid) {
                User U(id,nom,prenom,cin,email,role,mdp);
                   bool test=U.ajouter();

               if(test)
               {
                   QMessageBox::information(nullptr, QObject::tr("Add"),
                               QObject::tr("Task Successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->tab_users->setModel(U.afficher());
               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Add"),
                               QObject::tr("Task Failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else if(isValid==false) {
                QMessageBox::critical(nullptr, QObject::tr("Email"),
                            QObject::tr("Wrong Email.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else if(cinvalid==false) {
                QMessageBox::critical(nullptr, QObject::tr("CIN"),
                                                  QObject::tr("Cin 8 caracters.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);

            }



            }
}

void dashboard::on_pushButton_18_clicked()
{
    int id=ui->le_id_mo->text().toInt();
    QString nom=ui->le_nom_mo->text();
    QString prenom=ui->le_prenom_mo->text();
    QString cin=ui->le_cin_mo->text();
    QString email=ui->le_email_mo->text();
    QString role=ui->comboBox_role_mo->currentText();
    QString mdp=ui->le_mdp_mo->text();

    U.setid(ui->le_id_mo->text().toInt());
        bool test1=U.recherche(U.getid());

    QRegularExpression emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,}\\b", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    ui->le_email_mo->setValidator(emailValidator);
    QRegularExpressionMatch match = emailRegex.match(ui->le_email_mo->text());
    bool isValid = match.hasMatch();
            bool cinvalid =true;
            if(cin.size()!=8)
            {
                cinvalid=false;
            }
            if (nom.isEmpty() || prenom.isEmpty() || cin.isEmpty() || role.isEmpty() || email.isEmpty() || mdp.isEmpty()) {
                QMessageBox::critical(nullptr, QObject::tr("Empty"),
                            QObject::tr("Please Fill all labels.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            } else
            {
                if(test1)
                {

            if (isValid) {
                User U(id,nom,prenom,cin,email,role,mdp);
                   bool test=U.modifier(id);

               if(test)
               {
                   QMessageBox::information(nullptr, QObject::tr("Add"),
                               QObject::tr("Task Successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->tab_users->setModel(U.afficher());
               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Add"),
                               QObject::tr("Task Failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else if(isValid==false) {
                QMessageBox::critical(nullptr, QObject::tr("Email"),
                            QObject::tr("Wrong Email.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else if(cinvalid==false) {
                QMessageBox::critical(nullptr, QObject::tr("CIN"),
                                                  QObject::tr("Cin 8 caracters.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);
            }
                }

                else {
                    QMessageBox::critical(nullptr, QObject::tr("id non trouve"),
                                                      QObject::tr("id non trouve.\n"
                                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                }
            }
}

void dashboard::on_pushButton_19_clicked()
{
    close();
}

void dashboard::on_pushButton_13_clicked()
{
    ui->tab_users->setModel(U.afficher());
}

void dashboard::on_pushButton_12_clicked()
{
    User U1;
    U1.setid(ui->sup->text().toInt());

    bool test1=U1.recherche(U1.getid());
    QMessageBox msgBox ;
    if (test1)
    {
        bool test=U1.supprimer(U1.getid());
    if (test)
    {
       msgBox.setText("suppression avec succes.");
        ui->tab_users->setModel(U.afficher());

    }
    else
        {
        msgBox.setText("echec de suppression");
        }
        msgBox.exec();

}
    else
        {
        msgBox.setText("id non trouve");
        }
        msgBox.exec();
}

void dashboard::on_tri_currentIndexChanged(const QString &arg1)
{
    if(ui->tri->currentText()=="id ↓"){ ui->tab_users->setModel(U.afficher_id_decroissant());}
        if(ui->tri->currentText()=="id ↑"){ ui->tab_users->setModel(U.afficher_id_croissant());}
}

void dashboard::on_stats_2_clicked()
{
    QSqlQuery q1,q2,q3;

           qreal tot=0,c1=0,c2=0;
           q1.prepare("SELECT id FROM ADMINS");
           q1.exec();
           q2.prepare("SELECT id FROM ADMINS WHERE role='expert'");
           q2.exec();
           q3.prepare("SELECT id FROM ADMINS WHERE role='admin'");
           q3.exec();
           while (q1.next()){tot++;}
           while (q2.next()){c1++;}
           while (q3.next()){c2++;}
           c1=(c1*100)/tot;
           c2=(c2*100)/tot;
           QString c3= QString::number(c1) ;
           c3= " = "+c3+"%"  ;
        QString c4= QString::number(c2) ;
        c4= " = "+c4+"%"  ;
         QString etat1="expert" ;
         etat1=etat1+c3 ;
         QString etat2="admin" ;
         etat2=etat2+c4 ;
           //Création des pie series
           QPieSeries *series = new QPieSeries();
           series->append(etat1,c1);
           series->append(etat2,c2);
           //Creation d'un charte
           QChart *chart =new QChart();
           chart->setTitle("Les résultats:");
           chart->addSeries(series);
           chart->legend()->show();
            chart->setBackgroundBrush(QColor(252, 236, 218, 0));
           QChartView *chartView;
           chartView = new QChartView(chart,ui->graphicsView);
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->setMinimumSize(400,400);
           chartView->show();
}

void dashboard::on_imp_clicked()
{
    U.generate_pdf();
}
