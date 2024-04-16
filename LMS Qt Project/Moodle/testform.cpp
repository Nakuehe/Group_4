#include "testform.h"
#include "ui_testform.h"
#include <QFontDatabase>
#include <QStandardItem>
#include <QMainWindow>
#include <QScrollBar>
#include <QTimer>

TestForm::TestForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestForm)
{
    ui->setupUi(this);
    setUpTableView();
}

QString TestForm::loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}


void TestForm::setUpTableView(){

    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");

    // Set the font of the table

    // Create the model
    model = new QStandardItemModel(4, 6, this);
    for (int row = 0; row < 4; ++row) {
        QString courseID = "CS162";
        QString courseName = "Introduction to Computer Science II";
        QString midterm = "9";
        QString final = "10";
        QString bonus = "_";
        QString total = "10";

        QStandardItem *item1 = new QStandardItem(QString(courseID));
        model->setItem(row, 0, item1);

        QStandardItem *item2 = new QStandardItem(QString(courseName));
        model->setItem(row, 1, item2);

        QStandardItem *item3 = new QStandardItem(QString(midterm));
        item3->setTextAlignment(Qt::AlignCenter);
        model->setItem(row, 2, item3);

        QStandardItem *item4 = new QStandardItem(QString(final));
        item4->setTextAlignment(Qt::AlignCenter);
        model->setItem(row, 3, item4);

        QStandardItem *item5 = new QStandardItem(QString(bonus));
        item5->setTextAlignment(Qt::AlignCenter);
        model->setItem(row, 4, item5);

        QStandardItem *item6 = new QStandardItem(QString(total));
        item6->setTextAlignment(Qt::AlignCenter);
        model->setItem(row, 5, item6);
    }

    // // Set the stylesheet
    // ui->grade_view_table->setStyleSheet("QTableView {"
    //                                     "background-color: #E8E8E8;" // Set the background color
    //                                     "gridline-color: #606060;" // Set the gridline color
    //                                     "}"
    //                                     "QTableView::item {"
    //                                     "border: 1px solid #606060;" // Set the border of the items
    //                                     "}"
    //                                     "QTableView::item:selected {"
    //                                     "background-color: #909090;" // Set the background color of the selected items
    //                                "}");

    model->setHeaderData(0, Qt::Horizontal, tr("Course ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Course Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Midterm"));
    model->setHeaderData(3, Qt::Horizontal, tr("Final"));
    model->setHeaderData(4, Qt::Horizontal, tr("Bonus"));
    model->setHeaderData(5, Qt::Horizontal, tr("Total"));


    // set flexible size
    ui->test_view_table->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->test_view_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->test_view_table->setDragEnabled(false);
    ui->test_view_table->setDragDropOverwriteMode(false);
    ui->test_view_table->setDragDropMode(QAbstractItemView::NoDragDrop);
    ui->test_view_table->setSelectionMode(QAbstractItemView::NoSelection);

    // Set the model
    ui->test_view_table->setModel(model);

    // Make the table view uneditable
    ui->test_view_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Delay the resizing of the columns
    resizeColumns();

    // Set the font of the table
    //ui->grade_view_table->horizontalHeader()->setStyleSheet("QHeaderView { font-size: 12pt; font-weight: bold;}");
    ui->test_view_table->setFont(QFont(fontFamilyRegular, 12));

    int totalContentWidth = 0;
    for (int i = 0; i < model->columnCount(); ++i) {
        totalContentWidth += ui->test_view_table->columnWidth(i);
    }

    this->setMinimumWidth(totalContentWidth + 120);

    // Set the font of the header

}

void TestForm::resizeColumns() {
    ui->test_view_table->resizeColumnsToContents();

    bool isScrollBarVisible = ui->test_view_table->verticalScrollBar()->isVisible();

    // Calculate the total content width
    int totalContentWidth = 0;
    for (int i = 0; i < model->columnCount(); ++i) {
        totalContentWidth += ui->test_view_table->columnWidth(i);
    }

    //Calculate total width without tab
    int totalAvailableWidth = this->width();
    // qDebug() << "1. " << totalAvailableWidth;
    // qDebug() << "2. " << ui->grade_view_table->viewport()->width();

    int usedWidth = 0;

    // Set the width of each column
    int i;

    for (i = 0; i < model->columnCount() - 1; ++i) {
        int stretchFactor = ui->test_view_table->columnWidth(i) * 100 / totalContentWidth;
        int newWidth = stretchFactor * totalAvailableWidth / 100;
        ui->test_view_table->setColumnWidth(i, newWidth);
        usedWidth += newWidth;
    }

    if(!isScrollBarVisible)
        ui->test_view_table->setColumnWidth(i, totalAvailableWidth - usedWidth - 35); // Set the width of the last column
    else
        ui->test_view_table->setColumnWidth(i, totalAvailableWidth - usedWidth - 35 - ui->test_view_table->verticalScrollBar()->width()); // Set the width of the last colum
}

void TestForm::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);  // Call the base class implementation
    resizeColumns();  // Resize the columns
}

TestForm::~TestForm()
{
    delete ui;
}
