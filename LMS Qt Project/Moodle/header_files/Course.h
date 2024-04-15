#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "LinkedList.h"
#include "Score.h"
#include"Student.h"
#include "QInputDialog"
#include <QVBoxLayout>
#include <QLabel>
struct CourseInfo {
    std::string courseID;
    std::string courseName;
    std::string className;
    std::string teacherName;
    std::string credits;
    int maxStudent;
    std::string day;
    std::string session;

    CourseInfo() : courseID(""), courseName(""), className(""), teacherName(""), credits(""), maxStudent(0), day(""), session("") {}

    CourseInfo(const std::string& courseID, const std::string& courseName, const std::string& className, const std::string& teacherName, const std::string& credits, int maxStudent, const std::string& day, const std::string& session)
        : courseID(courseID), courseName(courseName), className(className), teacherName(teacherName), credits(credits), maxStudent(maxStudent), day(day), session(session) {}
};

struct Course : public CourseInfo {
    LinkedList<Student> students;
    LinkedList<Score> Scoreboard;

    Course() : CourseInfo(){};

    Course(const std::string& courseID, const std::string& courseName, const std::string& className, const std::string& teacherName, const std::string& credits, int maxStudent, const std::string& day, const std::string& session)
        : CourseInfo(courseID, courseName, className, teacherName, credits, maxStudent, day, session) {}

    void addStudent(const Student& student) {
        students.add(student); 
    }
    void add_a_student2Course()
    {
        QVBoxLayout *layout = new QVBoxLayout;

        QLineEdit *studentIdEdit = new QLineEdit;
        QLineEdit *firstNameEdit = new QLineEdit;
        QLineEdit *lastNameEdit = new QLineEdit;
        QLineEdit *genderEdit = new QLineEdit;
        QLineEdit *dayOfBirthEdit = new QLineEdit;
        QLineEdit *socialIdEdit = new QLineEdit;
        layout->addWidget(new QLabel("Student ID:"));
        layout->addWidget(studentIdEdit);
        layout->addWidget(new QLabel("First Name:"));
        layout->addWidget(firstNameEdit);
        layout->addWidget(new QLabel("Last Name:"));
        layout->addWidget(lastNameEdit);
        layout->addWidget(new QLabel("Gender:"));
        layout->addWidget(genderEdit);
        layout->addWidget(new QLabel("Day of birth:"));
        layout->addWidget(dayOfBirthEdit);
        layout->addWidget(new QLabel("Social ID:"));
        layout->addWidget(socialIdEdit);
        std::string studentID_std = studentIdEdit->text().toStdString();
        std::string firstName_std = firstNameEdit->text().toStdString();
        std::string lastName_std = lastNameEdit->text().toStdString();
        std::string gender_std = genderEdit->text().toStdString();
        std::string dayOfBirth_std = dayOfBirthEdit->text().toStdString();
        std::string socialID_std = socialIdEdit->text().toStdString();
        Student s(studentID_std,firstName_std,lastName_std,gender_std,dayOfBirth_std,socialID_std);
        students.add(s);
        QWidget *widget = new QWidget;
        widget->setLayout(layout);
        widget->show();
    }
    void removeStudent(const Student& student) {
        students.remove(student); 
    }

    void addScore(const Score& score) {
        Scoreboard.add(score); 
    }  

    void updateCourseInfo();
    void ExportStudentCSVFile();
};

#endif // COURSE_H
