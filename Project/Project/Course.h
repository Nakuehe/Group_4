#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "LinkedList.h"
#include "Score.h"
#include"Student.h"
#include "Semester.h"
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

    Course(const std::string& courseID, const std::string& courseName, const std::string& className, const std::string& teacherName, const std::string& credits, int maxStudent, const std::string& day, const std::string& session)
        : CourseInfo(courseID, courseName, className, teacherName, credits, maxStudent, day, session) {}

    void addStudent(const Student& student) {
        students.add(student); 
    }

    void removeStudent(const Student& student) {
        students.remove(student); 
    }
    void read_Students_from_CSV();
    void updateCourseInfo(Semester& semester, int k);
    void delete_a_Course(Semester& semester);
};

#endif // COURSE_H
