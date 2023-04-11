#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlQueryModel>
#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QTableWidget>
QT_CHARTS_USE_NAMESPACE
class Equipements
{
public:
    Equipements();
    Equipements(int,int,int,int,QString,QString);

    int getid();
    int getquantite();
    int getidseance();
    int getprix();
    QString getduree();
    QString getnom();

    void setid(int);
    void setquantite(int);
    void setidseance(int);
    void setprix(int);
    void setduree(QString);
    void setnom(QString);

                bool ajouter();
                QSqlQueryModel *afficher();
                bool supprimer(int);
                 bool modifier(int);
                 bool verifier (int id);
                 QSqlQueryModel *rechercher(QString var);
                 QSqlQueryModel * trier();

                 bool genererPDFact();
                 QChartView * stat();





private:
                 QString DUREE_VIE, NOMEQUIP;
                     int ID_EQU, QUANTITE, ID_SEANCE, PRIX;
};

#endif // EQUIPEMENTS_H
