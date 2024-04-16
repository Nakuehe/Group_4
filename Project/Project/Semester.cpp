#include "Semester.h"
#include <iostream>
/*void Semester::createSemester(SchoolYear& sy(), Semester& s())
{
    std::cout << "Input start date:";
    getline(std::cin, s().start_date); 
    std::cin.ignore();
    std::cout << "Input end date:";
    getline(std::cin, s().end_date);
    sy().addSemester(s());
}
*/
void Semester::createCourse(Semester& se())
{
    CourseInfo c;
    std::cout << "Input course ID:";
    std::getline(std::cin, c.courseID);
    std::cout << "Input course Name:";
    std::getline(std::cin, c.courseName);
    std::cout << "Input class Name:";
    std::getline(std::cin, c.className);
    std::cout << "Input teacher Name:";
    std::getline(std::cin, c.teacherName);
    std::cout << "Input credits:";
    std::getline(std::cin, c.credits);
    std::cout << "Input max Students:";
    std::cin >> c.maxStudent;
    std::cout << "Input course day (MON / TUE / WED / THU / FRI / SAT) : ";
    std::getline(std::cin, c.day);
    std::cout << "Input course session (S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)) : ";
    std::getline(std::cin, c.session);
} 