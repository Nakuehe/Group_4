#include <iostream>
#include "Source_files/User.h"
#include <fstream>

using namespace std;

bool Admin(string username, string password) {
    ifstream read("Admin.txt");
    string user, pass;
    if (read.is_open()) {
        getline(read, user);
        getline(read, pass);
        if (user == username && pass == password) {
            return true;
        }
    }
    return false;
}

bool check(const std::string& username, const std::string& password) {
    string user, pass;
    ifstream read(username + ".txt");
    if (read.is_open()) {
        getline(read, user);
        getline(read, pass);
        if (user == username && pass == password) {
            return true;
        }
    }
    return false;
}

void login(std::string& username,std::string& password) {
    system("cls");
    cout << "UserName:";
    cin >> user;
    cout << "Password:";
    cin >> password;
    if (!Admin(user, password))
    {
        if (!check(user, password)) {
            cout << "Incorrect Information, Please Try Again" << endl;
        }
        else {
            Student(user, password);
        }
    }
    else {
        Manager(user, password);
    }
}