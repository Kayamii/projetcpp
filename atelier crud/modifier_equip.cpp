#include "modifier_equip.h"
#include "ui_modifier_equip.h"

Modifier_equip::Modifier_equip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifier_equip)
{
    ui->setupUi(this);
}

Modifier_equip::~Modifier_equip()
{
    delete ui;
}
