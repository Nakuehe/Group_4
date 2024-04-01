#ifndef COURSEINFOWINDOW_H
#define COURSEINFOWINDOW_H

#include <QDialog>
#include <QPixmap>
#include <QFontDatabase>
#include "Course.h"

namespace Ui {
class CourseInfoWindow;
}

class CourseInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CourseInfoWindow(QWidget *parent = nullptr, const Course* thisCourse = nullptr, int index = 0);
    ~CourseInfoWindow();

    QString loadFont(const QString &resourcePath);  // Method to load the font

signals:
    void shown();
    void hidden();

protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    

private:
    Ui::CourseInfoWindow *ui;
    const Course* thisCourse;
    int index;
};

#endif // COURSEINFOWINDOW_H
