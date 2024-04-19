#include "SchoolYear.h"
#include "dialogclass.h"
#include "LinkedList.h"
#include <string>
#include <QString>
#include <QMessageBox>
void SchoolYear::createClass()
{
    DialogClass dialog;
    if (dialog.exec() == QDialog::Accepted)
    {
        QString tempClass = dialog.getClassName();
        for (int i = 0; i < tempClass.length(); ++i)
        {
            if (!tempClass.at(i).isLetterOrNumber())
            {
                //QMessageBox::warning(nullptr,"Error", "Invalid format. Class name should contain letters or numbers only.");
                dialog.announcement();
                return;
            }
        }
            std::string className = tempClass.toStdString();
            Node<Class>* curr = this->classes.getHead();
            while (curr != nullptr)
            {
                if (curr->data.classID == className)
                {
                    //QMessageBox::warning(nullptr, "Error", "Class '" + tempClass + "' already exists.");
                    dialog.announcement2(tempClass);
                    return;
                }
                if (curr->next == nullptr)
                    break;
                curr = curr->next;
            }
            Class new_class(className);
            this->addClass(new_class);


    }
}
