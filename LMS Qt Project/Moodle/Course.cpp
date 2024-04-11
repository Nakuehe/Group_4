
#include "Course.h"
#include "Student.h"
#include "LinkedList.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QString>

void Course::ExportStudentCSVFile()
{
    QString fileName = QString::fromStdString(courseName);
    fileName.append(".csv");
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    QTextStream fout(&file);
    fout << "StudentID,FirstName,LastName,Gender,DateOfBirth,SocialID\n";

    Node<Student>* temp = students.getHead();
    while (temp != nullptr)
    {
        fout << QString::fromStdString(temp->data.studentID) << ",";
        fout << QString::fromStdString(temp->data.firstName) << ",";
        fout << QString::fromStdString(temp->data.lastName) << ",";
        fout << QString::fromStdString(temp->data.gender) << ",";
        fout << QString::fromStdString(temp->data.dateOfBirth) << ",";
        fout << QString::fromStdString(temp->data.socialID) << "\n";
        temp = temp->next;
    }

    file.close();
    qDebug() << "The Course Student list is exported to " << fileName;
}
