#ifndef STUDENTVIEWTABLE_H
#define STUDENTVIEWTABLE_H

#include <QMainWindow>  // Change this
#include <QStandardItemModel>
#include "LinkedList.h"
#include "Student.h"

namespace Ui {
class StudentViewTable;
}



class StudentViewTable : public QMainWindow  // Change this
{
    Q_OBJECT

public:
    explicit StudentViewTable(QWidget *parent = nullptr, const LinkedList<Student>* student_list = nullptr);
    void updateStudentList(const LinkedList<Student>* student_list);  // Add this method
    ~StudentViewTable();

private:
    Ui::StudentViewTable *ui;
    QStandardItemModel *model;
    const LinkedList<Student>* student_list;


    void setUpTableView();

private slots:
    void resizeColumns();

protected:
    void resizeEvent(QResizeEvent *event) override;

};

#endif // STUDENTVIEWTABLE_H
