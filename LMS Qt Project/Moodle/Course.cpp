
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

void Course::Export_Scoreboard_Form()
{
    Node<Score>* temp = Scoreboard.getHead();
    if(temp == nullptr)
    {
        qDebug()<<"there is no student in a course\n";
        return;
    }
    QString fileName = QString("%1/%2-%3-scoreboard.csv").arg(QString::fromStdString(year)).arg(QString::fromStdString(courseID)).arg(QString::fromStdString(className));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }
    QTextStream fout(&file);
    fout<<"id,fullname,midterm,final,other\n";
    while(temp != nullptr)
    {
        fout<<QString::fromStdString(temp->data.id_student)<<",";
        fout<<QString::fromStdString(temp->data.fullName)<<",";
        fout<<temp->data.mid_mark<<",";
        fout<<temp->data.final_mark<<",";
        fout<<temp->data.other_mark<<"\n";
        temp = temp->next;
    }
    file.close();
    qDebug()<<"Export Successfully\n";

}

void Course::Import_Scoreboard_To()
{
    QString fileName = QString("%1/%2-%3-scoreboard.csv").arg(QString::fromStdString(year)).arg(QString::fromStdString(courseID)).arg(QString::fromStdString(className));
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading:" << file.errorString();
        return;
    }

    QTextStream in(&file);

    // Read and discard the title line
    QString titleLine = in.readLine();// title midterm , final ,other mark

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() < 5)
        {
            qDebug() << "Invalid line format, skipping line:" << line;
            continue;
        }

        Score data;
        data.id_student = fields[0].toStdString();
        data.fullName = fields[1].toStdString();
        data.mid_mark = fields[2].toFloat();
        data.final_mark = fields[3].toFloat();
        data.other_mark = fields[4].toFloat();
        data.courseID = courseID;
        data.courseName = courseName;
        Scoreboard.add(data);
    }

    file.close();
    qDebug() << "Import successfully";
}

void Course::updateStudentResult()
{
    
}
