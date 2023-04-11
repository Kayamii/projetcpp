#include "mainwindow.h"
#include<QDebug>
#include "ui_mainwindow.h"
#include "adherent.h"
#include <QMessageBox>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "stat_combo.h"
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
#include "mainwindow.h"


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


    QIcon icon("C:/Users/LEGION/Desktop/studies/qt/Atelier_Connexion/logo.ico");
      setWindowIcon(icon);
      QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("select ID from ADHERENTS");
      query.exec();
      model->setQuery(query);
      ui->le_id_2->setModel(model);
      ui->delete2->setModel(model);



    this->setStyleSheet("background-color: #E9F8F9;");

    ui->le_type->setValidator(new QIntValidator(1,4, this));
    ui->le_age->setValidator(new QIntValidator(1,18, this));
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->le_prenom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->le_sexe->setValidator(new QRegExpValidator(QRegExp("[fmFM]"), this));
    ui->tableView->setModel(Etmp.afficher());
    ui->tableView_2->setModel(Etmp.affichert1());
    ui->tableView_3->setModel(Etmp.affichert2());
    ui->tableView_4->setModel(Etmp.affichert3());


    ui->le_type_2->setValidator(new QIntValidator(1,3, this));
    ui->le_id_2->setValidator(new QIntValidator(1,9999, this));
    ui->le_age_2->setValidator(new QIntValidator(1,9999, this));
    ui->le_nom_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->le_prenom_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"), this));
    ui->le_sexe_2->setValidator(new QRegExpValidator(QRegExp("[fmFM]"), this));
    ui->tableView->setModel(Etmp.afficher());
    ui->statlayout->addWidget(Etmp.stat());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
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
       ui->tableView->setModel(Etmp.afficher());
       ui->tableView_2->setModel(Etmp.affichert1());
       ui->tableView_3->setModel(Etmp.affichert2());
       ui->tableView_4->setModel(Etmp.affichert3());



  QMessageBox::information(nullptr ,QObject ::tr ("OK"),
       QObject::tr("ajouté avec succés\n"
                   "Click cancel to exit"), QMessageBox::Cancel);
        }
        else
  QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
       QObject::tr("ajout echoué\n"
                   "Click cancel to exit"), QMessageBox::Cancel);

}



//modifier
void MainWindow::on_pb_ajouter_2_clicked()
{


        int id=ui->le_id_2->currentText().toInt();
        bool test=Etmp.verifier(id);
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
        ui->tableView->setModel(Etmp.afficher());
        ui->tableView_2->setModel(Etmp.affichert1());
        ui->tableView_3->setModel(Etmp.affichert2());
        ui->tableView_4->setModel(Etmp.affichert3());

}







void MainWindow::on_PDF_clicked()
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
                QObject::tr("PDF non généré.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
}



void MainWindow::on_sort_clicked()
{
    int type=ui->sortline->text().toInt();
    bool test=Etmp.verifiertype(type);
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryString = "SELECT * FROM Adherents WHERE type = :type";
    QSqlQuery query;
    query.prepare(queryString);

    query.bindValue(":type", type);
    if (type==0) {
      QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Column is empty !"), QMessageBox::Cancel);
      return;
  }
    if (test){
    if (query.exec()) {
        model->setQuery(query);
        ui->tableView_5->setModel(model);
    }}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("type non trouvé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}




void MainWindow::on_qr_clicked()
{
    // Check if a row is selected in the table view
    if(ui->tableView->currentIndex().row()==-1)
    {
        // Display a message box if no row is selected
        QMessageBox::critical(nullptr, QObject::tr("INVALID"), QObject::tr("Veuillez Choisir un adherent du tab.\nClick Ok to exit."), QMessageBox::Ok);
    }
    else
    {
        // Get the data for the selected row as a string
        QString row_data = "";
        QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
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
        myfile.open ("C:/Users/LEGION/Desktop/studies/qt/Atelier_Connexion/qrcode.svg") ;
        myfile << qr.toSvgString(1);
        myfile.flush();
        myfile.close();

        // Render the SVG file using Qt
        QSvgRenderer svgRenderer(QString("C:/Users/LEGION/Desktop/studies/qt/Atelier_Connexion/qrcode.svg"));
        QPixmap pix( QSize(90, 90) );
        QPainter pixPainter( &pix );
        svgRenderer.render(&pixPainter);

        // Display the QR code in a label
        ui->label_qr->setPixmap(pix);
    }
}





void MainWindow::on_deleteb2_clicked()
{
    int id=ui->delete2->currentText().toInt();
   bool test=Etmp.verifier(id);

    if (id == 0) {
            QMessageBox::critical(nullptr, QObject::tr("Error"), QObject::tr("Column id is empty or contains invalid option"), QMessageBox::Cancel);
            return;}
    if (test)
         {
        Etmp.supprimer(id);
        ui->tableView->setModel(Etmp.afficher());
        ui->tableView_2->setModel(Etmp.affichert1());
        ui->tableView_3->setModel(Etmp.affichert2());
        ui->tableView_4->setModel(Etmp.affichert3());

   QMessageBox::information(nullptr ,QObject ::tr ("OK"),
        QObject::tr("suprrimé avec succés\n"
                    "Click cancel to exit"), QMessageBox::Cancel);
         }
         else
   QMessageBox::critical(nullptr ,QObject ::tr ("not OK"),
        QObject::tr("supression echoué\n"
                    "Click cancel to exit"), QMessageBox::Cancel);
}


void MainWindow::on_rechercher_2_clicked()
{
    /*QString id=ui->liner_2->text();
    ui->tableView_5->setModel(Etmp.rechercher(id));









*/
}




void MainWindow::on_Tri_clicked()

{
 ui->tableView->setModel(Etmp.trier());

}

void MainWindow::on_PDF_button_clicked()
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



void MainWindow::on_liner_2_cursorPositionChanged(int arg1, int arg2)
{
    QString id=ui->liner_2->text();
    ui->tableView->setModel(Etmp.rechercher(id));

}





void MainWindow::on_on_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_off_clicked()
{
    A.write_to_arduino("0");
}

void MainWindow::on_l2_clicked()
{
    A.write_to_arduino("2");
}

void MainWindow::on_l2_2_clicked()
{
    A.write_to_arduino("3");
}


