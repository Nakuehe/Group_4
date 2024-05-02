/********************************************************************************
** Form generated from reading UI file 'testform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTFORM_H
#define UI_TESTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestForm
{
public:
    QGridLayout *gridLayout;
    QTableView *test_view_table;

    void setupUi(QWidget *TestForm)
    {
        if (TestForm->objectName().isEmpty())
            TestForm->setObjectName("TestForm");
        TestForm->resize(640, 480);
        gridLayout = new QGridLayout(TestForm);
        gridLayout->setObjectName("gridLayout");
        test_view_table = new QTableView(TestForm);
        test_view_table->setObjectName("test_view_table");
        test_view_table->setMinimumSize(QSize(0, 0));
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

        gridLayout->addWidget(test_view_table, 0, 0, 1, 1);


        retranslateUi(TestForm);

        QMetaObject::connectSlotsByName(TestForm);
    } // setupUi

    void retranslateUi(QWidget *TestForm)
    {
        TestForm->setWindowTitle(QCoreApplication::translate("TestForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestForm: public Ui_TestForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTFORM_H
