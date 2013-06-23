#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
}

QString Client::writeToServer(QString pMessage)
{
    socket->write(pMessage.toAscii());

    return this->recibeMessage();
}

void Client::connectToServer(QString pIP, int pPort)
{
    QHostAddress address(pIP);
    socket->connectToHost(address, pPort);
}

QString Client::recibeMessage()
{
    socket->waitForBytesWritten();
    socket->waitForReadyRead();
    QString message = socket->readAll();
    qDebug() << message;
    return message;
}
