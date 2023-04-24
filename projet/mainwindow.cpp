#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dialog.h>
#include <QApplication>
#include <QMessageBox>
#include "expert.h"
#include <QVariant>
#include <cstring>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(ex.listExpert());
    ui->statlayout->addWidget(ex.stat());

   // ui->prenom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->age->setValidator(new QIntValidator(27,60, this));

    ui->pushButton_2->setVisible(false);

    connect(ui->id,SIGNAL(editingFinished()),this,SLOT(testInt()));

    // Connexion du signal textChanged() du QLineEdit à la slot checkInput()
    connect(ui->prenom, SIGNAL(textChanged(QString)), this, SLOT(checkInput(QString))); //+reste

    connect(ui->id, SIGNAL(textChanged(QString)), this, SLOT(testInt(QString))); //+age
     clic=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::checkInput(QString text)
{
        // Vérification de la saisie
        std::string input = text.toStdString();
        bool valid = true;
        for (char c : input) {
                if (!isalpha(c)) {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                // La saisie est valide, on active le bouton OK
                ui->pushButton->setEnabled(true);
                ui->alerte_prenom->setText("");
            } else
            {
                  // La saisie est invalide, on désactive le bouton OK et on affiche un message d'erreur
                  ui->pushButton->setEnabled(false);
                  ui->alerte_prenom->setText("wrong try");
                  ui->prenom->setFocus(); //mettre le curseure sur line edit
                  ui->prenom->selectAll(); //selectioner le contenu du line edit
            }
}

void MainWindow::testInt(QString text)
{
    // Vérification de la saisie
    std::string input = text.toStdString();
    bool valid = true;
    for (int c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            // La saisie est valide, on active le bouton OK
            ui->pushButton->setEnabled(true);
            ui->alerte_id->setText("");
        } else
        {
              // La saisie est invalide, on désactive le bouton OK et on affiche un message d'erreur
              ui->pushButton->setEnabled(false);
              ui->alerte_id->setText("id can't be accepted");
              ui->id->setFocus(); //mettre le curseure sur line edit
              ui->id->selectAll(); //selectioner le contenu du line edit
        }
}
void MainWindow::testIntt(QString text)
{
    // Vérification de la saisie
    std::string input = text.toStdString();
    bool valid = true;
    for (int c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            // La saisie est valide, on active le bouton OK
            ui->pushButton->setEnabled(true);
            ui->age->setText("");
        } else
        {
              // La saisie est invalide, on désactive le bouton OK et on affiche un message d'erreur
              ui->pushButton->setEnabled(false);
              ui->age_2->setText("non acceptable age");
              ui->age->setFocus(); //mettre le curseure sur line edit
              ui->age->selectAll(); //selectioner le contenu du line edit
        }
}


void MainWindow::checkInputt(QString text)
{
        // Vérification de la saisie
        std::string input = text.toStdString();
        bool valid = true;
        for (char c : input) {
                if (!isalpha(c)) {
                    valid = false;
                    break;
                }
            }




            if (valid)
            {
                // La saisie est valide, on active le bouton OK
                ui->pushButton->setEnabled(true);
                ui->alerte_prenom->setText("");
            } else
            {
                  // La saisie est invalide, on désactive le bouton OK et on affiche un message d'erreur
                  ui->pushButton->setEnabled(false);
                  ui->sp->setText("wrong try");
                  ui->specialite->setFocus(); //mettre le curseure sur line edit
                  ui->specialite->selectAll(); //selectioner le contenu du line edit
            }
}

//ajouter
void MainWindow::on_pushButton_clicked()
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
              ui->tableView->setModel(ex.listExpert());
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

void MainWindow::on_supp_clicked()
{
    int id=ui->id_supp->text().toInt();
    bool test = ex.deletExpert(id);
    if(test)
       {
              ui->tableView->setModel(ex.listExpert());
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

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{

        if(clic % 2==0)
             ui->pushButton_2->setVisible(true);
        else
             ui->pushButton_2->setVisible(false);

        QModelIndex ind = ui->tableView->currentIndex();
        QString ci = ind.data(Qt::DisplayRole).toString();
        ui->label_7->setText("Modifier expert");



        QString id = ui->tableView->model()->index(index.row(), 0).data(Qt::DisplayRole) .toString(); //creation de model a traves colone 0
        ui->id->setText(id);

        QString prenom = ui->tableView->model()->index(index.row(), 1).data(Qt::DisplayRole).toString(); //creation de model a traves colone 1
        ui->prenom->setText(prenom);

        QString nom = ui->tableView->model()->index(index.row(), 2).data(Qt::DisplayRole).toString(); //creation de model a traves colone 2
        ui->nom->setText(nom);

        QString specialite = ui->tableView->model()->index(index.row(), 3).data(Qt::DisplayRole).toString(); //creation de model a traves colone 3
        ui->specialite->setText(specialite);

        QString sexe = ui->tableView->model()->index(index.row(), 4).data(Qt::DisplayRole).toString(); //creation de model a traves colone 3
        ui->comboBox->setCurrentText(sexe);

        QString age = ui->tableView->model()->index(index.row(), 5).data(Qt::DisplayRole).toString(); //creation de model a traves colone 3
        ui->age->setText(age);

    }


void MainWindow::on_pushButton_2_clicked()
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
                            ui->pushButton_2->setVisible(false);



                 ui->tableView->setModel(ex.listExpert());
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

void MainWindow::on_id_2_cursorPositionChanged(int arg1, int arg2)
{
        QString id=ui->id_2->text();
        ui->tableView->setModel(ex.rechercher(id));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(ex.trier());
}

void MainWindow::on_pushButton_5_clicked()
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

/*void MainWindow::on_pushButton_7_clicked()
{
    QSqlQuery query;
    int id=ui->sort->text().toInt();
    bool test=ex.verifiertype(id);
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryString = "SELECT * FROM Adherents WHERE idexpert = :id";

    query.prepare(queryString);

    query.bindValue(":id", id);
    if (id==0) {
      QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Column is empty !"), QMessageBox::Cancel);
      return;
  }
    if (test){
    if (query.exec()) {
        model->setQuery(query);
        ui->tableView_3->setModel(model);
    }}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("type non trouvé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}*/

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
        if(arg1=="1")
              ui->tableView_3->setModel(ex.listAdherants(1));
        else if(arg1=="2")
            ui->tableView_3->setModel(ex.listAdherants(2));
        else if (arg1=="3")
            ui->tableView_3->setModel(ex.listAdherants(3));
        else // cas: par defaut->vider table view
        {
           QSqlQueryModel *emptyModel = new QSqlQueryModel();
           emptyModel->clear();
           ui->tableView_3->setModel(emptyModel);
        }
}

void MainWindow::on_pushButton_7_clicked()
{

}

void MainWindow::on_pushButton_8_clicked()
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
