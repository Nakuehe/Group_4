#ifndef SEMESTER_H
#define SEMESTER_H
#include "QInputDialog"
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
        QString courseID = QInputDialog::getText(nullptr, "Input course ID", "Enter course ID:");
        std::string courseID_std = courseID.toStdString();
        QString courseName = QInputDialog::getText(nullptr, "Input course Name", "Enter course Name:");
        std::string courseName_std = courseName.toStdString();
        //Co the tao list cac lop co the chon
        QString className = QInputDialog::getText(nullptr, "Input class Name", "Enter class Name:");
        std::string className_std = className.toStdString();
        QString teacherName = QInputDialog::getText(nullptr, "Input teacher Name", "Enter teacher Name:");
        std::string teacherName_std = teacherName.toStdString();
        QString credits = QInputDialog::getText(nullptr, "Input course ID", "Enter course credits:");
        std::string credits_std = credits.toStdString();
        QStringList daysOfWeek = {"MON", "TUE", "WED", "THU", "FRI", "SAT"};
        QString selectedDay = QInputDialog::getItem(nullptr, "Input", "Select Day of Week:", daysOfWeek);
        std::string day_std = selectedDay.toStdString();
        QStringList timeOfDay = {"S1(07:30)","S2(09:30)","S3(13:30)","S4(15:30)"};
        QString selectedTime = QInputDialog::getItem(nullptr,"Input", "Select Time of Day:", timeOfDay);
        std::string session_std = selectedTime.toStdString();
        Course c = Course(courseID_std,courseName_std,className_std,teacherName_std,credits_std,50,day_std,session_std);
        this->addCourse(c);
    }


    void addCourse(const Course& course){
        courses.add(course);
    }
};


#endif // SEMESTER_H

