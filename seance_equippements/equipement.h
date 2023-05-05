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
#include <QLabel>
QT_CHARTS_USE_NAMESPACE
class Equipements
{
public:
    Equipements();
    Equipements(int,int,int,int,QString,QString,QByteArray );

    int getid();
    int getquantite();
    int getidseance();
    int getprix();
    QString getduree();
    QString getnom();
    QByteArray getimage();
    QLabel* getimageLabel();


    void setid(int);
    void setquantite(int);
    void setidseance(int);
    void setprix(int);
    void setduree(QString);
    void setnom(QString);
void setImage (QByteArray image);

                bool ajouter();
                QSqlQueryModel *afficher();
                bool supprimer(int);
                // bool modifier(int);
                bool modifier(int ID_EQU, QByteArray image);
                 bool verifier (int id);
                 QSqlQueryModel *rechercher(QString var);
                 QSqlQueryModel *rechercher1(QString var);
                 QSqlQueryModel * trier();

                 bool genererPDFact();
                 QChartView * stat();
              bool updateID_SEANCE(int ID_EQUIPP);
void setimageLabel(QLabel *);

int checkDureeVie(int id_equi);

private:
                 QString DUREE_VIE, NOMEQUIP;
                     int ID_EQU, QUANTITE, ID_SEANCE, PRIX;
                     QByteArray image;
                      QLabel* imageLabel;

};

#endif // EQUIPEMENTS_H
