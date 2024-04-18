#ifndef STAFFSIDEVIEW_H
#define STAFFSIDEVIEW_H

#include <QDialog>
#include <SchoolYear.h>
#include <QFontDatabase>
#include <QCloseEvent>
#include "staffmainview.h"

class MainWindow;

namespace Ui {
class StaffSideView;
}

class StaffSideView : public QDialog
{
    Q_OBJECT

public:
    explicit StaffSideView(QWidget *parent = nullptr, MainWindow* mainWindow = nullptr, LinkedList<SchoolYear>* SchoolYears = nullptr);
    ~StaffSideView();

protected:
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::StaffSideView *ui;
    LinkedList<SchoolYear>* SchoolYears;
    MainWindow* mainWindow;

    void onConfirmButtonClicked();
    void onAddSchoolYearButtonClicked();
};

#endif // STAFFSIDEVIEW_H
