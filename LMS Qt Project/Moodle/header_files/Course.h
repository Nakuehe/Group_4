#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "LinkedList.h"
#include "Score.h"
#include"Student.h"
#include "QInputDialog"
#include <QVBoxLayout>
#include <QLabel>
#include <QFile>
#include <QTextStream>
struct CourseInfo {
    std::string year;
    std::string semester;
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
    void read_students_from_CSV(const QString& filename)
    {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning() << "Error opening file:" << filename;
            return;
        }
        QTextStream in(&file);
        //in.setCodec("UTF-8");
        in.readLine();

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList studentData = line.split(',');

            if (studentData.size() != 6) {
                qWarning() << "Invalid data format in line:" << line;
                continue;
            }
            std::string studentID_std = studentData[0].toStdString();
            std::string firstName_std = studentData[1].toStdString();
            std::string lastName_std = studentData[2].toStdString();
            std::string gender_std = studentData[3].toStdString();
            std::string dateOfBirth_std = studentData[4].toStdString();
            std::string socialID_std = studentData[5].toStdString();
            Student student;
            student.studentID = studentID_std;
            student.firstName = firstName_std;
            student.lastName = lastName_std;
            student.gender = gender_std;
            student.dateOfBirth = dateOfBirth_std;
            student.socialID = socialID_std;

            students.add(student);
        }

        file.close();
    }
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
    bool operator==(const Course&other) const{
        return courseID == other.courseID;
    }
    bool operator!=(const Course&other) const{
        return !(*this==other);
    }
    void removeStudent(const Student& student) {
        students.remove(student); 
    }

    void addScore(const Score& score) {
        Scoreboard.add(score);
    }

    bool operator==(const Course& other) const {
        return courseID == other.courseID;
    }

    bool operator!=(const Course& other) const {
        return !(*this == other);
    }

    void updateCourseInfo();
    void ExportStudentCSVFile();
    void Export_Scoreboard_Form();
    void Import_Scoreboard_To();
    void updateStudentResult();
};

#endif // COURSE_H
