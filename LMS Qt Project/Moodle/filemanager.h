#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <string>
#include "Student.h" // Assuming you have these classes defined
#include "Course.h"
#include "Class.h"
#include "Semester.h"
#include "SchoolYear.h"

struct Score;

class FileManager {
public:
    void readStudentToCourse(const QString& filename, Course* this_course) {
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

                this_course->addStudent(Student(studentID, firstName, lastName, gender, dateOfBirth, socialID));
            }
        }
        file.close();
        return;
    }

    void readCourseToSemester(const QString& filename, Semester* this_semester) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        in.readLine(); // Skip the header line

        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            if (fields.size() == 8){
                std::string courseID = fields[0].toStdString();
                std::string courseName = fields[1].toStdString();
                std::string classID = fields[2].toStdString();
                std::string lecturerName = fields[3].toStdString();
                std::string creditNumber = fields[4].toStdString();
                int maxNumberOfStudents = fields[5].toInt();
                std::string dayOfWeek = fields[6].toStdString();
                std::string session = fields[7].toStdString();

                Course course = Course(courseID, courseName, classID, lecturerName, creditNumber, maxNumberOfStudents, dayOfWeek, session);
                this_semester->addCourse(course);
            }
        }
        file.close();
    }

    void readClassToSchoolYear(const QString& filename, SchoolYear* this_schoolyear) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        in.readLine(); // Skip the header line

        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            if (fields.size() == 1){
                std::string classID = fields[0].toStdString();

                Class new_class = Class(classID);
                this_schoolyear->addClass(new_class);
            }
        }
        file.close();
    }

    void readSemesterToSchoolYear(const QString& filename, SchoolYear* this_schoolyear) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        in.readLine(); // Skip the header line

        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            if (fields.size() == 3){
                std::string semesterID = fields[0].toStdString();
                std::string startDate = fields[1].toStdString();
                std::string endDate = fields[2].toStdString();

                Semester new_semester = Semester(semesterID, startDate, endDate);

                this_schoolyear->addSemester(new_semester);
            }
        }
        file.close();
    }

    void readStudentToClass(const QString& filename, Class* this_class){
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

                this_class->addStudent(Student(studentID, firstName, lastName, gender, dateOfBirth, socialID));
            }
        }
        file.close();
        return;
    }

    void readScoreboardToCourse(const QString& filename, Course* this_course) {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
 
        QTextStream in(&file);
        in.readLine(); // Skip the header line

        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            if (fields.size() == 5){
                std::string studentID = fields[0].toStdString();
                std::string fullName = fields[1].toStdString();
                float midterm = fields[2].toFloat();
                float final = fields[3].toFloat();
                float other = fields[4].toFloat();

                this_course->addScore(Score(studentID, fullName, this_course->courseID, this_course->courseName, midterm, final, other));
            }
        }
        file.close();
    }

    void readSchoolYearToYears(const QString& filename){
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        in.readLine(); // Skip the header line

        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            if (fields.size() == 1){
                std::string year = fields[0].toStdString();

                SchoolYear new_year = SchoolYear(year);
                SchoolYears->add(new_year);
            }
        }
        file.close();
    }



    // Similar methods can be implemented for Course, Score, Class, Semester, SchoolYear

    void writeStudentsToCourse(const QString& filename, Course* this_course) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "StudentID,FirstName,LastName,Gender,DateOfBirth,SocialID\n";

        Node<Student>* temp = this_course->students.getHead();
        while (temp != nullptr)
        {
            out << QString::fromStdString(temp->data.studentID) << ",";
            out << QString::fromStdString(temp->data.firstName) << ",";
            out << QString::fromStdString(temp->data.lastName) << ",";
            out << QString::fromStdString(temp->data.gender) << ",";
            out << QString::fromStdString(temp->data.dateOfBirth) << ",";
            out << QString::fromStdString(temp->data.socialID) << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void writeCourseToSemester(const QString& filename, Semester* this_semester) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "CourseID,CourseName,ClassID,LecturerName,CreditNumber,MaxNumberOfStudents,DayOfWeek,Session\n";

        Node<Course>* temp = this_semester->courses.getHead();
        while (temp != nullptr)
        {
            out << QString::fromStdString(temp->data.courseID) << ",";
            out << QString::fromStdString(temp->data.courseName) << ",";
            out << QString::fromStdString(temp->data.className) << ",";
            out << QString::fromStdString(temp->data.teacherName) << ",";
            out << QString::fromStdString(temp->data.credits) << ",";
            out << temp->data.maxStudent << ",";
            out << QString::fromStdString(temp->data.day) << ",";
            out << QString::fromStdString(temp->data.session) << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void writeClassToSchoolYear(const QString& filename, SchoolYear* this_schoolyear) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "ClassID\n";

        Node<Class>* temp = this_schoolyear->classes.getHead();
        while (temp != nullptr)
        {
            out << QString::fromStdString(temp->data.classID) << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void writeSemesterToSchoolYear(const QString& filename, SchoolYear* this_schoolyear) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "SemesterID,StartDate,EndDate\n";

        Node<Semester>* temp = this_schoolyear->semesters.getHead();
        while (temp != nullptr)
        {
            out << QString::fromStdString(temp->data.semester) << ",";
            out << QString::fromStdString(temp->data.start_date) << ",";
            out << QString::fromStdString(temp->data.end_date) << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void writeStudentsToClass(const QString& filename, Class* this_class) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "StudentID,FirstName,LastName,Gender,DateOfBirth,SocialID\n";

        Node<Student>* temp = this_class->students.getHead();
        while (temp != nullptr)
        {
            out << QString::fromStdString(temp->data.studentID) << ",";
            out << QString::fromStdString(temp->data.firstName) << ",";
            out << QString::fromStdString(temp->data.lastName) << ",";
            out << QString::fromStdString(temp->data.gender) << ",";
            out << QString::fromStdString(temp->data.dateOfBirth) << ",";
            out << QString::fromStdString(temp->data.socialID) << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void writeScoreboardToCourse(const QString& filename, Course* this_course) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "StudentID,FullName,Midterm,Final,Other\n";

        Node<Score>* temp = this_course->Scoreboard.getHead();
        while (temp != nullptr)
        {
            out << QString::fromStdString(temp->data.id_student) << ",";
            out << QString::fromStdString(temp->data.fullName) << ",";
            out << temp->data.mid_mark << ",";
            out << temp->data.final_mark << ",";
            out << temp->data.other_mark << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void writeSchoolYearToYears(const QString& filename){
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "Year\n";

        Node<SchoolYear>* temp = SchoolYears->getHead();
        while (temp != nullptr)
        {
            out << QString::fromStdString(temp->data.year) << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void loadData(){
        QString fileName = QString("%1/SchoolYears.csv").arg(QString::fromStdString(prefix_filename));
        readSchoolYearToYears(fileName);
        Node<SchoolYear>* temp = SchoolYears->getHead();
        while(temp != nullptr){
            fileName = QString("%1/%2-Classes.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year));
            readClassToSchoolYear(fileName, &temp->data);
            Node<Class>* temp1 = temp->data.classes.getHead();
            while(temp1 != nullptr){
                fileName = QString("%1/%2-%3-Students.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year)).arg(QString::fromStdString(temp1->data.classID));
                readStudentToClass(fileName, &temp1->data);
                temp1 = temp1->next;
            }
            fileName = QString("%1/%2-Semesters.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year));
            readSemesterToSchoolYear(fileName, &temp->data);
            Node<Semester>* temp2 = temp->data.semesters.getHead();
            while(temp2 != nullptr){
                fileName = QString("%1/%2-%3-Courses.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year)).arg(QString::fromStdString(temp2->data.semester));
                readCourseToSemester(fileName, &temp2->data);
                Node<Course>* temp3 = temp2->data.courses.getHead();
                while(temp3 != nullptr){
                    fileName = QString("%1/%2-%3-%4-Students.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year)).arg(QString::fromStdString(temp3->data.courseID)).arg(QString::fromStdString(temp3->data.className));
                    readStudentToCourse(fileName, &temp3->data);
                    fileName = QString("%1/%2-%3-%4-Scoreboard.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year)).arg(QString::fromStdString(temp3->data.courseID)).arg(QString::fromStdString(temp3->data.className));
                    readScoreboardToCourse(fileName, &temp3->data);
                    temp3 = temp3->next;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    void saveData(){
        QString fileName = QString("%1/SchoolYears.csv").arg(QString::fromStdString(prefix_filename));
        writeSchoolYearToYears(fileName);
        Node<SchoolYear>* temp = SchoolYears->getHead();
        while(temp != nullptr){
            fileName = QString("%1/%2-Classes.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year));
            writeClassToSchoolYear(fileName, &temp->data);
            Node<Class>* temp1 = temp->data.classes.getHead();
            while(temp1 != nullptr){
                fileName = QString("%1/%2-%3-Students.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year)).arg(QString::fromStdString(temp1->data.classID));
                writeStudentsToClass(fileName, &temp1->data);
                temp1 = temp1->next;
            }
            fileName = QString("%1/%2-Semesters.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year));
            writeSemesterToSchoolYear(fileName, &temp->data);
            Node<Semester>* temp2 = temp->data.semesters.getHead();
            while(temp2 != nullptr){
                fileName = QString("%1/%2-%3-Courses.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year)).arg(QString::fromStdString(temp2->data.semester));
                writeCourseToSemester(fileName, &temp2->data);
                Node<Course>* temp3 = temp2->data.courses.getHead();
                while(temp3 != nullptr){
                    fileName = QString("%1/%2-%3-%4-Students.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year)).arg(QString::fromStdString(temp3->data.courseID)).arg(QString::fromStdString(temp3->data.className));
                    writeStudentsToCourse(fileName, &temp3->data);
                    fileName = QString("%1/%2-%3-%4-Scoreboard.csv").arg(QString::fromStdString(prefix_filename)).arg(QString::fromStdString(temp->data.year)).arg(QString::fromStdString(temp3->data.courseID)).arg(QString::fromStdString(temp3->data.className));
                    writeScoreboardToCourse(fileName, &temp3->data);
                    temp3 = temp3->next;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }

    FileManager(const std::string& prefix_filename, LinkedList<SchoolYear>* SchoolYears) : prefix_filename(prefix_filename), SchoolYears(SchoolYears){}

    void deleteData(){
        // Iterate over all SchoolYear objects in SchoolYears
        while (!SchoolYears->isEmpty()) {
            SchoolYear year = SchoolYears->removeFirst();

            // Iterate over all Semester objects in each SchoolYear
            while (!year.semesters.isEmpty()) {
                Semester semester = year.semesters.removeFirst();

                // Iterate over all Course objects in each Semester
                while (!semester.courses.isEmpty()) {
                    Course course = semester.courses.removeFirst();

                    // Iterate over all Student objects in each Course
                    while (!course.students.isEmpty()) {
                        course.students.removeFirst();
                    }

                    while(!course.Scoreboard.isEmpty()){
                        course.Scoreboard.removeFirst();
                    }
                }
            }

            while(!year.classes.isEmpty()){
                Class this_class = year.classes.removeFirst();

                while(!this_class.students.isEmpty()){
                    this_class.students.removeFirst();
                }
            }
        }
    }
    

    // Similar methods can be implemented for Course, Score, Class, Semester, SchoolYear

private:
    LinkedList<SchoolYear>* SchoolYears;
    std::string prefix_filename;
};

#endif // FILEMANAGER_H
