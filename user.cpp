#include "user.h"
#include "QSqlQuery"
#include "QDebug"
#include <QObject>
#include <QMessageBox>
#include <QAxObject>
#include <QPdfWriter>
#include <QtCore>
#include <QtGui>
#include <QtSql>
#include <QFileDialog>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QSqlQuery>
#include "verification.h"
#include <string>

#include <iostream>
#include <cstdlib> // pour la fonction rand
#include <ctime> // pour initialiser le générateur de nombres aléatoires

User::User()
{
id=0;
nom="";
prenom="";
cin="";
email="";
role="";
mdp="";
}




User::User(int id,QString nom,QString prenom,QString cin,QString email,QString role,QString mdp)
{this->id=id;this->nom=nom;this->prenom=prenom; this->cin=cin;this->email=email;this->role=role;this->mdp=mdp;}
int User::getid(){return id;}
QString User::getnom(){return nom;}
QString User::getprenom(){return prenom;}
QString User::getcin(){return cin;}
QString User::getemail(){return email;}
QString User::getrole(){return role;}
QString User::getmdp(){return mdp;}
void User::setid(int id){this->id=id;}
void User::setnom(QString nom){this->nom=nom;}
void User::setprenom(QString prenom){this->prenom=prenom;}
void User::setcin(QString cin){this->cin=cin;}
void User::setemail(QString email){this->email=email;}
void User::setrole(QString role){this->role=role;}
void User::setmdp(QString mdp){this->mdp=mdp;}





bool User::ajouter(){


    QSqlQuery query;
    QString id_string=QString::number(id);
          query.prepare("INSERT INTO ADMINS (id, nom, prenom,cin,email,role,mdp) "
                        "VALUES (:id, :nom, :prenom, :cin, :email, :role, :mdp)");
          query.bindValue(0,id_string );
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, cin);
          query.bindValue(4, email);
          query.bindValue(5, role);
          query.bindValue(6, mdp);

          return query.exec();
}




QSqlQueryModel* User::afficher()
{
 QSqlQueryModel *model = new QSqlQueryModel;
 model->setQuery("SELECT * FROM ADMINS");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
return model;


}






bool User::supprimer(int id)
{
 QSqlQuery query;
 query.prepare("Delete from ADMINS where id=:id ");
 query.bindValue(0,id );
 return query.exec();

}

bool User::modifier(int id)
{

    QSqlQuery query;
    //QString id_string=QString::number(id);

    //

   query.prepare("UPDATE ADMINS SET nom=:nom,prenom=:prenom,cin=:cin,email=:email,role=:role,mdp=:mdp WHERE id=:id");

    //
   query.bindValue(6,id);
   query.bindValue(0, nom);
   query.bindValue(1, prenom);
   query.bindValue(2, cin);
   query.bindValue(3, email);
   query.bindValue(4, role);
   query.bindValue(5, mdp);


    return query.exec();
}
bool User::recherche(int a){
QSqlQuery query;
QString id1=QString::number(a);
query.prepare("select * from ADMINS where id=:id ");
query.bindValue(":id",id1);
query.exec();
    if (query.next()) {
        int compter= query.value(0).toInt();
        return (compter >0); // Utilisateur trouvé
    } else {
        return false; // Utilisateur non trouvé
    }
}


QSqlQueryModel * User::afficher_search_result(QString ch)
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from ADMINS where id LIKE '%"+ch+"%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
return model;
}


QSqlQueryModel * User::afficher_id_decroissant()
{
  QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from ADMINS order by id DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
return model;

}
QSqlQueryModel * User::afficher_id_croissant()
{
  QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from ADMINS order by id ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("mdp"));
return model;

}

bool User::comparerEmailMotDePasse(const QString& email, const QString& motDePasse) {
     QSqlQuery query;
     query.prepare("SELECT email FROM ADMINS WHERE email = ? AND mdp = ?"); // Remplacez "utilisateurs" par le nom de votre propre table d'utilisateurs
         query.bindValue(0, email);
         query.bindValue(1, motDePasse);


        if (!query.exec()) {
                 qWarning() << "Erreur lors de l'exécution de la requête SQL:"/* << query.lastError().text()*/;
                 return false;
             }

             // Vérifier si la requête a renvoyé un résultat
             if (query.next()) {
                 qDebug() << "Email et mot de passe valides.";
                 QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("Email et mot de passe valides.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 return true;
             } else {
                 qDebug() << "Email ou mot de passe invalides.";
                 QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("Email ou mot de passe invalides..\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 return false;
             }


}



QString User::envoyer_mail(QString destination) {
     qDebug() << "test test";
     QAxObject* outlook = new QAxObject("Outlook.Application");
     QSqlQuery query;
     QString mdp;
     query.prepare("SELECT mdp FROM ADMINS WHERE email =:x ");

     query.bindValue(":x", destination);
     query.exec();

     while (query.next())
          {
             mdp = query.value(0).toString();
         }
     std::srand(std::time(0));
     int nombreAleatoire = std::rand() % 900 + 100;
     QString monQString = QString::number(nombreAleatoire);


     if (!outlook->isNull()) {
         QAxObject* mail = outlook->querySubObject("CreateItem(int)", 0);
         mail->setProperty("To", destination);
         mail->setProperty("Subject", "mot de passe oublier");
         mail->setProperty("Body", "Bonjour M./Mme. "",\n\nVoici votre code de verification :\n"+monQString+"\n");
         mail->dynamicCall("Send()");
     }


    return monQString;

 }


void User::generate_pdf()
  {

    QPdfWriter pdf("C:/Users/LEGION/Desktop/before fucj/seance equippements/exoprt.pdf");
      QPainter painter(&pdf);
      int i = 4000;
      painter.setPen(Qt::red);
      // Détermine la taille maximale de police pour que le texte rentre dans la page
      int fontSize = 35;
      while (painter.fontMetrics().width("GESTION Admins") > pdf.width())
      {
          fontSize--;
          painter.setFont(QFont("Arial", fontSize));
      }
      painter.setFont(QFont("Arial", fontSize));
      painter.drawText(1100,1200,"GESTION Admins");
      painter.setPen(Qt::black);
      painter.setFont(QFont("Arial",12));
      painter.drawRect(1000,100,7300,2600);
      painter.drawRect(50,3000,9600,500);
      painter.setFont(QFont("Arial",11));
      painter.drawText(90,3300,"id");
      painter.drawText(1000,3300,"nom");
      painter.drawText(2390,3300,"prenom");
      painter.drawText(3590,3300,"cin");
      painter.drawText(5290,3300,"email");
      painter.drawText(6790,3300,"role");
      painter.drawText(8490,3300,"mdp");
      QSqlQuery query;
      query.prepare("SELECT * FROM ADMINS");
      query.exec();
      while (query.next())
      {
                painter.drawText(100,i,query.value(0).toString());
                painter.drawText(550,i,query.value(1).toString());
                painter.drawText(2400,i,query.value(2).toString());
                painter.drawText(3600,i,query.value(3).toString());
                painter.drawText(5300,i,query.value(4).toString());
                painter.drawText(6800,i,query.value(5).toString());
                painter.drawText(8500,i,query.value(6).toString());

                // Détermine la taille maximale de police pour que le texte rentre dans la page
                fontSize = 11;
                while (painter.fontMetrics().width(query.value(6).toString()) > pdf.width() - 7700) {
                    fontSize--;
                    painter.setFont(QFont("Arial", fontSize));
                }

                painter.setFont(QFont("Arial", fontSize));
                i = i + 500;
            }
        }



bool User::comparerEmail(const QString& email) {
     QSqlQuery query;
     query.prepare("SELECT email FROM ADMINS WHERE email = ?"); // Remplacez "utilisateurs" par le nom de votre propre table d'utilisateurs
         query.bindValue(0, email);



        if (!query.exec()) {
                 qWarning() << "Erreur lors de l'exécution de la requête SQL:"/* << query.lastError().text()*/;
                 return false;
             }

             // Vérifier si la requête a renvoyé un résultat
             if (query.next()) {
                 qDebug() << "Email valides.";
                 QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("Email\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 return true;
             } else {
                 qDebug() << "Email invalides.";
                 QMessageBox::information(nullptr, QObject::tr("Add"),
                             QObject::tr("Email invalides..\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                 return false;
             }


}


QString User::chercherRole(QString email, QString motDePasse) {
    QSqlQuery query;
    query.prepare("SELECT role FROM ADMINS WHERE email = :email AND mdp = :motDePasse");
    query.bindValue(":email", email);
    query.bindValue(":motDePasse", motDePasse);
    if (query.exec() && query.next()) {
        return query.value("role").toString();
    }
    else {
        return "";
    }
}


