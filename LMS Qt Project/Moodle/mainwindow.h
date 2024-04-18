#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QScreen>
#include <QGraphicsDropShadowEffect>  
#include <QFontDatabase>
#include <QMessageBox>
#include <QFont>
#include <QCursor>
#include <QPalette>
#include <QCloseEvent>
#include "LinkedList.h"
#include "SchoolYear.h"
#include "usermanager.h"
#include "staffsideview.h"
#include "filemanager.h"


class StudentView;
class StaffSideView;



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    LinkedList<SchoolYear> SchoolYears;

    //LinkedList<UserInfo> Users;
    ~MainWindow();
    void showCentered();
    UserManager* getUserManager() {return m_userManager;}

private slots:
    void on_pushButtonLogin_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEditPassword_textChanged(const QString &arg1);

    void on_lineEditPassword_focusChanged(bool hasFocus);

    void togglePasswordVisibility();

    void setupPage();

    void deleteStudentView(StudentView* studentView);


private:
    UserManager* m_userManager;
    FileManager* m_fileManager;
    Ui::MainWindow *ui;


    QList<StudentView*> studentViews;
    QList<StaffSideView*> staffSideViews;
};
#endif // MAINWINDOW_H
