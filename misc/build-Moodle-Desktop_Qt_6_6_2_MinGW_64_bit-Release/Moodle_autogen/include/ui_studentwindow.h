/********************************************************************************
** Form generated from reading UI file 'studentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentWindow
{
public:
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QWidget *tab;
    QWidget *tab_3;

    void setupUi(QTabWidget *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName("StudentWindow");
        StudentWindow->resize(751, 613);
        QPalette palette;
        QBrush brush(QColor(0, 145, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        StudentWindow->setPalette(palette);
        StudentWindow->setToolTipDuration(0);
        StudentWindow->setAutoFillBackground(true);
        StudentWindow->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	color: white;\n"
"	background: #0091FF;\n"
"	padding: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:top {\n"
"	margin-top: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:top:first {\n"
"	margin-left: 50px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	background: #006EDC;\n"
"}\n"
"\n"
" QTabBar::tab:hover{\n"
"	background: #0082E5\n"
"}"));
        StudentWindow->setTabPosition(QTabWidget::West);
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName("gridLayout");
        StudentWindow->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        StudentWindow->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        StudentWindow->addTab(tab_3, QString());

        retranslateUi(StudentWindow);

        StudentWindow->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QTabWidget *StudentWindow)
    {
        StudentWindow->setWindowTitle(QCoreApplication::translate("StudentWindow", "TabWidget", nullptr));
        StudentWindow->setTabText(StudentWindow->indexOf(tab_2), QCoreApplication::translate("StudentWindow", "Page", nullptr));
        StudentWindow->setTabText(StudentWindow->indexOf(tab), QCoreApplication::translate("StudentWindow", "Page", nullptr));
        StudentWindow->setTabText(StudentWindow->indexOf(tab_3), QCoreApplication::translate("StudentWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
