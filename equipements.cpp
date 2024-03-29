#include "equipement.h"
#include<QString>
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QLabel>
#include <QSqlRecord>
#include <QSqlError>

Equipements:: Equipements ()
{
ID_EQU=0;
QUANTITE=0;
PRIX=0;
ID_SEANCE=0;
DUREE_VIE=" ";
NOMEQUIP=" ";
}
Equipements:: Equipements (int ID_EQU, int QUANTITE,int PRIX,int ID_SEANCE,QString DUREE_VIE, QString NOMEQUIP,QByteArray image)
{

    this->ID_EQU=ID_EQU;

    this->QUANTITE=QUANTITE;
    this->ID_SEANCE=ID_SEANCE;
  this->PRIX =PRIX;
  this->DUREE_VIE=DUREE_VIE;
   this->NOMEQUIP=NOMEQUIP;
    this->image=image;
}

int Equipements::getid(){ return ID_EQU;};
int Equipements ::getquantite(){return QUANTITE;};
int Equipements :: getidseance(){return ID_SEANCE;}
int Equipements :: getprix(){return PRIX ;}
QString Equipements :: getduree(){return DUREE_VIE;}
QString Equipements ::getnom(){return  NOMEQUIP;}
QByteArray Equipements::getimage(){return image;}

void Equipements :: setid(int ID_EQU) {this->ID_EQU=ID_EQU;}
void Equipements ::setquantite(int QUANTITE) {this->QUANTITE=QUANTITE; }
void Equipements ::setidseance(int ID_SEANCE)  {this->ID_SEANCE=ID_SEANCE;}
void Equipements ::setprix(int PRIX){  this->PRIX =PRIX;}
void Equipements ::setduree(QString DUREE_VIE){this->DUREE_VIE=DUREE_VIE;}
void Equipements ::setnom(QString NOMEQUIP) { this->NOMEQUIP=NOMEQUIP;}
void Equipements :: setImage (QByteArray image){this->image=image;}



bool Equipements::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID_EQU);
    QString res1 = QString::number(PRIX);
    QString res2 = QString::number(QUANTITE);

    query.prepare("INSERT INTO EQUIPPEMENTS (ID_EQU, NOMEQUIP, PRIX, QUANTITE, DUREE_VIE, ID_SEANCE, image) VALUES (:ID_EQU, :NOMEQUIP, :PRIX, :QUANTITE, :DUREE_VIE, 0, :image)");

    query.bindValue(":ID_EQU", res);
    query.bindValue(":NOMEQUIP", NOMEQUIP);
    query.bindValue(":PRIX", res1);
    query.bindValue(":QUANTITE", res2);
    query.bindValue(":DUREE_VIE", DUREE_VIE);
    query.bindValue(":image", image);

    return query.exec();
}
QSqlQueryModel * Equipements ::afficher()

{

    QSqlQueryModel* model=new QSqlQueryModel() ; //

          model->setQuery("SELECT* FROM EQUIPPEMENTS");

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQU"));

          model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_SEANCE"));

          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));

          model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DUREE_VIE"));

     model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX"));

     model->setHeaderData(6, Qt::Horizontal, QObject::tr("image"));
     for (int i = 0; i < model->rowCount(); i++) {
         QModelIndex index = model->index(i, 6);
         QByteArray imageData = index.data(Qt::DisplayRole).toByteArray();
         QImage image = QImage::fromData(imageData);
         QLabel* imageLabel = new QLabel();
         imageLabel->setPixmap(QPixmap::fromImage(image));

     }
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
/*bool Equipements::modifier(int ID_EQU)

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
}*/

bool Equipements::modifier(int ID_EQU, QByteArray image)
{
    QSqlQuery query;
    QString res = QString::number(ID_EQU);
    QString res1 = QString::number(PRIX);
    QString res2 = QString::number(QUANTITE);
    QString res3 = QString::number(ID_SEANCE);

    query.prepare("UPDATE EQUIPPEMENTS SET ID_EQU=:ID_EQU, NOMEQUIP=:NOMEQUIP, PRIX=:PRIX, QUANTITE=:QUANTITE, DUREE_VIE=:DUREE_VIE, ID_SEANCE=:ID_SEANCE, image=:image WHERE ID_EQU=:ID_EQU");

    query.bindValue(":ID_EQU", res);
    query.bindValue(":NOMEQUIP", NOMEQUIP);
    query.bindValue(":PRIX", res1);
    query.bindValue(":QUANTITE", res2);
    query.bindValue(":DUREE_VIE", DUREE_VIE);
    query.bindValue(":ID_SEANCE", res3);
    query.bindValue(":image", image);

    return query.exec();
}

QSqlQueryModel *Equipements::rechercher(QString var)
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM EQUIPPEMENTS WHERE NOMEQUIP  LIKE '%"+var+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQU"));

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));

    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DUREE_VIE"));

    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_SEANCE"));

    return model;
}

QSqlQueryModel *Equipements::rechercher1(QString var)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPPEMENTS WHERE ID_EQU=:id");
    query.bindValue(":id", var);

    if (query.exec()) {
        model->setQuery(query);

        // Loop through each row in the model
        for (int i = 0; i < model->rowCount(); ++i) {
            // Get the image data for the current row
            QByteArray imageData = model->record(i).value("image").toByteArray();

            // Load the image data into a QPixmap object
            QPixmap pixmap;
            pixmap.loadFromData(imageData);

            // Set the pixmap as the image for the current row in the model
            model->setData(model->index(i, 6), pixmap.scaledToHeight(100), Qt::DecorationRole);
        }

        // Set the header data
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQU"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DUREE_VIE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_SEANCE"));
    }

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
           QPdfWriter pdf("C:/Users/LEGION/Desktop/seance equippements/emnasghira.pdf");
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

bool Equipements::updateID_SEANCE(int ID_EQUIPP)
{
    // prepare update query
    QSqlQuery query;

    query.prepare("UPDATE EQUIPPEMENTS "
                  "SET duree_vie = duree_vie - 1 "
                  "WHERE ID_EQU IN ("
                  "  SELECT DISTINCT ID_EQUI "
                  "  FROM SEANCES "
                  "  WHERE ID_EQUI = :ID_EQUIPP"
                  ")");

    query.bindValue(":ID_EQUIPP", ID_EQUIPP);

    // execute query
    if (!query.exec()) {
        qDebug() << "Failed to update ID_SEANCE value for ID_EQUIPP:" << ID_EQUIPP;
        return false;
    }

    return true;
}
int Equipements:: checkDureeVie(int ID_EQUIPP)
{

    // Create a query to get the current value of DUREE_VIE
    QSqlQuery query;
    //arduino A;

    query.prepare("SELECT DUREE_VIE FROM EQUIPPEMENTS where ID_EQU=:ID_EQUIPP");
    query.bindValue(":ID_EQUIPP", ID_EQUIPP);
    if (!query.exec()) {
        qDebug() << "Error: Could not execute query";
        qDebug() << query.lastError().text();
       return 0;
    }

    // Check if DUREE_VIE has changed from 1 to 0
    if (query.next()) {
        int dureeVie = query.value(0).toInt();
        if (dureeVie == 0) {
            return 1;
         //   QMessageBox() << "That was the last one";
//QMessageBox::information(nullptr, QObject::tr("Warning"), QObject::tr("That was the last one"));
        }

    }
    return -1;
}






void Equipements::checkOutOfStockEquipments() {/*
    qDebug() << "Checking for out-of-stock equipment...";

    // prepare query to find out-of-stock equipment
    QSqlQueryModel *modelll = new QSqlQueryModel(this);
    modelll->setQuery("SELECT * FROM EQUIPPEMENTS WHERE DUREE_VIE = 0");

    // set the model for the table view
    ui->tableView->setModel(modelll);

    // check if there are any rows in the result
    if (modelll->rowCount() == 0) {
        ui->etatlabel->setText("All equipment is in stock");
    } else {
        ui->etatlabel->setText("Out of stock equipment:");
    }*/
}








