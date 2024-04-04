#include "Staff.h"
#include "iostream"
#include "LinkedList.h"
void Staff::viewCourses(Semester semester)
{
	for (int i = 0; i < semester.courses.size(); ++i)
	{
		std::cout << "Course " << i + 1 << ":" << std::endl;
		std::cout << semester.courses.get(i).courseID << std::endl;
		std::cout << semester.courses.get(i).courseName << std::endl;
		std::cout << semester.courses.get(i).className << std::endl;
		std::cout << semester.courses.get(i).teacherName << std::endl;
		std::cout << semester.courses.get(i).credits << std::endl;
		std::cout << semester.courses.get(i).maxStudent << std::endl;
		std::cout << semester.courses.get(i).day << std::endl;
		std::cout << semester.courses.get(i).session << std::endl;
		std::cout << std::endl;
	}
}
