/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *pushButtonLogin;
    QGroupBox *groupBox_2;
    QLabel *labelPlaceholder;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonShowPassword;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(984, 732);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #F0F2F5"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setMinimumSize(QSize(701, 631));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color:#F0F2F5;\n"
"border: 0px\n"
""));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 541, 241));
        label->setPixmap(QPixmap(QString::fromUtf8(":/loginpageAsset/FITLogo.png")));
        label->setScaledContents(true);
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(120, 250, 461, 361));
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: #FFFFFF"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 60, 401, 51));
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit { \n"
"	border: 1px solid rgb(212, 212, 212); \n"
"	border-radius: 10px; \n"
"	color: black; \n"
"	padding-left: 15px; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    color: black;\n"
"}"));
        lineEdit->setDragEnabled(false);
        pushButtonLogin = new QPushButton(groupBox);
        pushButtonLogin->setObjectName("pushButtonLogin");
        pushButtonLogin->setGeometry(QRect(30, 230, 401, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("VNI-Helve-Condense")});
        font.setPointSize(16);
        pushButtonLogin->setFont(font);
        pushButtonLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0866FF;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: #0866FF;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #038EFF;\n"
"    border-color: #038EFF;\n"
"}\n"
"\n"
""));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 120, 431, 80));
        labelPlaceholder = new QLabel(groupBox_2);
        labelPlaceholder->setObjectName("labelPlaceholder");
        labelPlaceholder->setGeometry(QRect(30, 30, 191, 31));
        labelPlaceholder->setStyleSheet(QString::fromUtf8("color: gray;"));
        lineEditPassword = new QLineEdit(groupBox_2);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(10, 20, 401, 51));
        lineEditPassword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid rgb(212, 212, 212);\n"
"    border-radius: 10px;\n"
"    color: gray;\n"
"    padding-left: 15px;\n"
"	font-size: 12px; lineedit-password-character: 9679; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    color: black;\n"
"}"));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        pushButtonShowPassword = new QPushButton(groupBox_2);
        pushButtonShowPassword->setObjectName("pushButtonShowPassword");
        pushButtonShowPassword->setGeometry(QRect(370, 30, 31, 31));
        pushButtonShowPassword->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	border-radius: 15px; \n"
"	background-color: lightgray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border-radius: 15px; \n"
"	background-color: gray;\n"
"}\n"
"\n"
""));
        lineEditPassword->raise();
        labelPlaceholder->raise();
        pushButtonShowPassword->raise();
        groupBox_2->raise();
        lineEdit->raise();
        pushButtonLogin->raise();

        gridLayout->addWidget(groupBox_3, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonLogin, SIGNAL(clicked()), MainWindow, SLOT(on_button_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QString());
        label->setText(QString());
        groupBox->setTitle(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("MainWindow", "Log in", nullptr));
        groupBox_2->setTitle(QString());
        labelPlaceholder->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        lineEditPassword->setText(QString());
        lineEditPassword->setPlaceholderText(QString());
        pushButtonShowPassword->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
