/********************************************************************************
** Form generated from reading UI file 'studentviewtable.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTVIEWTABLE_H
#define UI_STUDENTVIEWTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentViewTable
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *test_view_table;

    void setupUi(QMainWindow *StudentViewTable)
    {
        if (StudentViewTable->objectName().isEmpty())
            StudentViewTable->setObjectName("StudentViewTable");
        StudentViewTable->resize(900, 600);
        StudentViewTable->setMinimumSize(QSize(900, 600));
        centralWidget = new QWidget(StudentViewTable);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setObjectName("gridLayout");
        test_view_table = new QTableView(centralWidget);
        test_view_table->setObjectName("test_view_table");
        test_view_table->setStyleSheet(QString::fromUtf8("QHeaderView {\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"    background-color: #FFFFFF; /* Match the table's background color */\n"
"	gridline-color: #606060;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"	border: 1px solid #606060;\n"
"	 background-color: lightgray;\n"
" }\n"
"\n"
"QHeaderView::section{\n"
"	border: 1px solid #606060\n"
"}\n"
"\n"
"QTableView {\n"
"    border: 2px solid lightgray;\n"
"    background-color: #FFFFFF;\n"
"}\n"
"\n"
"QTableView::item{\n"
"	border: 1px solid #606060\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"	background-color: #909090;\n"
"}\n"
"\n"
""));
        test_view_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout->addWidget(test_view_table, 0, 0, 1, 1);

        StudentViewTable->setCentralWidget(centralWidget);

        retranslateUi(StudentViewTable);

        QMetaObject::connectSlotsByName(StudentViewTable);
    } // setupUi

    void retranslateUi(QMainWindow *StudentViewTable)
    {
        StudentViewTable->setWindowTitle(QCoreApplication::translate("StudentViewTable", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentViewTable: public Ui_StudentViewTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTVIEWTABLE_H
