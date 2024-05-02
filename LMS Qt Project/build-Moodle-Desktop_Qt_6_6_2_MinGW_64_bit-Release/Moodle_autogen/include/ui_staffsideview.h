/********************************************************************************
** Form generated from reading UI file 'staffsideview.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAFFSIDEVIEW_H
#define UI_STAFFSIDEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StaffSideView
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *logo_lable;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *greeting_label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QComboBox *school_year_box;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirm_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_school_year_button;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *changePasswordButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *StaffSideView)
    {
        if (StaffSideView->objectName().isEmpty())
            StaffSideView->setObjectName("StaffSideView");
        StaffSideView->resize(761, 543);
        StaffSideView->setStyleSheet(QString::fromUtf8("background-color:#F0F2F5;\n"
""));
        gridLayout_2 = new QGridLayout(StaffSideView);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        logo_lable = new QLabel(StaffSideView);
        logo_lable->setObjectName("logo_lable");
        logo_lable->setMaximumSize(QSize(16777215, 200));
        logo_lable->setPixmap(QPixmap(QString::fromUtf8(":/asset/loginpageAsset/FITLogo.png")));
        logo_lable->setScaledContents(false);
        logo_lable->setAlignment(Qt::AlignCenter);
        logo_lable->setMargin(0);

        verticalLayout_4->addWidget(logo_lable);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 10, -1, -1);
        greeting_label = new QLabel(StaffSideView);
        greeting_label->setObjectName("greeting_label");
        greeting_label->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(greeting_label);

        groupBox = new QGroupBox(StaffSideView);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(350, 0));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:#FFFFFF;\n"
"border-radius: 10px;\n"
"background-color: #FFFFFF"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(20, 15, 20, 15);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        school_year_box = new QComboBox(groupBox);
        school_year_box->setObjectName("school_year_box");
        school_year_box->setMinimumSize(QSize(0, 50));
        school_year_box->setAutoFillBackground(false);
        school_year_box->setStyleSheet(QString::fromUtf8("/*\n"
"QComboBox { \n"
"	border: 1px solid rgb(212, 212, 212); \n"
"	border-radius: 25px; \n"
"	color: black; \n"
"	padding-left: 15px; \n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    color: black;\n"
"	border: 1px solid blue; \n"
"}\n"
"\n"
"QComboBox::down-arrow { \n"
"	image: url(qrc:/Asset/staffViewAsset/arrow-down-3101.svg);\n"
"} */\n"
""));

        verticalLayout->addWidget(school_year_box);

        verticalSpacer = new QSpacerItem(293, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        confirm_button = new QPushButton(groupBox);
        confirm_button->setObjectName("confirm_button");
        confirm_button->setMinimumSize(QSize(150, 50));
        confirm_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #42b72a;\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    border-color: #42b72a;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #37a520;\n"
"    border-color: #37a520;\n"
"	color: white;\n"
"}"));

        horizontalLayout->addWidget(confirm_button);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        add_school_year_button = new QPushButton(groupBox);
        add_school_year_button->setObjectName("add_school_year_button");
        add_school_year_button->setMinimumSize(QSize(150, 50));
        add_school_year_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0866FF;\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    border-color: #0866FF;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #038EFF;\n"
"    border-color: #038EFF;\n"
"	color: white;\n"
"}"));

        horizontalLayout->addWidget(add_school_year_button);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        changePasswordButton = new QPushButton(StaffSideView);
        changePasswordButton->setObjectName("changePasswordButton");

        horizontalLayout_4->addWidget(changePasswordButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_5);


        verticalLayout_4->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(StaffSideView);

        QMetaObject::connectSlotsByName(StaffSideView);
    } // setupUi

    void retranslateUi(QDialog *StaffSideView)
    {
        StaffSideView->setWindowTitle(QCoreApplication::translate("StaffSideView", "Dialog", nullptr));
        logo_lable->setText(QString());
        greeting_label->setText(QCoreApplication::translate("StaffSideView", "Choose School Year", nullptr));
        groupBox->setTitle(QString());
        confirm_button->setText(QCoreApplication::translate("StaffSideView", "OK", nullptr));
        add_school_year_button->setText(QCoreApplication::translate("StaffSideView", "Add ", nullptr));
        changePasswordButton->setText(QCoreApplication::translate("StaffSideView", "Change password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StaffSideView: public Ui_StaffSideView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAFFSIDEVIEW_H
