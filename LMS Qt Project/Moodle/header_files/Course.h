#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "LinkedList.h"
#include "Score.h"
#include"Student.h"

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

    void removeStudent(const Student& student) {
        students.remove(student); 
    }

    void addScore(const Score& score) {
        Scoreboard.add(score); 
    }  

    void updateCourseInfo();
    void ExportStudentCSVFile();
    void Export_Scoreboard_Form();
};

#endif // COURSE_H
