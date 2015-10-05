/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QSplitter *splitter_2;
    QPushButton *generateButton;
    QPushButton *closeButton;
    QSplitter *splitter;
    QLabel *heightLabel;
    QSpinBox *xSpinBox;
    QLabel *widthLabel;
    QSpinBox *ySpinBox;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(400, 320));
        MainWindow->setMaximumSize(QSize(400, 320));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(130, 10, 256, 281));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(10, 210, 111, 81));
        splitter_2->setOrientation(Qt::Vertical);
        generateButton = new QPushButton(splitter_2);
        generateButton->setObjectName(QStringLiteral("generateButton"));
        splitter_2->addWidget(generateButton);
        closeButton = new QPushButton(splitter_2);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        splitter_2->addWidget(closeButton);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 10, 111, 141));
        splitter->setOrientation(Qt::Vertical);
        heightLabel = new QLabel(splitter);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));
        splitter->addWidget(heightLabel);
        xSpinBox = new QSpinBox(splitter);
        xSpinBox->setObjectName(QStringLiteral("xSpinBox"));
        xSpinBox->setMinimum(1);
        xSpinBox->setMaximum(15);
        splitter->addWidget(xSpinBox);
        widthLabel = new QLabel(splitter);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));
        splitter->addWidget(widthLabel);
        ySpinBox = new QSpinBox(splitter);
        ySpinBox->setObjectName(QStringLiteral("ySpinBox"));
        ySpinBox->setMinimum(1);
        ySpinBox->setMaximum(15);
        splitter->addWidget(ySpinBox);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        generateButton->setText(QApplication::translate("MainWindow", "Generate", 0));
        closeButton->setText(QApplication::translate("MainWindow", "Close", 0));
        heightLabel->setText(QApplication::translate("MainWindow", "Array Height", 0));
        widthLabel->setText(QApplication::translate("MainWindow", "Array Width", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
