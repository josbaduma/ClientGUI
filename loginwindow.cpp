#include "loginwindow.h"
#include "ui_loginwindow.h"

LogInWindow::LogInWindow(Client *pClient, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogInWindow)
{
    ui->setupUi(this);
    this->_client = pClient;
    this->setWindowTitle("RaidB");
}

LogInWindow::~LogInWindow()
{
    delete ui;
}


void LogInWindow::on_actionGet_File_triggered()
{
    this->_dialogW = new DataDialog(this);
    this->_dialogW->exec();
    QString answer, message = "get " + this->_dialogW->getMessage();
    qDebug() << message;
    answer = this->_client->writeToServer(message);
    QFile file("file.csv");
    file.write(answer.toAscii());
    file.close();
    this->_dialogW->deleteLater();
}

void LogInWindow::on_actionCreate_File_triggered()
{
    this->_newfiledialog = new NewFileDialog(this);
    this->_newfiledialog->exec();
    QString message = "touch " + this->_newfiledialog->getFilePathAndFormat();
    qDebug() << message;
    this->_client->writeToServer(message);
    this->_newfiledialog->deleteLater();
}

void LogInWindow::on_actionCreate_Folder_triggered()
{
    this->_dialogW = new DataDialog(this);
    this->_dialogW->setWindowTitle("Create Folder...");
    this->_dialogW->exec();
    QString message = "mkdir " + this->_dialogW->getMessage();
    qDebug() << message;
    this->_client->writeToServer(message);
    this->_dialogW->deleteLater();
}

void LogInWindow::on_actionDelete_File_triggered()
{
    this->_dialogW = new DataDialog(this);
    this->_dialogW->setWindowTitle("Delete File...");
    this->_dialogW->exec();
    QString message = "rm " + this->_dialogW->getMessage();
    qDebug() << message;
    this->_client->writeToServer(message);
    this->_dialogW->deleteLater();
}

void LogInWindow::on_actionDelete_Folder_triggered()
{
    this->_dialogW = new DataDialog(this);
    this->_dialogW->setWindowTitle("Delete Folder...");
    this->_dialogW->exec();
    QString message = "rm " + this->_dialogW->getMessage();
    qDebug() << message;
    this->_client->writeToServer(message);
    this->_dialogW->deleteLater();
}

void LogInWindow::on_actionOpen_File_triggered()
{
    this->_dialogW = new DataDialog(this);
    this->_dialogW->setWindowTitle("Open file...");
    this->_dialogW->exec();
    QString message = "openfile " + this->_dialogW->getMessage();
    qDebug() << message;
    this->_client->writeToServer(message);
    this->_dialogW->deleteLater();

    //Funcion para recuperar en este formato
    QString answer = "jose;daniel;20\ndaniel;araya;19";
    QStringList listData, listAnswer = answer.split("\n");

    this->ui->tableFile->setRowCount(listAnswer.size());
    for (int row = 0; row < listAnswer.size(); ++row) {
        listData = listAnswer[row].split(";");
        this->ui->tableFile->setColumnCount(listData.size());

        for (int column = 0; column < listData.size(); ++column) {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(listData[column]);
            this->ui->tableFile->setItem(row, column,item);
            qDebug() << "Entro Data: " << listData[column];
        }
    }
}

void LogInWindow::on_actionLog_Out_triggered()
{
    this->_client->writeToServer("close");
    qDebug() << "close";
    this->parentWidget()->show();
    this->hide();
}

void LogInWindow::on_actionAbout_triggered()
{
    QMessageBox boxmessage;
    boxmessage.about(this,"About RaidB", "Made by:\n\nBrallan Aguilar\nJose Daniel Badilla\nDaniel Araya\nHowar Blandon");
    boxmessage.exec();
    boxmessage.deleteLater();
}

void LogInWindow::on_addButton_clicked()
{
    QString message = "appendReg " + this->ui->numRegistryLine->text() + ":"
            + this->ui->registryLine->text();
    qDebug() << message;
    this->_client->writeToServer(message);
}

void LogInWindow::on_removeButton_clicked()
{
    QString message = "delReg " + this->ui->numRegistryLine->text();
    qDebug() << message;
    this->_client->writeToServer(message);
}

void LogInWindow::on_modifyButton_clicked()
{
    QString message = "write "+ this->ui->registryLine->text() +
            ":" + this->ui->numRegistryLine->text() ;
    qDebug() << message;
    this->_client->writeToServer(message);
}

void LogInWindow::on_seekButton_clicked()
{
    QString message = "seek " + this->ui->numRegistryLine->text() ;
    qDebug() << message;
    this->_client->writeToServer(message);
}

void LogInWindow::on_readButton_clicked()
{
    QString answer, message = "read " + this->ui->numRegistryLine->text() ;
    qDebug() << message;
    answer = this->_client->writeToServer(message);
    this->ui->registryLine->setText(answer);
}

void LogInWindow::setUser(QString pUser)
{
    this->ui->userLabel->setText(pUser);
}

void LogInWindow::on_actionProtocol_triggered()
{
    QDesktopServices::openUrl(QUrl("file:////home/jose/QtCreator/apcomptec-RAIDB/doc/ProtocoloV1.0.pdf"));
}

