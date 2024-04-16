#ifndef COURSEINPUTDIALOG_H
#define COURSEINPUTDIALOG_H
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include "QComboBox"
class COURSEINPUTDIALOG: public QDialog {
    Q_OBJECT
public:
    QLineEdit *courseIDEdit;
    QLineEdit *courseNameEdit;
    QLineEdit *classNameEdit;
    QLineEdit *teacherNameEdit;
    QLineEdit *creditsEdit;
    QComboBox *DayComboBox;
    QComboBox *SessionComboBox;

    COURSEINPUTDIALOG(QWidget *parent = nullptr) : QDialog(parent)
    {
        courseIDEdit = new QLineEdit(this);
        courseNameEdit = new QLineEdit(this);
        classNameEdit = new QLineEdit(this);
        teacherNameEdit = new QLineEdit(this);
        creditsEdit = new QLineEdit(this);
        DayComboBox = new QComboBox(this);
        DayComboBox->addItems({"MON", "TUE", "WED", "THU", "FRI", "SAT"});
        SessionComboBox = new QComboBox(this);
        SessionComboBox->addItems({"S1(07:30)", "S2(09:30)", "S3(13:30)", "S4(15:30)"});

        QFormLayout *formLayout = new QFormLayout;
        formLayout->addRow("Course ID:", courseIDEdit);
        formLayout->addRow("Course Name:", courseNameEdit);
        formLayout->addRow("Class Name:", classNameEdit);
        formLayout->addRow("Teacher Name:", teacherNameEdit);
        formLayout->addRow("Credits:", creditsEdit);
        formLayout->addRow("Day:", DayComboBox);
        formLayout->addRow("Session:", SessionComboBox);

        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addLayout(formLayout);
        layout->addWidget(buttonBox);
    }

    QString getCourseID() {
        return courseIDEdit->text();
    }
    QString getCourseName() {
        return courseNameEdit->text();
    }
    QString getClassName() {
        return classNameEdit->text();
    }
    QString getTeacherName() {
        return teacherNameEdit->text();
    }
    QString getcredits() {
        return creditsEdit->text();
    }
    QString getDay() {
        return DayComboBox->currentText();
    }
    QString getSession() {
        return SessionComboBox->currentText();
    }
};
#endif // COURSEINPUTDIALOG_H
