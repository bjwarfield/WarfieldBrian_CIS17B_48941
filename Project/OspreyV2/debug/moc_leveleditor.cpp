/****************************************************************************
** Meta object code from reading C++ file 'leveleditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LevelEditor/leveleditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'leveleditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_levelEditor_t {
    QByteArrayData data[13];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_levelEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_levelEditor_t qt_meta_stringdata_levelEditor = {
    {
QT_MOC_LITERAL(0, 0, 11), // "levelEditor"
QT_MOC_LITERAL(1, 12, 13), // "modelModified"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 19), // "on_addEntry_clicked"
QT_MOC_LITERAL(4, 47, 22), // "on_removeEntry_clicked"
QT_MOC_LITERAL(5, 70, 18), // "on_addPath_clicked"
QT_MOC_LITERAL(6, 89, 21), // "on_deletePath_clicked"
QT_MOC_LITERAL(7, 111, 7), // "newFile"
QT_MOC_LITERAL(8, 119, 4), // "save"
QT_MOC_LITERAL(9, 124, 6), // "saveAs"
QT_MOC_LITERAL(10, 131, 4), // "open"
QT_MOC_LITERAL(11, 136, 20), // "on_copyEntry_clicked"
QT_MOC_LITERAL(12, 157, 19) // "on_copyPath_clicked"

    },
    "levelEditor\0modelModified\0\0"
    "on_addEntry_clicked\0on_removeEntry_clicked\0"
    "on_addPath_clicked\0on_deletePath_clicked\0"
    "newFile\0save\0saveAs\0open\0on_copyEntry_clicked\0"
    "on_copyPath_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_levelEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void levelEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        levelEditor *_t = static_cast<levelEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modelModified(); break;
        case 1: _t->on_addEntry_clicked(); break;
        case 2: _t->on_removeEntry_clicked(); break;
        case 3: _t->on_addPath_clicked(); break;
        case 4: _t->on_deletePath_clicked(); break;
        case 5: _t->newFile(); break;
        case 6: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->open(); break;
        case 9: _t->on_copyEntry_clicked(); break;
        case 10: _t->on_copyPath_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject levelEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_levelEditor.data,
      qt_meta_data_levelEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *levelEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *levelEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_levelEditor.stringdata0))
        return static_cast<void*>(const_cast< levelEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int levelEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
