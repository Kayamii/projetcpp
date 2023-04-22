#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlQuery>


#include <QIntValidator>
#include <QMessageBox>
#include <QTextStream>
#include <QTextDocument>
#include <QPainter>


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>

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
#include "mainwindow.h"



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

#include "QWidget"
#include <QFile>
#include <QPainter>
#include <string>

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
#include <QFileDialog>
#include <QLabel>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->statlayout->addWidget(Etmp.stat());

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

    ui->tableView->setModel(Etmp.afficher());
   ui->tabWidget->setTabText(0, "Ajouter un equipement");
   ui->tabWidget->setTabText(1, "Supprimer un equipement");
   ui->tabWidget->setTabText(2, "Modifier un equipement");
   ui->tabWidget->setTabText(3, "Consulter la liste des equipements");


   // update id_seances:
   int id_expert;
   int id_seance;
   int id_equipp;
      QString type;
       QString duree;
        QString date;


        /* Seance S(id_seance,id_expert,id_equipp, duree, date,type);
   if (S.ajouter())
   {
       // update ID_SEANCE values in EQUIPPEMENTS table
       Equipements E;
       E.updateID_SEANCE(id_seance);

       // success
       ui->tableView->setModel(S.afficher());

       QMessageBox::information(nullptr, QObject::tr("Ok"), QObject::tr("Ajout effectue.\nClick Cancel to exit."), QMessageBox::Cancel);
   }
   else
   {

       // failure
       QMessageBox::critical(nullptr, QObject::tr("Not okay"), QObject::tr("ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
   }
   */



}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_btnAjouterEquip_clicked()
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
        ui->tableView->setModel(E.afficher());

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







void MainWindow::on_suppEquip_clicked()
{

        int id=ui->lineEdit_IDS->text().toInt();
        bool test=Etmp.verifier(id);

        if (id== 0) {
                    QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Column id is empty or contains invalid option"), QMessageBox::Cancel);
                    return;}

        if (test)
             {
            Etmp.supprimer(id);
            ui->tableView->setModel(Etmp.afficher());
       QMessageBox::information(nullptr ,QObject ::tr ("OK"),
            QObject::tr("suprrimé avec succés\n"
                        "Click cancel to exit"), QMessageBox::Cancel);
             }
             else
       QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
            QObject::tr("supression echoué\n"
                        "Click cancel to exit"), QMessageBox::Cancel);
    }






/*void MainWindow::on_btnModifierEquip_clicked()
{  int ID_EQU=ui->ID_EQU_2->text().toInt();
    bool test=Etmp.verifier(ID_EQU);

    int PRIX=ui->prixEquip_2->text().toInt();
    QString DUREE_VIE=ui->DUREE_VIE_2->text();
    int QUANTITE=ui->quantite_2->text().toInt();
    QString NOMEQUIP =ui->nomEquip_2->text();
    int ID_SEANCE=ui->idSeance_2->text().toInt();
    QByteArray image;
    Equipements E (ID_EQU,QUANTITE,PRIX,ID_SEANCE,DUREE_VIE,NOMEQUIP,image);
    if ( ID_EQU == 0 || PRIX == 0 || DUREE_VIE.isEmpty() || NOMEQUIP.isEmpty() || QUANTITE==0|| ID_SEANCE==0) {
           QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("One or more columns are empty or have invalid values"), QMessageBox::Cancel);
           return;
       }
    if(E.modifier(ID_EQU) & test )
          {

              QMessageBox::information(nullptr,QObject::tr("Ok"),QObject::tr("Modification effectue.\n""Click cancel to exit."),QMessageBox::Cancel);
          }
          else
          {
              QMessageBox::critical(nullptr,QObject::tr("Not Ok"),QObject::tr("Modification non effectue.\n""Click cancel to exit"),QMessageBox::Cancel);
          }
          ui->tableView->setModel(Etmp.afficher());

  }*/

void MainWindow::on_btnModifierEquip_clicked()
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







void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    QString id=ui->lineEdit->text();
        ui->tableView->setModel(Etmp.rechercher(id));
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(Etmp.trier());
}

void MainWindow::on_pushButton_2_clicked()
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
                    QObject::tr("tri non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}





void MainWindow::on_idimage_cursorPositionChanged(int arg1, int arg2)
{
    QString id = ui->idimage->text();
    QSqlQueryModel *model = Etmp.rechercher1(id);
    ui->tableView_2->setModel(model);

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

