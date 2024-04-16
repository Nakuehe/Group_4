#ifndef SEMESTERCREATOR_H
#define SEMESTERCREATOR_H
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QString>
#include <QDebug>
class SemesterCreator : public QWidget {
public:
    SemesterCreator(QWidget *parent = nullptr) : QWidget(parent) {
        // Widgets for input
        QLabel *semesterLabel = new QLabel("Semester:");
        semesterEdit = new QLineEdit;
        QLabel *schoolYearLabel = new QLabel("School Year:");
        schoolYearEdit = new QLineEdit;
        QLabel *startDateLabel = new QLabel("Start Date:");
        startDateEdit = new QDateEdit;
        QLabel *endDateLabel = new QLabel("End Date:");
        endDateEdit = new QDateEdit;

        // Button to create semester
        QPushButton *createButton = new QPushButton("Create Semester");
        connect(createButton, &QPushButton::clicked, this, &SemesterCreator::createSemester);

        // Layout
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(semesterLabel);
        layout->addWidget(semesterEdit);
        layout->addWidget(schoolYearLabel);
        layout->addWidget(schoolYearEdit);
        layout->addWidget(startDateLabel);
        layout->addWidget(startDateEdit);
        layout->addWidget(endDateLabel);
        layout->addWidget(endDateEdit);
        layout->addWidget(createButton);

        setLayout(layout);
    }

private slots:
    void createSemester() {
        // Retrieve data from input fields
        QString semester = semesterEdit->text();
        QString schoolYear = schoolYearEdit->text();
        QDate startDate = startDateEdit->date();
        QDate endDate = endDateEdit->date();
        // Call function to create semester based on the passed school year
        qDebug() << "Creating semester" << semester << "for school year" << schoolYear
                 << "with start date" << startDate.toString("yyyy-MM-dd")
                 << "and end date" << endDate.toString("yyyy-MM-dd");
    }

private:
    QLineEdit *semesterEdit;
    QLineEdit *schoolYearEdit;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
};


#endif // SEMESTERCREATOR_H
