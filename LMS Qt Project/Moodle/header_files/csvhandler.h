#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include "Course.h"
#include "Class.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>

class SchoolYear;
class Semester;

class CSVHandler
{
public:
    CSVHandler(SchoolYear* year = nullptr, Semester* semester = nullptr, Course* course = nullptr, Class* this_class = nullptr)
        :this_year(year), this_semester(semester), this_course(course), this_class(this_class) {}

private:
    SchoolYear* this_year;
    Semester* this_semester;
    Course* this_course;
    Class* this_class;
};

#endif // CSVHANDLER_H
