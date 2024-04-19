#include "updateStudentResult.h"
#include "ui_updateStudentResult.h"
#include "LinkedList.h"
//#include "Score.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QScrollBar>
#include <QTimer>
#include <QDebug>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QPainterPath>
#include <QFont>
#include <QString>
#include <string>
#include "fontloader.h"

updateStudentResult::updateStudentResult(QWidget *parent, Course* thisCourse)
    : QDialog(parent)
    , thisCourse(thisCourse)
    , ui(new Ui::updateStudentResult)
{
    ui->setupUi(this);
    // Set fixed size
    this->setFixedSize(this->size());
    this->setWindowIcon(QIcon(":/Asset/loginpageAsset/logo.png"));
    this->setWindowTitle("Update");

    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QFont font(fontFamily1, 14);



    QWidget *darkenWidget = new QWidget(parent);
    darkenWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.7);");
    darkenWidget->resize(parent->size());
    darkenWidget->show();

    ui->comboBox_idstudent->setFont(font);
    ui->lineEdit_final->setFont(font);
    ui->lineEdit_mid->setFont(font);
    ui->lineEdit_other->setFont(font);

    connect(this, &updateStudentResult::shown, darkenWidget, &QWidget::show);
    connect(this, &updateStudentResult::hidden, darkenWidget, &QWidget::hide);

    for (int i = 0; i < thisCourse->Scoreboard.size(); i++) {
        Score& record = thisCourse->Scoreboard.get(i);
        QString studentInfo = QString::fromStdString(record.id_student + " - " + record.fullName);
        ui->comboBox_idstudent->addItem(studentInfo, QString::fromStdString(record.id_student));
    }


}


void updateStudentResult::showEvent(QShowEvent *event) {
    emit shown();
    QDialog::showEvent(event);
}

void updateStudentResult::hideEvent(QHideEvent *event) {
    emit hidden();
    QDialog::hideEvent(event);
}

updateStudentResult::~updateStudentResult()
{
    delete ui;
}


void updateStudentResult::on_pushButton_Search_clicked()
{
    QString ID = ui->comboBox_idstudent->currentText().left(8);



    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(5);
    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");
    std::string id_student = ID.toStdString();
    Node<Score>* temp = thisCourse->Scoreboard.getHead();
    while(temp != nullptr)
    {
        if(id_student == temp->data.id_student)
            break;
        temp = temp->next;
    }
    if(temp == nullptr)
    {
        QMessageBox::warning(this, "Error", "student is not in course");
    }
    else
    {
        Node<Score>* it = thisCourse->Scoreboard.getHead();
        while(it != nullptr)
        {
            if(it->data.id_student == temp->data.id_student)
                break;
            it = it->next;
        }

        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::fromStdString(temp->data.id_student)));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::fromStdString(temp->data.fullName)));
        if(it == nullptr)
        {
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString("")));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString("")));
            ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString("")));
        }
        else
        {
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(it->data.mid_mark,'f',2)));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(it->data.final_mark,'f',2)));
            ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(it->data.other_mark,'f',2)));
        }

        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "midterm"<<"final"<<"other");
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 12pt; font-weight: bold; }");

        ui->tableWidget->setFont(QFont(fontFamilyRegular, 12));
        resizeColumns();
    }

}


void updateStudentResult::on_pushButton_Accept_clicked()
{
    QString ID = ui->comboBox_idstudent->currentText().left(8);
    std::string id_student = ID.toStdString();
    QString mid_mark = ui->lineEdit_mid->text();
    QString final_mark = ui->lineEdit_final->text();
    QString other_mark = ui->lineEdit_other->text();
    if(mid_mark == QString("") || final_mark == QString("") || other_mark == QString(""))
    {
        QMessageBox::warning(this, "Error", "Please fill all column update");
        return;
    }
    Node<Score>* it = thisCourse->Scoreboard.getHead();
    // qDebug() << "ID: " << ID << '\n';

    while(it != nullptr)
    {
        // qDebug() << it->data.id_student << '\n';
        if(it->data.id_student == id_student)
            break;
        it = it->next;
    }

    if(it == nullptr){
        QMessageBox::warning(this, "Error", "Please choose exist student");
        return;
    }

    it->data.mid_mark = mid_mark.toFloat();
    it->data.final_mark = final_mark.toFloat();
    it->data.other_mark = other_mark.toFloat();
    it->data.total_mark = it->data.mid_mark*0.25 + it->data.final_mark*0.4 + it->data.other_mark*0.35;
    ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(it->data.mid_mark,'f',2)));// check update
    ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(it->data.final_mark,'f',2)));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(it->data.other_mark,'f',2)));
    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");
    ui->tableWidget->setFont(QFont(fontFamilyRegular, 12));
    resizeColumns();
}
void updateStudentResult::resizeColumns() {
    ui->tableWidget->resizeColumnsToContents();

    bool isScrollBarVisible = ui->tableWidget->verticalScrollBar()->isVisible();

    // Calculate the total content width
    int totalContentWidth = 0;
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
        totalContentWidth += ui->tableWidget->columnWidth(i);
    }

    // Calculate total width without tab
    int totalAvailableWidth = this->width() - 2 * ui->tableWidget->frameWidth();

    int usedWidth = 0;

    // Set the width of each column
    int i;
    for (i = 0; i < ui->tableWidget->columnCount() - 1; ++i) {
        int stretchFactor = ui->tableWidget->columnWidth(i) * 100 / totalContentWidth;
        int newWidth = stretchFactor * totalAvailableWidth / 100;
        ui->tableWidget->setColumnWidth(i, newWidth);
        usedWidth += newWidth;
    }

    // Calculate remaining space
    int remainingSpace = totalAvailableWidth - usedWidth;

    // If scrollbar is visible, adjust the remaining space
    if (isScrollBarVisible)
        remainingSpace -= (ui->tableWidget->verticalScrollBar()->width());

    // Set the width of the last column based on the remaining space
    ui->tableWidget->setColumnWidth(i, remainingSpace);
}
void updateStudentResult::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    resizeColumns();
}

