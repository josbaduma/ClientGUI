#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
}

QString Client::writeToServer(QString pMessage)
{
    socket->write(pMessage.toAscii());
    socket->waitForBytesWritten();
    socket->waitForReadyRead();
    QString message = socket->readAll();
    qDebug() << message;
    return message;
}

void Client::connectToServer(QString pIP, int pPort)
{
    QHostAddress address(pIP);
    socket->connectToHost(address, pPort);
}
