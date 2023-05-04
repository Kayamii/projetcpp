#include "seance.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include "mainwindow.h"

Seance::Seance()
{
id_seance = 0;
id_exp = 0;
id_equi = 0;
typee = "";
duree = "";
datee = "";
heure = "";
}

Seance::Seance(int id_exp, int id_equi, QString typee, QString duree, QString datee, QString heure)
{
this->id_seance = 0; // This should be initialized to 0 or assigned a value.
this->id_exp = id_exp;
this->id_equi = id_equi;
this->typee = typee;
this->duree = duree;
this->datee = datee;
this->heure = heure;
}
Seance::~Seance()
{}
int Seance::getid_seance() { return id_seance; }
int Seance::getid_exp() { return id_exp; }
int Seance::getid_equi() { return id_equi; }
QString Seance::gettype() { return typee; }
QString Seance::getduree() { return duree; }
QString Seance::getdate() { return datee; }
QString Seance::getheure() { return heure; }

void Seance::setid_seance(int id_seance) { this->id_seance = id_seance; }
void Seance::setid_exp(int id_exp) { this->id_exp = id_exp; }
void Seance::setid_equi(int id_equi) { this->id_equi = id_equi; }
void Seance::settype(QString type) { this->typee = type; }
void Seance::setduree(QString duree) { this->duree = duree; }
void Seance::setdate(QString date) { this->datee = date; }
void Seance::setheure(QString heure) { this->heure = heure; }
bool Seance::ajouter()
{

    QSqlQuery query;

    QString id_s = QString::number(id_seance);
    QString id_ex = QString::number(id_exp);
    QString id_equii= QString::number(id_equi);


query.prepare("INSERT INTO SEANCES (id_exp, typee, duree, datee,id_equi,heure) VALUES (:id_exp, :type, :duree, :date, :id_equi, :heure)");



    query.bindValue(":id_exp", id_ex);
    query.bindValue(":duree", duree);
    query.bindValue(":date", datee);
    query.bindValue(":type", typee);
    query.bindValue(":heure", heure);
    query.bindValue(":id_equi", id_equii);

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
model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_EQ"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("HEURE"));

return model;


}
bool Seance::modifier(int id)
{
    QSqlQuery query;
    QString ids = QString::number(id);
    QString idexp = QString::number(id_exp);
    QString id_equis = QString::number(id_equi);
    query.prepare("UPDATE SEANCES SET ID_SEANCE=:id, ID_EXP=:id_exp, DUREE=:duree, DATEE=:datee, TYPEE=:typee, ID_EQUI=:id_equi, heure=:heure WHERE ID_SEANCE=:id");
    //query.prepare("UPDATE SEANCES SET ID_SEANCE=:id, ID_EXPERT=:idexp, DUREE=:duree, DATEE=:datee, TYPEE=:typee, ID_EQUI=:id_equi, heure=:heure WHERE ID_SEANCE=:id");
    query.bindValue(":id", ids);
    query.bindValue(":id_exp",idexp);


    query.bindValue(":id_equi", id_equis);
    query.bindValue(":duree", duree);
    query.bindValue(":datee", datee);
    query.bindValue(":typee", typee);
    query.bindValue(":heure", heure);
    return query.exec();
}

bool Seance::verifier(int id)
{QSqlQuery query2;

   query2.prepare("select id_seance from seances where id_seance=:id");

   query2.bindValue(":id",id);
   return (query2.exec()) && (query2.next());



}
QSqlQueryModel * Seance::trier()
{QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM seances ORDER BY datee, heure ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SEANCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_EXP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DUREE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_EQ"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("HEURE"));

    return model;
}
QSqlQueryModel * Seance::rechercher(QString r)
{QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM seances WHERE id_seance LIKE '%" + r + "%' OR typee LIKE '%" + r + "%'OR id_exp LIKE '%" + r + "%'   ");



    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SEANCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_EXP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DUREE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_EQ"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("HEURE"));
return model;


}
bool Seance::pdf()
       {
           QPdfWriter pdf("C:/Users/mega pc/Desktop/pdf.pdf");
           QPainter painter(&pdf);
          int i = 4000;


               painter.setPen(Qt::darkBlue);
               painter.setFont(QFont("euphemia", 40));
               painter.drawText(1100,1200,"Liste Des seances");
               painter.setPen(Qt::black);
               painter.setFont(QFont("calibri", 20));
               painter.drawRect(100,100,7300,2600);
               painter.drawRect(0,3000,9600,500);
               painter.setFont(QFont("consolas", 9));
               painter.drawText(200,3300,"ID_seance");
               painter.drawText(1300,3300,"ID_Expert");
               painter.drawText(2400,3300,"duree");
               painter.drawText(3500,3300,"date");
               painter.drawText(4600,3300,"type");
                 painter.drawText(5700,3300,"heure");


               QSqlQuery query;
               query.prepare("select * from seances");
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
QChartView * Seance::stats()
{
    int row_count = 0;
    int row_count1 = 0;

    QSqlQuery query,query2;

    query.prepare("SELECT typee FROM seances WHERE typee='consultation' ");
    query.exec();

    query2.prepare("SELECT typee FROM seances WHERE typee='sport'");
    query2.exec();

    while(query2.next())
        row_count1++;

    while(query.next())
        row_count++;

    qDebug() << "row1=" << row_count << row_count1;

    QPieSeries *series = new QPieSeries();

    qreal total = row_count + row_count1;
    qreal sport_percent = (row_count1 / total) * 100;
   // qreal consultation_percent = (row_count / total) * 100;

    QString sport_label = QString("sport (%1%)").arg(sport_percent, 0, 'f', 1);
    QString consultation_label = QString("consultation");

    QPieSlice *sport_slice = series->append(sport_label, row_count1);
    sport_slice->setBrush(QColor("#90EE90")); // light green

    QPieSlice *consultation_slice = series->append(consultation_label, row_count);
    consultation_slice->setBrush(QColor("green"));

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique selon le type :");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setBackgroundVisible(true);
    chart->legend()->setBrush(QBrush(QColor(128, 128, 128, 128)));
    chart->legend()->setPen(QPen(QColor(192, 192, 192, 192)));
    series->setLabelsVisible();
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

    for (QPieSlice *slice : series->slices()) {
        qreal percentage = (slice->value() / total) * 100;
        if(slice->label() == consultation_label) {
            QString label = QString("%1 (%2%)").arg(slice->label()).arg(percentage, 0, 'f', 1);
            slice->setLabel(label);
        } else {
            QString label = QString("%1").arg(slice->label());
            slice->setLabel(label);
        }
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;

}

int Seance::getLastInsertedId()
{
    QSqlQuery query;
    query.exec("SELECT LAST_INSERT_ROWID()");

    if (query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}


