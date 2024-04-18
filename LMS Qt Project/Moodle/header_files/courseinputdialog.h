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
#include <QFontDatabase>
#include <QLabel>
#include "fontloader.h"



class MyLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    MyLineEdit(QWidget *parent = nullptr) : QLineEdit(parent) {}

protected:
    void focusOutEvent(QFocusEvent *event) override
    {
        QLineEdit::focusOutEvent(event);
        bool ok;
        int value = text().toInt(&ok);
        if (!ok || value < 1 || value > 100)
        {
            setText("50");  // revert to default value
        }
    }
};

class COURSEINPUTDIALOG: public QDialog {
    Q_OBJECT
public:
    QLineEdit *courseIDEdit;
    QLineEdit *courseNameEdit;
    QLineEdit *classNameEdit;
    QLineEdit *teacherNameEdit;
    QLineEdit *creditsEdit;
    QLineEdit *maxStudentsEdit;
    QComboBox *DayComboBox;
    QComboBox *SessionComboBox;



    COURSEINPUTDIALOG(QWidget *parent = nullptr) : QDialog(parent)
    {
        
        QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
        QFont font(fontFamily1, 14);

        courseIDEdit = new QLineEdit(this);
        courseIDEdit->setFont(font);
        courseNameEdit = new QLineEdit(this);
        courseNameEdit->setFont(font);
        classNameEdit = new QLineEdit(this);
        classNameEdit->setFont(font);
        teacherNameEdit = new QLineEdit(this);
        teacherNameEdit->setFont(font);
        creditsEdit = new QLineEdit(this);
        creditsEdit->setFont(font);
        maxStudentsEdit = new MyLineEdit(this);
        maxStudentsEdit->setFont(font);
        maxStudentsEdit->setValidator(new QIntValidator(1, 100, this));
        maxStudentsEdit->setText("50");
        DayComboBox = new QComboBox(this);
        DayComboBox->setFont(font);
        DayComboBox->addItems({"MON", "TUE", "WED", "THU", "FRI", "SAT"});
        SessionComboBox = new QComboBox(this);
        SessionComboBox->setFont(font);
        SessionComboBox->addItems({"S1(07:30)", "S2(09:30)", "S3(13:30)", "S4(15:30)"});

        QFormLayout *formLayout = new QFormLayout;
        QLabel *courseIDLabel = new QLabel("Course ID:", this);
        courseIDLabel->setFont(font);
        formLayout->addRow(courseIDLabel, courseIDEdit);

        QLabel *courseNameLabel = new QLabel("Course Name:", this);
        courseNameLabel->setFont(font);
        formLayout->addRow(courseNameLabel, courseNameEdit);

        QLabel *classNameLabel = new QLabel("Class Name:", this);
        classNameLabel->setFont(font);
        formLayout->addRow(classNameLabel, classNameEdit);

        QLabel *teacherNameLabel = new QLabel("Teacher Name:", this);
        teacherNameLabel->setFont(font);
        formLayout->addRow(teacherNameLabel, teacherNameEdit);

        QLabel *creditsLabel = new QLabel("Credits:", this);
        creditsLabel->setFont(font);
        formLayout->addRow(creditsLabel, creditsEdit);

        QLabel *maxStudentsLabel = new QLabel("Max Students:", this);
        maxStudentsLabel->setFont(font);
        formLayout->addRow(maxStudentsLabel, maxStudentsEdit);

        QLabel *dayLabel = new QLabel("Day:", this);
        dayLabel->setFont(font);
        formLayout->addRow(dayLabel, DayComboBox);

        QLabel *sessionLabel = new QLabel("Session:", this);
        sessionLabel->setFont(font);
        formLayout->addRow(sessionLabel, SessionComboBox);

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
    QString getMaxStudent() {
        return maxStudentsEdit->text();
    }
    QString getDay() {
        return DayComboBox->currentText();
    }
    QString getSession() {
        return SessionComboBox->currentText();
    }
};
#endif // COURSEINPUTDIALOG_H
