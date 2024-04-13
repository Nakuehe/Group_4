#ifndef STAFFMAINVIEW_H
#define STAFFMAINVIEW_H

#include <QMainWindow>
#include <QFontDatabase>



class StaffSideView;
class SchoolYear;

namespace Ui {
class StaffMainView;
}

class StaffMainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaffMainView(QWidget *parent = nullptr, StaffSideView* staffSideView = nullptr, SchoolYear* this_year = nullptr);
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

    void setUpPage();
    void setUpSemesters();

};

#endif // STAFFMAINVIEW_H
