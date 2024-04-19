#ifndef CLASSDIALOG_H
#define CLASSDIALOG_H
#include "SchoolYear.h"
#include <QDialog>

namespace Ui {
class ClassDialog;
}

class ClassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClassDialog(QWidget *parent = nullptr);
    ~ClassDialog();
    QString getClassName();
private:
    Ui::ClassDialog *ui;
};

#endif // CLASSDIALOG_H
