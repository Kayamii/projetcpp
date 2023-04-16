#include "verification.h"
#include "ui_verification.h"

verification::verification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verification)
{
    ui->setupUi(this);
}

verification::~verification()
{
    delete ui;
}
