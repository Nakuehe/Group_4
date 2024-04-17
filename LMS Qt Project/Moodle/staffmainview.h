#ifndef STAFFMAINVIEW_H
#define STAFFMAINVIEW_H

#include <QMainWindow>
#include <QFontDatabase>
#include "Course.h"
#include "Class.h"
#include "LinkedList.h"
#include <QListWidgetItem>



class StaffSideView;
class SchoolYear;
class StudentViewTable;
class Semester;

namespace Ui {
class StaffMainView;
}

class StaffMainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaffMainView(QWidget *parent = nullptr, StaffSideView* staffSideView = nullptr, SchoolYear* this_year = nullptr,LinkedList<SchoolYear>* SchoolYears = nullptr);
    ~StaffMainView();

    QString loadFont(const QString &resourcePath);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:

    void on_stackedWidget_currentChanged(int index);
    void on_semester_btn1_toggled();
    void on_semester_btn2_toggled();
    void on_class_btn1_toggled();
    void on_class_btn2_toggled();
    void menu_btn_toggled(bool checked);

private:
    Ui::StaffMainView *ui;
    StaffSideView* staffSideView;
    SchoolYear* this_year;
    Semester* this_semester;
    Course* this_course;
    LinkedList<Student>* student_list = nullptr;
    LinkedList<SchoolYear>* SchoolYears;
    QList<Course> courses;
    QList<Class> classes;

    void setUpPage();
    void setUpSemesters();
    void setUpClasses();
    void setUpCourses(LinkedList<Course>* curCourses);
    void courseViewSetUp(Course& this_course);
    void classViewSetup(Class& this_class);

    void onCourseListItemClicked(QListWidgetItem* item);
    void onClassListItemClicked(QListWidgetItem* item);

};

#endif // STAFFMAINVIEW_H
