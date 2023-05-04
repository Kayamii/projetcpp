#include "adherent.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QObject>
#include <QSqlDriver>
#include <QPdfWriter>
#include <QPainter>
#include <QImage>
#include <QSqlTableModel>
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
Adherent::Adherent()
{
 id=0; age=0; type=0; nom=" "; prenom=" "; sexe=" ";

}


Adherent::Adherent(int age,int type,QString nom,QString prenom,QString sexe)
{

    this->age=age;
    this->type=type;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;

}
int Adherent::getid(){return id;}
int Adherent::getage(){return age;}
int Adherent::gettype(){return type;}
QString Adherent::getnom(){return nom;}
QString Adherent::getprenom(){return prenom;}
QString Adherent::getsexe(){return sexe;}
void Adherent::setid(int id) {this->id=id;}
void Adherent::setage(int age) {this->age=age;}
void Adherent::settype(int type){this->type=type;}
void Adherent::setnom(QString nom){this->nom=nom;}
void Adherent::setprenom(QString prenom){this->prenom=prenom;}
void Adherent::setsexe(QString sexe){this->sexe=sexe;}

bool Adherent::ajouter()
{
    QSqlQuery query;

    QString age_string= QString::number(age);
    QString type_string= QString::number(type);
        query.prepare("INSERT INTO adherents (age,type,nom,prenom,sexe) "
                      "VALUES (:age, :type, :nom, :prenom, :sexe)");

        query.bindValue(":age",age_string);
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
model->setHeaderData(1,Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("degré"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
return model;
}

QSqlQueryModel * Adherent::affichert1()
{
    QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("SELECT * FROM adherents WHERE type = 3 AND age < 10 AND sexe = 'f';");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("degré"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
return model;
}

QSqlQueryModel * Adherent::affichert2()
{
    QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("SELECT * FROM adherents WHERE type = 2 AND age < 10 AND sexe IN ('f', 'm')");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("degré"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
return model;
}

QSqlQueryModel * Adherent::affichert3()
{
    QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("SELECT * FROM adherents WHERE type = 1 AND age > 10 AND sexe = 'm';");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("degré"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
return model;
}




bool Adherent::modifier(int id)
{
    QSqlQuery query;


    QString res = QString::number(id);
    QString res2 = QString::number(age);
    QString res3 = QString::number(type);

    //

   query.prepare("UPDATE ADHERENTS SET id=:id,age=:age,type=:type,nom=:nom,prenom=:prenom,sexe=:sexe WHERE id=:id");

    //
    query.bindValue(":id",res);
    query.bindValue(":age",res2);
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


bool Adherent::verifiertype(int type)
{

    QSqlQuery query2;
    query2.prepare("select type from adherents where type=:type");
    query2.bindValue(":type",type);
    bool test=(query2.exec()) && (query2.next());
    return test;
}



QSqlQueryModel * Adherent::rechercher(QString var)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM adherents WHERE nom LIKE '%" + var + "%' OR prenom LIKE '%" + var + "%'");


    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}

QSqlQueryModel * Adherent::trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM ADHERENTS ORDER BY NOM ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("sexe"));
    return model;
}

QChartView * Adherent::stat()
 {

     int row_count = 0;
     int row_count1 = 0;

             QSqlQuery query,query2;

             query.prepare("SELECT SEXE FROM ADHERENTS WHERE SEXE= 'f' ");
             query.exec();

             query2.prepare("SELECT SEXE FROM ADHERENTS WHERE SEXE = 'm' ");
             query2.exec();

             while(query2.next())

                 row_count1++;



             while(query.next())
                 row_count++;

             qDebug()<<"row1="<<row_count<<row_count1;

     QPieSeries *series = new QPieSeries();
     series->append("DES ADHERENTS QUI SONT MALES", row_count1);
     series->append("DES ADHERENTS QUI SONT FEMMES", row_count);
     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Statistique selon le sexe :");
     chart->legend()->setAlignment(Qt::AlignRight);
     chart->legend()->setBackgroundVisible(true);
     chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
     chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
     series->setLabelsVisible();

     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     return chartView;
 }


bool Adherent::genererPDFact()
       {
           QPdfWriter pdf("C:/Users/LEGION/Desktop/seance equippements/pdfA.pdf");
           QPainter painter(&pdf);
          int i = 4000;

          QImage img("C:/Users/LEGION/Desktop/studies/qt/Atelier_Connexion/logo.png");
          Q_ASSERT(!img.isNull());
          painter.drawImage(QRect(8000, 400,1000,1100), img);

               painter.setPen(Qt::darkBlue);
               QPixmap background("background.jpg");
               painter.setFont(QFont("euphemia", 40));
               painter.drawText(1100,1200,"Liste Des Adherents");
               painter.setPen(Qt::black);
               painter.setFont(QFont("calibri", 20));
               painter.drawRect(100,100,7300,2600);
               painter.drawRect(0,3000,9600,500);
               painter.setFont(QFont("consolas", 9));
               painter.drawText(200,3300,"ID_Adherent");
               painter.drawText(1300,3300,"AGE");
               painter.drawText(2400,3300,"TYPE");
               painter.drawText(3500,3300,"NOM");
               painter.drawText(4600,3300,"PRENOM");
               painter.drawText(5700,3300,"SEXE");


               QSqlQuery query;
               query.prepare("select * from ADHERENTS");
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


/*void Adherent::displayAdherentsByType(int type) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryString = "SELECT nom FROM Adherent WHERE type = :type";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":type", type);

    if (query.exec()) {
        model->setQuery(query);
        sortview->setModel(model);
    }
}*/





