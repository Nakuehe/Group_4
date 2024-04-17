#ifndef SCOREBOARDDIALOG_H
#define SCOREBOARDDIALOG_H

#include <QDialog>
#include "course.h"
#include <QDialog>
#include <QPixmap>
#include <QFontDatabase>
#include <QStandardItemModel>

namespace Ui {
class ScoreboardDialog;
}

class ScoreboardDialog : public QDialog {
    Q_OBJECT

public:
    explicit ScoreboardDialog(QWidget *parent = nullptr, Course* thisCourse = nullptr, int index = 0);
    ~ScoreboardDialog();
    QString loadFont(const QString &resourcePath);
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
    Ui::ScoreboardDialog *ui;
    Course* thisCourse;
    int index;
};
#endif // SCOREBOARDDIALOG_H
