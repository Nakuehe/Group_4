#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"

ChangePasswordDialog::ChangePasswordDialog(QWidget *parent, User thisStudent, UserManager* userManager)
    : QDialog(parent), ui(new Ui::ChangePasswordDialog), thisStudent(thisStudent), userManager(userManager) {
    ui->setupUi(this);

    QPushButton* okButton = ui->buttonBox->button(QDialogButtonBox::Ok);

    // If the okButton was found
    if (okButton != nullptr) {
        // Connect okButton's clicked signal to the on_okButton_clicked slot
        connect(okButton, &QPushButton::clicked, this, &ChangePasswordDialog::on_okButton_clicked);
    }
}

void ChangePasswordDialog::on_okButton_clicked() {
    QString oldPassword = ui->oldPasswordLineEdit->text();
    QString newPassword = ui->newPasswordLineEdit->text();
    QString confirmNewPassword = ui->confirmNewPasswordLineEdit->text();

    QString username = QString::fromStdString(thisStudent.username);

    if (userManager->authenticateUser(username, oldPassword)) {
        if (newPassword == confirmNewPassword) {
            userManager->changePassword(username, newPassword);
             QMessageBox::information(this, "Success", "Password has been changed successfully.");
            accept();
        } else {
            QMessageBox::warning(this, "Error", "New passwords do not match.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Old password is incorrect.");
    }
}

ChangePasswordDialog::~ChangePasswordDialog() {
    delete ui;
}
