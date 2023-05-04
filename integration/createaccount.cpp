#include "createaccount.h"
#include "ui_createaccount.h"
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



createaccount::createaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createaccount)
{
    ui->setupUi(this);
}

createaccount::~createaccount()
{
    delete ui;
}

void createaccount::on_pushButton_clicked()
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
           bool rolevalid =false;

               if(role!="choisir")
                   rolevalid =true;



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
           if (isValid&&cinvalid&&rolevalid) {
               User U(id,nom,prenom,cin,email,role,mdp);
                  bool test=U.ajouter();

              if(test)
              {
                  QMessageBox::information(nullptr, QObject::tr("Add"),
                              QObject::tr("Task Successful.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
                  close();

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
            else if(rolevalid==false)
           {
                          QMessageBox::critical(nullptr, QObject::tr("role"),
                                                            QObject::tr("choose role please .\n"
                                                                        "Click Cancel to exit."), QMessageBox::Cancel);

                      }




           }

}

void createaccount::on_pushButton_4_clicked()
{
    close();
}
