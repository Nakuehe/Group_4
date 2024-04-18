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
#include "fontloader.h"
#include <QMessageBox>
#include <QComboBox>
#include <QDialog>

#include "courseinputdialog.h"
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

        this->deleteThisStudentList();
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
        if(this->students.size()>=this->maxStudent){
            QMessageBox::warning(nullptr, "Warning", "The course is full.");
            return;
        }

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
        dialog.setWindowTitle("Update Course Information");
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
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(nullptr, "Confirmation", "Are you sure you want to update this course?", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                this->courseID = dialog.getCourseID().toStdString();
                this->courseName = dialog.getCourseName().toStdString();
                this->className = dialog.getClassName().toStdString();
                this->teacherName = dialog.getTeacherName().toStdString();
                this->credits = dialog.getcredits().toStdString();
                this->maxStudent = dialog.getMaxStudent().toInt();
                this->day = dialog.getDay().toStdString();
                this->session = dialog.getSession().left(2).toStdString();

                QMessageBox::information(nullptr, "Confirmation", "Course information updated successfully.");
            }
        }
    }
   //bool operator==(const Course&other) const{
     //   return courseID == other.courseID;
    //}
    //bool operator!=(const Course&other) const{
       // return !(*this==other);
    //}
    void removeStudent(const Student& student) {
        students.remove(student);
    }

    void remove_a_studentFromCourse()
    {
        QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
        QFont font(fontFamily1, 14);


        QComboBox* studentComboBox = new QComboBox();
        for (int i = 0; i < this->students.size(); i++) {
            Student& student = this->students.get(i);
            QString studentInfo = QString::fromStdString(student.studentID + " - " + student.getStudentFullName());
            studentComboBox->addItem(studentInfo, QString::fromStdString(student.studentID));
        }
    
        QDialog dialog;
        dialog.setFont(font);
        QVBoxLayout layout(&dialog);
        layout.addWidget(studentComboBox);
        QPushButton okButton("OK");
        layout.addWidget(&okButton);
        QObject::connect(&okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    
        if (dialog.exec() == QDialog::Accepted) {
            QString selectedStudentID = studentComboBox->currentData().toString();
            std::string selectedStudentID_std = selectedStudentID.toStdString();
            for (int i = 0; i < this->students.size(); i++) {
                Student student = this->students.get(i);
                if (student.studentID == selectedStudentID_std) {
                    QMessageBox::StandardButton reply;
                    reply = QMessageBox::warning(nullptr, "Confirmation", "Are you sure you want to remove this student?", QMessageBox::Yes|QMessageBox::No);
                    if (reply == QMessageBox::Yes) {
                        this->students.remove(student);
                        break;
                    }
                }
            }
        }
    
        delete studentComboBox;
    }


    void addScore(const Score& score) {
        Scoreboard.add(score);
    }

    void deleteThisStudentList();
    void ExportStudentCSVFile();

    void Export_Scoreboard_Form();
    void Import_Scoreboard_To();
    void updateStudentResult();
};

#endif // COURSE_H
