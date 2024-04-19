
#include "Course.h"
#include "Student.h"
#include "LinkedList.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>


void Course::ExportStudentCSVFile()
{
    // QString fileName = QString::fromStdString(courseName);
    // fileName.append(".csv");

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export CSV", "", "CSV files (*.csv)");
    if (fileName.isEmpty()) {
        return; // User canceled the dialog
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Error", "Failed to open file for writing.");
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
    QMessageBox::information(nullptr, "Success", "The Course Student list is exported successfully.");
}

void Course::Export_Scoreboard_Form()
{
    Node<Score>* temp = Scoreboard.getHead();
    if(temp == nullptr)
    {
        QMessageBox::critical(nullptr, "Error", "There is no student in a course.");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export CSV", "", "CSV files (*.csv)");
    if (fileName.isEmpty()) {
        return; // User canceled the dialog
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Error", "Failed to open file for writing.");
        return;
    }

    QTextStream fout(&file);
    fout << "id,fullname,midterm,final,other\n";
    while(temp != nullptr)
    {
        fout << QString::fromStdString(temp->data.id_student) << ",";
        fout << QString::fromStdString(temp->data.fullName) << ",";
        fout << temp->data.mid_mark << ",";
        fout << temp->data.final_mark << ",";
        fout << temp->data.other_mark << "\n";
        temp = temp->next;
    }

    file.close();
    QMessageBox::information(nullptr, "Success", "The Course Scoreboard is exported successfully.");
}

void Course::Import_Scoreboard_To()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open CSV", "", "CSV files (*.csv)");
    if (fileName.isEmpty()) {
        return; // User canceled the dialog
    }

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Failed to open file for reading.");
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
            QMessageBox::critical(nullptr, "Error", "Invalid line format, skipping line.");
            continue;
        }

        Score data;
        data.id_student = fields[0].toStdString();
        data.fullName = fields[1].toStdString();
        data.mid_mark = fields[2].toFloat();
        data.final_mark = fields[3].toFloat();
        data.other_mark = fields[4].toFloat();
        data.total_mark  = 0.4*data.final_mark + 0.25*data.mid_mark + 0.35*data.other_mark;
        data.courseID = courseID;
        data.courseName = courseName;
        Scoreboard.add(data);
    }

    file.close();
    QMessageBox::information(nullptr, "Success", "Import successfully.");
}

void Course::updateStudentResult()
{

}

void Course::deleteThisStudentList(){
    while(!students.isEmpty()){
        students.removeFirst();
    }
}
