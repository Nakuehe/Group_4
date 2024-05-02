#include "dialogclass.h"
#include "ui_dialogclass.h"
#include "fontloader.h"

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
    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QFont font(fontFamily1, 14);

    ui ->label ->setFont(font);
    ui->lineEdit->setFont(font);
}

DialogClass::~DialogClass()
{
    delete ui;
}
