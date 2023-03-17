#include "mainwindow.h"
#include<QDebug>
#include "ui_mainwindow.h"
#include "adherent.h"
#include <QMessageBox>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlQuery>

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
            ui->le_idexpert_2->setModel(model);
            ui->le_idexpert->setModel(model);
    this->setStyleSheet("background-color: #F1DEC9;");

    ui->le_type->setValidator(new QIntValidator(1,4, this));
    ui->le_idexpert->setValidator(new QIntValidator(1,9999, this));
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->le_prenom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->le_sexe->setValidator(new QRegExpValidator(QRegExp("[fmFM]"), this));
    ui->tableView->setModel(Etmp.afficher());
    ui->le_type_2->setValidator(new QIntValidator(1,4, this));
    ui->le_id_2->setValidator(new QIntValidator(1,9999, this));
    ui->le_idexpert_2->setValidator(new QIntValidator(1,9999, this));
    ui->le_nom_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->le_prenom_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->le_sexe_2->setValidator(new QRegExpValidator(QRegExp("[fmFM]"), this));
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    int idexpert=ui->le_idexpert->currentText().toInt();
    int type=ui->le_type->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString sexe=ui->le_sexe->text();

    Adherent A(idexpert,type,nom,prenom,sexe);

   bool test=A.ajouter();

   if ( idexpert == 0 || type == 0 || nom.isEmpty() || prenom.isEmpty() || sexe.isEmpty()) {
       QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("One or more columns are empty or have invalid values"), QMessageBox::Cancel);
       return;
   }
   if (test)
        {
       ui->tableView->setModel(Etmp.afficher());
  QMessageBox::information(nullptr ,QObject ::tr ("OK"),
       QObject::tr("ajouté avec succés\n"
                   "Click cancel to exit"), QMessageBox::Cancel);
        }
        else
  QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
       QObject::tr("ajout echoué\n"
                   "Click cancel to exit"), QMessageBox::Cancel);

}


void MainWindow::on_supprimer_clicked()
{
    int id=ui->lineEdit->text().toInt();
   bool test=Etmp.verifier(id);

    if (id == 0) {
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

void MainWindow::on_pb_ajouter_2_clicked()
{


        int id=ui->le_id_2->text().toInt();
        bool test=Etmp.verifier(id);
        int idexpert=ui->le_idexpert_2->currentText().toInt();
        int type=ui->le_type_2->text().toInt();
        QString nom=ui->le_nom_2->text();
        QString prenom=ui->le_prenom_2->text();
        QString sexe=ui->le_sexe_2->text();
        Adherent a(idexpert,type,nom,prenom,sexe);

        if (nom.isEmpty() || prenom.isEmpty() || sexe.isEmpty() || idexpert == 0 || type == 0 || id==0) {
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
        ui->tableView->setModel(Etmp.afficher());

}
