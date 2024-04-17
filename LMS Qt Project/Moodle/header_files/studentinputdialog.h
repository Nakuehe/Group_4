#ifndef STUDENTINPUTDIALOG_H
#define STUDENTINPUTDIALOG_H
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include "QComboBox"
class STUDENTINPUTDIALOG: public QDialog {
    Q_OBJECT

public:
    QLineEdit *studentIDEdit;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QComboBox *genderComboBox;
    QLineEdit *dateOfBirthEdit;
    QLineEdit *socialIDEdit;

    STUDENTINPUTDIALOG(QWidget *parent = nullptr) : QDialog(parent)
    {
        studentIDEdit = new QLineEdit(this);
        firstNameEdit = new QLineEdit(this);
        lastNameEdit = new QLineEdit(this);
        genderComboBox = new QComboBox(this);
        genderComboBox->addItems({"Male", "Female"});
        dateOfBirthEdit = new QLineEdit(this);
        socialIDEdit = new QLineEdit(this);
        QFormLayout *formLayout = new QFormLayout;
        formLayout->addRow("Student ID:", studentIDEdit);
        formLayout->addRow("First Name:", firstNameEdit);
        formLayout->addRow("Last Name:", lastNameEdit);
        formLayout->addRow("Gender:", genderComboBox);
        formLayout->addRow("Date of Birth:", dateOfBirthEdit);
        formLayout->addRow("Social ID:", socialIDEdit);
        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addLayout(formLayout);
        layout->addWidget(buttonBox);
    }

    QString getStudentID() {
        return studentIDEdit->text();
    }
    QString getFirstName() {
        return firstNameEdit->text();
    }
    QString getLastName() {
        return lastNameEdit->text();
    }
    QString getGender() {
        return genderComboBox->currentText();
    }
    QString getDateofBirth() {
        return dateOfBirthEdit->text();
    }
    QString getsocialID() {
        return socialIDEdit->text();
    }

};


#endif // STUDENTINPUTDIALOG_H
