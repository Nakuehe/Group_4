#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <sys/stat.h>
#include <direct.h>
#include "Display.h"
#include "SchoolYear.h"

void School_year::deleteClassList()
{
	while (class_list)
	{
		Class* temp = class_list;
		temp->deleteStudentList();
		class_list = class_list->next;
		delete temp;
	}
}

void School_year::create_schoolyear()
{
	// create folder school year
	if (_mkdir(year.c_str()) == -1)
		return;
	else
		std::cout << "Successfully creating new school year \n";
	// create file class for this schoolyear
	std::string file_name = year + "/" + year + "-class.csv";
	std::ofstream fout_1(file_name);
	fout_1.close();
	// create file semester for this schoolyear
	std::string semester_file = year + "/" + year + "-semester.csv";
	std::ofstream fout_semester(semester_file);
	fout_semester.close();
}

void School_year::saveClassList()
{
	std::string temp = year + "/" + year + "-class.csv";
	std::ofstream fout(temp);
	Class* curr = class_list;
	while (curr)
	{
		fout << curr->classname << '\n';
		curr = curr->next;
	}
	fout.close();
}

void School_year::loadClassList()
{
	std::string temp = year + "/" + year + "-class.csv";
	std::ifstream fin(temp);
	if (fin)
	{
		while (fin.peek() != EOF)
		{
			std::string tempName;
			std::getline(fin, tempName, '\n');
			if (tempName.length() == 0)
				continue;
			Class* temp_class = new Class();
			temp_class->classname = tempName;
			temp_class->insertStudentList(year);
			temp_class->next = class_list;
			class_list = temp_class;
		}
	}
	fin.close();
}

void School_year::create_class()
{
	std::cout << "Enter name of class: ";
	std::string tempClass;
	std::getline(std::cin, tempClass, '\n');
	for (int i = 0; i < tempClass.length(); ++i)
		if (tempClass[i] < '0' || (tempClass[i] > '9' && tempClass[i] < 'A') || (tempClass[i] > 'Z' && tempClass[i] < 'a') || tempClass[i] > 'z')
		{
			std::cout << "Invalid format. Please enter again\n";
			return;
		}
	Class* curr = class_list;
	while (curr)
	{
		if (curr->classname == tempClass)
		{
			std::cout << "Existent class\n";
			return;
		}
		if (curr->next == nullptr)
			break;
		curr = curr->next;
	}
	// create new class
	Class* new_class = new Class();
	new_class->classname = tempClass;
	if (curr)
		curr->next = new_class;
	else
		class_list = new_class;
	std::ofstream fout((year + "/" + tempClass + "-student.csv").c_str());
	fout.close();
}

void School_year::addClass()
{
	std::string choice;
	do {
		create_class();
		std::cout << "[1] Continue adding class\n";
		std::cout << "[0] Stop\n";
		getChoice(choice);
	} while (choice == "1");
	saveClassList();
}

void School_year::addStudentClass(Class*& curr_class)
{
	std::string choice;
	std::cout << "[1] Input student one by one\n";
	std::cout << "[2] Input students from CSV file\n";
	std::cout << "[3] Back\n";
	getChoice(choice);
	if (choice == "1")
	{
		std::string Y;
		do
		{
			curr_class->loadStudentList_Manual();
			std::cout << "Press [1] to continue adding \n";
			std::cout << "Press [0] to stop \n";
			getChoice(Y);
		} while (Y == "1");
		sortID(curr_class->student_list);
		curr_class->saveStudentList(year);
	}
	else if (choice == "2")
	{
		std::string fileName;
		std::cout << "Enter path of file CSV students: ";
		std::getline(std::cin, fileName, '\n');
		if (fileName[0] == '"')
			fileName = fileName.substr(1, fileName.length() - 2);
		std::ifstream fin(fileName.c_str());
		if (fin)
		{
			curr_class->loadStudentList_file(fin);
			sortID(curr_class->student_list);
			curr_class->saveStudentList(year);
		}
		else {
			std::cout << "Could not open the file \n";
		}
		fin.close();
	}
	else
		return;
}
void School_year::loadSemesterList()
{
	std::string temp_semester = year + "/" + year + "-semester.csv";
	std::ifstream fin(temp_semester);
	if (fin)
	{
		std::string line;
		Semester* curr = semester_list;
		while (std::getline(fin, line, '\n'))
		{
			if (line.length() == 0)
				return;
			std::stringstream ss(line);
			Semester* temp = new Semester();
			std::getline(ss, temp->order, ',');
			std::getline(ss, temp->year, ',');
			std::getline(ss, temp->start_date, ',');
			std::getline(ss, temp->end_date, ',');
			if (curr)
			{
				curr->next = temp;
				curr = curr->next;
			}
			else
			{
				semester_list = temp;
				curr = temp;
			}
		}
	}
	fin.close();
}
void School_year::create_semester(Semester*& currensemester)
{
	std::cout << "Enter new semester: ";
	std::string temp;
	std::getline(std::cin, temp, '\n');
	if (temp < "0" || temp > "9")
	{
		std::cout << "Invalid format. Please enter again \n";
		return;
	}
	Semester* cur = semester_list;
	int max_semester = 0;
	while (cur)
	{
		if (cur->order == temp)
		{
			std::cout << "Existent semester\n";
			return;
		}
		max_semester = max(max_semester, std::stoi(cur->order));
		cur = cur->next;
	}
	cur = semester_list;
	if (cur == nullptr && std::stoi(temp) != max_semester + 1)
	{
		std::cout << "Incorrect order of semester \n";
		return;
	}
	Semester* newSemester = new Semester();
	currensemester = newSemester;
	newSemester->order = temp;
	newSemester->year = year;
	std::cout << "Enter start date\n";
	getDate(newSemester->start_date);
	std::cout << "Enter end date\n";
	getDate(newSemester->end_date);
	newSemester->next = semester_list;
	semester_list = newSemester;
	std::cout << "Successfully creating new semester \n";
	// create course file
	std::string temp_course = year + "/" + temp + "-course.csv";
	std::ofstream fout_course(temp_course);
	fout_course.close();
	//Use saveSemesterList() to add created semester to semester list
}
void School_year::saveSemesterList()
{
	std::string nameFile = year + "/" + year + "-semester.csv";
	std::ofstream fout(nameFile);
	Semester* curr = semester_list;
	while (curr) {
		fout << curr->order << ',' << curr->year << ',' << curr->start_date << ',' << curr->end_date << '\n';
		curr = curr->next;
	}
	fout.close();
}
void School_year::deleteSemesterList()
{
	while (semester_list)
	{
		Semester* temp = semester_list;
		temp->deleteCourse();
		semester_list = semester_list->next;
		delete temp;
	}
}
Class_Student* School_year::Find_Student(std::string ID)
{
	Class* temp = class_list;
	while (temp)
	{
		Class_Student* cur = temp->student_list;
		while (cur)
		{
			if (cur->ID == ID) return cur;
			else cur = cur->next;
		}
		temp = temp->next;
	}
	return nullptr;
}
void School_year::Sync_Student_Course_To_Class(Course_Student* student, Course* course)
{
	if (!course || !student) return;
	Class_Student* find = Find_Student(student->ID);
	if (!find) return;
	Score* temp = find->score_list;
	while (temp)
	{
		if (temp->course == course) break;
		else temp = temp->next;
	}
	if (!temp)
	{
		temp = find->score_list;
		if (!find->score_list)
		{
			find->score_list = new Score();
			find->score_list->next = nullptr;
			temp = find->score_list;
		}
		else
		{
			while (temp->next) temp = temp->next;
			temp->next = new Score();
			temp = temp->next;
		}
		temp->course = course;
		temp->other_mark = student->other_mark;
		temp->midterm_mark = student->midterm_mark;
		temp->final_mark = student->final_mark;
		temp->total_mark = student->total_mark;
	}
	else
	{
		temp->other_mark = student->other_mark;
		temp->midterm_mark = student->midterm_mark;
		temp->final_mark = student->final_mark;
		temp->total_mark = student->total_mark;
	}
}
void School_year::LoadScoreboard()
{
	Semester* sem_ite = semester_list;
	while (sem_ite)
	{
		Course* ite = sem_ite->course_list;
		while (ite)
		{
			std::string filename = ite->year + "/" + ite->ID + "-" + ite->class_name + "-scoreboard.csv";
			std::ifstream fin(filename.c_str());
			if (!fin)
			{
				ite = ite->next; continue;
			}
			else
			{
				std::string line;
				std::getline(fin, line);
				//ignore first line: NO,ID,name,...
				Course_Student* stu_ite = ite->student_list;
				//read score for each student
				while (std::getline(fin, line) && stu_ite)
				{
					std::stringstream ss(line);
					std::string word;
					for (int i = 1; i <= 6; ++i) getline(ss, word, ',');
					//ignore attribute such as NO,ID,name when reading
					std::getline(ss, word, ',');
					stu_ite->midterm_mark = ReadFloat(word);
					std::getline(ss, word, ',');
					stu_ite->final_mark = ReadFloat(word);
					std::getline(ss, word, ',');
					stu_ite->other_mark = ReadFloat(word);
					std::getline(ss, word, ',');
					stu_ite->total_mark = ReadFloat(word);
					stu_ite = stu_ite->next;
				}
			}
			fin.close();
			ite = ite->next;
		}
		sem_ite = sem_ite->next;
	}
}
void School_year::DeleteScoreList()
{
	Class* class_ite = class_list;
	while (class_ite)
	{
		Class_Student* student_ite = class_ite->student_list;
		while (student_ite)
		{
			Score* score_ite= student_ite->score_list;
			while (score_ite)
			{
				Score* cur = score_ite;
				score_ite = score_ite->next;
				delete cur;
			}
			student_ite->score_list = nullptr;
			student_ite = student_ite->next;
		}
		class_ite = class_ite->next;
	}
}