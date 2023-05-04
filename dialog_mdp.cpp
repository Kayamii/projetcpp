#include "dialog_mdp.h"
#include "ui_dialog_mdp.h"
#include "dialog_mdp.h"
#include "ui_dialog_mdp.h"
#include "user.h"
#include "verification.h"
#include <QDebug>
#include <QMessageBox>

dialog_mdp::dialog_mdp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_mdp)
{
    ui->setupUi(this);
}

dialog_mdp::~dialog_mdp()
{
    delete ui;
}



void dialog_mdp::on_pushButton_4_clicked()
{
    close();
}

void dialog_mdp::on_pushButton_clicked()
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
