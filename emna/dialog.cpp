<<<<<<< HEAD
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
=======
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
>>>>>>> c8f612c71c066dc8965fe32616aa55601a129795
