#ifndef SCHOOLYEAR_H
#define SCHOOLYEAR_H

#include "LinkedList.h"
#include "Semester.h"

#include "Class.h"
#include <QInputDialog>

struct SchoolYear {
    std::string year;
    std::string start_date; // format: dd/mm/yyyy
    std::string end_date;
    LinkedList<Semester> semesters;
    LinkedList<Class> classes;

    SchoolYear(const std::string& year ="", const std::string &start_date = "", const std::string &end_date = "")
        : year(year), start_date(start_date), end_date(end_date){}


    void createYear();
    void createSemester()
    {
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


