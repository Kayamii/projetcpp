#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "equipements.h"
#include<QMessageBox>
#include<QTabWidget>
#include<QSqlQuery>
#include<QSqlQueryModel>
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
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_btnAjouterEquip_clicked()
{

int ID_EQU=ui->ID_EQU->text().toInt();
int PRIX=ui->prixEquip->text().toInt();
QString DUREE_VIE=ui->DUREE_VIE->text();
int QUANTITE=ui->quantite->text().toInt();
QString NOMEQUIP =ui->nomEquip->text();
int ID_SEANCE=ui->idSeance->text().toInt();
Equipements E (ID_EQU,QUANTITE,PRIX,ID_SEANCE,DUREE_VIE,NOMEQUIP);
if ( ID_EQU == 0 || PRIX == 0 || DUREE_VIE.isEmpty() || NOMEQUIP.isEmpty() || QUANTITE==0|| ID_SEANCE==0) {
       QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("One or more columns are empty or have invalid values"), QMessageBox::Cancel);
       return;
   }
bool test=E.ajouter(); //etablir la connexion

if(test)

{

  ui-> tableView->setModel(E.afficher()) ;

 QMessageBox::information(nullptr, QObject::tr("Ok"),

              QObject::tr("Ajout effectue.\n"

                          "Click Cancel to exit."), QMessageBox::Cancel);



}

  else

 QMessageBox::critical(nullptr, QObject::tr("Not okay"),

              QObject::tr("connection failed.\n"

                     "Click Cancel to exit."), QMessageBox::Cancel);



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






void MainWindow::on_btnModifierEquip_clicked()
{  int ID_EQU=ui->ID_EQU_2->text().toInt();
    bool test=Etmp.verifier(ID_EQU);

    int PRIX=ui->prixEquip_2->text().toInt();
    QString DUREE_VIE=ui->DUREE_VIE_2->text();
    int QUANTITE=ui->quantite_2->text().toInt();
    QString NOMEQUIP =ui->nomEquip_2->text();
    int ID_SEANCE=ui->idSeance_2->text().toInt();
    Equipements E (ID_EQU,QUANTITE,PRIX,ID_SEANCE,DUREE_VIE,NOMEQUIP);
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
