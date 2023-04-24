#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("testDB");
db.setUserName("Emna");//inserer nom de l'utilisateur
db.setPassword("esprit2A18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
