#ifndef DATEINPUTDIALOG_H
#define DATEINPUTDIALOG_H
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>
#include <QDate>
#include <QString>
#include <QFontDatabase>
#include "fontloader.h"

class DateInputDialog : public QDialog {
    Q_OBJECT

public:
    QLineEdit *startDateEdit;
    QLineEdit *endDateEdit;
    QComboBox *startDayComboBox;
    QComboBox *startMonthComboBox;
    QComboBox *startYearComboBox;
    QComboBox *endDayComboBox;
    QComboBox *endMonthComboBox;
    QComboBox *endYearComboBox;
    DateInputDialog(QWidget *parent = nullptr) : QDialog(parent) {

        QString fontFamily1 = loadFont(":/asset/font/HelveticaWorld-Regular.ttf");
        QFont font(fontFamily1, 14);

        this->setFont(font);

        startDayComboBox = new QComboBox(this);
        startMonthComboBox = new QComboBox(this);
        startYearComboBox = new QComboBox(this);
        endDayComboBox = new QComboBox(this);
        endMonthComboBox = new QComboBox(this);
        endYearComboBox = new QComboBox(this);

        int minWidth = 50;  // Adjust this value as needed
        startDayComboBox->setMinimumWidth(minWidth);
        startMonthComboBox->setMinimumWidth(minWidth);
        startYearComboBox->setMinimumWidth(minWidth + 20);
        endDayComboBox->setMinimumWidth(minWidth);
        endMonthComboBox->setMinimumWidth(minWidth);
        endYearComboBox->setMinimumWidth(minWidth + 20);
        
        for (int i = 1; i <= 31; ++i) {
            startDayComboBox->addItem(QString::number(i));
            endDayComboBox->addItem(QString::number(i));
        }
        
        for (int i = 1; i <= 12; ++i) {
            startMonthComboBox->addItem(QString::number(i));
            endMonthComboBox->addItem(QString::number(i));
        }
        
        for (int i = QDate::currentDate().year()-5; i < 2100; i++) {
            startYearComboBox->addItem(QString::number(i));
            endYearComboBox->addItem(QString::number(i));
        }
        
        QHBoxLayout *startDateLayout = new QHBoxLayout;
        startDateLayout->addWidget(startDayComboBox);
        startDateLayout->addWidget(startMonthComboBox);
        startDateLayout->addWidget(startYearComboBox);
        
        QHBoxLayout *endDateLayout = new QHBoxLayout;
        endDateLayout->addWidget(endDayComboBox);
        endDateLayout->addWidget(endMonthComboBox);
        endDateLayout->addWidget(endYearComboBox);
        
        QFormLayout *formLayout = new QFormLayout;
        formLayout->addRow("Start Date:", startDateLayout);
        formLayout->addRow("End Date:", endDateLayout);
        
        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        connect(buttonBox, &QDialogButtonBox::accepted, this, [this]() {
            int startDay = startDayComboBox->currentText().toInt();
            int startMonth = startMonthComboBox->currentText().toInt();
            int startYear = startYearComboBox->currentText().toInt();
            if (!QDate::isValid(startYear, startMonth, startDay)) {
                QMessageBox::warning(this, "Invalid date", "The start date is not valid.");
                return;
            }
        
            int endDay = endDayComboBox->currentText().toInt();
            int endMonth = endMonthComboBox->currentText().toInt();
            int endYear = endYearComboBox->currentText().toInt();
            if (!QDate::isValid(endYear, endMonth, endDay)) {
                QMessageBox::warning(this, "Invalid date", "The end date is not valid.");
                return;
            }

            QDate startDate(startYear, startMonth, startDay);
            QDate endDate(endYear, endMonth, endDay);
            if (endDate < startDate) {
                QMessageBox::warning(this, "Invalid date", "The end date must be after the start date.");
                return;
            }
        
            accept();
        });
        connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
        
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addLayout(formLayout);
        layout->addWidget(buttonBox);
    }

    QString getStartDate() {
        return startDayComboBox->currentText() + "/" + startMonthComboBox->currentText() + "/" + startYearComboBox->currentText();
    }

    QString getEndDate() {
        return endDayComboBox->currentText() + "/" + endMonthComboBox->currentText() + "/" + endYearComboBox->currentText();
    }
};
#endif
