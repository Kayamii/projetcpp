#include "equipements.h"
#include<QString>
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QImage>
#include <QDebug>

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

bool Equipements::verifier(int id)
{

    QSqlQuery query2;
    query2.prepare("select ID_EQU from EQUIPPEMENTS where ID_EQU=:id");
    query2.bindValue(":id",id);
    bool test=(query2.exec()) && (query2.next());
    return test;
}
bool Equipements::modifier(int ID_EQU)

{

    QSqlQuery query;
    QString res =QString ::number (ID_EQU);
    QString res1 =QString ::number (PRIX);
    QString res2 =QString ::number (QUANTITE);
    QString res3 =QString ::number (ID_SEANCE);

query.prepare("UPDATE EQUIPPEMENTS SET ID_EQU=:ID_EQU,  NOMEQUIP =:NOMEQUIP,PRIX=:PRIX,QUANTITE=:QUANTITE, DUREE_VIE=:DUREE_VIE, ID_SEANCE=:ID_SEANCE WHERE ID_EQU=:ID_EQU");

    query.bindValue(":ID_EQU",res);
    query.bindValue(":NOMEQUIP",NOMEQUIP);
    query.bindValue(":PRIX",res1);
    query.bindValue(":QUANTITE",res2);
    query.bindValue(":DUREE_VIE",DUREE_VIE);
    query.bindValue(":ID_SEANCE",res3);

      return query.exec();
}
QSqlQueryModel *Equipements::rechercher(QString var)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM EQUIPPEMENTS WHERE NOMEQUIP  LIKE '%"+var+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQU"));

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DUREE_VIE"));

    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_SEANCE"));

    return model;
}


QSqlQueryModel * Equipements::trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM EQUIPPEMENTS ORDER BY NOMEQUIP ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQU"));

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DUREE_VIE"));

    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_SEANCE"));
    return model;
}

bool Equipements::genererPDFact()
       {
           QPdfWriter pdf("C:/Users/user/Desktop/Qt C++/atelier crud/pdf.pdf");
           QPainter painter(&pdf);
          int i = 4000;



               painter.setPen(Qt::darkBlue);

               painter.setFont(QFont("euphemia", 40));
               painter.drawText(1000,1200,"Liste Des Equippements");
               painter.setPen(Qt::black);
               painter.setFont(QFont("calibri", 20));
               painter.drawRect(100,100,7300,2600);
               painter.drawRect(0,3000,9600,500);
               painter.setFont(QFont("consolas", 9));
               painter.drawText(200,3300,"ID_EQU");
               painter.drawText(1300,3300,"NOM");
               painter.drawText(2400,3300,"PRIX");
               painter.drawText(3500,3300,"QUANTITE");
               painter.drawText(4600,3300,"DUREE_VIE");
               painter.drawText(5700,3300,"ID_SEANCE");


               QSqlQuery query;
               query.prepare("select * from EQUIPPEMENTS");
               query.exec();
               while (query.next())
               {
                   painter.drawText(200,i,query.value(0).toString());
                   painter.drawText(1300,i,query.value(1).toString());
                   painter.drawText(2400,i,query.value(2).toString());
                   painter.drawText(3500,i,query.value(3).toString());
                   painter.drawText(4600,i,query.value(4).toString());
                   painter.drawText(5700,i,query.value(5).toString());



                  i = i + 600;


               }



               return query.exec();

      }
QChartView * Equipements::stat()
 {

     int row_count = 0;
     int row_count1 = 0;

             QSqlQuery query,query2;

             query.prepare("SELECT QUANTITE FROM EQUIPPEMENTS WHERE QUANTITE>10 ");
             query.exec();

             query2.prepare("SELECT QUANTITE FROM EQUIPPEMENTS WHERE QUANTITE<10 ");
             query2.exec();

             while(query2.next())

                 row_count1++;



             while(query.next())
                 row_count++;

             qDebug()<<"row1="<<row_count<<row_count1;

     QPieSeries *series = new QPieSeries();
     series->append("DES EQUIPPEMENTS AVEC QT<10", row_count1);
     series->append("DES EQUIPPEMENTS AVEC QT>10", row_count);
     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Statistique selon la quantite des equippements :");
     chart->legend()->setAlignment(Qt::AlignRight);
     chart->legend()->setBackgroundVisible(true);
     chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
     chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
     series->setLabelsVisible();

     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     return chartView;
 }





