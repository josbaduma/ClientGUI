#include "datadialog.h"
#include "ui_datadialog.h"

DataDialog::DataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataDialog)
{
    ui->setupUi(this);
}

DataDialog::~DataDialog()
{
    delete ui;
}

QString DataDialog::getMessage()
{
    return this->ui->lineEdit->text();
}
