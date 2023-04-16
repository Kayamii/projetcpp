#include "dialog_mdp.h"
#include "ui_dialog_mdp.h"
#include "user.h"
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
    User u;
    QString destination=ui->mail->text();
    u.envoyer_mail(destination);
    close();
}
