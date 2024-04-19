#include "staffsideview.h"

#include "mainwindow.h"
#include "ui_staffsideview.h"
#include "QAbstractItemView"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include "fontloader.h"
#include "changepassworddialog.h"
#include <QInputDialog>
#include "dateinputdialog.h"
#include <QDebug>
#include "Semester.h"
StaffSideView::StaffSideView(QWidget *parent, MainWindow* mainWindow, User thisStaffUser, UserManager* s_UserManager,LinkedList<SchoolYear>* SchoolYears)
    : QDialog(parent)
    , SchoolYears(SchoolYears)
    , mainWindow(mainWindow)
    , thisStaffUser(thisStaffUser)
    , s_UserManager(s_UserManager)
    , ui(new Ui::StaffSideView)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Asset/loginpageAsset/logo.png"));
    this->setWindowTitle("Course");

    // Set the font for this page

    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");

    // Populate the combo box with school years

    for(int i = 0; i < SchoolYears->size(); i++){
        SchoolYear* this_year = &SchoolYears->get(i);
        ui->school_year_box->addItem(QString::fromStdString(this_year->year));
    }

    // Connect the confirm button's clicked signal to a slot
    connect(ui->confirm_button, &QPushButton::clicked, this, &StaffSideView::onConfirmButtonClicked);

    // Connect the add school year button's clicked signal to a slot
    connect(ui->add_school_year_button, &QPushButton::clicked, this, &StaffSideView::onAddSchoolYearButtonClicked);


    // Set font for greeting_label
    ui->greeting_label->setStyleSheet("QLabel{ text-align: left; font-weight: 500; color: #0D63E6; border: none; }");
    ui->greeting_label->setFont(QFont(fontFamilyMedium, 16));

    ui->school_year_box->setStyleSheet("QComboBox {"
                            "combobox-popup: 0;"
                            "background: transparent;"
                            "border: 1px solid rgb(212, 212, 212);"
                            "border-radius: 8px;"
                            "color: black;"
                            "padding-left: 15px;"
                            "}"
                            "QComboBox::hover {"
                            "background: rgb(212, 212, 212);"
                            "}"
                            "QComboBox::drop-down { width: 0px; }");

    ui->school_year_box->view()->setStyleSheet("QListView{"
                        "border:1px solid red;"
                        "border-radius: 8px;"
                        "}");

    ui->school_year_box->view()->window()->setWindowFlags( Qt::Popup | Qt::FramelessWindowHint |Qt::NoDropShadowWindowHint);
    ui->school_year_box->view()->window()->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(20); // Adjust the blur radius
    effect->setOffset(0, 0); // Adjust the offset
    ui->groupBox->setGraphicsEffect(effect);

    ui->school_year_box->setFont(QFont(fontFamilyRegular, 14));

    ui->add_school_year_button->setCursor(QCursor(Qt::PointingHandCursor));
    ui->add_school_year_button->setFont(QFont(fontFamilyBold, 15));

    ui->confirm_button->setCursor(QCursor(Qt::PointingHandCursor));
    ui->confirm_button->setFont(QFont(fontFamilyBold, 15));

    connect(ui->changePasswordButton, &QPushButton::clicked, this, &StaffSideView::on_changePasswordButton_clicked);
    ui->changePasswordButton->setFlat(true);
    ui->changePasswordButton->setStyleSheet("QPushButton:hover { color: #ff6600; text-decoration: underline;} QPushButton:pressed { background-color: transparent; } QPushButton { text-align: center; font-weight: 500; color: #0D63E6; border: none; }");
    ui->changePasswordButton->setFont(QFont(fontFamilyRegular, 12));
    ui->changePasswordButton->setCursor(QCursor(Qt::PointingHandCursor));


}

void StaffSideView::on_changePasswordButton_clicked(){
    ChangePasswordDialog dialog(this, thisStaffUser, s_UserManager);
    dialog.exec();
}

void StaffSideView::onConfirmButtonClicked()
{
    QString selectedSchoolYear = ui->school_year_box->currentText();
    for (int i = 0; i < SchoolYears->size(); i++) {

        SchoolYear* schoolYear = &SchoolYears->get(i);

        QString check_name = QString::fromStdString(schoolYear->year);

        if (check_name == selectedSchoolYear) {
            StaffMainView* staffMainView = new StaffMainView(nullptr, this, schoolYear,SchoolYears);
            staffMainView->setAttribute(Qt::WA_DeleteOnClose);
            staffMainView->show();
            this->hide(); // Hide the MainWindow
            break;
        }
    }
}

void StaffSideView::closeEvent(QCloseEvent *event){
    int ret = QMessageBox::warning(this, "Warning", "Are you sure you want to log out?",
                                   QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        this->close();
        mainWindow->showCentered();
    }
    else{
        event->ignore();
    }
}

// Slot for handling the add school year button's clicked signal
void StaffSideView::onAddSchoolYearButtonClicked()
{
    this->createYear();// create new year and back to staff view
    QString fontFamilyRegular = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
    QString fontFamilyMedium = loadFont(":/asset/font/Helvetica Neue/helveticaneuemedium.ttf");
    QString fontFamilyBold = loadFont(":/asset/font/Helvetica Neue/HelveticaNeue-Bold.otf");

    // Populate the combo box with school years
    ui->school_year_box->clear();//clear all item in comboBox
    for(int i = 0; i < SchoolYears->size(); i++){
        SchoolYear* this_year = &SchoolYears->get(i);
        ui->school_year_box->addItem(QString::fromStdString(this_year->year));
    }

    // Connect the confirm button's clicked signal to a slot
    connect(ui->confirm_button, &QPushButton::clicked, this, &StaffSideView::onConfirmButtonClicked);

    // Connect the add school year button's clicked signal to a slot
    connect(ui->add_school_year_button, &QPushButton::clicked, this, &StaffSideView::onAddSchoolYearButtonClicked);


    // Set font for greeting_label
    ui->greeting_label->setStyleSheet("QLabel{ text-align: left; font-weight: 500; color: #0D63E6; border: none; }");
    ui->greeting_label->setFont(QFont(fontFamilyMedium, 16));

    ui->school_year_box->setStyleSheet("QComboBox {"
                                       "combobox-popup: 0;"
                                       "background: transparent;"
                                       "border: 1px solid rgb(212, 212, 212);"
                                       "border-radius: 8px;"
                                       "color: black;"
                                       "padding-left: 15px;"
                                       "}"
                                       "QComboBox::hover {"
                                       "background: rgb(212, 212, 212);"
                                       "}"
                                       "QComboBox::drop-down { width: 0px; }");

    ui->school_year_box->view()->setStyleSheet("QListView{"
                                               "border:1px solid red;"
                                               "border-radius: 8px;"
                                               "}");

    ui->school_year_box->view()->window()->setWindowFlags( Qt::Popup | Qt::FramelessWindowHint |Qt::NoDropShadowWindowHint);
    ui->school_year_box->view()->window()->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(20); // Adjust the blur radius
    effect->setOffset(0, 0); // Adjust the offset
    ui->groupBox->setGraphicsEffect(effect);

    ui->school_year_box->setFont(QFont(fontFamilyRegular, 14));

    ui->add_school_year_button->setCursor(QCursor(Qt::PointingHandCursor));
    ui->add_school_year_button->setFont(QFont(fontFamilyBold, 15));

    ui->confirm_button->setCursor(QCursor(Qt::PointingHandCursor));
    ui->confirm_button->setFont(QFont(fontFamilyBold, 15));

    connect(ui->changePasswordButton, &QPushButton::clicked, this, &StaffSideView::on_changePasswordButton_clicked);
    ui->changePasswordButton->setFlat(true);
    ui->changePasswordButton->setStyleSheet("QPushButton:hover { color: #ff6600; text-decoration: underline;} QPushButton:pressed { background-color: transparent; } QPushButton { text-align: center; font-weight: 500; color: #0D63E6; border: none; }");
    ui->changePasswordButton->setFont(QFont(fontFamilyRegular, 12));
    ui->changePasswordButton->setCursor(QCursor(Qt::PointingHandCursor));

}

StaffSideView::~StaffSideView()
{
    delete ui;
}

void StaffSideView::createYear()
{
    Node<SchoolYear>* cur = SchoolYears->getHead();
    if(cur != nullptr)
    {
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        Node<Semester>* curSemester = cur->data.semesters.getHead();
        if(curSemester == nullptr)
            {
                QMessageBox::warning(this, "Error", "semester of old yearis not 3 , we can not create new School Year");
                return;
            }
        while(curSemester->next != nullptr)
            curSemester = curSemester->next;
        if(curSemester->data.semester != "Semester 3")
        {
            QMessageBox::warning(this, "Error", "semester of old year is not fully , we can not create new School Year");
            return;
        }
    }
    DateInputDialog dialog;
    if (dialog.exec() == QDialog::Accepted)
    {
        std::string start_date_std = dialog.getStartDate().toStdString();
        std::string end_date_std = dialog.getEndDate().toStdString();
        std::string yearName;
        cur = SchoolYears->getHead();
        if(cur == nullptr)
        {
            QDate currentDate = QDate::currentDate();
            int currentYear = currentDate.year();
            yearName = std::to_string(currentYear) + "-" + std::to_string(currentYear+1);
        }
        else
        {
            while(cur->next != nullptr)
            {
                cur = cur->next;
            }
            yearName = cur->data.getNextYear(cur->data.year);
        }
        qDebug()<<QString::fromStdString(yearName);
        SchoolYear new_schoolyear(yearName, start_date_std, end_date_std);
        SchoolYears->add(new_schoolyear);
        //int i = SchoolYears->size()-1;
        //SchoolYear* schoolYear = &SchoolYears->get(i);
        //StaffMainView* staffMainView = new StaffMainView(nullptr, this, schoolYear,SchoolYears);
        //staffMainView->show();
        //this->hide();
    }
}
