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
#include "QFormLayout"
#include "LinkedList.h"
#include "Course.h"
#include "courseinputdialog.h"
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
        COURSEINPUTDIALOG dialog;
        if (dialog.exec() == QDialog::Accepted)
        {
            Course new_course;
            new_course.courseID = dialog.getCourseID().toStdString();
            new_course.courseName = dialog.getCourseName().toStdString();
            new_course.className = dialog.getClassName().toStdString();
            new_course.teacherName = dialog.getTeacherName().toStdString();
            new_course.credits = dialog.getcredits().toStdString();
            new_course.maxStudent = dialog.getMaxStudent().toInt();
            new_course.day = dialog.getDay().toStdString();
            new_course.session = dialog.getSession().left(2).toStdString();

            this->addCourse(new_course);
        }
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

