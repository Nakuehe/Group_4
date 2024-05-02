/********************************************************************************
** Form generated from reading UI file 'updateStudentResult.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATESTUDENTRESULT_H
#define UI_UPDATESTUDENTRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_updateStudentResult
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox_idstudent;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Search;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_mid;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_final;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_other;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_Accept;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *updateStudentResult)
    {
        if (updateStudentResult->objectName().isEmpty())
            updateStudentResult->setObjectName("updateStudentResult");
        updateStudentResult->resize(1096, 636);
        gridLayout = new QGridLayout(updateStudentResult);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        comboBox_idstudent = new QComboBox(updateStudentResult);
        comboBox_idstudent->setObjectName("comboBox_idstudent");

        horizontalLayout->addWidget(comboBox_idstudent);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Search = new QPushButton(updateStudentResult);
        pushButton_Search->setObjectName("pushButton_Search");
        pushButton_Search->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    border : none;\n"
"   color : white;\n"
"   background-color : blue;\n"
"	font: 700 14pt \"Arial\";\n"
"   border-radius : 30px;\n"
"}\n"
"QPushButton::Hover\n"
"{\n"
"  background-color : green;\n"
"}"));

        horizontalLayout->addWidget(pushButton_Search);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        tableWidget = new QTableWidget(updateStudentResult);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView {\n"
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

        verticalLayout->addWidget(tableWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(updateStudentResult);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("border : none;\n"
"   color : white;\n"
"   background-color : blue;\n"
"	font: 700 14pt \"Arial\";\n"
"   border-radius : 30px;"));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_mid = new QLineEdit(updateStudentResult);
        lineEdit_mid->setObjectName("lineEdit_mid");

        horizontalLayout_2->addWidget(lineEdit_mid);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        lineEdit_final = new QLineEdit(updateStudentResult);
        lineEdit_final->setObjectName("lineEdit_final");

        horizontalLayout_2->addWidget(lineEdit_final);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        lineEdit_other = new QLineEdit(updateStudentResult);
        lineEdit_other->setObjectName("lineEdit_other");

        horizontalLayout_2->addWidget(lineEdit_other);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        pushButton_Accept = new QPushButton(updateStudentResult);
        pushButton_Accept->setObjectName("pushButton_Accept");
        pushButton_Accept->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    border : none;\n"
"   color : white;\n"
"   background-color : blue;\n"
"	font: 700 14pt \"Arial\";\n"
"   border-radius : 30px;\n"
"}\n"
"QPushButton::Hover\n"
"{\n"
"  background-color : green;\n"
"}"));

        horizontalLayout_3->addWidget(pushButton_Accept);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(updateStudentResult);

        QMetaObject::connectSlotsByName(updateStudentResult);
    } // setupUi

    void retranslateUi(QDialog *updateStudentResult)
    {
        updateStudentResult->setWindowTitle(QCoreApplication::translate("updateStudentResult", "Dialog", nullptr));
        pushButton_Search->setText(QCoreApplication::translate("updateStudentResult", "Search", nullptr));
        pushButton_2->setText(QCoreApplication::translate("updateStudentResult", "Update result", nullptr));
        lineEdit_mid->setPlaceholderText(QCoreApplication::translate("updateStudentResult", "Enter update midterm", nullptr));
        lineEdit_final->setPlaceholderText(QCoreApplication::translate("updateStudentResult", "Enter update final", nullptr));
        lineEdit_other->setPlaceholderText(QCoreApplication::translate("updateStudentResult", "Enter update other ", nullptr));
        pushButton_Accept->setText(QCoreApplication::translate("updateStudentResult", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateStudentResult: public Ui_updateStudentResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATESTUDENTRESULT_H
