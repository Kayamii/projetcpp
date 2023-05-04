#ifndef EXPERT_H
#define EXPERT_H
#include <QString>
#include <QSqlQueryModel>
#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QTableWidget>
using namespace QtCharts;

class expert
{
public:
    void setid_expert(int n);
    void setprenom(QString n);
    void setnom(QString n);
    void setspecialite(QString n);
    void setsexe(QString sexe);
    void setage(int age);

    int getid_expert();
    QString getprenom();
    QString getnom();
    QString getsexe();
    QString getspecialite();
    int getage();

    expert(int  , QString , QString ,QString ,QString ,int );
    expert();
    bool ajoutExpert();
        QSqlQueryModel* listExpert();
        expert* getExpert(int &id);
        bool deletExpert(int id);
        bool modifierExpert(int , QString  ,QString  , QString ,QString ,int );
        QSqlQueryModel *rechercher(QString var);
        QSqlQueryModel * trier();
        bool genererPDFact();
        QChartView * stat();
        bool verifiertype(int id);
         QSqlQueryModel* listAdherants(int);
         void writeLog(int id,QString message);

private:
    QString  prenom ,nom , specialite,sexe;
    int id_expert,age;
};

#endif // EXPERT_H

