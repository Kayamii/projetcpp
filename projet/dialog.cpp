#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
/*void Dialog::setexpert(expert e)
{
 ui->id->setText(e.getid());
 ui->prenom->setText(e.getprenom ());
 ui->nom->setText(e.getnom());
 ui->specialite->setText(e.getspecialite());

}*/
