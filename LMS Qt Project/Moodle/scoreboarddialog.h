#ifndef SCOREBOARDDIALOG_H
#define SCOREBOARDDIALOG_H

#include <QDialog>

namespace Ui {
class ScoreBoardDialog;
}

class ScoreBoardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScoreBoardDialog(QWidget *parent = nullptr);
    ~ScoreBoardDialog();

private:
    Ui::ScoreBoardDialog *ui;
};

#endif // SCOREBOARDDIALOG_H
