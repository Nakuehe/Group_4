#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "LinkedList.h"
#include "Student.h"
#include "Score.h"

struct Course {
    std::string courseID;
    std::string courseName;
    LinkedList<Student> students;
    LinkedList<Score> Scoreboard;

    Course(const std::string& courseID, const std::string& courseName)
        : courseID(courseID), courseName(courseName) {}

    void addStudent(const Student& student) {
        students.add(student); //pseudo code
    }

    void removeStudent(const Student& student) {
        students.remove(student); // pseudo code
    }

    void updateCourseInfo();
};

#endif // COURSE_H