#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class TestForm;
}

class TestForm : public QWidget
{
    Q_OBJECT

public:
    explicit TestForm(QWidget *parent = nullptr);

    ~TestForm();

private:
    Ui::TestForm *ui;
    QStandardItemModel *model;


    void setUpTableView();
    

private slots:
    void resizeColumns();

protected:
    void resizeEvent(QResizeEvent *event) override;

};

#endif // TESTFORM_H
