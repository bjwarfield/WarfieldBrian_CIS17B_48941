/********************************************************************************
** Form generated from reading UI file 'leveleditor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELEDITOR_H
#define UI_LEVELEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_levelEditor
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionNew;
    QAction *actionSave_As;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addEntry;
    QPushButton *copyEntry;
    QPushButton *sortEntries;
    QPushButton *removeEntry;
    QVBoxLayout *entryView;
    QLabel *entryLabel;
    QTableView *entryTable;
    QVBoxLayout *pathButtons;
    QPushButton *addPath;
    QPushButton *copyPath;
    QPushButton *deletePath;
    QVBoxLayout *pathView;
    QLabel *pathLabel;
    QTableView *pathTable;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *levelEditor)
    {
        if (levelEditor->objectName().isEmpty())
            levelEditor->setObjectName(QStringLiteral("levelEditor"));
        levelEditor->resize(866, 618);
        actionOpen = new QAction(levelEditor);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(levelEditor);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionNew = new QAction(levelEditor);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSave_As = new QAction(levelEditor);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        centralwidget = new QWidget(levelEditor);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addEntry = new QPushButton(centralwidget);
        addEntry->setObjectName(QStringLiteral("addEntry"));

        verticalLayout_3->addWidget(addEntry);

        copyEntry = new QPushButton(centralwidget);
        copyEntry->setObjectName(QStringLiteral("copyEntry"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(copyEntry->sizePolicy().hasHeightForWidth());
        copyEntry->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(copyEntry);

        sortEntries = new QPushButton(centralwidget);
        sortEntries->setObjectName(QStringLiteral("sortEntries"));

        verticalLayout_3->addWidget(sortEntries);

        removeEntry = new QPushButton(centralwidget);
        removeEntry->setObjectName(QStringLiteral("removeEntry"));

        verticalLayout_3->addWidget(removeEntry);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        entryView = new QVBoxLayout();
        entryView->setObjectName(QStringLiteral("entryView"));
        entryLabel = new QLabel(centralwidget);
        entryLabel->setObjectName(QStringLiteral("entryLabel"));

        entryView->addWidget(entryLabel);

        entryTable = new QTableView(centralwidget);
        entryTable->setObjectName(QStringLiteral("entryTable"));

        entryView->addWidget(entryTable);


        gridLayout->addLayout(entryView, 0, 1, 1, 1);

        pathButtons = new QVBoxLayout();
        pathButtons->setObjectName(QStringLiteral("pathButtons"));
        addPath = new QPushButton(centralwidget);
        addPath->setObjectName(QStringLiteral("addPath"));

        pathButtons->addWidget(addPath);

        copyPath = new QPushButton(centralwidget);
        copyPath->setObjectName(QStringLiteral("copyPath"));

        pathButtons->addWidget(copyPath);

        deletePath = new QPushButton(centralwidget);
        deletePath->setObjectName(QStringLiteral("deletePath"));

        pathButtons->addWidget(deletePath);


        gridLayout->addLayout(pathButtons, 1, 0, 1, 1);

        pathView = new QVBoxLayout();
        pathView->setObjectName(QStringLiteral("pathView"));
        pathLabel = new QLabel(centralwidget);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));

        pathView->addWidget(pathLabel);

        pathTable = new QTableView(centralwidget);
        pathTable->setObjectName(QStringLiteral("pathTable"));

        pathView->addWidget(pathTable);


        gridLayout->addLayout(pathView, 1, 1, 1, 1);

        levelEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(levelEditor);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 866, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        levelEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(levelEditor);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        levelEditor->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        entryLabel->setBuddy(entryTable);
        pathLabel->setBuddy(pathTable);
#endif // QT_NO_SHORTCUT

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);

        retranslateUi(levelEditor);

        QMetaObject::connectSlotsByName(levelEditor);
    } // setupUi

    void retranslateUi(QMainWindow *levelEditor)
    {
        levelEditor->setWindowTitle(QApplication::translate("levelEditor", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("levelEditor", "Open...", 0));
        actionSave->setText(QApplication::translate("levelEditor", "Save", 0));
        actionNew->setText(QApplication::translate("levelEditor", "New", 0));
        actionSave_As->setText(QApplication::translate("levelEditor", "Save As...", 0));
        addEntry->setText(QApplication::translate("levelEditor", "Add Entry", 0));
        copyEntry->setText(QApplication::translate("levelEditor", "Copy Entry", 0));
        sortEntries->setText(QApplication::translate("levelEditor", "Sort Entries", 0));
        removeEntry->setText(QApplication::translate("levelEditor", "Delete Entry", 0));
        entryLabel->setText(QApplication::translate("levelEditor", "Entries", 0));
        addPath->setText(QApplication::translate("levelEditor", "Add path", 0));
        copyPath->setText(QApplication::translate("levelEditor", "Copy Path", 0));
        deletePath->setText(QApplication::translate("levelEditor", "Delete Path", 0));
        pathLabel->setText(QApplication::translate("levelEditor", "Entry Path", 0));
        menuFile->setTitle(QApplication::translate("levelEditor", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class levelEditor: public Ui_levelEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELEDITOR_H
