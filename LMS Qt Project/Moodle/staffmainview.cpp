#include "staffmainview.h"
#include "staffsideview.h"
#include "ui_staffmainview.h"
#include <QMessageBox>
#include <QCloseEvent>

StaffMainView::StaffMainView(QWidget *parent, StaffSideView* staffSideView, SchoolYear* this_year)
    : QMainWindow(parent)
    , staffSideView(staffSideView)
    , this_year(this_year)
    , ui(new Ui::StaffMainView)
{
    ui->setupUi(this);
    setUpPage();
    setUpSemesters();
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
            Semester curSemester = this_year->semesters.get(i);
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            btn_semester->setText(QString::fromStdString(curSemester.semester));

            connect(btn_semester, &QPushButton::clicked, this, [=]() {
                // Handle semester button click here
            });
        } else if (i == this_year->semesters.size()) { // If this is the "Add Semester" button
            widget->setStyleSheet("QWidget { border: 2px solid lightgray; border-radius: 10px; background: white; } QWidget:hover { border-color: #0D3ECC; }");
            btn_semester->setIcon(QIcon(":/Asset/staffViewAsset/addButton.png"));
            btn_semester->setIconSize(QSize(48, 48)); // Adjust size as needed

            connect(btn_semester, &QPushButton::clicked, this, [=]() {
                // Handle "Add Semester" button click here
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

