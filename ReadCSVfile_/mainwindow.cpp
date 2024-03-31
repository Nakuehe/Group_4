#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile CSVFile(QCoreApplication::applicationDirPath()+"2023-2024_class_23CLC03.csv");
    if(CSVFile.open(QIODevice::ReadWrite))
    {
        QTextStream Stream(&CSVFile);
        while(Stream.atEnd()==false)
        {
            QString LineData = Stream.readLine();
            QStringList Data = LineData.split(",");
            for(int i =0;i<Data.length();i++)
            {
                qDebug() <<"Data is: "<<Data.at(i);
            }
        }
    }
    CSVFile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
