#include "staffsideview.h"
#include "ui_staffsideview.h"

StaffSideView::StaffSideView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StaffSideView)
{
    ui->setupUi(this);
}

StaffSideView::~StaffSideView()
{
    delete ui;
}
