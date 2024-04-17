#include "staffsideview.h"

#include "mainwindow.h"
#include "ui_staffsideview.h"
#include "QAbstractItemView"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>

StaffSideView::StaffSideView(QWidget *parent, MainWindow* mainWindow, LinkedList<SchoolYear>* SchoolYears)
    : QDialog(parent)
    , SchoolYears(SchoolYears)
    , mainWindow(mainWindow)
    , ui(new Ui::StaffSideView)
{
    ui->setupUi(this);

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

}

QString StaffSideView::loadFont(const QString &resourcePath) {
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

void StaffSideView::onConfirmButtonClicked()
{
    QString selectedSchoolYear = ui->school_year_box->currentText();
    for (int i = 0; i < SchoolYears->size(); i++) {

        SchoolYear* schoolYear = &SchoolYears->get(i);

        QString check_name = QString::fromStdString(schoolYear->year);

        if (check_name == selectedSchoolYear) {
            StaffMainView* staffMainView = new StaffMainView(nullptr, this, schoolYear,SchoolYears);
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
    // Open a new window for adding a school year...
}

StaffSideView::~StaffSideView()
{
    delete ui;
}
