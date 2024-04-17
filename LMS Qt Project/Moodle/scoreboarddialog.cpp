#include "scoreboarddialog.h"
#include "ui_scoreboarddialog.h"

ScoreBoardDialog::ScoreBoardDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScoreBoardDialog)
{
    ui->setupUi(this);
}

ScoreBoardDialog::~ScoreBoardDialog()
{
    delete ui;
}
