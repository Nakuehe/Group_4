#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
//#include"Main.h"

int maxline(std::string strname, int colsize);
void sepline(std::string strnameline[], std::string strname, int colsize);
void viewclass(std::string Year, int& countline);
void viewstudentinclass(std::string Year, std::string className);
void viewcourse(std::string Year,std::string curSemester);
void listofstudentincourse(std::string Year);