#include "mdp.h"
#include "ui_mdp.h"
#include "verification.h"
#include <qsqlquery.h>
#include <qdebug.h>
#include <QMessageBox>
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

void mdp::on_pushButton_clicked()
{
    QString mdp = ui->mdp_2->text();
    QString confmdp = ui->mdp_3->text();
    if(confmdp==mdp)
    {
    QSqlQuery query;
    query.prepare("UPDATE ADMINS SET MDP=:mdp where email=:mm");
    qDebug()<<"mail="<<mm;
    qDebug()<<"mot de passe="<<mdp;
    query.bindValue(0,mdp);
    query.bindValue(1,mm);
    query.exec();}
    else{

        QMessageBox::critical(nullptr, QObject::tr("Empty"),
                    QObject::tr("wrong email verify please.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }


}
