#ifndef COURSE_H
#define COURSE_H
#include "studentinputdialog.h"
#include <string>
#include "LinkedList.h"
#include "Score.h"
#include"Student.h"
#include "QInputDialog"
#include <QVBoxLayout>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include "courseinputdialog.h"
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
        if(this->students.size()>=this->maxStudent) return;
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
            this->students.add(new_stu);
        }
    }
    void updateCourseInfo()
    {
        COURSEINPUTDIALOG dialog;
        dialog.courseIDEdit->setText(QString::fromStdString(this->courseID));
        dialog.courseNameEdit->setText(QString::fromStdString(this->courseName));
        dialog.classNameEdit->setText(QString::fromStdString(this->className));
        dialog.teacherNameEdit->setText(QString::fromStdString(this->teacherName));
        dialog.creditsEdit->setText(QString::fromStdString(this->credits));
        dialog.maxStudentsEdit->setText(QString::number(this->maxStudent));
        dialog.DayComboBox->setCurrentText(QString::fromStdString(this->day));
        //int index = dialog.DayComboBox->findText(QString::fromStdString(this->day), Qt::MatchExactly);
        //if (index != -1)

        //    dialog.DayComboBox->setCurrentIndex(index);
        dialog.SessionComboBox->setCurrentText(QString::fromStdString(this->session));
        //    int rindex = dialog.SessionComboBox->findText(QString::fromStdString(this->session), Qt::MatchExactly);
        //    if (rindex != -1)
        //        dialog.SessionComboBox->setCurrentIndex(rindex);
        if (dialog.exec() == QDialog::Accepted)
        {
            this->courseID = dialog.getCourseID().toStdString();
            this->courseName = dialog.getCourseName().toStdString();
            this->className = dialog.getClassName().toStdString();
            this->teacherName = dialog.getTeacherName().toStdString();
            this->credits = dialog.getcredits().toStdString();
            this->maxStudent = dialog.getMaxStudent().toInt();
            this->day = dialog.getDay().toStdString();
            this->session = dialog.getSession().toStdString();
        }
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
    void remove_a_studentFromCourse()
    {
        QString studentID = QInputDialog::getText(nullptr, "Input student ID removed", "Enter student ID:");
        std::string studentID_std = studentID.toStdString();
        for(int i=0;i<this->students.size();i++)
        {
            if(this->students.get(i).studentID==studentID_std)
            {
                this->students.remove(this->students.get(i));
            }
        }
    }
    void addScore(const Score& score) {
        Scoreboard.add(score); 
    }  

    void ExportStudentCSVFile();
};

#endif // COURSE_H
