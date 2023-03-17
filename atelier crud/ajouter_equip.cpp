#include "ajouter_equip.h"
#include "ui_ajouter_equip.h"

Ajouter_equip::Ajouter_equip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ajouter_equip)
{
    ui->setupUi(this);
}

Ajouter_equip::~Ajouter_equip()
{
    delete ui;
}


void Ajouter_equip::on_btnSave_clicked()
{
    QString NOMEQUIP= ui->nomEquip->text();
    QString PRIX=ui->prixEquip->text();
    QString QUANTITE=ui->quantite->text();
    QString DUREE_VIE=ui->DUREE_VIE->text();
    QString ID_EQU=ui->ID_EQU->text();
}
