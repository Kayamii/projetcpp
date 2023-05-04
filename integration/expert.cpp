#include "expert.h"
#include <QtSql/QSqlQueryModel>
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

     QSqlQueryModel * expert::rechercher(QString var)
     {
         QSqlQueryModel *model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM experts WHERE nom LIKE '%" + var + "%' OR prenom LIKE '%" + var + "%'");


         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_expert"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("specialite"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("sexe"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));

         return model;
     }

     QSqlQueryModel * expert::trier()
     {
         QSqlQueryModel *model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM experts ORDER BY NOM ASC");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_expert"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("specialite"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("sexe"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));
         return model;
     }


     bool expert::genererPDFact()
            {
                QPdfWriter pdf("C:/Users/LEGION/Desktop/seance equippements/pdfex.pdf");
                QPainter painter(&pdf);
               int i = 4000;

              // QImage img("C:/Users/LEGION/Desktop/studies/qt/Atelier_Connexion/download.jpeg");
              /* Q_ASSERT(!img.isNull());
               painter.drawImage(QRect(8000, 400, 504, 403), img);*/

                    painter.setPen(Qt::darkBlue);
                    painter.setFont(QFont("euphemia", 40));
                    painter.drawText(1100,1200,"Liste Des experts");
                    painter.setPen(Qt::black);
                    painter.setFont(QFont("calibri", 20));
                    painter.drawRect(100,100,7300,2600);
                    painter.drawRect(0,3000,9600,500);
                    painter.setFont(QFont("consolas", 9));
                    painter.drawText(200,3300,"ID_expert");
                    painter.drawText(1300,3300,"prenom");
                    painter.drawText(2400,3300,"nom");
                    painter.drawText(3500,3300,"specialite");
                    painter.drawText(4600,3300,"sexe");
                    painter.drawText(5700,3300,"age");

                    QSqlQuery query;
                    query.prepare("select * from experts");
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


     QChartView * expert::stat()
      {

          int row_count = 0;
          int row_count1 = 0;

                  QSqlQuery query,query2;

                  query.prepare("SELECT SEXE FROM experts WHERE AGE > 20; ");
                  query.exec();

                  query2.prepare("SELECT SEXE FROM experts WHERE AGE < 20 ");
                  query2.exec();

                  while(query2.next())

                      row_count1++;



                  while(query.next())
                      row_count++;

                  qDebug()<<"row1="<<row_count<<row_count1;

          QPieSeries *series = new QPieSeries();
          series->append("DES EXPERTS QUI ONT - 20  ans", row_count1);
          series->append("DES EXPERTS QUI ONT + 20 ans ", row_count);
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


     bool expert::verifiertype(int id)
     {

         QSqlQuery query2;
         query2.prepare("select * from adherents where idexpert=:id");
         query2.bindValue(":id",id);
         bool test=(query2.exec()) && (query2.next());
         return test;
     }


     QSqlQueryModel* expert::listAdherants(int type)
     {
         QSqlQueryModel *model = new QSqlQueryModel();
         QSqlQuery q;

         q.prepare("SELECT id, CASE :type WHEN 1 THEN 'medecin' WHEN 2 THEN 'coach' ELSE 'psychologue' END AS type,nom,prenom,sexe FROM adherents where type=:type;");
         q.bindValue(":type",type);
         q.exec();
         model->setQuery(q);

         return model;
     }

     void expert::writeLog(int id,QString message)
     {
         // Ouverture du fichier en mode écriture à la fin du fichier
         QFile file("C:/Users/LEGION/Desktop/seance equippements/txt.txt");
         if (!file.open(QIODevice::Append | QIODevice::Text))
             return;

         // Création d'un objet QTextStream pour écrire dans le fichier
         QTextStream out(&file);
         QDateTime currentDateTime = QDateTime::currentDateTime();
           QString dateTimeString = currentDateTime.toString("dd-MM-yyyy hh:mm:ss");

         // Écriture du message de log avec l'ID correspondant
         out << dateTimeString <<" " << " " << message << id << endl;

         // Fermeture du fichier
         file.close();
     }





