/********************************************************************************
** Form generated from reading UI file 'scoreboardclass.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREBOARDCLASS_H
#define UI_SCOREBOARDCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreboardClass
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget_Scoreboard;

    void setupUi(QDialog *ScoreboardClass)
    {
        if (ScoreboardClass->objectName().isEmpty())
            ScoreboardClass->setObjectName("ScoreboardClass");
        ScoreboardClass->resize(1198, 671);
        pushButton = new QPushButton(ScoreboardClass);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 1201, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    border : none;\n"
"   color : white;\n"
"   background-color : blue;\n"
"	font: 700 14pt \"Arial\";\n"
"   border-radius : 30px;\n"
"}"));
        tableWidget_Scoreboard = new QTableWidget(ScoreboardClass);
        tableWidget_Scoreboard->setObjectName("tableWidget_Scoreboard");
        tableWidget_Scoreboard->setGeometry(QRect(0, 30, 1201, 641));
        tableWidget_Scoreboard->setStyleSheet(QString::fromUtf8("QHeaderView {\n"
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
"}"));

        retranslateUi(ScoreboardClass);

        QMetaObject::connectSlotsByName(ScoreboardClass);
    } // setupUi

    void retranslateUi(QDialog *ScoreboardClass)
    {
        ScoreboardClass->setWindowTitle(QCoreApplication::translate("ScoreboardClass", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ScoreboardClass", "Class Scoreboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreboardClass: public Ui_ScoreboardClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREBOARDCLASS_H
