#ifndef USER_H
#define USER_H
#include <QString>
#include <qsqlquerymodel.h>
#include<QSqlQuery>
#include<QSqlQueryModel>

class User
{
public:
    User();
    User(int,QString,QString,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getcin();
    QString getemail();
    QString getrole();
    QString getmdp();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setcin(QString);
    void setemail(QString);
    void setrole(QString);
    void setmdp(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    bool recherche(int);
    QSqlQueryModel *afficher_search_result(QString ch);
    QSqlQueryModel *afficher_id_decroissant();
    QSqlQueryModel *afficher_id_croissant();
    bool comparerEmailMotDePasse(const QString& email, const QString& motDePasse);
    QString envoyer_mail(QString);
    void generate_pdf();
    bool comparerEmail(const QString& email);
    QString chercherRole(QString email, QString motDePasse);


private:
    int id;
    QString nom,prenom,cin,email,role,mdp;
};

#endif // USER_H
