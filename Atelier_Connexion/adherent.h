#ifndef ADHERENT_H
#define ADHERENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QTableWidget>
QT_CHARTS_USE_NAMESPACE

class Adherent
{
public:
    Adherent();
    Adherent(int,int,QString,QString,QString);
    int getid();
    int getage();
    int gettype();
    QString getnom();
    QString getprenom();
    QString getsexe();
    void setid(int);
    void setage(int);
    void settype(int);
    void setnom(QString);
    void setprenom(QString);
    void setsexe(QString);
    bool ajouter();
    bool supprimer(int id);
    bool modifier(int id);
    bool verifier(int id);
    bool verifiertype(int type);
    bool genererPDFact();
    void displayAdherentsByType(int type);



    QSqlQueryModel *afficher();
    QSqlQueryModel *affichert1();
    QSqlQueryModel *affichert2();
    QSqlQueryModel *affichert3();
    QSqlQueryModel *rechercher(QString var);
    QSqlQueryModel * trier();
    QChartView * stat();


private:
QString nom, prenom, sexe;
int type,id,age;

};

#endif // ADHERENT_H
