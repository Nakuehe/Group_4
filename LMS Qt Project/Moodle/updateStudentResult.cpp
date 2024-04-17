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

updateStudentResult::updateStudentResult(QWidget *parent, Course* thisCourse)
    : QDialog(parent)
    , thisCourse(thisCourse)
    , ui(new Ui::updateStudentResult)
{
    ui->setupUi(this);
    // Set fixed size
    this->setFixedSize(this->size());

    QWidget *darkenWidget = new QWidget(parent);
    darkenWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.7);");
    darkenWidget->resize(parent->size());
    darkenWidget->show();

    connect(this, &ScoreboardDialog::shown, darkenWidget, &QWidget::show);
    connect(this, &ScoreboardDialog::hidden, darkenWidget, &QWidget::hide);
    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");


}


void updateStudentResult::showEvent(QShowEvent *event) {
    emit shown();
    QDialog::showEvent(event);
}

void updateStudentResult::hideEvent(QHideEvent *event) {
    emit hidden();
    QDialog::hideEvent(event);
}

QString updateStudentResult::loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

updateStudentResult::~updateStudentResult()
{
    delete ui;
}


void updateStudentResult::on_pushButton_Search_clicked()
{
    QString ID = ui->lineEdit_idStudent->text();
    ui->tableWidget->clear();
    string id_student = ID.toStdString();
    Node<Student>* temp = thisCourse->students.getHead();
    while(temp != nullptr)
    {
        if(id_student == temp->data.studentID)
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
            if(it->data.id_student == temp->data.studentID)
                break;
            it = it->next;
        }

        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString(temp->data.studentID)));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString(temp->data.getStudentFullName())));
        if(it == nullptr)
        {
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString("")));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString("")));
            ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString("")));
        }
        else
        {
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString(it->data.mid_mark)));
            ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString(it->data.final_mark)));
            ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString(it->data.other_mark)));
        }

        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "midterm"<<"final"<<"other");
        ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 12pt; font-weight: bold; }");

        ui->tableWidget->setFont(QFont(fontFamilyRegular, 12));
    }

}

