#include "LinkedList.h"
#include "Semester.h"

struct SchoolYear {
    std::string year;
    std::string start_date; // format: dd/mm/yyyy
    std::string end_date;
    LinkedList<Semester> semesters;

    SchoolYear(const std::string& year ="", const std::string &start_date = "", const std::string &end_date = "")
        : year(year), start_date(start_date), end_date(end_date){}


    void createYear();
    void createSemester();
    void addSemester(const Semester& semester) {
        semesters.add(semester);
    }

    void viewSemesters() const;
};
