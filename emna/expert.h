#ifndef EXPERT_H
#define EXPERT_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QtSql/QSqlQueryModel>
#include <QVariant>

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
private:
    QString  prenom ,nom , specialite,sexe;
    int id_expert,age;
};

#endif // EXPERT_H
