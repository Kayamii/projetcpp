#include "seance.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
Seance::Seance()
{
    id_seance =0;
    id_exp=0;
    //id_equi=0;
    type=" ";
    duree=" ";
    date=" ";

}

Seance::Seance(int id_exp,QString type,QString duree,QString date)
{//this->id_seance=id_seance ;
    this->id_exp=id_exp ;
   // this->id_equi=id_equi ;
    this->type=type ;
    this->duree=duree ;
    this->date=date;
}
int Seance::getid_seance(){return id_seance;}
int Seance::getid_exp(){return id_exp;}
//int Seance::getid_equi(){return id_equi;}
QString Seance::gettype(){return type;}
QString Seance::getduree(){return duree;}
QString Seance::getdate(){return date;}
void Seance::setid_seance(int id_seance){this->id_seance=id_seance;}
void Seance::setid_exp(int id_exp){this->id_exp=id_exp;}
//void Seance::setid_equi(int id_equi){this->id_equi=id_equi;}
void Seance::settype(QString type){this->type=type;}
void Seance::setduree(QString duree){this->duree=duree;}
void Seance::setdate(QString date){this->date=date;}
bool Seance::ajouter()
{
    QSqlQuery query;
    QString id_s= QString::number(id_seance);
     QString id_ex= QString::number(id_exp);
      //QString id_eq= QString::number(id_equi);
        query.prepare("INSERT INTO SEANCES (ID_EXPERT,DUREE,DATEE,TYPEE) "
                      "VALUES ( :id_exp, :duree, :date, :type )");
       // query.bindValue(":id_seance", id_s);
        query.bindValue(":id_exp", id_ex);
       // query.bindValue(":id_equi", id_eq);
         query.bindValue(":type", type);
          query.bindValue(":duree", duree);
           query.bindValue(":date", date);

       return query.exec();
}
bool Seance::supprimer(int id)
{QSqlQuery query;
    QString ids=QString::number(id);
    query.prepare("Delete from SEANCES where ID_SEANCE=:id");
    query.bindValue(":id",ids);
return query.exec();


}
QSqlQueryModel * Seance::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from SEANCES");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SEANCE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_EXP"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DUREE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE"));
//model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_EQUI"));
return model;


}
bool Seance::modifier(int id)
{
    QSqlQuery query;
    QString ids=QString::number(id);
    QString idexp=QString::number(id_exp);
    query.prepare("UPDATE SEANCES SET ID_SEANCE=:id,ID_EXPERT=:idexpert,DUREE=:duree,DATEE=:date,TYPEE=:type WHERE ID_SEANCE=:id");
    query.bindValue(":id",ids);
      query.bindValue(":idexpert",idexp);
        query.bindValue(":duree",duree);
          query.bindValue(":date",date);
           query.bindValue(":type",type);
return query.exec();


}
