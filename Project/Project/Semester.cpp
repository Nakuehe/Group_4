#include "Semester.h"
#include <iostream>
void Semester::createSemester(SchoolYear& sy(), Semester& s())
{
    std::cout << "Input start date:";
    getline(std::cin, s().start_date); 
    std::cin.ignore();
    std::cout << "Input end date:";
    getline(std::cin, s().end_date);
    sy().addSemester(s());
}