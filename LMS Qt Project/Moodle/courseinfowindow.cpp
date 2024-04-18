#include "courseinfowindow.h"
#include "ui_courseinfowindow.h"
#include "fontloader.h"


CourseInfoWindow::CourseInfoWindow(QWidget *parent, const Course* thisCourse, int index)
    : QDialog(parent)
    , thisCourse(thisCourse)
    , index(index)
    , ui(new Ui::CourseInfoWindow)
{
    ui->setupUi(this);

    // Set fixed size
    this->setFixedSize(this->size());

    // Create semi-transparent black QWidget
    QWidget *darkenWidget = new QWidget(parent);
    darkenWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.7);");
    darkenWidget->resize(parent->size());
    darkenWidget->show();

    // Connect the signals and slots to show and hide the darkenWidget
    connect(this, &CourseInfoWindow::shown, darkenWidget, &QWidget::show);
    connect(this, &CourseInfoWindow::hidden, darkenWidget, &QWidget::hide);

    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");

    //Image
    //--------------START----------------

    QString pathToImage = ":/Asset/studentviewAsset/background" + QString::number(index%4 + 1) + ".jpg";
    QPixmap pixmap(pathToImage);
    QPixmap scaledPixmap = pixmap.scaled(ui->placeholder_image->size()*2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->placeholder_image->setPixmap(scaledPixmap);

    //--------------END----------------

    //Course Info
    //--------------START----------------

    ui->course_info_label->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->course_info_label->setFont(QFont(fontFamilyMedium, 13));
    ui->course_info_label->setText("  Course Infomation");

    //--------------END----------------

    //Set up Course name
    //--------------START----------------

    std::string courseName;
    courseName = courseName + thisCourse->courseID + " - " + thisCourse->courseName;
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


    ui->full_course_name->setStyleSheet("QLabel{ text-align: left; font-weight: 500; color: #0D63E6; border: none; }");
    ui->full_course_name->setFont(QFont(fontFamilyMedium, 20));
    ui->full_course_name->setText(qCourseName);

    //--------------END----------------

    //Course ID
    //--------------START----------------

    ui->course_id_label1->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->course_id_label1->setFont(QFont(fontFamilyBold, 14));

    ui->course_id_label2->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->course_id_label2->setFont(QFont(fontFamilyRegular, 13));
    ui->course_id_label2->setText(QString::fromStdString(thisCourse->courseID));

    //--------------END----------------

    //Course name
    //--------------START----------------

    ui->course_name_label1->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->course_name_label1->setFont(QFont(fontFamilyBold, 14));

    ui->course_name_label2->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->course_name_label2->setFont(QFont(fontFamilyRegular, 13));

    qCourseName = QString::fromStdString(thisCourse->courseName);
    wrapLen = 20;
    if (qCourseName.length() > wrapLen) {
        int lastSpace = qCourseName.lastIndexOf(' ', wrapLen);
        if (lastSpace != -1) {
            qCourseName = qCourseName.left(lastSpace) + "\n" + qCourseName.mid(lastSpace + 1);
        } else {
            qCourseName = qCourseName.left(wrapLen) + "\n" + qCourseName.mid(wrapLen);
        }
    }

    ui->course_name_label2->setText(qCourseName);


    //--------------END----------------

    //Class name
    //--------------START----------------

    ui->class_name_label1->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->class_name_label1->setFont(QFont(fontFamilyBold, 14));

    ui->class_name_label2->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->class_name_label2->setFont(QFont(fontFamilyRegular, 13));
    ui->class_name_label2->setText(QString::fromStdString(thisCourse->className));

    //--------------END----------------

    //Teacher Name
    //--------------START----------------

    ui->teacher_name_label1->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->teacher_name_label1->setFont(QFont(fontFamilyBold, 14));


    ui->teacher_name_label2->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->teacher_name_label2->setFont(QFont(fontFamilyRegular, 13));
    ui->teacher_name_label2->setText(QString::fromStdString(thisCourse->teacherName));

    //--------------END----------------

    //Credits
    //--------------START----------------

    ui->credits_label1->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->credits_label1->setFont(QFont(fontFamilyBold, 14));


    ui->credits_label2->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->credits_label2->setFont(QFont(fontFamilyRegular, 13));
    ui->credits_label2->setText(QString::fromStdString(thisCourse->credits));

    //--------------END----------------

    //Max Student
    //--------------START----------------
    ui->max_student_label1->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->max_student_label1->setFont(QFont(fontFamilyBold, 14));


    ui->max_student_label2->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->max_student_label2->setFont(QFont(fontFamilyRegular, 13));
    ui->max_student_label2->setText(QString::number(thisCourse->maxStudent));

    //--------------END----------------

    //Session
    //--------------START----------------

    ui->session_label1->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->session_label1->setFont(QFont(fontFamilyBold, 14));

    std::string time;
    std::string session = thisCourse->session;

    if (session == "S1") {
        time = "7:30";
    } else if (session == "S2") {
        time = "9:30";
    } else if (session == "S3") {
        time = "13:30";
    } else if (session == "S4") {
        time = "15:30";
    }



    ui->session_label2->setStyleSheet("QLabel{ text-align: left; font-weight: 500; border: none; }");
    ui->session_label2->setFont(QFont(fontFamilyRegular, 13));
    ui->session_label2->setText(QString::fromStdString(thisCourse->day + " " + time));


    //--------------END----------------


}

void CourseInfoWindow::showEvent(QShowEvent *event) {
    emit shown();
    QDialog::showEvent(event);
}

void CourseInfoWindow::hideEvent(QHideEvent *event) {
    emit hidden();
    QDialog::hideEvent(event);
}

CourseInfoWindow::~CourseInfoWindow()
{
    delete ui;
}
