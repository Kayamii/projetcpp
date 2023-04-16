#include "mdp.h"
#include "ui_mdp.h"

mdp::mdp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mdp)
{
    ui->setupUi(this);
}

mdp::~mdp()
{
    delete ui;
}
