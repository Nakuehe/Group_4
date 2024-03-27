#include "studentview.h"
#include "ui_studentview.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>




StudentView::StudentView(QWidget *parent, MainWindow* mainWindow, User thisStudent)
    : QMainWindow(parent)
    , mainWindow(mainWindow)
    , ui(new Ui::StudentView)
    , thisStudent(thisStudent)

{
    ui->setupUi(this);

    setupPage();
    setStudent(thisStudent.username);
    setUpCourseList();
    setUpGradeView();

    // for (int i = 0; i < thisStudentCourse.size(); i++) {
    //     ui->courseList->addItem(QString::fromStdString(thisStudentCourse.get(i).courseInfo.courseID));
    // }

}

void StudentView::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::warning(this, "Warning", "Are you sure you want to log out?",
                                   QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        this->close();
        mainWindow->showCentered(); // Show the MainWindow
    }
    else{
        event->ignore();
    }
}

void StudentView::setStudent(std::string StudentID){
    // Find courses that the student is in
    LinkedList<SchoolYear> schoolYears = mainWindow->SchoolYears;
    for (int i = 0; i < schoolYears.size(); i++) {
        LinkedList<Semester> semesters = schoolYears.get(i).semesters;
        for(int j = 0; j < semesters.size(); j++){
            LinkedList<Course> courses = semesters.get(j).courses;
            for (int k = 0; k < courses.size(); k++) {
                LinkedList<Student> students = courses.get(k).students;
                for (int h = 0; h < students.size(); h++) {
                    if (students.get(h).studentID == StudentID) {
                        thisStudentCourse.add(courses.get(k));
                    }
                }

                LinkedList<Score> scores = courses.get(k).Scoreboard;
                for (int h = 0; h < scores.size(); h++) {
                    if (scores.get(h).id_student == StudentID) {
                        thisStudentScore.add(scores.get(h));
                    }
                }
            }
        }
    }
}


StudentView::~StudentView()
{
    delete ui;
}



void StudentView::on_actionExit_triggered(QCloseEvent *event)
{
    int ret = QMessageBox::warning(this, "Warning", "Are you sure you want to log out?",
                                   QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        QMainWindow::closeEvent(event);
        parentWidget()->show(); // Show the MainWindow
    } else if (ret == QMessageBox::No) {
        event->ignore(); // Ignore the close event
    }
}



void StudentView::setupPage(){

    //setup font
    //start
    QString fontFamily = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    ui->profile_btn2->setFont(QFont(fontFamily, 12));
    ui->course_btn2->setFont(QFont(fontFamily, 12));
    ui->grade_btn2->setFont(QFont(fontFamily, 12));
    ui->exit_btn2->setFont(QFont(fontFamily, 12));
    ui->exit_btn2->setCursor(QCursor(Qt::PointingHandCursor));
    //end

    //hide full menu widget
    ui->full_menu_widget->hide();

    //initiallize page
    ui->stackedWidget->setCurrentIndex(1);
    ui->course_btn1->toggle();

    //connect exit button with exit action
    connect(ui->exit_btn1, &QPushButton::clicked, this, &StudentView::close);
    ui->exit_btn1->setCursor(QCursor(Qt::PointingHandCursor));

    // Connect changePasswordButton's clicked signal to the slot
    connect(ui->changePasswordButton, &QPushButton::clicked, this, &StudentView::on_changePasswordButton_clicked);
    ui->changePasswordButton->setCursor(QCursor(Qt::PointingHandCursor));
}

QString StudentView::loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

void StudentView::on_stackedWidget_currentChanged(int index) {
    QList<QPushButton*> btnList = ui->icon_only_widget->findChildren<QPushButton*>();
    btnList.append(ui->full_menu_widget->findChildren<QPushButton*>());

    for(QPushButton* btn : btnList) {
            btn->setAutoExclusive(true);
    }
}

void StudentView::setUpCourseList() {
    LinkedList<Course> curCourses = thisStudentCourse;
    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamily2 = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");

    QWidget *page = ui->stackedWidget->widget(1); // Get the page at index 1
    QGridLayout *layout = page->findChild<QGridLayout*>(); // Find the grid layout in this page
    int row = 0, col = 0;
    for (int i = 0; i < 9; i++) { // Loop 9 times for 9 slots
        QWidget *widget = new QWidget(this);
        QVBoxLayout *widgetLayout = new QVBoxLayout(this);
        widget->setLayout(widgetLayout);
        QLabel *label = new QLabel(this);
        QPushButton *btn_course = new QPushButton(this);
        btn_course->setFlat(true);
        btn_course->setStyleSheet("QPushButton:hover { color: #ff6600; } QPushButton:pressed { background-color: transparent; } QPushButton { text-align: left; font-weight: 500; color: #0D63E6; border: none; }");
        btn_course->setFont(QFont(fontFamily2, 16));
        btn_course->setCursor(QCursor(Qt::PointingHandCursor));
        
        btn_course->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        label->setTextFormat(Qt::RichText);
        label->setStyleSheet("QWidget { border: none; }");
        widgetLayout->addWidget(btn_course);
        widgetLayout->addWidget(label);
        widgetLayout->setContentsMargins(10, 5, 5, 15);

        if (i < curCourses.size()) { // If there are courses left
            Course curCourse = curCourses.get(i);
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            std::string courseName;
            courseName = courseName + curCourse.courseID + " - " + curCourse.courseName;
            QString qCourseName = QString::fromStdString(courseName);
            int wrapLen = 30;
            if (qCourseName.length() > wrapLen) {
                int lastSpace = qCourseName.lastIndexOf(' ', wrapLen);
                if (lastSpace != -1) {
                    qCourseName = qCourseName.left(lastSpace) + "\n" + qCourseName.mid(lastSpace + 1);
                } else {
                    qCourseName = qCourseName.left(wrapLen) + "\n" + qCourseName.mid(wrapLen);
                }
            }
            btn_course->setText(qCourseName);
            
            std::string time;
            std::string session = curCourse.session;
            if (session == "S1") {
                time = "7:30";
            } else if (session == "S2") {
                time = "9:30";
            } else if (session == "S3") {
                time = "13:30";
            } else if (session == "S4") {
                time = "15:30";
            }
            std::string text;
            label->setFont(QFont(fontFamily1, 12));
            text = text + "<p style=\"color:#0D63E6;\">" + time + " " + curCourse.day + "</p>";
            text = text + "<p>Teacher: " + "<font color=#0D63E6>" + curCourse.teacherName + "</font></p>";
            label->setText(QString::fromStdString(text));
        } else { // If there are no courses left
            widget->setStyleSheet("QWidget { border: none; }"); // Set the style to invisible
            btn_course->hide(); // Hide the button
            label->hide(); // Hide the label
        }

        layout->addWidget(widget, row, col);
        col++;
        if (col == 3) {
            col = 0;
            row++;
        }
    }
}

void StudentView::setUpGradeView(){
    
    QStandardItemModel *model = new QStandardItemModel(thisStudentScore.size(), 6, this); 
    for (int row = 0; row < thisStudentScore.size(); ++row) {
        QString courseID = QString::fromStdString(thisStudentScore.get(row).courseID);
        QString courseName = QString::fromStdString(thisStudentScore.get(row).courseName);
        QString midterm = thisStudentScore.get(row).mid_mark == 0 ? "_" : QString::number(thisStudentScore.get(row).mid_mark);
        QString final = thisStudentScore.get(row).final_mark == 0 ? "_" : QString::number(thisStudentScore.get(row).final_mark);
        QString bonus = thisStudentScore.get(row).other_mark == 0 ? "_" : QString::number(thisStudentScore.get(row).other_mark);
        QString total = thisStudentScore.get(row).GPA == 0 ? "_" : QString::number(thisStudentScore.get(row).GPA);

        QStandardItem *item1 = new QStandardItem(QString(courseID));
        model->setItem(row, 0, item1);
        QStandardItem *item2 = new QStandardItem(QString(courseName));
        model->setItem(row, 1, item2);
        QStandardItem *item3 = new QStandardItem(QString(midterm));
        model->setItem(row, 2, item3);
        QStandardItem *item4 = new QStandardItem(QString(final));
        model->setItem(row, 3, item4);
        QStandardItem *item5 = new QStandardItem(QString(bonus));
        model->setItem(row, 4, item5);
        QStandardItem *item6 = new QStandardItem(QString(total));
        model->setItem(row, 5, item6);
    }

    QTableView *tableView = new QTableView;
    tableView->setModel(model);

    QWidget *page = ui->stackedWidget->widget(2); // Get the page at index 2

    QVBoxLayout *layout = new QVBoxLayout(page); // Create a QVBoxLayout for the page
    layout->addWidget(tableView); // Add the QTableView to the layout
    page->setLayout(layout); // Set the layout of the page
}

void StudentView::on_profile_btn1_toggled() {
    ui->stackedWidget->setCurrentIndex(0);
}

void StudentView::on_profile_btn2_toggled() {
    ui->stackedWidget->setCurrentIndex(0);
}

void StudentView::on_course_btn1_toggled() {
    ui->stackedWidget->setCurrentIndex(1);
}

void StudentView::on_course_btn2_toggled() {
    ui->stackedWidget->setCurrentIndex(1);
}

void StudentView::on_grade_btn1_toggled() {
    ui->stackedWidget->setCurrentIndex(2);
}

void StudentView::on_grade_btn2_toggled() {
    ui->stackedWidget->setCurrentIndex(2);
}

void StudentView::on_changePasswordButton_clicked() {
    ChangePasswordDialog dialog(this, thisStudent, mainWindow->getUserManager());
    dialog.exec();
}
