#ifndef STUDENTINPUTDIALOG_H
#define STUDENTINPUTDIALOG_H
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QDate>
#include <QMessageBox>
#include "fontloader.h"
#include "QComboBox"


class STUDENTINPUTDIALOG: public QDialog {
    Q_OBJECT

public:
    QLineEdit *studentIDEdit;
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QComboBox *genderComboBox;
    QComboBox *dayComboBox;
    QComboBox *monthComboBox;
    QComboBox *yearComboBox;
    QLineEdit *dateOfBirthEdit;
    QLineEdit *socialIDEdit;

    STUDENTINPUTDIALOG(QWidget *parent = nullptr) : QDialog(parent)
    {
        QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
        QFont font(fontFamily1, 14);

        this->setWindowIcon(QIcon(":/Asset/loginpageAsset/logo.png"));
        this->setWindowTitle("Info");

        this->setFont(font);

        studentIDEdit = new QLineEdit(this);
        firstNameEdit = new QLineEdit(this);
        lastNameEdit = new QLineEdit(this);
        genderComboBox = new QComboBox(this);
        genderComboBox->addItems({"Male", "Female"});
        socialIDEdit = new QLineEdit(this);

        dayComboBox = new QComboBox(this);
        for (int i = 1; i <= 31; ++i) {
            dayComboBox->addItem(QString::number(i));
        }

        monthComboBox = new QComboBox(this);
        for (int i = 1; i <= 12; ++i) {
            monthComboBox->addItem(QString::number(i));
        }

        yearComboBox = new QComboBox(this);
        for (int i = QDate::currentDate().year(); i >= 1900; --i) {
            yearComboBox->addItem(QString::number(i));
        }

        int minWidth = 50;  // Adjust this value as needed
        dayComboBox->setMinimumWidth(minWidth);
        monthComboBox->setMinimumWidth(minWidth);
        yearComboBox->setMinimumWidth(minWidth + 20);

        QHBoxLayout *dateOfBirthLayout = new QHBoxLayout;
        dateOfBirthLayout->addWidget(dayComboBox);
        dateOfBirthLayout->addWidget(monthComboBox);
        dateOfBirthLayout->addWidget(yearComboBox);


        
        QFormLayout *formLayout = new QFormLayout;
        formLayout->addRow("Student ID:", studentIDEdit);
        formLayout->addRow("First Name:", firstNameEdit);
        formLayout->addRow("Last Name:", lastNameEdit);
        formLayout->addRow("Gender:", genderComboBox);
        formLayout->addRow("Date of Birth:", dateOfBirthLayout);
        formLayout->addRow("Social ID:", socialIDEdit);
        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        connect(buttonBox, &QDialogButtonBox::accepted, this, [this]() {
            int day = dayComboBox->currentText().toInt();
            int month = monthComboBox->currentText().toInt();
            int year = yearComboBox->currentText().toInt();
            if (!QDate::isValid(year, month, day)) {
                QMessageBox::warning(this, "Invalid date", "The selected date is not valid.");
                return;
            }
            accept();
        });
        
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
        return dayComboBox->currentText() + "/" + monthComboBox->currentText() + "/" + yearComboBox->currentText();
    }
    QString getsocialID() {
        return socialIDEdit->text();
    }

};


#endif // STUDENTINPUTDIALOG_H
