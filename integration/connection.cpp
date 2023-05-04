#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{bool test=false;
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("test-bd");
        db.setUserName("maguko");//inserer nom de l'utilisateur
        db.setPassword("maguko");//inserer mot de passe de cet utilisateur

        if (db.open())
        test=true;





            return  test;
}
