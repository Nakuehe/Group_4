#ifndef SEMESTER_H
#define SEMESTER_H

#include "LinkedList.h"
#include "Course.h"

struct Semester {
    std::string semester;
    LinkedList<Course> courses;

    Semester(const std::string& semester)
        : semester(semester) {}

    void createSemester();
    void addCourse(const Course& course){
        courses.add(course);
    }
    Node<Course>* Find_Course();
    void Update_Student_Result();
};


#endif // SEMESTER_H
