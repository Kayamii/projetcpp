#include "verification.h"
#include "ui_verification.h"
#include "mdp.h"
#include "qdebug.h"
#include "QMessageBox"
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

void verification::on_pushButton_clicked()
{
    QString code=ui->code->text();
    if(code==ch)
    {

        qDebug() << "code valide.";
        QMessageBox::information(nullptr, QObject::tr("Add"),
                    QObject::tr("Email\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        mdp w;
        w.mm=m;
        w.exec();


    }
}
