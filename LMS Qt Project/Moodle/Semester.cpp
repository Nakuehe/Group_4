#include "Semester.h"

Node<Course> *Semester::Find_Course()
{
    return nullptr;
}

void Semester::Update_Student_Result()
{
    {
	//Ask for course info to find course
	std::cout << "Please input some information of the course ";
	std::cout << "that you want to change the score of student\n";
	Course* temp = Find_Course();
	//Handle wrong input from user
	while (!temp)
	{
		std::cout << "Can't find the course with these infomation\n";
		std::cout << "You can choose to continue or exit\n";
		std::cout << "[1] Reinput\n";
		std::cout << "[0] Exit\n";
		std::string choice;
		getChoice(choice);
		while (choice != "0" && choice != "1")
		{
			std::cout << "Please input 0 or 1 for choosing\n";
			getChoice(choice);
		}
		if (choice == "0") return;
		else temp = Find_Course();
	}
	std::string choice = "1";
	while (true)
	{
		if (choice == "0") break;
		else if (choice == "1")
		{
			//Find student to update score
			std::cout << "Input ID of student: ";
			std::string ID; std::getline(std::cin, ID, '\n');
			Course_Student* cur = temp->student_list;
			while (cur)
			{
				if (cur->ID == ID) break;
				else cur = cur->next;
			}
			//Handle if can't find student by inputted ID
			while (!cur)
			{
				std::cout << "We can't find student with this ID in this course\n";
				std::string set;
				std::cout << "You can choose to continue or exit\n";
				std::cout << "[1] Reinput\n";
				std::cout << "[0] Exit\n";
				getChoice(set);
				while (set != "0" && set != "1")
				{
					std::cout << "Please input 0 or 1 for choosing\n";
					getChoice(set);
				}
				if (set == "0") return;
				if (set == "1")
				{
					std::cout << "Input student ID: ";
					std::string ID; std::getline(std::cin, ID, '\n');
					cur = temp->student_list;
					while (cur)
					{
						if (cur->ID == ID) break;
						else cur = cur->next;
					}
				}
			}
			std::cout << "List of change\n";
			std::cout << "Changed midterm mark: "; std::cin >> cur->midterm_mark;
			std::cout << "Changed final mark: "; std::cin >> cur->final_mark;
			std::cout << "Changed other mark: "; std::cin >> cur->other_mark;
			std::cout << "Changed total mark: "; std::cin >> cur->total_mark;
			std::cin.get();
			std::cout << "Press [1] to continue to update student's result in this course\n";
			std::cout << "Press [0] to exit\n";
			getChoice(choice);
		}
	}
	std::ofstream fout(year + "/" + temp->ID + "-" + temp->class_name + "-scoreboard.csv"); 
	Course_Student* student = temp->student_list; 
	fout << "No,ID,Full name,Gender,Birthday,Social ID,Midterm mark,Final mark,Other mark,Total mark\n";
	while (student)
	{
		fout << student->No << ",";
		fout << student->ID << ",";
		fout << student->first_name << " " << student->last_name << ",";
		fout << student->gender << ",";
		fout << student->birth_day << ",";
		fout << student->social_ID << ',';
		fout << student->midterm_mark << ",";
		fout << student->final_mark << ",";
		fout << student->other_mark << ",";
		fout << student->total_mark << "\n";
		student = student->next;
	}
	fout.close();
}