#include "supprimer_equip.h"
#include "ui_supprimer_equip.h"

Supprimer_equip::Supprimer_equip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supprimer_equip)
{
    ui->setupUi(this);
}

Supprimer_equip::~Supprimer_equip()
{
    delete ui;
}
