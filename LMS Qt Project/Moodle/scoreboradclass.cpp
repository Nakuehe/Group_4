#include "scoreboradclass.h"
#include "ui_scoreboradclass.h"

ScoreboradClass::ScoreboradClass(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScoreboradClass)
{
    ui->setupUi(this);
}

ScoreboradClass::~ScoreboradClass()
{
    delete ui;
}
