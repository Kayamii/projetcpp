#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "expert.h"
#include "employe.h"
#include "dialog_mdp.h"
#include "createaccount.h"
#include "user.h"
#include "QDebug"
#include "QMessageBox"
#include "QSystemTrayIcon"
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("C:/Users/Mohamed/Downloads/logo.png"));
    trayIcon->setVisible(true);

    QAction* notificationAction = new QAction("Notification", this);
    connect(notificationAction, &QAction::triggered, [trayIcon]() { trayIcon->showMessage("Notification", "Vous avez une seance dans 10 minutes", QSystemTrayIcon::Information, 5000);
    });
    notificationAction->trigger();*/
    }







MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
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

                if(role=="employee")
                {
                Dialog w;
                w.exec();}
                else
                {
                employe e;
                e.exec();}


            } else {
                qDebug() << "Email ou mot de passe invalides";
            }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog_mdp w;
    w.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    createaccount w;
    w.exec();
}
