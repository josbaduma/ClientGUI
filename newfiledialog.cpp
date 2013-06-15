#include "newfiledialog.h"
#include "ui_newfiledialog.h"

NewFileDialog::NewFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFileDialog)
{
    ui->setupUi(this);
}

NewFileDialog::~NewFileDialog()
{
    delete ui;
}

QString NewFileDialog::getFilePathAndFormat()
{
    return this->ui->directoryLine->text() + ":-f:" +
            this->ui->formatLine->text();
}
