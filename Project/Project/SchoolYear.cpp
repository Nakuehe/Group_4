#include "SchoolYear.h"
#include <iostream>
void SchoolYear::createYear(SchoolYear& sy())
{
    Semester news();
    std::string s;
    std::cout << "Input start date:";
    std::getline(std::cin, s);
    news().start_date = s;
    std::cin.ignore();
    std::cout << "Input end date:";
    std::getline(std::cin, s);
    news().end_date = s;
    sy().addSemester(news());
}
