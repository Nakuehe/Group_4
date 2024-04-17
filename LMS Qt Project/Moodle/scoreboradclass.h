#ifndef SCOREBORADCLASS_H
#define SCOREBORADCLASS_H

#include <QDialog>

namespace Ui {
class ScoreboradClass;
}

class ScoreboradClass : public QDialog
{
    Q_OBJECT

public:
    explicit ScoreboradClass(QWidget *parent = nullptr);
    ~ScoreboradClass();

private:
    Ui::ScoreboradClass *ui;
};

#endif // SCOREBORADCLASS_H
