#ifndef DATADIALOG_H
#define DATADIALOG_H

#include <QDialog>

namespace Ui {
class DataDialog;
}

class DataDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DataDialog(QWidget *parent = 0);
    ~DataDialog();
    QString getMessage();
    
private:
    Ui::DataDialog *ui;
};

#endif // DATADIALOG_H
