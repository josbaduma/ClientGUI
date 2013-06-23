#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>

class QTcpSocket;

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    void connectToServer(QString pIP, int pPort);

signals:

public slots:
    QString writeToServer(QString pMessage);
    QString recibeMessage();

private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
