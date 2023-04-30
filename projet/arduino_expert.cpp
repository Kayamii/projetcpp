#include "arduino_expert.h"

arduino_test::arduino_test()
{
       data="";
       arduino_port_name="";
       arduino_is_available=false;
       serial=new QSerialPort;
}

QString arduino_test::getarduino_port_name()
{
    return arduino_port_name;
}


QSerialPort *arduino_test::getserial()
{
   return serial;
}
int arduino_test::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}


int arduino_test::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;

}


/*QByteArray arduino_test::read_from_arduino()
{
    QByteArray data;
    if (serial->waitForReadyRead(100)) {
        data = serial->read(8); // lire numBytes octets
    }
    QList<QByteArray> lines = data.split('\n');
    for (int i = 0; i < lines.size(); i++) {
        QByteArray line = lines[i].trimmed(); // supprimer les espaces de début et de fin
        line = line.replace("\r", ""); // supprimer le caractère de retour chariot
        if (line.isEmpty()) {
            // supprimer les lignes vides
            lines.removeAt(i);
            i--;
        }
        else {
            lines[i] = line;
        }
    }
    data = lines.join("");
    return data;
}*/

QByteArray arduino_test::read_from_arduino()
{
   if(serial->isReadable()){
        data=serial->readAll();

        return data;
   }
}


int arduino_test::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }

}
