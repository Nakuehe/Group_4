#include "scoreboardclass.h"
#include "ui_scoreboardclass.h"
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
#include <QFontDatabase>
#include <QString>
#include <string>

ScoreboardClass::ScoreboardClass(QWidget *parent, Class* thisClass, LinkedList<SchoolYear>* SchoolYears,Semester* thisSemester)
    : QDialog(parent)
    , thisClass(thisClass)
    , SchoolYears(SchoolYears)
    , thisSemester(thisSemester)
    , ui(new Ui::ScoreboardClass)
{
    ui->setupUi(this);
    // Set fixed size
    this->setFixedSize(this->size());

    QWidget *darkenWidget = new QWidget(parent);
    darkenWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.7);");
    darkenWidget->resize(parent->size());
    darkenWidget->show();

    connect(this, &ScoreboardClass::shown, darkenWidget, &QWidget::show);
    connect(this, &ScoreboardClass::hidden, darkenWidget, &QWidget::hide);

    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");



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
    ui->tableWidget_Scoreboard->setColumnWidth(i, remainingSpace);
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

float ScoreboardClass::semesterGPA(Student *st)
{
    Node<Course>* temp = thisSemester->courses.getHead();
    float sumMark = 0;
    float sumCredit = 0;
    while(temp != nullptr)
    {
        Node<Score>* it = temp->data.Scoreboard.getHead();

        while(it != nullptr)
        {
            if(it->data.id_student == st->studentID)
                break;
            it = it->next;
        }
        if(it != nullptr)
        {
            sumMark += (it->data.total_mark)*std::stoi(temp->data.credits);
            sumCredit += std::stoi(temp->data.credits);
        }
        temp = temp->next;
    }
    return sumMark/sumCredit;
}

float ScoreboardClass::overallGPA(Student *st)
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
                    if(it->data.id_student == st->studentID)
                        break;
                    it = it->next;
                }
                if(it != nullptr)
                {
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
