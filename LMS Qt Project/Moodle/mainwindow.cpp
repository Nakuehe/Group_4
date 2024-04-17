#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Course.h"
#include "Student.h"
#include "testform.h"
#include "studentview.h"
#include "staffsideview.h"
#include "Class.h"



QString loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_userManager = new UserManager(QCoreApplication::applicationDirPath() + "/data/users.csv", QCoreApplication::applicationDirPath() + "/data/students.csv");

    setupPage();
    m_userManager->loadUsers();
    m_userManager->loadStudents();
    


    Student student = Student("23125061", "Pham", "Gia Hung Khoa", "Male", "09/05/2005", "049205000001");
    Student student2 = Student("23125093", "Le", "Thi Tuyet Tram", "Female", "14/04/2005", "0xx105xxxxxx");

    Course course = Course("CS162", "Introduction to Programming", "23APCS02", "Dinh Ba Tien", "4", 50, "WED", "S3");
    Course course2 = Course("MTH252", "Calculus II", "23APCS02", "Phan Thi My Duyen", "4", 50, "FRI", "S1");
    Course course3 = Course("BAA00004", "General Law", "23APCS", "Hoang Thanh Tu", "3", 50, "MON", "S3");
    Course course4 = Course("PH212", "General Physic II", "23APCS02", "Do Duc Cuong", "4", 50, "SAT", "S4");

    Score score1 = Score("23125061", "Pham Khoa", "CS162", "Introduction to Programming", 8.5, 9.0, 0, 8.5);
    Score score2 = Score("23125061", "Pham Khoa", "MTH252", "Calculus II", 8.5, 9.0, 10, 10);
    Score score3 = Score("23125061", "Pham Khoa", "BAA00004", "General Law", 8.5, 0, 8.0, 8.5);
    Score score4 = Score("23125061", "Pham Khoa", "PH212", "General Physic II", 8.5, 9.0, 0, 8.5);

    Class class1 = Class("23APCS02");
    Class class2 = Class("23CLC03");



    Semester semester = Semester("Semester 1");

    course.addStudent(student);
    course.addStudent(student2);

    course2.addStudent(student);
    course3.addStudent(student);
    course4.addStudent(student);

    class1.addStudent(student);
    // class2.addStudent(student);


    course.addScore(score1);
    course2.addScore(score2);
    course3.addScore(score3);
    course4.addScore(score4);

    semester.addCourse(course);
    semester.addCourse(course2);
    semester.addCourse(course3);
    semester.addCourse(course4);

    SchoolYear year = SchoolYear("2023-2024", "01/09/2023", "01/06/2024");
    year.addSemester(semester);
    year.addClass(class1);
    year.addClass(class2);

    SchoolYear year2 = SchoolYear("2022-2023", "01/09/2022", "01/06/2023");

    this->SchoolYears.addSorted(year);
    this->SchoolYears.addSorted(year2);

    
}



void MainWindow::setupPage(){
    QString font1Family = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");
    QString font2Family = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");

    //Group box
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(20); // Adjust the blur radius
    effect->setOffset(0, 0); // Adjust the offset
    ui->groupBox->setGraphicsEffect(effect);


    //Log in button

    QFont font1(font1Family);
    font1.setPointSize(15);
    ui->pushButtonLogin->setFont(font1);
    QPalette palette = ui->pushButtonLogin->palette();
    palette.setColor(QPalette::ButtonText, Qt::white); // Set the color of the font
    ui->pushButtonLogin->setPalette(palette);
    ui->pushButtonLogin->setCursor(QCursor(Qt::PointingHandCursor));

    //Description part

    QFont font2(font2Family);
    font2.setPointSize(15);
    //ui->label_2->setFont(font2);

    //Username line

    ui->lineEdit->setPlaceholderText("Username");
    ui->lineEdit->setFont(font2);

    // Password line

    font2.setPointSize(12);
    ui->lineEditPassword->setFont(font2);

    // Set the initial icon
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->pushButtonShowPassword->setIcon(QIcon(":/asset/loginpageAsset/hide.png"));

    // Connect the clicked signal to a slot
    connect(ui->pushButtonShowPassword, &QPushButton::clicked, this, &MainWindow::togglePasswordVisibility);

    // for placeholder Qlabel
    font2.setPointSize(15);
    ui->labelPlaceholder->setFont(font2);
    palette = ui->labelPlaceholder->palette();
    palette.setColor(QPalette::WindowText, Qt::gray);
    ui->labelPlaceholder->setPalette(palette);
    ui->labelPlaceholder->setAttribute(Qt::WA_TransparentForMouseEvents); // Make it click-through-able

    //Enter to login
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_pushButtonLogin_clicked);
    connect(ui->lineEditPassword, &QLineEdit::returnPressed, this, &MainWindow::on_pushButtonLogin_clicked);

    //press tab to switch between fields
    QWidget::setTabOrder(ui->lineEdit, ui->lineEditPassword);
}

void MainWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEditPassword->text();



    if (m_userManager->authenticateUser(username, password)){
        User user = m_userManager->findUser(username, password);
        if(user.role == "student"){
            Student student = m_userManager->findStudent(username);
        StudentView* studentView = new StudentView(nullptr, this, user, student, this->m_userManager);
        studentViews.append(studentView);
        connect(studentView, &QObject::destroyed, this, [=]() {
            studentViews.removeOne(studentView);
        });
        connect(studentView, &StudentView::closed, this, [=]() {
            deleteStudentView(studentView);
        });

        studentView->show();
        this->hide(); // Hide the MainWindow
    }
        else{ //staff view
            StaffSideView* staffSideView = new StaffSideView(nullptr, this, &SchoolYears);
            staffSideViews.append(staffSideView);
            connect(staffSideView, &QObject::destroyed, this, [=]() {
                staffSideViews.removeOne(staffSideView);
            });
            staffSideView->setAttribute(Qt::WA_DeleteOnClose);
            staffSideView->show();
            this->hide(); // Hide the MainWindow

            // //Test Table
            // TestForm* testForm = new TestForm(nullptr);
            // testForm->show();
            // this->hide();
        }
    } else {
        // Login failed
        QMessageBox::warning(this, "Login", "Username or password is incorrect.");
    }
}

void MainWindow::showCentered() {
     // Get the screen size
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    // Get the window size
    int windowWidth = this->width();
    int windowHeight = this->height();

    // Calculate the position to center the window
    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2 - 50; // Subtract 50 to offset for the taskbar

    // Move the window to the center position
    this->move(posX, posY);

    // Show the window
    this->show();
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->lineEdit->setStyleSheet("QLineEdit { border: 1px solid rgb(212, 212, 212); border-radius: 10px; color: black; padding-left: 15px; } QLineEdit:focus{border: 1px solid blue}" );
}




void MainWindow::on_lineEditPassword_textChanged(const QString &arg1)
{
    ui->lineEditPassword->setStyleSheet("QLineEdit { border: 1px solid rgb(212, 212, 212); border-radius: 10px; color: black; padding-left: 15px; } QLineEdit:focus{border: 1px solid blue}");
    ui->labelPlaceholder->setVisible(arg1.isEmpty());

}

void MainWindow::on_lineEditPassword_focusChanged(bool hasFocus)
{
    ui->labelPlaceholder->setVisible(!hasFocus && ui->lineEditPassword->text().isEmpty());
}

void MainWindow::togglePasswordVisibility()
{
    QFont font = ui->lineEditPassword->font();
    if (ui->lineEditPassword->echoMode() == QLineEdit::Password) {
        // The password is hidden, show it and set the "hide" icon
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
        ui->pushButtonShowPassword->setIcon(QIcon(":/asset/loginpageAsset/show.png"));
        font.setPointSize(15); // Set the font size to 15
    } else {
        // The password is shown, hide it and set the "unhide" icon
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
        ui->pushButtonShowPassword->setIcon(QIcon(":/asset/loginpageAsset/hide.png"));
        font.setPointSize(12); // Set the font size back to 12
    }
    ui->lineEditPassword->setFont(font); // Apply the font changes
}

void MainWindow::deleteStudentView(StudentView* studentView) {
    delete studentView;
}

MainWindow::~MainWindow()
{
    // Iterate over all SchoolYear objects in SchoolYears
    while (!SchoolYears.isEmpty()) {
        SchoolYear year = SchoolYears.removeFirst();

        // Iterate over all Semester objects in each SchoolYear
        while (!year.semesters.isEmpty()) {
            Semester semester = year.semesters.removeFirst();

            // Iterate over all Course objects in each Semester
            while (!semester.courses.isEmpty()) {
                Course course = semester.courses.removeFirst();

                // Iterate over all Student objects in each Course
                while (!course.students.isEmpty()) {
                    course.students.removeFirst();
                }

                while(!course.Scoreboard.isEmpty()){
                    course.Scoreboard.removeFirst();
                }
            }
        }

        while(!year.classes.isEmpty()){
            Class this_class = year.classes.removeFirst();

            while(!this_class.students.isEmpty()){
                this_class.students.removeFirst();
            }
        }
    }

    // m_userManager.changePassword("23125061", "newpassword");
    m_userManager->saveUsers();
    m_userManager->saveStudents();

    m_userManager->deleteThis();

    delete m_userManager;



    delete ui;
}
