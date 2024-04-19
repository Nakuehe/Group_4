#include "dialogclass.h"
#include "ui_dialogclass.h"

QString DialogClass::getClassName()
{
    return ui->lineEdit->text();
}

void DialogClass::announcement()
{
    QMessageBox::warning(this,"Error", "Invalid format. Class name should contain letters or numbers only.");
}

void DialogClass::announcement2(QString tempClass)
{
    QMessageBox::warning(this, "Error", "Class '" + tempClass + "' already exists.");
}

DialogClass::DialogClass(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogClass)
{
    ui->setupUi(this);
}

DialogClass::~DialogClass()
{
    delete ui;
}
