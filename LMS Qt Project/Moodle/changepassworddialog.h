#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include "usermanager.h"
#include "User.h"

namespace Ui {
class ChangePasswordDialog;
}

class ChangePasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordDialog(QWidget *parent = nullptr, User thisStudent = User(), UserManager* userManager = nullptr);
    ~ChangePasswordDialog();

private slots:
    void on_okButton_clicked();

private:
    Ui::ChangePasswordDialog *ui;
    User thisStudent;
    UserManager* userManager;

};

#endif // CHANGEPASSWORDDIALOG_H
