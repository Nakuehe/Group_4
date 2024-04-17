#include "studentviewtable.h"
#include "table_view_form/ui_studentviewtable.h"
#include <QFontDatabase>
#include <QStandardItem>
#include <QMainWindow>
#include <QScrollBar>
#include <QTimer>

StudentViewTable::StudentViewTable(QWidget *parent, const LinkedList<Student> *student_list)
    : QMainWindow(parent)
    , student_list(student_list)
    , ui(new Ui::StudentViewTable)
{
    ui->setupUi(this);
    setUpTableView();
}

QString StudentViewTable::loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}


void StudentViewTable::setUpTableView(){

    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");

    // Set the font of the table

    // Create the model
    model = new QStandardItemModel(student_list->size(), 6, this);
    for (int row = 0; row < student_list->size(); ++row) {
        Student* this_student = &student_list->get(row);

        QString StudentID = QString::fromStdString(this_student->studentID);
        QString firstName = QString::fromStdString(this_student->firstName);
        QString lastName = QString::fromStdString(this_student->lastName);
        QString gender = QString::fromStdString(this_student->gender);
        QString dateOfBirth = QString::fromStdString(this_student->dateOfBirth);
        QString socialID = QString::fromStdString(this_student->socialID);


        QStandardItem *item1 = new QStandardItem(QString(StudentID));
        model->setItem(row, 0, item1);

        QStandardItem *item2 = new QStandardItem(QString(firstName));
        model->setItem(row, 1, item2);

        QStandardItem *item3 = new QStandardItem(QString(lastName));
        //item3->setTextAlignment(Qt::AlignCenter);
        model->setItem(row, 2, item3);

        QStandardItem *item4 = new QStandardItem(QString(gender));
        item4->setTextAlignment(Qt::AlignCenter);
        model->setItem(row, 3, item4);

        QStandardItem *item5 = new QStandardItem(QString(dateOfBirth));
        //item5->setTextAlignment(Qt::AlignCenter);
        model->setItem(row, 4, item5);

        QStandardItem *item6 = new QStandardItem(QString(socialID));
        //item6->setTextAlignment(Qt::AlignCenter);
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

    model->setHeaderData(0, Qt::Horizontal, tr("Student ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("First Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Last Name"));
    model->setHeaderData(3, Qt::Horizontal, tr("Gender"));
    model->setHeaderData(4, Qt::Horizontal, tr("Date of birth"));
    model->setHeaderData(5, Qt::Horizontal, tr("Social ID"));


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

    resizeColumns();
}

void StudentViewTable::resizeColumns() {
    ui->test_view_table->resizeColumnsToContents();

    bool isScrollBarVisible = ui->test_view_table->verticalScrollBar()->isVisible();

    // Calculate the total content width
    int totalContentWidth = 0;
    for (int i = 0; i < model->columnCount(); ++i) {
        totalContentWidth += ui->test_view_table->columnWidth(i);
    }

    //Calculate total width without tab
    int totalAvailableWidth = this->width() - 2 * ui->test_view_table->frameWidth();
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

    // Calculate remaining space
    int remainingSpace = totalAvailableWidth - usedWidth;

    // If scrollbar is visible, adjust the remaining space
    if(isScrollBarVisible)
        remainingSpace -= (ui->test_view_table->verticalScrollBar()->width());

    // Set the width of the last column based on the remaining space
    ui->test_view_table->setColumnWidth(i, remainingSpace - 38);
}

void StudentViewTable::updateStudentList(const LinkedList<Student>* student_list) {
    this->student_list = student_list;
    // Update the table view with the new student list
}

void StudentViewTable::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);  // Call the base class implementation
    resizeColumns();  // Resize the columns
}


StudentViewTable::~StudentViewTable()
{
    delete ui;
}
