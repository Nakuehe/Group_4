#include <string> 
#include "Course.h"
#include "Student.h"
#include "LinkedList.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>


void Course::ExportStudentCSVFile()
{
    QString fileName = courseName + ".csv";
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
        fout << temp->data.studentID << ",";
        fout << temp->data.firstName << ",";
        fout << temp->data.lastName << ",";
        fout << temp->data.gender << ",";
        fout << temp->data.dateOfBirth << ",";
        fout << temp->data.socialID << "\n";
        temp = temp->next;
    }

    file.close();
    qDebug() << "The Course Student list is exported to " << fileName;
}