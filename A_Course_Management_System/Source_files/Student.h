#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Student.h"
#include <string>
#include <vector>

struct Student : public User {
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string gender;
    std::string dateOfBirth;
    std::string socialID;
    // LinkedList<Course> courses;

    Student(const std::string& username, const std::string& password, const std::string& studentID, const std::string& firstName, const std::string& lastName, const std::string& gender, const std::string& dateOfBirth, const std::string& socialID)
        : User(username, password), studentID(studentID), firstName(firstName), lastName(lastName), gender(gender), dateOfBirth(dateOfBirth), socialID(socialID) {}

    void viewCourses();

    void viewScoreboard();

    
};

#endif // STUDENT_H