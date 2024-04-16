#ifndef DATEINPUTDIALOG_H
#define DATEINPUTDIALOG_H
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>

class DateInputDialog : public QDialog {
    Q_OBJECT

public:
    QLineEdit *startDateEdit;
    QLineEdit *endDateEdit;

    DateInputDialog(QWidget *parent = nullptr) : QDialog(parent) {
        startDateEdit = new QLineEdit(this);
        endDateEdit = new QLineEdit(this);

        QFormLayout *formLayout = new QFormLayout;
        formLayout->addRow("Start Date:", startDateEdit);
        formLayout->addRow("End Date:", endDateEdit);

        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addLayout(formLayout);
        layout->addWidget(buttonBox);
    }

    QString getStartDate() {
        return startDateEdit->text();
    }

    QString getEndDate() {
        return endDateEdit->text();
    }
};
#endif
