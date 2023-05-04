#include "login.h"
#include "ui_login.h"
#include "dashboard.h"
#include "ui_dashboard.h"
#include "dashboard_e.h"
#include "ui_dashboard_e.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "employe.h"
#include "ui_employe.h"
#include "dialog_mdp.h"
#include "createaccount.h"
#include "user.h"
#include "mdp.h"
#include "QDebug"
#include "QMessageBox"
#include "QSystemTrayIcon"
#include <QSqlQuery>




login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap pixmap("C:/Users/LEGION/Desktop/before fucj/seance equippements/back_app.PNG");
    ui->back->setPixmap(pixmap.scaledToHeight(ui->back->height()));
    QIcon icon("C:/Users/LEGION/Desktop/studies/qt/Atelier_Connexion/logo.ico");
    setWindowIcon(icon);

}

login::~login()
{
    delete ui;
}






void login::on_pushButton_clicked()
{
    User U;
    QString email = ui->lineEdit_email->text();
    QString motDePasse = ui->lineEdit_mdp->text();


    QRegularExpression emailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,}\\b", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegex, this);
    ui->lineEdit_email->setValidator(emailValidator);
    QRegularExpressionMatch match = emailRegex.match(ui->lineEdit_email->text());
    bool isValid = match.hasMatch();
    if(isValid==false) {
                    QMessageBox::critical(nullptr, QObject::tr("Email"),
                                QObject::tr("Wrong Email.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
    else
    {
        bool result = U.comparerEmailMotDePasse(email, motDePasse);
        if (result) {
                qDebug() << "Connexion réussie";
                QSqlQuery query;
                QString role ;



            role = U.chercherRole(email, motDePasse);


                if(role=="admin")
                {
                Dialog w;
                dashboard d;
                dashboard_e e;
                //mdp m;
                MainWindow m;

                d.exec();}
                else
                {
                dashboard_e e;

                e.exec();}


            } else {
                qDebug() << "Email ou mot de passe invalides";
            }
    }
}

void login::on_pushButton_3_clicked()
{
    dialog_mdp w;
    w.exec();
}

void login::on_pushButton_2_clicked()
{
    createaccount w;
    w.exec();
}
