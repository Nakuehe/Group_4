#ifndef SEMESTER_H
#define SEMESTER_H

#include "LinkedList.h"
#include "Course.h"
struct Semester {
    std::string semester;
     std::string end_date, start_date;
    LinkedList<Course> courses;
     //Semester(const std::string& semester, const std::string& start_date, const std::string& end_date)
         //: semester(semester), start_date(start_date), end_date(end_date){}
    Semester(const std::string& semester)
        : semester(semester) {}
//Semester(const std::string& semester, const std::string& start_date, const std::string& end_date)
//       : semester(semester), start_date(start_date), end_date(end_date){}
    void addCourse(const Course& course){
        courses.add(course);
    }
};


#endif // SEMESTER_H

