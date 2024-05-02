/****************************************************************************
** Meta object code from reading C++ file 'studentview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Moodle/studentview.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'studentview.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS = QtMocHelpers::stringData(
    "RoundAvatarLabel"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS_t qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16)   // "RoundAvatarLabel"
    },
    "RoundAvatarLabel"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRoundAvatarLabelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject RoundAvatarLabel::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRoundAvatarLabelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RoundAvatarLabel, std::true_type>
    >,
    nullptr
} };

void RoundAvatarLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *RoundAvatarLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoundAvatarLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRoundAvatarLabelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int RoundAvatarLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSStudentViewENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSStudentViewENDCLASS = QtMocHelpers::stringData(
    "StudentView",
    "closed",
    "",
    "menu_btn_toggled",
    "checked",
    "on_stackedWidget_currentChanged",
    "index",
    "on_profile_btn1_toggled",
    "on_profile_btn2_toggled",
    "on_course_btn1_toggled",
    "on_course_btn2_toggled",
    "on_grade_btn1_toggled",
    "on_grade_btn2_toggled",
    "resizeColumns"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSStudentViewENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[12];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[8];
    char stringdata5[32];
    char stringdata6[6];
    char stringdata7[24];
    char stringdata8[24];
    char stringdata9[23];
    char stringdata10[23];
    char stringdata11[22];
    char stringdata12[22];
    char stringdata13[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSStudentViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSStudentViewENDCLASS_t qt_meta_stringdata_CLASSStudentViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "StudentView"
        QT_MOC_LITERAL(12, 6),  // "closed"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 16),  // "menu_btn_toggled"
        QT_MOC_LITERAL(37, 7),  // "checked"
        QT_MOC_LITERAL(45, 31),  // "on_stackedWidget_currentChanged"
        QT_MOC_LITERAL(77, 5),  // "index"
        QT_MOC_LITERAL(83, 23),  // "on_profile_btn1_toggled"
        QT_MOC_LITERAL(107, 23),  // "on_profile_btn2_toggled"
        QT_MOC_LITERAL(131, 22),  // "on_course_btn1_toggled"
        QT_MOC_LITERAL(154, 22),  // "on_course_btn2_toggled"
        QT_MOC_LITERAL(177, 21),  // "on_grade_btn1_toggled"
        QT_MOC_LITERAL(199, 21),  // "on_grade_btn2_toggled"
        QT_MOC_LITERAL(221, 13)   // "resizeColumns"
    },
    "StudentView",
    "closed",
    "",
    "menu_btn_toggled",
    "checked",
    "on_stackedWidget_currentChanged",
    "index",
    "on_profile_btn1_toggled",
    "on_profile_btn2_toggled",
    "on_course_btn1_toggled",
    "on_course_btn2_toggled",
    "on_grade_btn1_toggled",
    "on_grade_btn2_toggled",
    "resizeColumns"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSStudentViewENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   75,    2, 0x0a,    2 /* Public */,
       5,    1,   78,    2, 0x08,    4 /* Private */,
       7,    0,   81,    2, 0x08,    6 /* Private */,
       8,    0,   82,    2, 0x08,    7 /* Private */,
       9,    0,   83,    2, 0x08,    8 /* Private */,
      10,    0,   84,    2, 0x08,    9 /* Private */,
      11,    0,   85,    2, 0x08,   10 /* Private */,
      12,    0,   86,    2, 0x08,   11 /* Private */,
      13,    0,   87,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject StudentView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSStudentViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSStudentViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSStudentViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<StudentView, std::true_type>,
        // method 'closed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'menu_btn_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_stackedWidget_currentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_profile_btn1_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_profile_btn2_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_course_btn1_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_course_btn2_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_grade_btn1_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_grade_btn2_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resizeColumns'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void StudentView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StudentView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->menu_btn_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->on_stackedWidget_currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_profile_btn1_toggled(); break;
        case 4: _t->on_profile_btn2_toggled(); break;
        case 5: _t->on_course_btn1_toggled(); break;
        case 6: _t->on_course_btn2_toggled(); break;
        case 7: _t->on_grade_btn1_toggled(); break;
        case 8: _t->on_grade_btn2_toggled(); break;
        case 9: _t->resizeColumns(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StudentView::*)();
            if (_t _q_method = &StudentView::closed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *StudentView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudentView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSStudentViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int StudentView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void StudentView::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
