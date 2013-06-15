#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include <client.h>
#include <datadialog.h>
#include <QFile>
#include <QMessageBox>
#include <newfiledialog.h>
#include <QSound>


namespace Ui {
class LogInWindow;
}

class LogInWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LogInWindow(Client* pClient, QWidget *parent = 0);

    ~LogInWindow();

    void setUser(QString pUser);
    
private slots:

    void on_actionGet_File_triggered();

    void on_actionCreate_File_triggered();

    void on_actionCreate_Folder_triggered();

    void on_actionDelete_File_triggered();

    void on_actionDelete_Folder_triggered();

    void on_actionOpen_File_triggered();

    void on_actionLog_Out_triggered();

    void on_actionAbout_triggered();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_modifyButton_clicked();

    void on_seekButton_clicked();

    void on_actionProtocol_triggered();

    void on_readButton_clicked();

private:
    Ui::LogInWindow *ui;
    DataDialog* _dialogW;
    Client* _client;
    NewFileDialog* _newfiledialog;
};

#endif // LOGINWINDOW_H
