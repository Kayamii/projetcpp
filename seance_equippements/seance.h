#ifndef SEANCE_H
#define SEANCE_H
#include <QString>
#include <QSqlQueryModel>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDialog>
#include <QtCharts/QChartView>
#include <QPainter>
#include <QPdfWriter>
using namespace QtCharts;

class Seance
{
public:
    Seance();
    Seance(int,int,QString,QString,QString,QString);
~Seance();
    int getid_seance();
    int getid_exp();
    int getid_equi();

    QString gettype();
    QString getduree();
    QString getdate();
     QString getheure();
    void setid_seance(int);
    void setid_exp(int);
    void setid_equi(int);

      void settype(QString);
         void setduree(QString);
            void setdate(QString);
             void setheure(QString);
bool ajouter();
bool supprimer(int id);
bool modifier(int id);
bool verifier(int id);
QSqlQueryModel * afficher();
QSqlQueryModel * trier();
QSqlQueryModel * rechercher(QString r);
QChartView *stats();
int getLastInsertedId();

bool pdf();
private:
    int id_seance, id_exp,id_equi;
    QString typee,duree,datee,heure;

};

#endif // SEANCE_H

