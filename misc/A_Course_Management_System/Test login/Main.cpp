#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

#include "Function.h";

int main() {
  
    string username, password;
    int choice;
    system("cls");
    cout << "+---------MENU---------+" << endl;
    cout << "|       1.Log In       |" << endl;
    cout << "|                      |" << endl;
    cout << "|      2.Register      |" << endl;
    cout << "|                      |" << endl;
    cout << "|        0.Exit        |" << endl;
    cout << "+----------------------+" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        Login(username, password);
        break;
    case 2:
    {
        system("cls");
        cout << "Enter a username:"; cin >> username;
        cout << "Enter a password:"; cin >> password;

        ofstream data;
        data.open(username + ".txt");
        data << username << endl << password;
        data.close();
        
        main();
    }
    break;
    default:
        break;
    }
    return 0;
}