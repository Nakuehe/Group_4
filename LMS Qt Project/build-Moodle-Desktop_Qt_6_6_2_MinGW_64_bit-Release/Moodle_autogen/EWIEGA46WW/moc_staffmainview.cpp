/****************************************************************************
** Meta object code from reading C++ file 'staffmainview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Moodle/staffmainview.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'staffmainview.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSStaffMainViewENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSStaffMainViewENDCLASS = QtMocHelpers::stringData(
    "StaffMainView",
    "on_stackedWidget_currentChanged",
    "",
    "index",
    "on_semester_btn1_toggled",
    "on_semester_btn2_toggled",
    "on_class_btn1_toggled",
    "on_class_btn2_toggled",
    "menu_btn_toggled",
    "checked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSStaffMainViewENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[14];
    char stringdata1[32];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[25];
    char stringdata5[25];
    char stringdata6[22];
    char stringdata7[22];
    char stringdata8[17];
    char stringdata9[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSStaffMainViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSStaffMainViewENDCLASS_t qt_meta_stringdata_CLASSStaffMainViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "StaffMainView"
        QT_MOC_LITERAL(14, 31),  // "on_stackedWidget_currentChanged"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 5),  // "index"
        QT_MOC_LITERAL(53, 24),  // "on_semester_btn1_toggled"
        QT_MOC_LITERAL(78, 24),  // "on_semester_btn2_toggled"
        QT_MOC_LITERAL(103, 21),  // "on_class_btn1_toggled"
        QT_MOC_LITERAL(125, 21),  // "on_class_btn2_toggled"
        QT_MOC_LITERAL(147, 16),  // "menu_btn_toggled"
        QT_MOC_LITERAL(164, 7)   // "checked"
    },
    "StaffMainView",
    "on_stackedWidget_currentChanged",
    "",
    "index",
    "on_semester_btn1_toggled",
    "on_semester_btn2_toggled",
    "on_class_btn1_toggled",
    "on_class_btn2_toggled",
    "menu_btn_toggled",
    "checked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSStaffMainViewENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       4,    0,   53,    2, 0x08,    3 /* Private */,
       5,    0,   54,    2, 0x08,    4 /* Private */,
       6,    0,   55,    2, 0x08,    5 /* Private */,
       7,    0,   56,    2, 0x08,    6 /* Private */,
       8,    1,   57,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject StaffMainView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSStaffMainViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSStaffMainViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSStaffMainViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<StaffMainView, std::true_type>,
        // method 'on_stackedWidget_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_semester_btn1_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_semester_btn2_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_class_btn1_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_class_btn2_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'menu_btn_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void StaffMainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StaffMainView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_stackedWidget_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_semester_btn1_toggled(); break;
        case 2: _t->on_semester_btn2_toggled(); break;
        case 3: _t->on_class_btn1_toggled(); break;
        case 4: _t->on_class_btn2_toggled(); break;
        case 5: _t->menu_btn_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *StaffMainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StaffMainView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSStaffMainViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int StaffMainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
