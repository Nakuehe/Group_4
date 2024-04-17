#ifndef SCOREBOARDCLASS_H
#define SCOREBOARDCLASS_H

#include <QDialog>
#include "SchoolYear.h"
#include "Semester.h"
#include "Class.h"
#include "Student.h"
#include <LinkedList.h>

class SchoolYear;
class Semester;
class Course;
namespace Ui {
class ScoreboardClass;
}

class ScoreboardClass : public QDialog
{
    Q_OBJECT
public:
    explicit ScoreboardClass(QWidget *parent = nullptr, LinkedList<Student>* students = nullptr, LinkedList<SchoolYear>* SchoolYears = nullptr,Semester* thisSemester = nullptr);
    ~ScoreboardClass();
    QString loadFont(const QString &resourcePath);
    float semesterGPA(Node<Student>* st);
    float overallGPA(Node<Student>* st);
signals:
    void shown();
    void hidden();
private slots:
    void resizeColumns();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
private:
    Ui::ScoreboardClass *ui;
   // Class* thisClass;
    Semester* thisSemester;
    LinkedList<Student>* students ;
    LinkedList<SchoolYear>* SchoolYears;

};

#endif // SCOREBOARDCLASS_H
