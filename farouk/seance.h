#ifndef SEANCE_H
#define SEANCE_H
#include <QString>
#include <QSqlQueryModel>

class Seance
{
public:
    Seance();
    Seance(int,QString,QString,QString);
    int getid_seance();
    int getid_exp();
    //int getid_equi();
    QString gettype();
    QString getduree();
    QString getdate();
    void setid_seance(int);
    void setid_exp(int);
  // void setid_equi(int);
      void settype(QString);
         void setduree(QString);
            void setdate(QString);
bool ajouter();
bool supprimer(int id);
bool modifier(int id);
QSqlQueryModel * afficher();
private:
    int id_seance, id_exp;
    QString type,duree,date;

};

#endif // SEANCE_H
