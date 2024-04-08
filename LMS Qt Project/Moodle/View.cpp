
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include"View.h"
//#include"Display.h"

// Find the number of line seperated from a string and the length of the column
int maxline(std::string strname, int colsize)
{
    int cntstrname = 0;
	for (int i = 0;i < strname.size();i++) {
		if (strname[i] == ' ') {
			cntstrname++;
		}
	}
	if (cntstrname == 0) {
		return 1;
	}
	// create a array of type string
	std::string* strname1 = new std::string[cntstrname + 1];
	// get value for the first element
	for (int i = 0;i < strname.size();i++) {
		if (strname[i] != ' ') {
			strname1[0] += strname[i];
		}
		else {
			break;
		}
	}
	// Get value for the remaining of the the array ( each have space before)
	int curstrname = 1;
	for (int i = 0;i < strname.size();i++) {
		if (strname[i] == ' ') {
			if (curstrname < cntstrname + 1) {
				strname1[curstrname] += ' ';
				for (int j = i + 1;j < strname.size();j++) {
					if (strname[j] != ' ') {
						strname1[curstrname] += strname[j];
					}
					else {
						break;
					}
				}
				curstrname += 1;
			}
		}
	}
	// Find the number of line
	int cntstrname1 = strname1[0].size();
	int maxstrname = 1;
	for (int i = 1;i < cntstrname + 1;i++) {
		cntstrname1 += strname1[i].size();
		if (cntstrname1 >= colsize) {
			maxstrname++;
			cntstrname1 = strname1[i].size() - 1;
		}
	}
	delete[] strname1;
	return maxstrname;
}