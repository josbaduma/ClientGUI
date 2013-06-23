#ifndef CLIENTMAIN_H
#define CLIENTMAIN_H

#include <QMainWindow>
#include <loginwindow.h>
#include <client.h>
#include <QNetworkInterface>
#include <QtCore>
#include <QtGui>
#include <datadialog.h>
#include <util/Encryption.h>
#include <util/Converter.h>

namespace Ui {
class ClientMain;
}

class ClientMain : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ClientMain(QWidget *parent = 0);
    ~ClientMain();
    
private slots:
    void on_signInButton_clicked();

    void on_logInButton_clicked();

    void on_actionExit_triggered();

    void on_actionConnect_to_Server_triggered();

    void on_actionAbout_triggered();

private:
    LogInWindow* _userWindows;
    DataDialog* _dialogWind;
    Ui::ClientMain *ui;
    Client* _client;
    QString _ip;
    int _port;
    Encryption *encryption;


};

#endif // CLIENTMAIN_H
