TEMPLATE      = app
HEADERS       = cell.h \
                finddialog.h \
                gotocelldialog.h \
                mainwindow.h \
                sortdialog.h \
                spreadsheet.h \
    spreadsheetcompare.h
SOURCES       = cell.cpp \
                finddialog.cpp \
                gotocelldialog.cpp \
                main.cpp \
                mainwindow.cpp \
                sortdialog.cpp \
                spreadsheet.cpp \
    spreadsheetcompare.cpp
FORMS         = gotocelldialog.ui \
                sortdialog.ui
RESOURCES     = spreadsheet.qrc
QT            += widgets
