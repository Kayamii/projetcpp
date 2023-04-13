#include "expert.h"
#include <QtSql/QSqlQueryModel>

expert::expert()
{
    id_expert=0;
    prenom="";
    nom="";
    specialite="";
    sexe="";
    age=0;
}
expert::expert (int id , QString prenom, QString nom,QString specialite,QString sexe,int age)
{
    this->id_expert=id;
    this->prenom=prenom;
    this->nom=nom;
    this->specialite=specialite;
    this->sexe=sexe;
    this->age=age;
}

    void expert::setid_expert(int n){id_expert=n;}
    void expert::setprenom(QString n){prenom=n;}
    void expert::setspecialite(QString n){specialite=n;}
    void expert::setnom(QString n){nom=n;}
    int expert::getid_expert(){return id_expert;}
    QString expert::getprenom(){return prenom;}
    QString expert::getnom(){return nom;}
    QString expert::getspecialite(){return specialite;}
    int expert:: getage(){return age; }
    QString expert:: getsexe(){return sexe;}

    bool expert::ajoutExpert()
     {
        QSqlQuery query;
         query.prepare("INSERT INTO experts (id_expert, prenom, nom, specialite, sexe, age) "
                       "VALUES (:id_expert, :prenom, :nom, :specialite, :sexe, :age)");
         // Set values for parameters
         query.bindValue(":id_expert", id_expert);
         query.bindValue(":prenom", prenom);
         query.bindValue(":nom", nom);
         query.bindValue(":specialite", specialite);
         query.bindValue(":sexe", sexe);
         query.bindValue(":age", age);


    return query.exec();
           }
    QSqlQueryModel* expert::listExpert()
    {
            QSqlQueryModel* model = new QSqlQueryModel();
             model->setQuery("SELECT * FROM experts ");
             model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
              model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
             model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
              model->setHeaderData(3,Qt::Horizontal,QObject::tr("specialite"));
                model->setHeaderData(4,Qt::Horizontal,QObject::tr("sexe"));
                  model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));

             return model;
    }

     bool expert::deletExpert(int id)
     {
         QSqlQuery query;

            query.prepare("DELETE FROM experts WHERE id_expert = ?");
            query.addBindValue(id);

              return query.exec();
     }
     bool expert::modifierExpert(int id_expert, QString prenom ,QString nom , QString specialite,QString sexe,int age)
     {
         QSqlQuery query;
         query.prepare("update experts set id_expert=:id_expert ,prenom=:prenom,nom=:nom,specialite=:specialite,sexe=:sexe,age=:age WHERE id_expert=:id_expert "); //requette
         query.bindValue(":id_expert",id_expert);
         query.bindValue(":prenom",prenom);
         query.bindValue(":nom",nom);
         query.bindValue(":specialite",specialite);
         query.bindValue(":sexe",sexe);
         query.bindValue(":age",age);

         return query.exec();

     }
