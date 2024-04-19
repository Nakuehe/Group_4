#include "classdialog.h"
#include "ui_classdialog.h"

ClassDialog::ClassDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClassDialog)
{
    ui->setupUi(this);
}

ClassDialog::~ClassDialog()
{
    delete ui;
}

QString ClassDialog::getClassName()
{
   return ui->lineEdit()->text();
}
