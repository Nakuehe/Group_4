#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QList>
#include "User.h"
#include "Student.h"
#include "LinkedList.h"

class UserManager : public QObject
{
    Q_OBJECT
public:
    explicit UserManager(const QString &userFilename, const QString &studentFilename, QObject *parent = nullptr)
        : QObject(parent), m_user_filename(userFilename), m_student_filename(studentFilename) {}

   
    void loadUsers() {
        QFile file(m_user_filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        in.readLine();
        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            if (fields.size() == 3){
                std::string username = fields[0].toStdString();
                std::string password = fields[1].toStdString();
                std::string role = fields[2].toStdString();

                m_users.add(User(username, password, role));
            }
        }

        file.close();
    }

    void saveUsers() {
        QFile file(m_user_filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "username,password,role\n";
        for (int i = 0; i < m_users.size(); i++){
            User cur_user = m_users.get(i);

            QString username = QString::fromStdString(cur_user.username);
            QString password = QString::fromStdString(cur_user.password);
            QString role = QString::fromStdString(cur_user.role);
            


            out << username << "," << password << "," << role << "\n";
        }

        file.close();
    }

    bool authenticateUser(const QString &username, const QString &password) {
        for (int i = 0; i < m_users.size(); i++) {
            User cur_user = m_users.get(i);

            QString cur_username = QString::fromStdString(cur_user.username);
            QString cur_password = QString::fromStdString(cur_user.password);

            if (cur_username == username && cur_password == password)
                return true;
        }

        return false;
    }

    User findUser(const QString &username, const QString &password) {
        for (int i = 0; i < m_users.size(); i++) {
            User cur_user = m_users.get(i);

            QString cur_username = QString::fromStdString(cur_user.username);
            QString cur_password = QString::fromStdString(cur_user.password);

            if (cur_username == username && cur_password == password)
                return cur_user;
        }

        return User();
    }


    void changePassword(const QString &username, const QString &newPassword) {
        for (int i = 0; i < m_users.size(); i++) {

            User& cur_user = m_users.get(i);
            QString cur_username = QString::fromStdString(cur_user.username);

            if (cur_username == username){
                cur_user.setPassword(newPassword.toStdString());
                return;
            }
        }
    }

    void loadStudents() {
        QFile file(m_student_filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;



        QTextStream in(&file);
        in.readLine();
        while (!in.atEnd()) {
            QStringList fields = in.readLine().split(",");
            if (fields.size() == 6){
                std::string studentID = fields[0].toStdString();
                std::string firstName = fields[1].toStdString();
                std::string lastName = fields[2].toStdString();
                std::string gender = fields[3].toStdString();
                std::string dateOfBirth = fields[4].toStdString();
                std::string socialID = fields[5].toStdString();

                m_students.add(Student(studentID, firstName, lastName, gender, dateOfBirth, socialID));
            }
        }
    }

    void saveStudents(){
        QFile file(m_student_filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
        out << "StudentID,FirstName,LastName,Gender,DateOfBirth,SocialID\n";
        for (int i = 0; i < m_students.size(); i++){
            Student cur_student = m_students.get(i);

            QString studentID = QString::fromStdString(cur_student.studentID);
            QString firstName = QString::fromStdString(cur_student.firstName);
            QString lastName = QString::fromStdString(cur_student.lastName);
            QString gender = QString::fromStdString(cur_student.gender);
            QString dateOfBirth = QString::fromStdString(cur_student.dateOfBirth);
            QString socialID= QString::fromStdString(cur_student.socialID);

            out << studentID << "," << firstName << "," << lastName << "," << gender << "," << dateOfBirth << "," << socialID << "\n";
        }
    }
    
    Student findStudent(const QString &studentID) {
        for (int i = 0; i < m_students.size(); i++) {
            Student cur_student = m_students.get(i);

            QString cur_studentID = QString::fromStdString(cur_student.studentID);

            if (cur_studentID == studentID)
                return cur_student;
        }

        return Student();
    }

    void deleteThis(){
        while(!m_users.isEmpty()){
            m_users.removeFirst();
        }
        while(!m_students.isEmpty()){
            m_students.removeFirst();
        }
    }

    

private:
    QString m_user_filename;
    QString m_student_filename;
    LinkedList<User> m_users;
    LinkedList<Student> m_students;
};

#endif // USERMANAGER_H
