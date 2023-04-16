#include "dialog.h"
#include "ui_dialog.h"
#include "user.h"
#include "QSqlQuery"
#include <QMessageBox>
#include "QDebug"
#include <QIntValidator>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QtPrintSupport>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //controle de saisie
    ui->le_id->setValidator(new QIntValidator(0,999,this));
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"),this));
    ui->le_prenom->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]+"),this));
    ui->le_cin->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}"),this));
    ui->le_email->setValidator(new QRegExpValidator(QRegExp("\\w+@\\w+\\.\\w+"), ui->le_email));



}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
   int id=ui->le_id->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QString cin=ui->le_cin->text();
   QString email=ui->le_email->text();
   QString role=ui->comboBox_role->currentText();
   QString mdp=ui->le_mdp->text();

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
       ui->le_email->setValidator(emailValidator);
           QRegularExpressionMatch match = emailRegex.match(ui->le_email->text());
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



void Dialog::on_pushButton_2_clicked()
{
    ui->tab_users->setModel(U.afficher());

}

void Dialog::on_pushButton_3_clicked()
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

void Dialog::on_pushButton_5_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString cin=ui->le_cin->text();
    QString email=ui->le_email->text();
    QString role=ui->comboBox_role->currentText();
    QString mdp=ui->le_mdp->text();

    U.setid(ui->le_id->text().toInt());
        bool test1=U.recherche(U.getid());

    QRegularExpression emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,}\\b", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    ui->le_email->setValidator(emailValidator);
    QRegularExpressionMatch match = emailRegex.match(ui->le_email->text());
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

void Dialog::on_rech_textChanged(const QString &arg1)
{
ui->tab_users->setModel(U.afficher_search_result(ui->rech->text() ));
}

void Dialog::on_tri_currentIndexChanged(const QString &arg1)
{
    if(ui->tri->currentText()=="id ↓"){ ui->tab_users->setModel(U.afficher_id_decroissant());}
        if(ui->tri->currentText()=="id ↑"){ ui->tab_users->setModel(U.afficher_id_croissant());}

}


void Dialog::on_stats_clicked()
{
    QSqlQuery q1,q2,q3;

           qreal tot=0,c1=0,c2=0;
           q1.prepare("SELECT id FROM ADMINS");
           q1.exec();
           q2.prepare("SELECT id FROM ADMINS WHERE role='expert'");
           q2.exec();
           q3.prepare("SELECT id FROM ADMINS WHERE role='employee'");
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
         QString etat2="employee" ;
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
           chartView->setMinimumSize(400,200);
           chartView->show();
}

void Dialog::on_imp_clicked()
{

    U.generate_pdf();


}

void Dialog::on_pushButton_4_clicked()
{

    close();
}



