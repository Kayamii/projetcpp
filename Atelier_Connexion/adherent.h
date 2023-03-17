#ifndef ADHERENT_H
#define ADHERENT_H
#include <QString>
#include <QSqlQueryModel>

class Adherent
{
public:
    Adherent();
    Adherent(int,int,QString,QString,QString);
    int getid();
    int getidexpert();
    int gettype();
    QString getnom();
    QString getprenom();
    QString getsexe();
    void setid(int);
    void setidexpert(int);
    void settype(int);
    void setnom(QString);
    void setprenom(QString);
    void setsexe(QString);
    bool ajouter();
    bool supprimer(int id);
    bool modifier(int id);
    bool verifier(int id);

    QSqlQueryModel *afficher();

private:
QString nom, prenom, sexe;
int type,id,idexpert;

};

#endif // ADHERENT_H
