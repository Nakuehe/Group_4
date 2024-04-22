#include "mainwindow.h"
#include <QtCore>
#include <QApplication>
#include <QListWidget>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showCentered();
    return a.exec();
}
