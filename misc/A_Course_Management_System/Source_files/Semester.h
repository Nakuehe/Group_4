#ifndef SEMESTER_H
#define SEMESTER_H

#include <string>
#include <vector>
#include "LinkedList.h"
#include "Course.h"

struct Semester {
    std::string semester;
    LinkedList<Course> courses;

    Semester(const std::string& semester)
        : semester(semester) {}

    void createSemester();
    void addCourse(const std::string& course);
    void viewCourses() const;
};


#endif // SEMESTER_H