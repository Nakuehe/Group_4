/****************************************************************************
** Meta object code from reading C++ file 'updateStudentResult.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Moodle/updateStudentResult.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'updateStudentResult.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSupdateStudentResultENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSupdateStudentResultENDCLASS = QtMocHelpers::stringData(
    "updateStudentResult",
    "shown",
    "",
    "hidden",
    "resizeColumns",
    "on_pushButton_Search_clicked",
    "on_pushButton_Accept_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSupdateStudentResultENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[20];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[14];
    char stringdata5[29];
    char stringdata6[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSupdateStudentResultENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSupdateStudentResultENDCLASS_t qt_meta_stringdata_CLASSupdateStudentResultENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "updateStudentResult"
        QT_MOC_LITERAL(20, 5),  // "shown"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 6),  // "hidden"
        QT_MOC_LITERAL(34, 13),  // "resizeColumns"
        QT_MOC_LITERAL(48, 28),  // "on_pushButton_Search_clicked"
        QT_MOC_LITERAL(77, 28)   // "on_pushButton_Accept_clicked"
    },
    "updateStudentResult",
    "shown",
    "",
    "hidden",
    "resizeColumns",
    "on_pushButton_Search_clicked",
    "on_pushButton_Accept_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSupdateStudentResultENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject updateStudentResult::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSupdateStudentResultENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSupdateStudentResultENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSupdateStudentResultENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<updateStudentResult, std::true_type>,
        // method 'shown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hidden'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resizeColumns'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Search_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Accept_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void updateStudentResult::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<updateStudentResult *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->shown(); break;
        case 1: _t->hidden(); break;
        case 2: _t->resizeColumns(); break;
        case 3: _t->on_pushButton_Search_clicked(); break;
        case 4: _t->on_pushButton_Accept_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (updateStudentResult::*)();
            if (_t _q_method = &updateStudentResult::shown; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (updateStudentResult::*)();
            if (_t _q_method = &updateStudentResult::hidden; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *updateStudentResult::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *updateStudentResult::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSupdateStudentResultENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int updateStudentResult::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void updateStudentResult::shown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void updateStudentResult::hidden()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
