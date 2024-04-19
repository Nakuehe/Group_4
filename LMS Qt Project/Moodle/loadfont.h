#ifndef LOADFONT_H
#define LOADFONT_H
#include <QFontDatabase>
#include <QString>
#include <QStringList> 

QString loadFont(const QString &resourcePath){
    int id = QFontDatabase::addApplicationFont(resourcePath);
    if (id != -1) {
        return QFontDatabase::applicationFontFamilies(id).at(0);
    }
    return QString();
}

#endif // LOADFONT_H
