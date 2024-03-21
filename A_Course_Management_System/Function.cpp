#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Function.h"

struct Student
{
    int No;
    int Id;
    string FirstName;
    string LastName;
    string Gender;
    int DateOfBirth;
    int SocialId;

};

void changepass(string username, string newPassword) { 
    ofstream data(username + ".txt");
    system("cls");
    cout << "Please Enter New Password:";
    cin >> newPassword;
    data << username << endl << newPassword;
    data.close();
    cout << "Password changed successfully!" << endl;
    main();
}

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

bool check(string username, string password) {
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

void Student(string username, string password) {
    system("cls");
    int choice;
    cout << "Welcome back " << username << endl;
    cout << "+---------MENU---------+" << endl;
    cout << "|        1.View        |" << endl;
    cout << "|                      |" << endl;
    cout << "|    2.Rest Password   |" << endl;
    cout << "|                      |" << endl;
    cout << "|       0.LogOut       |" << endl;
    cout << "+----------------------+" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        system("cls");
        cout << "+---------VIEW---------+" << endl;
        cout << "|    1.Your Courses    |" << endl;
        cout << "|                      |" << endl;
        cout << "|   2.Your Scoreboard  |" << endl;
        cout << "|                      |" << endl;
        cout << "|    0.Back to menu    |" << endl;
        cout << "+----------------------+" << endl;
        cin >> choice;
        switch (choice)
        {
        default:
        {
            Student(username, password);
        }
        break;
        case 1:
            break;
        case 2:
            break;
        }
    }
    break;
    case 2:
        changepass(username, password);
        break;
    default:
        main();
        break;
    }
}

void View(string username, string password) {
    int choice;
    system("cls");
    cout << "+---------VIEW---------+" << endl;
    cout << "|    1.School Years    |" << endl;
    cout << "|                      |" << endl;
    cout << "|      2.Classes       |" << endl;
    cout << "|                      |" << endl;
    cout << "|    0.Back to menu    |" << endl;
    cout << "+----------------------+" << endl;
    cin >> choice;
    switch (choice)
    {
    default:
    {
        Manager(username, password);
    }
    break;
    case 1:
    {
        SchoolYears(username, password);
    }
        break;
    case 2:
    {
        classes(username, password);
    }
        break;
    }
}

void Manager(string username,string password) {
    system("cls");
    int choice;
    cout << "Welcome back " << username << endl;
    cout << "+---------MENU---------+" << endl;
    cout << "|        1.View        |" << endl;
    cout << "|                      |" << endl;
    cout << "|   2.Reset Password   |" << endl;
    cout << "|                      |" << endl;
    cout << "|       0.LogOut       |" << endl;
    cout << "+----------------------+" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        View(username, password);
    }
    break;
    case 2:
    changepass(username, password);
    break;
    default:
        main();
        break;
    }
}

void Login(string& user, string& password) {
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

void inclasses() {
    ifstream data("Classes.txt");
    string line;

    if (data.is_open()) {
        cout << "+-----VIEW-CLASSES-----+" << endl;
        bool foundData = false;
        while (getline(data, line)) {
            foundData = true;
            cout << "|       " << line << "        |" << endl;
        }
        if (!foundData) {
            cout << "|Can't find any classes|" << endl;
        }
        cout << "+----------------------+" << endl;
        data.close();
    }
    else {
        cout << "Không thể mở tệp tin." << endl;
    }
}

void inyear() {
    ifstream data("schoolyears.txt");
    string line;

    if (data.is_open()) {
        cout << "+-----VIEW-SCHOOl-YEARS-----+" << endl;
        bool foundData = false;
        while (getline(data, line)) {
            foundData = true;
            cout << "|         " << line << "         |" << endl;
        }
        if (!foundData) {
            cout << "| Can't find any schoolyear |" << endl;
        }
        cout << "+---------------------------+" << endl;
        data.close();
    }
    else {
        cout << "Không thể mở tệp tin." << endl;
    }
}

void classes(string username, string password) {
    string temp;
    int choice;
    system("cls");
    inclasses();
    cout << "+---------VIEW---------+" << endl;
    cout << "|    1.Add Classes     |" << endl;
    cout << "|                      |" << endl;
    cout << "|        0.Back        |" << endl;
    cout << "+----------------------+" << endl;
    cin >> choice;
    switch (choice)
    {
    default:
    {
        View(username, password);
    }
    break;
    case 1:
    {
        system("cls");
        cout << "Enter a Classes:";
        cin >> temp;
        ofstream data;
        data.open(temp + ".txt");
        data.close();
        data.open("Classes.txt", ios::app);
        data << temp << endl;
        data.close();
        classes(username, password);
    }
    break;
    }
}

void SchoolYears(string username, string password) {
    string temp;
    int choice;
    system("cls");
    inyear();
    cout << "+---------VIEW---------+" << endl;
    cout << "|  1.Add School years  |" << endl;
    cout << "|                      |" << endl;
    cout << "|        0.Back        |" << endl;
    cout << "+----------------------+" << endl;
    cin >> choice;
    switch (choice)
    {
    default:
    {
        View(username, password); 
    }
        break;
    case 1: 
    {
        system("cls");
        cout << "Enter a school year:";
        cin >> temp;
        ofstream data;
        data.open(temp + ".txt");
        data << "semester 1" << endl << "semester 2" << endl << "semester 3" << endl;
        data.close();
        data.open("schoolyears.txt", ios::app);
        data << temp << endl;
        data.close();
        SchoolYears(username, password);
    }
    break;
    }
}
