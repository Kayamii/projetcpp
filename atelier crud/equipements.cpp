#include "equipements.h"
#include<QString>
#include<QMessageBox>
Equipements:: Equipements ()
{
ID_EQU=0;
QUANTITE=0;
PRIX=0;
ID_SEANCE=0;
DUREE_VIE=" ";
NOMEQUIP=" ";
}
Equipements:: Equipements (int ID_EQU, int QUANTITE,int PRIX,int ID_SEANCE,QString DUREE_VIE, QString NOMEQUIP)
{

    this->ID_EQU=ID_EQU;

    this->QUANTITE=QUANTITE;
    this->ID_SEANCE=ID_SEANCE;
  this->PRIX =PRIX;
  this->DUREE_VIE=DUREE_VIE;
   this->NOMEQUIP=NOMEQUIP;
}

int Equipements::getid(){ return ID_EQU;};
int Equipements ::getquantite(){return QUANTITE;};
int Equipements :: getidseance(){return ID_SEANCE;}
int Equipements :: getprix(){return PRIX ;}
QString Equipements :: getduree(){return DUREE_VIE;}
QString Equipements ::getnom(){return  NOMEQUIP;}

void Equipements :: setid(int ID_EQU) {this->ID_EQU=ID_EQU;}
void Equipements ::setquantite(int QUANTITE) {this->QUANTITE=QUANTITE; }
void Equipements ::setidseance(int ID_SEANCE)  {this->ID_SEANCE=ID_SEANCE;}
void Equipements ::setprix(int PRIX){  this->PRIX =PRIX;}
void Equipements ::setduree(QString DUREE_VIE){this->DUREE_VIE=DUREE_VIE;}
void Equipements ::setnom(QString NOMEQUIP) { this->NOMEQUIP=NOMEQUIP;}

bool Equipements::ajouter()
{

    QSqlQuery query;
    QString res =QString ::number (ID_EQU);
    QString res1 =QString ::number (PRIX);
    QString res2 =QString ::number (QUANTITE);
    QString res3 =QString ::number (ID_SEANCE);
    query.prepare("INSERT INTO EQUIPPEMENTS (ID_EQU,NOMEQUIP,PRIX,QUANTITE,DUREE_VIE,ID_SEANCE)" "values(:ID_EQU,:NOMEQUIP,:PRIX,:QUANTITE,:DUREE_VIE,:ID_SEANCE)");
    query.bindValue(":ID_EQU",res);
    query.bindValue(":NOMEQUIP",NOMEQUIP);
    query.bindValue(":PRIX",res1);
    query.bindValue(":QUANTITE",res2);
    query.bindValue(":DUREE_VIE",DUREE_VIE);
    query.bindValue(":ID_SEANCE",res3);

    return query.exec();

}
QSqlQueryModel * Equipements ::afficher()

{

    QSqlQueryModel* model=new QSqlQueryModel() ; //

          model->setQuery("SELECT* FROM EQUIPPEMENTS");

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQU"));

          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));

          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

          model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DUREE_VIE"));

     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_SEANCE"));

          return model ;



}
bool Equipements::supprimer(int id)
{
    QSqlQuery query;
    QString res =QString::number(id);
    query.prepare("Delete from EQUIPPEMENTS Where ID_EQU=:id");
    query.bindValue(":id",res);

    return query.exec();
}
bool Equipements::modifier(int ID_EQU)

{

    QSqlQuery query;
    QSqlQuery checkQuery;

    QString res =QString ::number (ID_EQU);
    QString res1 =QString ::number (PRIX);
    QString res2 =QString ::number (QUANTITE);
    QString res3 =QString ::number (ID_SEANCE);
    checkQuery.prepare("SELECT id FROM equipment WHERE ID_EQU = :ID_EQU");
      checkQuery.bindValue(":ID_EQU",ID_EQU);
      if (!checkQuery.exec()) {
          QMessageBox::critical(nullptr, QObject::tr("Not okay"),

                       QObject::tr("couldn't search for equipement.\n"

                              "Click Cancel to exit."), QMessageBox::Cancel);


      }
      if (!checkQuery.next()) {
          QMessageBox::critical(nullptr, QObject::tr("Not okay"),

                       QObject::tr("EQUIPEMENT N'EXISTE PAS.\n"

                              "Click Cancel to exit."), QMessageBox::Cancel);

      }
else {
query.prepare("UPDATE EQUIPPEMENTS SET ID_EQU=:ID_EQU,  NOMEQUIP =:NOMEQUIP,PRIX=:PRIX,QUANTITE=:QUANTITE, DUREE_VIE=:DUREE_VIE, ID_SEANCE=:ID_SEANCE WHERE ID_EQU=:ID_EQU");


    query.bindValue(":ID_EQU",res);
    query.bindValue(":NOMEQUIP",NOMEQUIP);
    query.bindValue(":PRIX",res1);
    query.bindValue(":QUANTITE",res2);
    query.bindValue(":DUREE_VIE",DUREE_VIE);
    query.bindValue(":ID_SEANCE",res3);

}

      return query.exec();

}

