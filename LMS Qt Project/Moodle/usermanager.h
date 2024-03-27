#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QList>
#include "User.h"
#include "LinkedList.h"

class UserManager : public QObject
{
    Q_OBJECT
public:
    explicit UserManager(const QString &filename, QObject *parent = nullptr)
        : QObject(parent), m_filename(filename) {}

    void loadUsers() {
        QFile file(m_filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
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
        QFile file(m_filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream out(&file);
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


private:
    QString m_filename;
    LinkedList<User> m_users;
};

#endif // USERMANAGER_H
