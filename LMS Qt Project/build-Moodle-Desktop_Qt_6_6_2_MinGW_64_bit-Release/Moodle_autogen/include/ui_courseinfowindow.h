/********************************************************************************
** Form generated from reading UI file 'courseinfowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSEINFOWINDOW_H
#define UI_COURSEINFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CourseInfoWindow
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *course_info_label;
    QLabel *placeholder_image;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *full_course_name;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *course_id_label1;
    QLabel *course_id_label2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *course_name_label1;
    QLabel *course_name_label2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *class_name_label1;
    QLabel *class_name_label2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *teacher_name_label1;
    QLabel *teacher_name_label2;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *credits_label1;
    QLabel *credits_label2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *max_student_label1;
    QLabel *max_student_label2;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QLabel *session_label1;
    QLabel *session_label2;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CourseInfoWindow)
    {
        if (CourseInfoWindow->objectName().isEmpty())
            CourseInfoWindow->setObjectName("CourseInfoWindow");
        CourseInfoWindow->resize(480, 591);
        verticalLayout_4 = new QVBoxLayout(CourseInfoWindow);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        course_info_label = new QLabel(CourseInfoWindow);
        course_info_label->setObjectName("course_info_label");
        course_info_label->setMinimumSize(QSize(0, 40));
        course_info_label->setMaximumSize(QSize(16777215, 40));

        verticalLayout_3->addWidget(course_info_label);

        placeholder_image = new QLabel(CourseInfoWindow);
        placeholder_image->setObjectName("placeholder_image");
        placeholder_image->setMinimumSize(QSize(390, 170));
        placeholder_image->setMaximumSize(QSize(500, 170));

        verticalLayout_3->addWidget(placeholder_image);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        full_course_name = new QLabel(CourseInfoWindow);
        full_course_name->setObjectName("full_course_name");

        horizontalLayout_8->addWidget(full_course_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        course_id_label1 = new QLabel(CourseInfoWindow);
        course_id_label1->setObjectName("course_id_label1");

        horizontalLayout_7->addWidget(course_id_label1);

        course_id_label2 = new QLabel(CourseInfoWindow);
        course_id_label2->setObjectName("course_id_label2");

        horizontalLayout_7->addWidget(course_id_label2);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        course_name_label1 = new QLabel(CourseInfoWindow);
        course_name_label1->setObjectName("course_name_label1");

        horizontalLayout_6->addWidget(course_name_label1);

        course_name_label2 = new QLabel(CourseInfoWindow);
        course_name_label2->setObjectName("course_name_label2");

        horizontalLayout_6->addWidget(course_name_label2);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        class_name_label1 = new QLabel(CourseInfoWindow);
        class_name_label1->setObjectName("class_name_label1");

        horizontalLayout_5->addWidget(class_name_label1);

        class_name_label2 = new QLabel(CourseInfoWindow);
        class_name_label2->setObjectName("class_name_label2");

        horizontalLayout_5->addWidget(class_name_label2);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        teacher_name_label1 = new QLabel(CourseInfoWindow);
        teacher_name_label1->setObjectName("teacher_name_label1");

        horizontalLayout_4->addWidget(teacher_name_label1);

        teacher_name_label2 = new QLabel(CourseInfoWindow);
        teacher_name_label2->setObjectName("teacher_name_label2");

        horizontalLayout_4->addWidget(teacher_name_label2);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        credits_label1 = new QLabel(CourseInfoWindow);
        credits_label1->setObjectName("credits_label1");

        horizontalLayout_3->addWidget(credits_label1);

        credits_label2 = new QLabel(CourseInfoWindow);
        credits_label2->setObjectName("credits_label2");

        horizontalLayout_3->addWidget(credits_label2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        max_student_label1 = new QLabel(CourseInfoWindow);
        max_student_label1->setObjectName("max_student_label1");

        horizontalLayout_2->addWidget(max_student_label1);

        max_student_label2 = new QLabel(CourseInfoWindow);
        max_student_label2->setObjectName("max_student_label2");

        horizontalLayout_2->addWidget(max_student_label2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        session_label1 = new QLabel(CourseInfoWindow);
        session_label1->setObjectName("session_label1");

        horizontalLayout->addWidget(session_label1);

        session_label2 = new QLabel(CourseInfoWindow);
        session_label2->setObjectName("session_label2");

        horizontalLayout->addWidget(session_label2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_10);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_9->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(CourseInfoWindow);

        QMetaObject::connectSlotsByName(CourseInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *CourseInfoWindow)
    {
        CourseInfoWindow->setWindowTitle(QCoreApplication::translate("CourseInfoWindow", "Dialog", nullptr));
        course_info_label->setText(QCoreApplication::translate("CourseInfoWindow", "TextLabel", nullptr));
        placeholder_image->setText(QString());
        full_course_name->setText(QCoreApplication::translate("CourseInfoWindow", "fullcoursename", nullptr));
        course_id_label1->setText(QCoreApplication::translate("CourseInfoWindow", "Course ID:", nullptr));
        course_id_label2->setText(QCoreApplication::translate("CourseInfoWindow", "CS162", nullptr));
        course_name_label1->setText(QCoreApplication::translate("CourseInfoWindow", "Course Name:", nullptr));
        course_name_label2->setText(QCoreApplication::translate("CourseInfoWindow", "Intro to Comci", nullptr));
        class_name_label1->setText(QCoreApplication::translate("CourseInfoWindow", "Class Name:", nullptr));
        class_name_label2->setText(QCoreApplication::translate("CourseInfoWindow", "23TT2", nullptr));
        teacher_name_label1->setText(QCoreApplication::translate("CourseInfoWindow", "Teacher Name:", nullptr));
        teacher_name_label2->setText(QCoreApplication::translate("CourseInfoWindow", "Dinh Ba Tien", nullptr));
        credits_label1->setText(QCoreApplication::translate("CourseInfoWindow", "Credits:", nullptr));
        credits_label2->setText(QCoreApplication::translate("CourseInfoWindow", "4", nullptr));
        max_student_label1->setText(QCoreApplication::translate("CourseInfoWindow", "Max Student:", nullptr));
        max_student_label2->setText(QCoreApplication::translate("CourseInfoWindow", "50", nullptr));
        session_label1->setText(QCoreApplication::translate("CourseInfoWindow", "Session:", nullptr));
        session_label2->setText(QCoreApplication::translate("CourseInfoWindow", "WED 13:30", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseInfoWindow: public Ui_CourseInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEINFOWINDOW_H
