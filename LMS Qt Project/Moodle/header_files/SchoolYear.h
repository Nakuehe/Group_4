#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H

#include "LinkedList.h"
#include "Semester.h"
#include "./classdialog.h"
#include "Class.h"
#include <QInputDialog>
#include "dateinputdialog.h"


struct SchoolYear {
    std::string year;
    std::string start_date; // format: dd/mm/yyyy
    std::string end_date;
    LinkedList<Semester> semesters;
    LinkedList<Class> classes;

    SchoolYear(const std::string& year ="", const std::string &start_date = "", const std::string &end_date = "")
        : year(year), start_date(start_date), end_date(end_date){}

    std::string getNextYear(const std::string& currentYear)
    {
        size_t hyphenPos = currentYear.find('-');
        if (hyphenPos == std::string::npos || hyphenPos == 0 || hyphenPos == currentYear.length() - 1)
        {

            return currentYear;
        }
        std::string startYearStr = currentYear.substr(0, hyphenPos);
        std::string endYearStr = currentYear.substr(hyphenPos + 1);
        int startYear = std::stoi(startYearStr);
        int endYear = std::stoi(endYearStr);
        startYear++;
        endYear++;
        std::string nextYear = std::to_string(startYear) + "-" + std::to_string(endYear);
        return nextYear;
    }
    void createSemester()
    {   /*
        if(this->semesters.size()>2) return;
        else
        {
        QString start_date = QInputDialog::getText(nullptr, "Input start date", "Enter start date:");
        std::string start_date_std = start_date.toStdString();
        QString end_date = QInputDialog::getText(nullptr, "Input end date", "Enter end date:");
        std::string end_date_std = end_date.toStdString();
        if(this->semesters.size()==0) {
            Semester new_semester("Semester 1");
            new_semester.start_date = start_date_std;
            new_semester.end_date = end_date_std;
            this->addSemester(new_semester);
        }
        else if(this->semesters.size()==1) {
            Semester new_semester("Semester 2");
            new_semester.start_date = start_date_std;
            new_semester.end_date = end_date_std;
            this->addSemester(new_semester);
        }
        else if(this->semesters.size()==2) {
            Semester new_semester("Semester 3");
            new_semester.start_date = start_date_std;
            new_semester.end_date = end_date_std;
            this->addSemester(new_semester);
        }
        }
        */
        if (this->semesters.size() > 2) return;

        DateInputDialog dialog;
        if (dialog.exec() == QDialog::Accepted) {
            std::string start_date_std = dialog.getStartDate().toStdString();
            std::string end_date_std = dialog.getEndDate().toStdString();

            std::string semesterName = "Semester " + std::to_string(this->semesters.size() + 1);

            Semester new_semester(semesterName, start_date_std, end_date_std);
            this->addSemester(new_semester);
        }
    }
    void createClass()
    {
        ClassDialog dialog;
        if (dialog.exec() == QDialog::Accepted)
        {
            std::string tempClass = dialog.getClassName().toStdString();
            for (int i = 0; i < tempClass.length(); ++i)
            {
                if (!tempClass.at(i).isLetterOrNumber())
                {
                    QMessageBox::warning(nullptr,"Invalid Format", "Invalid format. Class name should contain letters or numbers only.");
                    return;
                }
                Class* curr = this->classes;
                while (curr)
                {
                    if (curr->classname == tempClass)
                    {
                        QMessageBox::warning(nullptr, "Class Exists", "Class '" + tempClass + "' already exists.");
                        return;
                    }
                    if (curr->next == nullptr)
                        break;
                    curr = curr->next;
                }
                Class new_class(tempClass,this->year);
                this->addClass(new_class);

            }
        }
    void addSemester(const Semester& semester) {
        semesters.add(semester);
    }

    void addClass(const Class& this_class){
        classes.add(this_class);
    }

    void viewSemesters() const;

    bool operator==(const SchoolYear& other) const {
        return year == other.year;
    }

    bool operator!=(const SchoolYear& other) const {
        return !(*this == other);
    }

    bool operator>(const SchoolYear& other) const {
        return year > other.year;
    }

    bool operator<=(const SchoolYear& other) const {
        return (year < other.year || year == other.year);
    }

    bool operator<(const SchoolYear& other) const {
        return year < other.year;
    }
};

#endif //SCHOOLYEAR_H


