#include "scoreboarddialog.h"
#include "./ui_scoreboarddialog.h"
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

ScoreboardDialog::ScoreboardDialog(QWidget *parent, Course* thisCourse, int index)
    : QDialog(parent)
    , thisCourse(thisCourse)
    , index(index)
    , ui(new Ui::ScoreboardDialog)
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
    // create scoreboard
    Node<Score>* temp = thisCourse->Scoreboard.getHead();
    if(temp == nullptr)
    {
        QMessageBox::warning(this, "Error", "there is no student in this course");
        qDebug() << "there is no student in this course";
        return;
    }
    else
    {
       ui->tableWidget_Scoreboard->clear();
        int numStudent = 0;
       Node<Score>* temp = thisCourse->Scoreboard.getHead();
        while(temp != nullptr)
       {
           temp = temp->next;
            numStudent ++;
       }
        temp = thisCourse->Scoreboard.getHead();
       ui->tableWidget_Scoreboard->setRowCount(numStudent);
       ui->tableWidget_Scoreboard->setColumnCount(6);
       int i =0;
       while(temp != nullptr)
       {
           ui->tableWidget_Scoreboard->setItem(i,0,new QTableWidgetItem(QString::fromStdString(temp->data.id_student)));
           qDebug()<< QString::fromStdString(temp->data.fullName);
           ui->tableWidget_Scoreboard->setItem(i,1,new QTableWidgetItem(QString::fromStdString(temp->data.fullName)));
           QTableWidgetItem* mid_mark = new QTableWidgetItem(QString::number(temp->data.mid_mark,'f',2));
           mid_mark->setTextAlignment(Qt::AlignCenter);
           ui->tableWidget_Scoreboard->setItem(i,2,mid_mark);
           QTableWidgetItem* final_mark = new QTableWidgetItem(QString::number(temp->data.final_mark,'f',2));
           final_mark->setTextAlignment(Qt::AlignCenter);
           ui->tableWidget_Scoreboard->setItem(i,3,final_mark);
           QTableWidgetItem* other_mark = new QTableWidgetItem(QString::number(temp->data.other_mark,'f',2));
           other_mark->setTextAlignment(Qt::AlignCenter);
           ui->tableWidget_Scoreboard->setItem(i,4,other_mark);
           if(temp->data.total_mark == -1)
           {
               temp->data.total_mark = temp->data.mid_mark*0.25 + temp->data.final_mark*0.40 + temp->data.other_mark*0.35;
           }
           QTableWidgetItem* total_mark = new QTableWidgetItem(QString::number(temp->data.total_mark,'f',2));
           total_mark->setTextAlignment(Qt::AlignCenter);
           ui->tableWidget_Scoreboard->setItem(i,5,total_mark);
           temp = temp->next;
           i++;
       }
       ui->tableWidget_Scoreboard->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "midterm"<<"final"<<"other"<<"total");
       ui->tableWidget_Scoreboard->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 12pt; font-weight: bold; }");

       ui->tableWidget_Scoreboard->setFont(QFont(fontFamilyRegular, 12));
       resizeColumns();
    }

}
void ScoreboardDialog::resizeColumns() {
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
void ScoreboardDialog::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    resizeColumns();
}

void ScoreboardDialog::showEvent(QShowEvent *event) {
    emit shown();
    QDialog::showEvent(event);
}

void ScoreboardDialog::hideEvent(QHideEvent *event) {
    emit hidden();
    QDialog::hideEvent(event);
}

QString ScoreboardDialog::loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

ScoreboardDialog::~ScoreboardDialog()
{
    delete ui;
}
