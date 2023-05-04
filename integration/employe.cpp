#include "employe.h"
#include "ui_employe.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "user.h"
#include "QSqlQuery"
#include <QMessageBox>
#include "QDebug"
#include <QIntValidator>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
QT_CHARTS_USE_NAMESPACE
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QtPrintSupport>



employe::employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employe)
{
    ui->setupUi(this);
}

employe::~employe()
{
    delete ui;
}

void employe::on_stats_clicked()
{
    QSqlQuery q1,q2,q3;

           qreal tot=0,c1=0,c2=0;
           q1.prepare("SELECT id FROM ADMINS");
           q1.exec();
           q2.prepare("SELECT id FROM ADMINS WHERE role='expert'");
           q2.exec();
           q3.prepare("SELECT id FROM ADMINS WHERE role='employee'");
           q3.exec();
           while (q1.next()){tot++;}
           while (q2.next()){c1++;}
           while (q3.next()){c2++;}
           c1=(c1*100)/tot;
           c2=(c2*100)/tot;
           QString c3= QString::number(c1) ;
           c3= " = "+c3+"%"  ;
        QString c4= QString::number(c2) ;
        c4= " = "+c4+"%"  ;
         QString etat1="expert" ;
         etat1=etat1+c3 ;
         QString etat2="employee" ;
         etat2=etat2+c4 ;
           //Création des pie series
           QPieSeries *series = new QPieSeries();
           series->append(etat1,c1);
           series->append(etat2,c2);
           //Creation d'un charte
           QChart *chart =new QChart();
           chart->setTitle("Les résultats:");
           chart->addSeries(series);
           chart->legend()->show();
            chart->setBackgroundBrush(QColor(252, 236, 218, 0));
           QChartView *chartView;
           chartView = new QChartView(chart,ui->graphicsView);
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->setMinimumSize(400,400);
           chartView->show();
}

void employe::on_imp_clicked()
{

    U.generate_pdf();


}

void employe::on_rech_textChanged(const QString &arg1)
{
ui->tab_users->setModel(U.afficher_search_result(ui->rech->text() ));
}

void employe::on_tri_currentIndexChanged(const QString &arg1)
{
    if(ui->tri->currentText()=="id ↓"){ ui->tab_users->setModel(U.afficher_id_decroissant());}
        if(ui->tri->currentText()=="id ↑"){ ui->tab_users->setModel(U.afficher_id_croissant());}

}


void employe::on_pushButton_2_clicked()
{
    ui->tab_users->setModel(U.afficher());

}
