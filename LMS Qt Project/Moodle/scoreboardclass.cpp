#include "scoreboardclass.h"
#include "ui_scoreboardclass.h"
#include "LinkedList.h"
#include "Course.h"
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
#include <QFontDatabase>
#include <QString>
#include <string>
#include <QStringList>

ScoreboardClass::ScoreboardClass(QWidget *parent, LinkedList<Student>* students , LinkedList<SchoolYear>* SchoolYears,Semester* thisSemester, const std::string& className)
    : QDialog(parent)
    , students(students)
    , SchoolYears(SchoolYears)
    , thisSemester(thisSemester)
    , className(className)
    , ui(new Ui::ScoreboardClass)
{

    ui->setupUi(this);
    // Set fixed size
    this->setFixedSize(this->size());
    this->setWindowIcon(QIcon(":/Asset/loginpageAsset/logo.png"));
    this->setWindowTitle("Score");

    QWidget *darkenWidget = new QWidget(parent);
    darkenWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.7);");
    darkenWidget->resize(parent->size());
    darkenWidget->show();

    connect(this, &ScoreboardClass::shown, darkenWidget, &QWidget::show);
    connect(this, &ScoreboardClass::hidden, darkenWidget, &QWidget::hide);

    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");

    ui->pushButton->setText(QString::fromStdString(className) + " Scoreboard " + QString::fromStdString(thisSemester->semester));

    Node<Student>* temp = students->getHead();


    if(thisSemester == nullptr)
    {
        //qDebug()<<"No Semester";
        return;
    }
    ui->tableWidget_Scoreboard->clear();

    ui->tableWidget_Scoreboard->setRowCount(students->size());

    ui->tableWidget_Scoreboard->setColumnCount(thisSemester->courses.size()+4);
    int i = 0;
    Node<Course>* tempCourse = nullptr;
    while(temp != nullptr)
    {

        ui->tableWidget_Scoreboard->setItem(i,0,new QTableWidgetItem(QString::fromStdString(temp->data.studentID)));
        ui->tableWidget_Scoreboard->setItem(i,1,new QTableWidgetItem(QString::fromStdString(temp->data.getStudentFullName())));
        tempCourse = thisSemester->courses.getHead();
        for(int j = 0;j<thisSemester->courses.size();j++)
        {
            Node<Score>* it = tempCourse->data.Scoreboard.getHead();
            while(it != nullptr)
            {
                if(it->data.id_student == temp->data.studentID)
                    break;
                it = it->next;
            }
            if(it != nullptr)
            {
                QTableWidgetItem* mark = new QTableWidgetItem(QString::number(it->data.total_mark,'f',2));
                mark->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_Scoreboard->setItem(i,2+j,mark);
            }
            else
            {
                QTableWidgetItem* mark = new QTableWidgetItem(QString("N/A"));
                mark->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_Scoreboard->setItem(i,2+j,mark);
            }
            tempCourse = tempCourse->next;
        }
        float GPA = semesterGPA(temp);
        //qDebug()<<GPA;
        if(GPA == -1)
        {
            QTableWidgetItem* mark = new QTableWidgetItem(QString("N/A"));
            mark->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_Scoreboard->setItem(i,thisSemester->courses.size()+2,mark);
        }
        else
        {
            QTableWidgetItem* mark = new QTableWidgetItem(QString::number(GPA,'f',2));
            mark->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_Scoreboard->setItem(i,thisSemester->courses.size()+2,mark);
        }
        float mGPA = overallGPA(temp);
        if(mGPA == -1)
        {
            QTableWidgetItem* mark = new QTableWidgetItem(QString("N/A"));
            mark->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_Scoreboard->setItem(i,thisSemester->courses.size()+3,mark);
        }
        else
        {
            QTableWidgetItem* mark = new QTableWidgetItem(QString::number(mGPA,'f',2));
            mark->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_Scoreboard->setItem(i,thisSemester->courses.size()+3,mark);
        }
        i++;
        temp = temp->next;
    }
    QStringList headerLabels;
    headerLabels << "ID"<<"Full Name";
    Node<Course>* ourse = thisSemester->courses.getHead();
    for(int k = 0;k<thisSemester->courses.size();k++)
    {
        headerLabels<<QString::fromStdString(ourse->data.courseID)+ "-" + QString::fromStdString(ourse->data.className);
        ourse = ourse->next;
    }
    headerLabels << "GPA"<<"OverallGPA";
    ui->tableWidget_Scoreboard->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget_Scoreboard->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 12pt; font-weight: bold; }");

    ui->tableWidget_Scoreboard->setFont(QFont(fontFamilyRegular, 12));
    resizeColumns();

}
void ScoreboardClass::resizeColumns() {
    ui->tableWidget_Scoreboard->resizeColumnsToContents();

    bool isScrollBarVisible = ui->tableWidget_Scoreboard->verticalScrollBar()->isVisible();

    // Calculate the total content width
    int totalContentWidth = 0;
    for (int i = 0; i < ui->tableWidget_Scoreboard->columnCount(); ++i) {
        totalContentWidth += ui->tableWidget_Scoreboard->columnWidth(i);
    }

    // Calculate total width without tab
    int totalAvailableWidth = this->width() - 2 * ui->tableWidget_Scoreboard->frameWidth();

    int usedWidth = 0;

    // Set the width of each column
    int i;
    for (i = 0; i < ui->tableWidget_Scoreboard->columnCount() - 1; ++i) {
        int stretchFactor = ui->tableWidget_Scoreboard->columnWidth(i) * 100 / totalContentWidth;
        int newWidth = stretchFactor * totalAvailableWidth / 100;
        ui->tableWidget_Scoreboard->setColumnWidth(i, newWidth);
        usedWidth += newWidth;
    }

    // Calculate remaining space
    int remainingSpace = totalAvailableWidth - usedWidth;

    // If scrollbar is visible, adjust the remaining space
    if (isScrollBarVisible)
        remainingSpace -= (ui->tableWidget_Scoreboard->verticalScrollBar()->width());

    // Set the width of the last column based on the remaining space
    ui->tableWidget_Scoreboard->setColumnWidth(i, remainingSpace - 30);
}
void ScoreboardClass::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    resizeColumns();
}

void ScoreboardClass::showEvent(QShowEvent *event) {
    emit shown();
    QDialog::showEvent(event);
}

void ScoreboardClass::hideEvent(QHideEvent *event) {
    emit hidden();
    QDialog::hideEvent(event);
}

QString ScoreboardClass::loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

ScoreboardClass::~ScoreboardClass()
{
    delete ui;
}

float ScoreboardClass::semesterGPA(Node<Student>* st)
{
    Node<Course>* temp = thisSemester->courses.getHead();
    float sumMark = 0;
    float sumCredit = 0;
    while(temp != nullptr)
    {
        Node<Score>* it = temp->data.Scoreboard.getHead();

        while(it != nullptr)
        {
            if(it->data.id_student == st->data.studentID)
                break;
            it = it->next;
        }
        if(it != nullptr)
        {
            it->data.total_mark = it->data.final_mark*0.4 + it->data.mid_mark*0.25 + it->data.other_mark*0.35;
            sumMark += (it->data.total_mark)*std::stoi(temp->data.credits);
            sumCredit += std::stoi(temp->data.credits);
        }
        temp = temp->next;
    }
    //qDebug()<<"I am here";
    return sumMark/sumCredit;
}

float ScoreboardClass::overallGPA(Node<Student>* st)
{
    Node<SchoolYear>* cur_year = SchoolYears->getHead();
    float sumMark = 0;
    float sumCredit = 0;
    while(cur_year != nullptr)
    {
        Node<Semester>* cur_semester = cur_year->data.semesters.getHead();
        while(cur_semester != nullptr)
        {
            Node<Course>* temp = cur_semester->data.courses.getHead();
            while(temp != nullptr)
            {
                Node<Score>* it = temp->data.Scoreboard.getHead();

                while(it != nullptr)
                {
                    if(it->data.id_student == st->data.studentID)
                        break;
                    it = it->next;
                }
                if(it != nullptr)
                {
                     it->data.total_mark = it->data.final_mark*0.4 + it->data.mid_mark*0.25 + it->data.other_mark*0.35;
                    sumMark += (it->data.total_mark)*std::stoi(temp->data.credits);
                    sumCredit += std::stoi(temp->data.credits);
                }
                temp = temp->next;
            }
            cur_semester = cur_semester->next;
        }
        cur_year = cur_year->next;
    }
    return sumMark/sumCredit;
}
