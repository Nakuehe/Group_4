#include <string> 
#include "Course.h"
#include "Student.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>

void Course::ExportStudentCSVFile()
{
  
	std::cout << "The Course Student list is exported to " << courseName + ".csv" << "\n";
	std::ofstream fout((courseName + ".csv").c_str());
	Node<Student>* temp = students.getHead();
	while (temp != nullptr)
	{
		fout << temp->data.studentID << ",";
		fout << temp->data.firstName << ",";
		fout << temp->data.lastName << " ";
		fout << temp->data.gender << ",";
		fout << temp->data.dateOfBirth << ",";
		fout << temp->data.socialID << "\n";
		temp = temp->next;
	}
	fout.close();
}