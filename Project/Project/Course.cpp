#include "Course.h"
#include <iostream>
void Course::updateCourseInfo(Semester& semester, int k)
{
	std::cout << "1.Course ID:" << semester.courses.get(k).courseID << std::endl; 
	std::cout << "2.Course Name:" << semester.courses.get(k).courseName << std::endl;
	std::cout << "3.Class Name:" << semester.courses.get(k).className << std::endl;
	std::cout << "4.Teacher Name:" << semester.courses.get(k).teacherName << std::endl;
	std::cout << "5.Course Credits:" << semester.courses.get(k).credits << std::endl;
	std::cout << "6.Max Students:" << semester.courses.get(k).maxStudent << std::endl;
	std::cout << "7.Course Day:" << semester.courses.get(k).day << std::endl;
	std::cout << "8.Course session:" << semester.courses.get(k).session << std::endl;
	std::cout << "Input number you want to change:"; int sel;
	std::cin >> sel;
	switch (sel)
	{
	case 1:
	{
		std::cout << "Input a new ID:";
		std::string new_info;
		getline(std::cin, new_info);
		semester.courses.get(k).courseID = new_info;
		break;
	}
	case 2:
	{
		std::cout << "Input a new Name:";
		std::string new_info;
		getline(std::cin, new_info);
		semester.courses.get(k).courseName = new_info;
		break;
	}
	case 3:
	{
		std::cout << "Input a new ID:";
		std::string new_info;
		getline(std::cin, new_info);
		semester.courses.get(k).className = new_info;
		break;
	}
	case 4:
	{
		std::cout << "Input a new ID:";
		std::string new_info;
		getline(std::cin, new_info);
		semester.courses.get(k).teacherName = new_info;
		break;
	}
	case 5:
	{
		std::cout << "Input a new ID:";
		std::string new_info;
		getline(std::cin, new_info);
		semester.courses.get(k).credits = new_info;
		break;
	}
	case 6:
	{
		std::cout << "Input new max students:";
		int n;
		std::cin >> n;
		semester.courses.get(k).maxStudent = n;
		break;
	}
	case 7:
	{
		std::cout << "Input a new ID:";
		std::string new_info;
		getline(std::cin, new_info);
		semester.courses.get(k).day = new_info;
		break;
	}
	case 8:
	{
		std::cout << "Input a new ID:";
		std::string new_info;
		getline(std::cin, new_info);
		semester.courses.get(k).session = new_info;
		break;
	}
	default:
	{
		std::cout << "Input is false!!";
		return;
	}
	}
}
