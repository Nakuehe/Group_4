/********************************************************************************
** Form generated from reading UI file 'scoreboarddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREBOARDDIALOG_H
#define UI_SCOREBOARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreboardDialog
{
public:
    QPushButton *pushButton;
    QTableWidget *tableWidget_Scoreboard;

    void setupUi(QDialog *ScoreboardDialog)
    {
        if (ScoreboardDialog->objectName().isEmpty())
            ScoreboardDialog->setObjectName("ScoreboardDialog");
        ScoreboardDialog->resize(1211, 634);
        pushButton = new QPushButton(ScoreboardDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 1211, 29));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    border : none;\n"
"   color : white;\n"
"   background-color : blue;\n"
"	font: 700 14pt \"Arial\";\n"
"   border-radius : 30px;\n"
"}"));
        tableWidget_Scoreboard = new QTableWidget(ScoreboardDialog);
        tableWidget_Scoreboard->setObjectName("tableWidget_Scoreboard");
        tableWidget_Scoreboard->setGeometry(QRect(0, 31, 1211, 601));
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
        tableWidget_Scoreboard->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Scoreboard->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_Scoreboard->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_Scoreboard->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Scoreboard->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget_Scoreboard->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_Scoreboard->verticalHeader()->setStretchLastSection(false);

        retranslateUi(ScoreboardDialog);

        QMetaObject::connectSlotsByName(ScoreboardDialog);
    } // setupUi

    void retranslateUi(QDialog *ScoreboardDialog)
    {
        ScoreboardDialog->setWindowTitle(QCoreApplication::translate("ScoreboardDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ScoreboardDialog", "View Scoreboard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreboardDialog: public Ui_ScoreboardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREBOARDDIALOG_H
