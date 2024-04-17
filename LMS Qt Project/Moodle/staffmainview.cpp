#include "staffmainview.h"
#include "staffsideview.h"
#include "ui_staffmainview.h"
#include "Semester.h"
#include "table_view_form/studentviewtable.h"
#include "scoreboarddialog.h"
#include "updateStudentResult.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QLabel>
#include <QFileDialog>

StaffMainView::StaffMainView(QWidget *parent, StaffSideView* staffSideView, SchoolYear* this_year)
    : QMainWindow(parent)
    , staffSideView(staffSideView)
    , this_year(this_year)
    , ui(new Ui::StaffMainView)
{
    ui->setupUi(this);
    setUpPage();
    setUpSemesters();
    setUpClasses();
}

StaffMainView::~StaffMainView()
{
    delete ui;
}

QString StaffMainView::loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

void StaffMainView::on_stackedWidget_currentChanged(int index) {
    QList<QPushButton*> btnList = ui->icon_only_widget->findChildren<QPushButton*>();
    btnList.append(ui->full_menu_widget->findChildren<QPushButton*>());

    for(QPushButton* btn : btnList) {
        btn->setAutoExclusive(true);
    }
}

void StaffMainView::setUpPage(){
    //setup font
    //start
    QString fontFamily = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");

    ui->semester_btn2->setFont(QFont(fontFamily, 12));
    ui->class_btn2->setFont(QFont(fontFamily, 12));

    ui->exit_btn2->setFont(QFont(fontFamily, 12));
    ui->exit_btn2->setCursor(QCursor(Qt::PointingHandCursor));
    //end

    //hide full menu widget
    ui->full_menu_widget->hide();
    connect(ui->menu_btn, &QPushButton::toggled, this, &StaffMainView::menu_btn_toggled);
    ui->menu_btn->setCursor(QCursor(Qt::PointingHandCursor));


    //initiallize page
    ui->stackedWidget->setCurrentIndex(0);
    ui->semester_btn1->toggle();

    //connect exit button with exit action
    connect(ui->exit_btn1, &QPushButton::clicked, this, &StaffMainView::close);
    ui->exit_btn1->setCursor(QCursor(Qt::PointingHandCursor));


}
void StaffMainView::closeEvent(QCloseEvent *event){
    this->close();
    staffSideView->show();
}

void StaffMainView::setUpClasses(){
    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamily2 = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");

    QWidget *page = ui->stackedWidget->widget(1); // Get the page at index 1
    QGridLayout *layout = page->findChild<QGridLayout*>(); // Find the grid layout in this page
    int row = 0, col = 0;
    for (int i = 0; i < 9; i++) { // Loop 9 times for 9 slots
        QWidget *widget = new QWidget(this);
        widget->setFixedSize(280, 170);
        QVBoxLayout *widgetLayout = new QVBoxLayout(widget); // Set the QVBoxLayout to the widget
        QPushButton *btn_class = new QPushButton(widget); // Set the QPushButton to the widget
        btn_class->setFlat(true);
        btn_class->setStyleSheet("QPushButton:hover { color: #ff6600; } QPushButton:pressed { background-color: transparent; } QPushButton { text-align: center; font-weight: 500; color: #0D63E6; border: none; }");
        btn_class->setFont(QFont(fontFamily2, 16));
        btn_class->setCursor(QCursor(Qt::PointingHandCursor));
        btn_class->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);

        widgetLayout->addWidget(btn_class);
        widgetLayout->setContentsMargins(10, 5, 5, 15);

        if (i < this_year->classes.size()) { // If there are semesters left
            Class* curClass = &this_year->classes.get(i);
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            btn_class->setText(QString::fromStdString(curClass->classID));

            connect(btn_class, &QPushButton::clicked, this, [this, i, curClass]() {
                classViewSetup(*curClass);
                ui->stackedWidget->setCurrentIndex(4);
            });

        } else if (i == this_year->classes.size()) { // If this is the "Add Class" button
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            btn_class->setIcon(QIcon(":/Asset/staffViewAsset/addButton.png"));
            btn_class->setIconSize(QSize(48, 48)); // Adjust size as needed

            connect(btn_class, &QPushButton::clicked, this, [=]() {
                //to be implemented
            });
        } else { // If there are no buttons left
            widget->setStyleSheet("QWidget { border: none; }"); // Set the style to invisible
            btn_class->hide(); // Hide the button
        }

        layout->addWidget(widget, row, col);
        col++;
        if (col == 3) {
            col = 0;
            row++;
        }
    }
}


void StaffMainView::setUpSemesters(){
    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamily2 = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");

    QWidget *page = ui->stackedWidget->widget(0); // Get the page at index 0
    QGridLayout *layout = page->findChild<QGridLayout*>(); // Find the grid layout in this page
    int row = 0, col = 0;
    for (int i = 0; i < 9; i++) { // Loop 9 times for 9 slots
        QWidget *widget = new QWidget(this);
        widget->setFixedSize(280, 170);
        QVBoxLayout *widgetLayout = new QVBoxLayout(widget); // Set the QVBoxLayout to the widget
        QPushButton *btn_semester = new QPushButton(widget); // Set the QPushButton to the widget
        btn_semester->setFlat(true);
        btn_semester->setStyleSheet("QPushButton:hover { color: #ff6600; } QPushButton:pressed { background-color: transparent; } QPushButton { text-align: center; font-weight: 500; color: #0D63E6; border: none; }");
        btn_semester->setFont(QFont(fontFamily2, 16));
        btn_semester->setCursor(QCursor(Qt::PointingHandCursor));
        btn_semester->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);

        widgetLayout->addWidget(btn_semester);
        widgetLayout->setContentsMargins(10, 5, 5, 15);

        if (i < this_year->semesters.size()) { // If there are semesters left
            Semester* curSemester = &this_year->semesters.get(i);
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            btn_semester->setText(QString::fromStdString(curSemester->semester));

            connect(btn_semester, &QPushButton::clicked, this, [=]() {
                this_semester = curSemester;
                setUpCourses(&(curSemester->courses));
                ui->stackedWidget->setCurrentIndex(2);
            });
        } else if (i == this_year->semesters.size()) { // If this is the "Add Semester" button
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            btn_semester->setIcon(QIcon(":/Asset/staffViewAsset/addButton.png"));
            btn_semester->setIconSize(QSize(48, 48)); // Adjust size as needed

            connect(btn_semester, &QPushButton::clicked, this, [=]() {
                this_year->createSemester();
                setUpSemesters();
            });
        } else { // If there are no buttons left
            widget->setStyleSheet("QWidget { border: none; }"); // Set the style to invisible
            btn_semester->hide(); // Hide the button
        }

        layout->addWidget(widget, row, col);
        col++;
        if (col == 3) {
            col = 0;
            row++;
        }
    }
}

void StaffMainView::setUpCourses(LinkedList<Course>* curCourses){

    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamily2 = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");

    QWidget *page = ui->stackedWidget->widget(2); // Get the page at index 2
    QGridLayout *layout = page->findChild<QGridLayout*>(); // Find the grid layout in this page
    int row = 0, col = 0;
    for (int i = 0; i < 9; i++) { // Loop 9 times for 9 slots
        QWidget *widget = new QWidget(this);
        widget->setFixedSize(280, 170);
        QVBoxLayout *widgetLayout = new QVBoxLayout();
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

        if (i < curCourses->size()) { // If there are courses left
            Course* curCourse = &curCourses->get(i);
            courses.append(*curCourse);

            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            std::string courseName;
            courseName = courseName + curCourse->courseID + " - " + curCourse->courseName;
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

            //course function implementation
            connect(btn_course, &QPushButton::clicked, this, [this, i, curCourse]() {
                this_course = curCourse;
                courseViewSetUp(*curCourse);
                ui->stackedWidget->setCurrentIndex(3);
            });

            std::string time;
            std::string session = curCourse->session;
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
            text = text + "<p style=\"color:#0D63E6;\">" + time + " " + curCourse->day + "</p>";
            text = text + "<p>Teacher: " + "<font color=#0D63E6>" + curCourse->teacherName + "</font></p>";
            label->setText(QString::fromStdString(text));
        } else if (i == curCourses->size() + 1) { // If this is the "Back" button
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            btn_course->setIcon(QIcon(":/Asset/staffViewAsset/backButton.png"));    
            btn_course->setIconSize(QSize(48, 48)); // Adjust size as needed

            widgetLayout->removeWidget(label); // Remove the label from the layout
            label->deleteLater(); // Schedule the label for deletion
            btn_course->setStyleSheet("QPushButton:hover { color: #ff6600; } QPushButton:pressed { background-color: transparent; } QPushButton { text-align: center; font-weight: 500; color: #0D63E6; border: none; }");
            //widgetLayout->setAlignment(btn_course, Qt::AlignCenter); // Center the button

            connect(btn_course, &QPushButton::clicked, this, [=]() {
                ui->stackedWidget->setCurrentIndex(0);
            });
        }

        else if(i == curCourses->size()){
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            btn_course->setIcon(QIcon(":/Asset/staffViewAsset/addButton.png"));
            btn_course->setIconSize(QSize(48, 48)); // Adjust size as needed

            widgetLayout->removeWidget(label); // Remove the label from the layout
            label->deleteLater(); // Schedule the label for deletion
            btn_course->setStyleSheet("QPushButton:hover { color: #ff6600; } QPushButton:pressed { background-color: transparent; } QPushButton { text-align: center; font-weight: 500; color: #0D63E6; border: none; }");
            //widgetLayout->setAlignment(btn_course, Qt::AlignCenter); // Center the button

            connect(btn_course, &QPushButton::clicked, this, [=]() {
                //to be implemented
            });
        }

        else { // If there are no courses left
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

void StaffMainView::courseViewSetUp(Course& this_course){
    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamily2 = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");

    std::string courseName;
    courseName = courseName + this_course.courseID + " - " + this_course.courseName;

    ui->course_label->setText(QString::fromStdString(courseName));
    ui->course_label->setFont(QFont(fontFamily2, 15));

    ui->backButton->setFont(QFont(fontFamily1, 12));
    ui->backButton->setFlat(true);
    ui->backButton->setCursor(QCursor(Qt::PointingHandCursor));

    // Connect the backButton's clicked signal to a lambda function
    connect(ui->backButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    student_list = &this_course.students;


    ui->course_function_list->setFont(QFont(fontFamily1, 12));

    // Disconnect the signal before connecting it again
    disconnect(ui->course_function_list, &QListWidget::itemClicked, this, &StaffMainView::onCourseListItemClicked);
    connect(ui->course_function_list, &QListWidget::itemClicked, this, &StaffMainView::onCourseListItemClicked);
}

void StaffMainView::classViewSetup(Class& this_class){
    QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamily2 = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");

    ui->class_name->setText(QString::fromStdString(this_class.classID));
    ui->class_name->setFont(QFont(fontFamily2, 15));

    ui->backButton2->setFont(QFont(fontFamily1, 12));
    ui->backButton2->setFlat(true);
    ui->backButton2->setCursor(QCursor(Qt::PointingHandCursor));

    // Connect the backButton's clicked signal to a lambda function
    connect(ui->backButton2, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    student_list = &this_class.students;


    ui->class_function_list->setFont(QFont(fontFamily1, 12));

    // Disconnect the signal before connecting it again
    disconnect(ui->class_function_list, &QListWidget::itemClicked, this, &StaffMainView::onClassListItemClicked);
    connect(ui->class_function_list, &QListWidget::itemClicked, this, &StaffMainView::onClassListItemClicked);
}

void StaffMainView::onCourseListItemClicked(QListWidgetItem* item)
{
    if(ui->course_function_list->row(item) == 0) // if the first item was clicked
    {
        StudentViewTable* studentViewTable = new StudentViewTable(this, student_list);
        studentViewTable->show();
        }

    if(ui->course_function_list->row(item) == 6) // if the sixth item was clicked
        {
        QString filename = QFileDialog::getOpenFileName(
            this,
            "Open CSV file",
            "data", // Start in the 'data' directory
            "CSV Files (*.csv);;All Files (*)" // Filter for .csv files
            );

        if (!filename.isEmpty()) {
            this->this_course->read_students_from_CSV(filename);
        }
        }

    if(ui->course_function_list->row(item) == 8) // if the sixth item was clicked
    {
        int ret = QMessageBox::warning(this, "Warning", "Are you sure you want to delete this course?",
                                    QMessageBox::Yes | QMessageBox::No);

        if (ret == QMessageBox::Yes) {
            this_semester->removeCourse(*this_course);
            this_course = nullptr;
            setUpCourses(&(this_semester->courses));
            ui->stackedWidget->setCurrentIndex(2);
        }
    }
    if(ui->course_function_list->row(item) == 1) // view scoreboard
    {
        ScoreboardDialog* dialog = new ScoreboardDialog(this,this_course,0);
        dialog->show();
    }
    if(ui->course_function_list->row(item) == 3) // update student result
    {
        updateStudentResult* dialog_up = new updateStudentResult(this,this_course);
        dialog_up->show();
    }
}
void StaffMainView::onClassListItemClicked(QListWidgetItem* item)
{
    if(ui->class_function_list->row(item) == 2) // if the third item was clicked
    {
        StudentViewTable* studentViewTable = new StudentViewTable(this, student_list);
        studentViewTable->show();
    }
}

void StaffMainView::menu_btn_toggled(bool checked) {
    // Show or hide the full_menu_widget and icon_only_widget
    ui->icon_only_widget->setHidden(checked);
    ui->full_menu_widget->setVisible(checked);
}



void StaffMainView::on_semester_btn1_toggled() {
    ui->stackedWidget->setCurrentIndex(0);
}

void StaffMainView::on_semester_btn2_toggled() {
    ui->stackedWidget->setCurrentIndex(0);
}

void StaffMainView::on_class_btn1_toggled() {
    ui->stackedWidget->setCurrentIndex(1);
}

void StaffMainView::on_class_btn2_toggled() {
    ui->stackedWidget->setCurrentIndex(1);
}

