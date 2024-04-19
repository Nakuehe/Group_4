#ifndef CLASS_H
#define CLASS_H

#include <string>
#include "LinkedList.h"
#include "Student.h"
#include "studentinputdialog.h"
struct Class {
    std::string classID;
    LinkedList<Student> students;

    Class(const std::string& classID)
        : classID(classID) {}

    void addStudent(const Student& student){
        students.add(student); //pseudo code
    }
    void add_a_student2Class()
    {
        STUDENTINPUTDIALOG dialog;
        if (dialog.exec() == QDialog::Accepted)
        {
            Student new_stu;
            new_stu.studentID = dialog.getStudentID().toStdString();
            new_stu.firstName = dialog.getFirstName().toStdString();
            new_stu.lastName = dialog.getLastName().toStdString();
            new_stu.gender = dialog.getGender().toStdString();
            new_stu.dateOfBirth = dialog.getDateofBirth().toStdString();
            new_stu.socialID = dialog.getsocialID().toStdString();
            this->students.addSorted(new_stu);
        }
    }
    void removeStudent(const Student& student);
};

#endif // CLASS_H
