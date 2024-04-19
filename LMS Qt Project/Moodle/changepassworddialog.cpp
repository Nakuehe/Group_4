#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"
#include "fontloader.h"

ChangePasswordDialog::ChangePasswordDialog(QWidget *parent, User thisStudent, UserManager* userManager)
    : QDialog(parent), ui(new Ui::ChangePasswordDialog), thisStudent(thisStudent), userManager(userManager) {
    ui->setupUi(this);

    QPushButton* okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QFont font(fontFamily1, 14);

    this->setWindowIcon(QIcon(":/Asset/loginpageAsset/logo.png"));
    this->setWindowTitle("Course");

    ui->buttonBox->setFont(font);
    ui->confirmNewPasswordLineEdit->setFont(font);
    ui->newPasswordLineEdit->setFont(font);
    ui->oldPasswordLineEdit->setFont(font);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);

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
