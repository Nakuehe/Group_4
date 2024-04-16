#ifndef SEMESTER_H
#define SEMESTER_H
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <string>
#include <QWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include "LinkedList.h"
#include "QInputDialog"
#include "Course.h"
#include "QFormLayout"
#include "LinkedList.h"
#include "Course.h"
struct Semester {
    std::string semester;
     std::string end_date, start_date;
    LinkedList<Course> courses;

     //Semester(const std::string& semester, const std::string& start_date, const std::string& end_date)
         //: semester(semester), start_date(start_date), end_date(end_date){}
    Semester(const std::string& semester)
        : semester(semester) {}
//Semester(const std::string& semester, const std::string& start_date, const std::string& end_date)
//       : semester(semester), start_date(start_date), end_date(end_date){}
    void createCourse()
    {
        QVBoxLayout *layout = new QVBoxLayout;

        QLineEdit *courseIdEdit = new QLineEdit;
        QLineEdit *courseNameEdit = new QLineEdit;
        QLineEdit *classNameEdit = new QLineEdit;
        QLineEdit *teacherNameEdit = new QLineEdit;
        QLineEdit *creditsEdit = new QLineEdit;
        //QLineEdit *maxStudentEdit = new QLineEdit{"50"};
        QComboBox *dayOfWeekComboBox = new QComboBox;
        dayOfWeekComboBox->addItems({"MON", "TUE", "WED", "THU", "FRI", "SAT"});
        QComboBox *sessionComboBox = new QComboBox;
        sessionComboBox->addItems({"S1(07:30)", "S2(09:30)", "S3(13:30)", "S4(15:30)"});
        QPushButton *addCourseButton = new QPushButton("Add Course");
        layout->addWidget(new QLabel("Course ID:"));
        layout->addWidget(courseIdEdit);
        layout->addWidget(new QLabel("Course Name:"));
        layout->addWidget(courseNameEdit);
        layout->addWidget(new QLabel("Class Name:"));
        layout->addWidget(classNameEdit);
        layout->addWidget(new QLabel("Teacher Name:"));
        layout->addWidget(teacherNameEdit);
        layout->addWidget(new QLabel("Credits:"));
        layout->addWidget(creditsEdit);
        //layout->addWidget(new QLabel("Max Students:"));
        //layout->addWidget(maxStudentEdit);
        layout->addWidget(new QLabel("Day of Week:"));
        layout->addWidget(dayOfWeekComboBox);
        layout->addWidget(new QLabel("Session:"));
        layout->addWidget(sessionComboBox);
        dayOfWeekComboBox->addItems({"MON", "TUE", "WED", "THU", "FRI", "SAT"});
        layout->addWidget(addCourseButton);
        std::string courseID_std = courseIdEdit->text().toStdString();
        std::string courseName_std = courseNameEdit->text().toStdString();
        std::string className_std = classNameEdit->text().toStdString();
        std::string teacherName_std = teacherNameEdit->text().toStdString();
        std::string credits_std = creditsEdit->text().toStdString();
        std::string day_std = dayOfWeekComboBox->currentText().toStdString();
        std::string session_std = sessionComboBox->currentText().toStdString();
        Course c = Course(courseID_std,courseName_std,className_std,teacherName_std,credits_std,50,day_std,session_std);
        this->addCourse(c);
        QWidget *widget = new QWidget;
        widget->setLayout(layout);
        widget->show();
    }



    void addCourse(const Course& course){
        courses.add(course);
    }

    void removeCourse(const Course& course){
        courses.remove(course);
    }

    Node<Course>* Find_Course();
    //void Update_Student_Result();
};


#endif // SEMESTER_H

