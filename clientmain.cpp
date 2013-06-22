#include "clientmain.h"
#include "ui_clientmain.h"

ClientMain::ClientMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientMain)
{
    ui->setupUi(this);
    this->encryption = new Encryption();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    this->_client = new Client();
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
            this->_ip = address.toString();
    }
    qDebug() << this->_ip;
    QMovie* movie = new QMovie(":/lunapic_13545596828390_1.gif");
    movie->setScaledSize(this->ui->label->size());
    this->ui->label->setMovie(movie);
    movie->start();
}

ClientMain::~ClientMain()
{
    delete ui;
}

void ClientMain::on_signInButton_clicked()
{
    QString user = this->ui->userLineEdit->text();
    QString password = Converter::fromStringToQString(
                encryption->passwordEncryption(this->ui->passwordlineEdit->text().toStdString()));
    QString message = "adduser " + this->_ip + ":" + QString::number(this->_port)
            + ":" + user + ":" + password + ":" + this->ui->diskIdLineEdit->text();

    this->ui->userLineEdit->setText("");
    this->ui->passwordlineEdit->setText("");
    this->ui->diskIdLineEdit->setText("");

    if(this->_client->writeToServer(message) == "true")
    {
        qDebug() << "Usuario registrado";
    }else{
        qDebug() << "Verifique los datos";
    }
}

void ClientMain::on_logInButton_clicked()
{
    QString user = this->ui->userLineEdit->text();
    QString password = Converter::fromStringToQString(
                encryption->passwordEncryption(this->ui->passwordlineEdit->text().toStdString()));
    QString message = "connect " + this->_ip + ":" + QString::number(this->_port)
            + ":" + user + ":" + password + ":" + this->ui->diskIdLineEdit->text();

    this->ui->userLineEdit->setText("");
    this->ui->passwordlineEdit->setText("");
    this->ui->diskIdLineEdit->setText("");

    if(this->_client->writeToServer(message) == "true\n")
    {
        this->_userWindows = new LogInWindow(this->_client,this);
        this->_userWindows->setUser("User: " + user);
        this->_userWindows->show();
        this->hide();
        qDebug() << "Usuario ingreso";
    }else{
        qDebug() << "Verifique los datos";
    }
}

void ClientMain::on_actionExit_triggered()
{
    QMessageBox box;
    box.about(this,"Alert", "Good Bye");
    exit(0);
}

void ClientMain::on_actionConnect_to_Server_triggered()
{
    this->_dialogWind = new DataDialog(this);
    this->_dialogWind->exec();
    this->_port = this->_dialogWind->getMessage().toInt();
    this->_client->connectToServer("192.168.1.2", this->_port);
    this->_dialogWind->deleteLater();
}

void ClientMain::on_actionAbout_triggered()
{
    QMessageBox boxmessage;
    boxmessage.about(this,"About RaidB", "Made by:\n\nBrallan Aguilar\nJose Daniel Badilla\nDaniel Araya\nHowar Blandon");
    boxmessage.exec();
    boxmessage.deleteLater();
}
