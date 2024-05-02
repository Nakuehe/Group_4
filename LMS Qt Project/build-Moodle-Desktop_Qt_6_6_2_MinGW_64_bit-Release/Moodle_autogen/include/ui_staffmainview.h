/********************************************************************************
** Form generated from reading UI file 'staffmainview.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAFFMAINVIEW_H
#define UI_STAFFMAINVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StaffMainView
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *icon_only_widget;
    QVBoxLayout *verticalLayout;
    QPushButton *semester_btn1;
    QPushButton *class_btn1;
    QSpacerItem *verticalSpacer;
    QPushButton *exit_btn1;
    QWidget *full_menu_widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *semester_btn2;
    QPushButton *class_btn2;
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
    QWidget *page_1;
    QGridLayout *gridLayout_4;
    QWidget *page_2;
    QGridLayout *gridLayout_8;
    QWidget *page_3;
    QGridLayout *gridLayout_5;
    QWidget *page;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *course_label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *backButton;
    QListWidget *course_function_list;
    QWidget *page_4;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *class_name;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *backButton2;
    QListWidget *class_function_list;

    void setupUi(QMainWindow *StaffMainView)
    {
        if (StaffMainView->objectName().isEmpty())
            StaffMainView->setObjectName("StaffMainView");
        StaffMainView->resize(1134, 614);
        StaffMainView->setStyleSheet(QString::fromUtf8("background-color: #F0F2F5"));
        actionExit = new QAction(StaffMainView);
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
        centralwidget = new QWidget(StaffMainView);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
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
        semester_btn1 = new QPushButton(icon_only_widget);
        semester_btn1->setObjectName("semester_btn1");
        semester_btn1->setMinimumSize(QSize(60, 60));
        semester_btn1->setMaximumSize(QSize(60, 60));
        semester_btn1->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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
        icon1.addFile(QString::fromUtf8(":/Asset/staffViewAsset/semester1.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/Asset/staffViewAsset/semester2.png"), QSize(), QIcon::Normal, QIcon::On);
        semester_btn1->setIcon(icon1);
        semester_btn1->setIconSize(QSize(40, 40));
        semester_btn1->setCheckable(true);
        semester_btn1->setChecked(false);
        semester_btn1->setAutoExclusive(true);

        verticalLayout->addWidget(semester_btn1);

        class_btn1 = new QPushButton(icon_only_widget);
        class_btn1->setObjectName("class_btn1");
        class_btn1->setMinimumSize(QSize(60, 60));
        class_btn1->setMaximumSize(QSize(60, 60));
        class_btn1->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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
        icon2.addFile(QString::fromUtf8(":/Asset/staffViewAsset/class1.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/Asset/staffViewAsset/class2.png"), QSize(), QIcon::Normal, QIcon::On);
        class_btn1->setIcon(icon2);
        class_btn1->setIconSize(QSize(40, 40));
        class_btn1->setCheckable(true);
        class_btn1->setChecked(true);
        class_btn1->setAutoExclusive(true);

        verticalLayout->addWidget(class_btn1);

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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/asset/loginpageAsset/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/asset/loginpageAsset/exit_toggled.png"), QSize(), QIcon::Normal, QIcon::On);
        exit_btn1->setIcon(icon3);
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
        semester_btn2 = new QPushButton(full_menu_widget);
        semester_btn2->setObjectName("semester_btn2");
        semester_btn2->setMinimumSize(QSize(150, 40));
        semester_btn2->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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
        semester_btn2->setIcon(icon1);
        semester_btn2->setIconSize(QSize(30, 30));
        semester_btn2->setCheckable(true);
        semester_btn2->setChecked(true);
        semester_btn2->setAutoExclusive(true);

        verticalLayout_2->addWidget(semester_btn2);

        class_btn2 = new QPushButton(full_menu_widget);
        class_btn2->setObjectName("class_btn2");
        class_btn2->setMinimumSize(QSize(150, 40));
        class_btn2->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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
        class_btn2->setIcon(icon2);
        class_btn2->setIconSize(QSize(30, 30));
        class_btn2->setCheckable(true);
        class_btn2->setAutoExclusive(true);

        verticalLayout_2->addWidget(class_btn2);

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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/asset/loginpageAsset/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit_btn2->setIcon(icon4);
        exit_btn2->setIconSize(QSize(30, 30));
        exit_btn2->setCheckable(false);
        exit_btn2->setAutoExclusive(false);

        verticalLayout_2->addWidget(exit_btn2);


        gridLayout->addWidget(full_menu_widget, 0, 1, 1, 1);

        main_view = new QWidget(centralwidget);
        main_view->setObjectName("main_view");
        main_view->setMinimumSize(QSize(900, 612));
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/asset/loginpageAsset/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        menu_btn->setIcon(icon5);
        menu_btn->setCheckable(true);

        horizontalLayout_2->addWidget(menu_btn);

        horizontalSpacer = new QSpacerItem(626, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(widget);

        stackedWidget = new QStackedWidget(main_view);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        stackedWidget->setMinimumSize(QSize(500, 400));
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        gridLayout_4 = new QGridLayout(page_1);
        gridLayout_4->setObjectName("gridLayout_4");
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_8 = new QGridLayout(page_2);
        gridLayout_8->setSpacing(5);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setContentsMargins(5, 5, 5, 5);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout_5 = new QGridLayout(page_3);
        gridLayout_5->setObjectName("gridLayout_5");
        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_6 = new QGridLayout(page);
        gridLayout_6->setObjectName("gridLayout_6");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        course_label = new QLabel(page);
        course_label->setObjectName("course_label");
        course_label->setStyleSheet(QString::fromUtf8("text-align: center; font-weight: 500; color: #0D63E6; border: none;"));

        horizontalLayout->addWidget(course_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        backButton = new QPushButton(page);
        backButton->setObjectName("backButton");
        backButton->setMinimumSize(QSize(80, 27));
        backButton->setStyleSheet(QString::fromUtf8("QPushButton { text-align: center; font-weight: 500; color: #0D63E6; border: 1px solid gray; background-color: white; border-radius: 5px;  }\n"
"\n"
"QPushButton::hover{color: #ff6600; text-decoration: underline;}"));

        horizontalLayout->addWidget(backButton);


        verticalLayout_4->addLayout(horizontalLayout);

        course_function_list = new QListWidget(page);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        new QListWidgetItem(course_function_list);
        course_function_list->setObjectName("course_function_list");
        course_function_list->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid lightgray"));

        verticalLayout_4->addWidget(course_function_list);


        gridLayout_6->addLayout(verticalLayout_4, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        gridLayout_9 = new QGridLayout(page_4);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        class_name = new QLabel(page_4);
        class_name->setObjectName("class_name");
        class_name->setStyleSheet(QString::fromUtf8("text-align: center; font-weight: 500; color: #0D63E6; border: none;"));

        horizontalLayout_3->addWidget(class_name);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        backButton2 = new QPushButton(page_4);
        backButton2->setObjectName("backButton2");
        backButton2->setMinimumSize(QSize(80, 27));
        backButton2->setStyleSheet(QString::fromUtf8("QPushButton { text-align: center; font-weight: 500; color: #0D63E6; border: 1px solid gray; background-color: white; border-radius: 5px;  }\n"
"\n"
"QPushButton::hover{color: #ff6600; text-decoration: underline;}"));

        horizontalLayout_3->addWidget(backButton2);


        gridLayout_7->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        class_function_list = new QListWidget(page_4);
        new QListWidgetItem(class_function_list);
        new QListWidgetItem(class_function_list);
        new QListWidgetItem(class_function_list);
        new QListWidgetItem(class_function_list);
        class_function_list->setObjectName("class_function_list");
        class_function_list->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid lightgray"));

        gridLayout_7->addWidget(class_function_list, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 0, 0, 1, 1);

        stackedWidget->addWidget(page_4);

        verticalLayout_3->addWidget(stackedWidget);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout->addWidget(main_view, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        StaffMainView->setCentralWidget(centralwidget);

        retranslateUi(StaffMainView);
        QObject::connect(actionExit, &QAction::triggered, StaffMainView, qOverload<>(&QMainWindow::close));
        QObject::connect(exit_btn2, &QPushButton::clicked, exit_btn1, qOverload<>(&QPushButton::click));
        QObject::connect(semester_btn1, &QPushButton::toggled, semester_btn2, &QPushButton::setChecked);
        QObject::connect(semester_btn2, &QPushButton::toggled, semester_btn1, &QPushButton::setChecked);
        QObject::connect(class_btn1, &QPushButton::toggled, class_btn2, &QPushButton::setChecked);
        QObject::connect(class_btn2, &QPushButton::toggled, class_btn1, &QPushButton::setChecked);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(StaffMainView);
    } // setupUi

    void retranslateUi(QMainWindow *StaffMainView)
    {
        StaffMainView->setWindowTitle(QCoreApplication::translate("StaffMainView", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("StaffMainView", "Exit", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("StaffMainView", "<html><head/><body><p>Click here to exit</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("StaffMainView", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        semester_btn1->setText(QString());
        class_btn1->setText(QString());
        exit_btn1->setText(QString());
        semester_btn2->setText(QCoreApplication::translate("StaffMainView", "Semesters", nullptr));
        class_btn2->setText(QCoreApplication::translate("StaffMainView", "Classes", nullptr));
        exit_btn2->setText(QCoreApplication::translate("StaffMainView", "Log out", nullptr));
        menu_btn->setText(QString());
        course_label->setText(QCoreApplication::translate("StaffMainView", "TextLabel", nullptr));
        backButton->setText(QCoreApplication::translate("StaffMainView", "Back", nullptr));

        const bool __sortingEnabled = course_function_list->isSortingEnabled();
        course_function_list->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = course_function_list->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("StaffMainView", "View lists of students in this course", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = course_function_list->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("StaffMainView", "View scoreboard of this course", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = course_function_list->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("StaffMainView", "Update course infomation", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = course_function_list->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("StaffMainView", "Update a student's result", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = course_function_list->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("StaffMainView", "Add a student to this course", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = course_function_list->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("StaffMainView", "Remove a student from this course", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = course_function_list->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("StaffMainView", "Import list of students to this course", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = course_function_list->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("StaffMainView", "Export list of students from this course", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = course_function_list->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("StaffMainView", "Import scoreboard for this course", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = course_function_list->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("StaffMainView", "Export scoreboard for this course", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = course_function_list->item(10);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("StaffMainView", "Delete this course", nullptr));
        course_function_list->setSortingEnabled(__sortingEnabled);

        class_name->setText(QCoreApplication::translate("StaffMainView", "TextLabel", nullptr));
        backButton2->setText(QCoreApplication::translate("StaffMainView", "Back", nullptr));

        const bool __sortingEnabled1 = class_function_list->isSortingEnabled();
        class_function_list->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem11 = class_function_list->item(0);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("StaffMainView", "Add a student to this class (first year student)", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = class_function_list->item(1);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("StaffMainView", "Import a list of student to this class", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = class_function_list->item(2);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("StaffMainView", "View list of students in this class", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = class_function_list->item(3);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("StaffMainView", "View the scoreboard of this class", nullptr));
        class_function_list->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class StaffMainView: public Ui_StaffMainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAFFMAINVIEW_H
