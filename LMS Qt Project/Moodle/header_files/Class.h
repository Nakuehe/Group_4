#ifndef CLASS_H
#define CLASS_H

#include <string>
#include "LinkedList.h"
#include "Student.h"
#include <QString>
#include <QFileDialog>

struct Class {
    std::string classID;
    LinkedList<Student> students;

    Class(const std::string& classID)
        : classID(classID) {}

    void addStudent(const Student& student){
        students.add(student); //pseudo code
    }

    void removeStudent(const Student& student);

    void readStudentToClass(){
        QString filename = QFileDialog::getOpenFileName(
            nullptr,
            "Open Student File",
            "data",
            "CSV Files (*.csv);;All Files (*)"
        );

        if (filename.isEmpty()) {
            return;
        }

        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        in.readLine();

        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            if (fields.size() == 6){
                std::string studentID = fields[0].toStdString();
                std::string firstName = fields[1].toStdString();
                std::string lastName = fields[2].toStdString();
                std::string gender = fields[3].toStdString();
                std::string dateOfBirth = fields[4].toStdString();
                std::string socialID = fields[5].toStdString();

                this->addStudent(Student(studentID, firstName, lastName, gender, dateOfBirth, socialID));
            }
        }
        file.close();
        return;
    }
};

#endif // CLASS_H
