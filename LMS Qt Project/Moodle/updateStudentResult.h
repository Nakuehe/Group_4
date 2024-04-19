#ifndef UPDATESTUDENTRESULT_H
#define UPDATESTUDENTRESULT_H

#include <QDialog>
#include "course.h"
#include <QDialog>
#include <QPixmap>
#include <QFontDatabase>
#include <QStandardItemModel>
namespace Ui {
class updateStudentResult;
}

class updateStudentResult : public QDialog
{
    Q_OBJECT

public:
    explicit updateStudentResult(QWidget *parent = nullptr, Course* thisCourse = nullptr);
    ~updateStudentResult();
signals:
    void shown();
    void hidden();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
private slots:
    void resizeColumns();
    void on_pushButton_Search_clicked();

    void on_pushButton_Accept_clicked();

private:
    Ui::updateStudentResult *ui;
    Course* thisCourse;
};

#endif // UPDATESTUDENTRESULT_H
