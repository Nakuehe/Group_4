#ifndef DIALOGCLASS_H
#define DIALOGCLASS_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
namespace Ui {
class DialogClass;
}

class DialogClass : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClass(QWidget *parent = nullptr);
    ~DialogClass();
    QString getClassName();
    void announcement();
    void announcement2(QString tempClass);

private:
    Ui::DialogClass *ui;
};

#endif // DIALOGCLASS_H
