#ifndef USER_H
#define USER_H

#include <string>

struct User {
    std::string username;
    std::string password;
    std::string role;


    User(const std::string& username = "", const std::string& password = "", const std::string& role = "")
        : username(username), password(password), role(role) {}

    bool login(const std::string& username, const std::string& password);

    void setPassword(const std::string &new_password) { password = new_password; }
    
    bool check(const std::string& username,const std::string& password);

};


#endif // USER_H
