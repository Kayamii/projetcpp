#include "dialog_mdp.h"
#include "ui_dialog_mdp.h"
#include "user.h"
#include "verification.h"
#include <QDebug>
#include <QMessageBox>
Dialog_mdp::Dialog_mdp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_mdp)
{
    ui->setupUi(this);
}

Dialog_mdp::~Dialog_mdp()
{
    delete ui;
}

void Dialog_mdp::on_pushButton_4_clicked()
{
    close();
}

void Dialog_mdp::on_pushButton_clicked()
{

    User U;
    QString email = ui->mail->text();


    bool result = U.comparerEmail(email);
    if (result) {
        qDebug() << "Email valides.";




        verification w;
        w.ch=U.envoyer_mail(email);
        w.m=email;
        w.exec();


        } else {
            qDebug() << "Email invalides";
        }


}
