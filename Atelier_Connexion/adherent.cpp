#include "adherent.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

Adherent::Adherent()
{
 id=0; idexpert=0; type=0; nom=" "; prenom=" "; sexe=" ";

}


Adherent::Adherent(int idexpert,int type,QString nom,QString prenom,QString sexe)
{

    this->idexpert=idexpert;
    this->type=type;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;

}
int Adherent::getid(){return id;}
int Adherent::getidexpert(){return idexpert;}
int Adherent::gettype(){return type;}
QString Adherent::getnom(){return nom;}
QString Adherent::getprenom(){return prenom;}
QString Adherent::getsexe(){return sexe;}
void Adherent::setid(int id) {this->id=id;}
void Adherent::setidexpert(int idexpert) {this->idexpert=idexpert;}
void Adherent::settype(int type){this->type=type;}
void Adherent::setnom(QString nom){this->nom=nom;}
void Adherent::setprenom(QString prenom){this->prenom=prenom;}
void Adherent::setsexe(QString sexe){this->sexe=sexe;}

bool Adherent::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString idexpert_string= QString::number(idexpert);
    QString type_string= QString::number(type);
        query.prepare("INSERT INTO adherents (idexpert,type,nom,prenom,sexe) "
                      "VALUES (:idexpert, :type, :nom, :prenom, :sexe)");

        query.bindValue(":idexpert",idexpert_string);
        query.bindValue(":type",type_string);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":sexe",sexe);
        return query.exec();
}

bool Adherent::supprimer(int id)
{
 QSqlQuery query;

 QString res=QString::number(id);
 query.prepare("Delete from adherents Where ID=:id");
 query.bindValue(":id",res);
 return query.exec();
}

QSqlQueryModel * Adherent::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from adherents");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("idexpert"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
return model;
}

bool Adherent::modifier(int id)
{
    QSqlQuery query;


    QString res = QString::number(id);
    QString res2 = QString::number(idexpert);
    QString res3 = QString::number(type);

    //

   query.prepare("UPDATE ADHERENTS SET id=:id,idexpert=:idexpert,type=:type,nom=:nom,prenom=:prenom,sexe=:sexe WHERE id=:id");

    //
    query.bindValue(":id",res);
    query.bindValue(":idexpert",res2);
    query.bindValue(":type",res3);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);


    return query.exec();
}


bool Adherent::verifier(int id)
{

    QSqlQuery query2;
    query2.prepare("select id from adherents where id=:id");
    query2.bindValue(":id",id);
    bool test=(query2.exec()) && (query2.next());
    return test;
}

