#include "connectionclass.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("nouvadhd");
db.setUserName("mohamed");//inserer nom de l'utilisateur
db.setPassword("mohamed");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}


