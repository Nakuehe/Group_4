#ifndef STAFFSIDEVIEW_H
#define STAFFSIDEVIEW_H

#include <QDialog>
#include <SchoolYear.h>
#include <QFontDatabase>
#include <QCloseEvent>
#include "staffmainview.h"
#include "User.h"
#include "usermanager.h"

class MainWindow;

namespace Ui {
class StaffSideView;
}

class StaffSideView : public QDialog
{
    Q_OBJECT

public:
    explicit StaffSideView(QWidget *parent = nullptr, MainWindow* mainWindow = nullptr, User thisStaffUser = User(), UserManager *s_UserManager = nullptr, LinkedList<SchoolYear>* SchoolYears = nullptr);
    ~StaffSideView();
    void createYear();

protected:
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::StaffSideView *ui;
    LinkedList<SchoolYear>* SchoolYears;
    MainWindow* mainWindow;
    User thisStaffUser;
    UserManager *s_UserManager;

    void onConfirmButtonClicked();
    void on_changePasswordButton_clicked();
    void onAddSchoolYearButtonClicked();
    void comboBoxUpdate();
};

#endif // STAFFSIDEVIEW_H
