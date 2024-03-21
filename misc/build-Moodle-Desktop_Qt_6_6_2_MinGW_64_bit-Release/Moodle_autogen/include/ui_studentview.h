/********************************************************************************
** Form generated from reading UI file 'studentview.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTVIEW_H
#define UI_STUDENTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentView
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *icon_only_widget;
    QVBoxLayout *verticalLayout;
    QPushButton *profile_btn1;
    QPushButton *course_btn1;
    QPushButton *grade_btn1;
    QSpacerItem *verticalSpacer;
    QPushButton *exit_btn1;
    QWidget *full_menu_widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *profile_btn2;
    QPushButton *course_btn2;
    QPushButton *grade_btn2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *exit_btn2;
    QWidget *main_view;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *menu_btn;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_5;
    QLabel *label_2;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QWidget *page_3;
    QGridLayout *gridLayout_6;
    QLabel *label_3;

    void setupUi(QMainWindow *StudentView)
    {
        if (StudentView->objectName().isEmpty())
            StudentView->setObjectName("StudentView");
        StudentView->resize(956, 614);
        StudentView->setStyleSheet(QString::fromUtf8("background-color: #F0F2F5"));
        actionExit = new QAction(StudentView);
        actionExit->setObjectName("actionExit");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("weather-few-clouds");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(":/loginpageAsset/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionExit->setIcon(icon);
        actionExit->setMenuRole(QAction::QuitRole);
        centralwidget = new QWidget(StudentView);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        icon_only_widget = new QWidget(centralwidget);
        icon_only_widget->setObjectName("icon_only_widget");
        icon_only_widget->setMinimumSize(QSize(60, 300));
        icon_only_widget->setMaximumSize(QSize(60, 16777215));
        icon_only_widget->setStyleSheet(QString::fromUtf8("background-color: #0091FF"));
        verticalLayout = new QVBoxLayout(icon_only_widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        profile_btn1 = new QPushButton(icon_only_widget);
        profile_btn1->setObjectName("profile_btn1");
        profile_btn1->setMinimumSize(QSize(60, 60));
        profile_btn1->setMaximumSize(QSize(60, 60));
        profile_btn1->setAutoFillBackground(false);
        profile_btn1->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: #0082E5;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: #006EDC;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/loginpageAsset/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/loginpageAsset/user_toggled.png"), QSize(), QIcon::Normal, QIcon::On);
        profile_btn1->setIcon(icon1);
        profile_btn1->setIconSize(QSize(40, 40));
        profile_btn1->setCheckable(true);
        profile_btn1->setChecked(false);
        profile_btn1->setAutoRepeat(false);
        profile_btn1->setAutoExclusive(true);

        verticalLayout->addWidget(profile_btn1);

        course_btn1 = new QPushButton(icon_only_widget);
        course_btn1->setObjectName("course_btn1");
        course_btn1->setMinimumSize(QSize(60, 60));
        course_btn1->setMaximumSize(QSize(60, 60));
        course_btn1->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: #0082E5;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: #006EDC;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/loginpageAsset/course2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/loginpageAsset/course2_toggled.png"), QSize(), QIcon::Normal, QIcon::On);
        course_btn1->setIcon(icon2);
        course_btn1->setIconSize(QSize(40, 40));
        course_btn1->setCheckable(true);
        course_btn1->setChecked(false);
        course_btn1->setAutoExclusive(true);

        verticalLayout->addWidget(course_btn1);

        grade_btn1 = new QPushButton(icon_only_widget);
        grade_btn1->setObjectName("grade_btn1");
        grade_btn1->setMinimumSize(QSize(60, 60));
        grade_btn1->setMaximumSize(QSize(60, 60));
        grade_btn1->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: #0082E5;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: #006EDC;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/loginpageAsset/grade.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/loginpageAsset/grade_toggled.png"), QSize(), QIcon::Normal, QIcon::On);
        grade_btn1->setIcon(icon3);
        grade_btn1->setIconSize(QSize(40, 40));
        grade_btn1->setCheckable(true);
        grade_btn1->setChecked(true);
        grade_btn1->setAutoExclusive(true);

        verticalLayout->addWidget(grade_btn1);

        verticalSpacer = new QSpacerItem(20, 347, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        exit_btn1 = new QPushButton(icon_only_widget);
        exit_btn1->setObjectName("exit_btn1");
        exit_btn1->setMinimumSize(QSize(60, 60));
        exit_btn1->setMaximumSize(QSize(60, 60));
        exit_btn1->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: #0082E5;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/loginpageAsset/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/loginpageAsset/exit_toggled.png"), QSize(), QIcon::Normal, QIcon::On);
        exit_btn1->setIcon(icon4);
        exit_btn1->setIconSize(QSize(40, 40));
        exit_btn1->setCheckable(false);
        exit_btn1->setChecked(false);
        exit_btn1->setAutoExclusive(false);

        verticalLayout->addWidget(exit_btn1);


        gridLayout->addWidget(icon_only_widget, 0, 0, 1, 1);

        full_menu_widget = new QWidget(centralwidget);
        full_menu_widget->setObjectName("full_menu_widget");
        full_menu_widget->setMinimumSize(QSize(172, 300));
        full_menu_widget->setMaximumSize(QSize(172, 16777215));
        full_menu_widget->setStyleSheet(QString::fromUtf8("background-color: #0091FF"));
        verticalLayout_2 = new QVBoxLayout(full_menu_widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        profile_btn2 = new QPushButton(full_menu_widget);
        profile_btn2->setObjectName("profile_btn2");
        profile_btn2->setMinimumSize(QSize(150, 40));
        profile_btn2->setAutoFillBackground(false);
        profile_btn2->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: #0082E5;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: #006EDC;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	color: white;\n"
"	text-align: left;\n"
"	padding: 8px 0 8px 25px;\n"
"}"));
        profile_btn2->setIcon(icon1);
        profile_btn2->setIconSize(QSize(30, 30));
        profile_btn2->setCheckable(true);
        profile_btn2->setAutoExclusive(true);

        verticalLayout_2->addWidget(profile_btn2);

        course_btn2 = new QPushButton(full_menu_widget);
        course_btn2->setObjectName("course_btn2");
        course_btn2->setMinimumSize(QSize(150, 40));
        course_btn2->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: #0082E5;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: #006EDC;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	color: white;\n"
"	text-align: left;\n"
"	padding: 8px 0 8px 25px;\n"
"}"));
        course_btn2->setIcon(icon2);
        course_btn2->setIconSize(QSize(30, 30));
        course_btn2->setCheckable(true);
        course_btn2->setAutoExclusive(true);

        verticalLayout_2->addWidget(course_btn2);

        grade_btn2 = new QPushButton(full_menu_widget);
        grade_btn2->setObjectName("grade_btn2");
        grade_btn2->setMinimumSize(QSize(150, 40));
        grade_btn2->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: #0082E5;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: #006EDC;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	color: white;\n"
"	text-align: left;\n"
"	padding: 8px 0 8px 25px;\n"
"}"));
        grade_btn2->setIcon(icon3);
        grade_btn2->setIconSize(QSize(30, 30));
        grade_btn2->setCheckable(true);
        grade_btn2->setAutoExclusive(true);

        verticalLayout_2->addWidget(grade_btn2);

        verticalSpacer_2 = new QSpacerItem(20, 403, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        exit_btn2 = new QPushButton(full_menu_widget);
        exit_btn2->setObjectName("exit_btn2");
        exit_btn2->setMinimumSize(QSize(150, 40));
        exit_btn2->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: #0082E5;\n"
"}\n"
"\n"
"QPushButton:checked{\n"
"	background-color: #006EDC;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: transparent;\n"
"	border: none;\n"
"	color: white;\n"
"	text-align: left;\n"
"	padding: 8px 0 8px 25px;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/loginpageAsset/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit_btn2->setIcon(icon5);
        exit_btn2->setIconSize(QSize(30, 30));
        exit_btn2->setCheckable(false);
        exit_btn2->setAutoExclusive(false);

        verticalLayout_2->addWidget(exit_btn2);


        gridLayout->addWidget(full_menu_widget, 0, 1, 1, 1);

        main_view = new QWidget(centralwidget);
        main_view->setObjectName("main_view");
        main_view->setMinimumSize(QSize(690, 590));
        gridLayout_3 = new QGridLayout(main_view);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget = new QWidget(main_view);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(660, 50));
        widget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        menu_btn = new QPushButton(widget);
        menu_btn->setObjectName("menu_btn");
        menu_btn->setMinimumSize(QSize(40, 40));
        menu_btn->setMaximumSize(QSize(40, 40));
        menu_btn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: none\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: lightgray\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/loginpageAsset/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        menu_btn->setIcon(icon6);
        menu_btn->setCheckable(true);

        horizontalLayout_2->addWidget(menu_btn);

        horizontalSpacer = new QSpacerItem(626, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(widget);

        stackedWidget = new QStackedWidget(main_view);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        stackedWidget->setMinimumSize(QSize(500, 400));
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_5 = new QGridLayout(page);
        gridLayout_5->setObjectName("gridLayout_5");
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setObjectName("gridLayout_4");
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setAutoFillBackground(false);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_6 = new QGridLayout(page_3);
        gridLayout_6->setObjectName("gridLayout_6");
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        verticalLayout_3->addWidget(stackedWidget);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout->addWidget(main_view, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        StudentView->setCentralWidget(centralwidget);

        retranslateUi(StudentView);
        QObject::connect(actionExit, &QAction::triggered, StudentView, qOverload<>(&QMainWindow::close));
        QObject::connect(menu_btn, &QPushButton::toggled, icon_only_widget, &QWidget::setHidden);
        QObject::connect(menu_btn, &QPushButton::toggled, full_menu_widget, &QWidget::setVisible);
        QObject::connect(exit_btn2, &QPushButton::clicked, exit_btn1, qOverload<>(&QPushButton::click));
        QObject::connect(profile_btn1, &QPushButton::toggled, profile_btn2, &QPushButton::setChecked);
        QObject::connect(profile_btn2, &QPushButton::toggled, profile_btn1, &QPushButton::setChecked);
        QObject::connect(course_btn1, &QPushButton::toggled, course_btn2, &QPushButton::setChecked);
        QObject::connect(course_btn2, &QPushButton::toggled, course_btn1, &QPushButton::setChecked);
        QObject::connect(grade_btn1, &QPushButton::toggled, grade_btn2, &QPushButton::setChecked);
        QObject::connect(grade_btn2, &QPushButton::toggled, grade_btn1, &QPushButton::setChecked);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StudentView);
    } // setupUi

    void retranslateUi(QMainWindow *StudentView)
    {
        StudentView->setWindowTitle(QCoreApplication::translate("StudentView", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("StudentView", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("StudentView", "<html><head/><body><p>Click here to exit</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("StudentView", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        profile_btn1->setText(QString());
        course_btn1->setText(QString());
        grade_btn1->setText(QString());
        exit_btn1->setText(QString());
        profile_btn2->setText(QCoreApplication::translate("StudentView", "Profile", nullptr));
        course_btn2->setText(QCoreApplication::translate("StudentView", "My Courses", nullptr));
        grade_btn2->setText(QCoreApplication::translate("StudentView", "My Grades", nullptr));
        exit_btn2->setText(QCoreApplication::translate("StudentView", "Log out", nullptr));
        menu_btn->setText(QString());
        label_2->setText(QCoreApplication::translate("StudentView", "Profile Page", nullptr));
        label->setText(QCoreApplication::translate("StudentView", "Course page", nullptr));
        label_3->setText(QCoreApplication::translate("StudentView", "Grade page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentView: public Ui_StudentView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTVIEW_H
