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
     QString loadFont(const QString &resourcePath);
signals:
    void shown();
    void hidden();
protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
private slots:
    void on_pushButton_Search_clicked();

private:
    Ui::updateStudentResult *ui;
    Course* thisCourse;
};

#endif // UPDATESTUDENTRESULT_H
