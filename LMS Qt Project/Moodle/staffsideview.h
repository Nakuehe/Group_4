#ifndef STAFFSIDEVIEW_H
#define STAFFSIDEVIEW_H

#include <QDialog>

namespace Ui {
class StaffSideView;
}

class StaffSideView : public QDialog
{
    Q_OBJECT

public:
    explicit StaffSideView(QWidget *parent = nullptr);
    ~StaffSideView();

private:
    Ui::StaffSideView *ui;
};

#endif // STAFFSIDEVIEW_H
