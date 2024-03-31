#ifndef SEMESTER_H
#define SEMESTER_H

#include "LinkedList.h"
#include "Course.h"
#include "SchoolYear.h" //.
struct Semester {
    std::string semester;
    LinkedList<Course> courses;
    std::string end_date, start_date;//.
    Semester(const std::string& semester)
        : semester(semester) {}

    void createSemester(SchoolYear& sy(), Semester& s());//.
    void addCourse(const Course& course){
        courses.add(course);
    }
};


#endif // SEMESTER_H
