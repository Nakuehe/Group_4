#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QCloseEvent>
#include <QMessageBox>
#include "changepassworddialog.h"
#include <QFontDatabase>
#include "Course.h"
#include "User.h"
#include <string>

class MainWindow;

namespace Ui {
class StudentView;
}

class StudentView : public QMainWindow
{
    Q_OBJECT

public:

    explicit StudentView(QWidget *parent = nullptr, MainWindow* mainWindow = nullptr, User thisStudent = User());
    ~StudentView();
    void closeEvent(QCloseEvent *event);
    void setStudent(std::string StudentID);  // Method to set the student
    void setupPage();  // Method to set up the page
    QString loadFont(const QString &resourcePath);  // Method to load the font
    
    void on_changePasswordButton_clicked();

private slots:
    void on_actionExit_triggered(QCloseEvent *event);
    void on_stackedWidget_currentChanged(int index);
    void on_profile_btn1_toggled();
    void on_profile_btn2_toggled();
    void on_course_btn1_toggled();
    void on_course_btn2_toggled();
    void on_grade_btn1_toggled();
    void on_grade_btn2_toggled();


private:
    Ui::StudentView *ui;
    MainWindow* mainWindow;
    User thisStudent;  
    LinkedList<Course> thisStudentCourse;
    LinkedList<Score> thisStudentScore;

    void setUpCourseList();  // Method to set up the course list
    void setUpGradeView();  // Method to set up the grade view

};

#endif // STUDENTVIEW_H
