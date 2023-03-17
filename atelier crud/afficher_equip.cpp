#include "afficher_equip.h"
#include "ui_afficher_equip.h"

Afficher_equip::Afficher_equip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Afficher_equip)
{
    ui->setupUi(this);
}

Afficher_equip::~Afficher_equip()
{
    delete ui;
}
