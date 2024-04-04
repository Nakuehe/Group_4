#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QPainter>
#include <QCloseEvent>
#include <QLabel>
#include <QMessageBox>

#include <QFontDatabase>
#include "mainwindow.h"
#include "Student.h"
#include <QDesktopServices>
#include "Course.h"
#include "User.h"

#include <string>

class MainWindow;

class RoundAvatarLabel : public QLabel {
    Q_OBJECT

public:
    RoundAvatarLabel(QWidget *parent = nullptr) : QLabel(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override {
        QPixmap pixmap(":/Asset/studentviewAsset/profile.png");
        QPixmap scaled = pixmap.scaled(width(), height(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        QBrush brush(scaled);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::transparent); // Set the pen to a transparent color
        painter.setBrush(brush);
        painter.drawRoundedRect(0, 0, width(), height(), width() / 2, height() / 2);
        QLabel::paintEvent(event);
    }
};

namespace Ui {
class StudentView;
}

class StudentView : public QMainWindow
{
    Q_OBJECT

public:
    //(nullptr, this, user, student, this->m_userManager)
    explicit StudentView(QWidget *parent = nullptr, MainWindow* mainWindow = nullptr, User thisStudentUser = User(), Student thisStudent = Student(), UserManager *s_UserManager = nullptr);
    ~StudentView();

    void setStudent(std::string StudentID);  // Method to set the student
    void setupPage();  // Method to set up the page
    QString loadFont(const QString &resourcePath);  // Method to load the font

    void on_changePasswordButton_clicked();

public slots:
    void menu_btn_toggled(bool checked);

private slots:
    void on_actionExit_triggered(QCloseEvent *event);
    void on_stackedWidget_currentChanged(int index);
    void on_profile_btn1_toggled();
    void on_profile_btn2_toggled();
    void on_course_btn1_toggled();
    void on_course_btn2_toggled();
    void on_grade_btn1_toggled();
    void on_grade_btn2_toggled();
    void resizeColumns();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::StudentView *ui;
    MainWindow* mainWindow;
    UserManager* s_UserManager;
    User thisStudentUser;
    Student thisStudent;
    LinkedList<Course>* thisStudentCourse;
    LinkedList<Score>* thisStudentScore;
    QStandardItemModel *model;

    void setUpCourseList();  // Method to set up the course list
    void setUpGradeView();  // Method to set up the grade view
    void setUpProfile();  // Method to set up the profile

};

#endif // STUDENTVIEW_H
