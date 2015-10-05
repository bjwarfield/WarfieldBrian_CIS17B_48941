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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSplitter *splitter_4;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QLabel *yLabel;
    QSpinBox *yBox;
    QLabel *xLabel;
    QSpinBox *xBox;
    QSplitter *splitter_2;
    QPushButton *generateButton;
    QPushButton *closeButton;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(400, 300));
        MainWindow->setMaximumSize(QSize(400, 300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        splitter_4 = new QSplitter(centralWidget);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(10, 10, 381, 281));
        sizePolicy.setHeightForWidth(splitter_4->sizePolicy().hasHeightForWidth());
        splitter_4->setSizePolicy(sizePolicy);
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        sizePolicy.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy);
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Vertical);
        yLabel = new QLabel(splitter);
        yLabel->setObjectName(QStringLiteral("yLabel"));
        yLabel->setMinimumSize(QSize(90, 29));
        yLabel->setMaximumSize(QSize(90, 29));
        splitter->addWidget(yLabel);
        yBox = new QSpinBox(splitter);
        yBox->setObjectName(QStringLiteral("yBox"));
        yBox->setMinimumSize(QSize(90, 52));
        yBox->setMaximumSize(QSize(90, 52));
        yBox->setMinimum(1);
        yBox->setMaximum(15);
        splitter->addWidget(yBox);
        xLabel = new QLabel(splitter);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setMinimumSize(QSize(90, 30));
        xLabel->setMaximumSize(QSize(90, 30));
        splitter->addWidget(xLabel);
        xBox = new QSpinBox(splitter);
        xBox->setObjectName(QStringLiteral("xBox"));
        xBox->setMinimumSize(QSize(90, 52));
        xBox->setMaximumSize(QSize(90, 52));
        xBox->setMinimum(1);
        xBox->setMaximum(15);
        splitter->addWidget(xBox);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        sizePolicy.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy);
        splitter_2->setOrientation(Qt::Vertical);
        generateButton = new QPushButton(splitter_2);
        generateButton->setObjectName(QStringLiteral("generateButton"));
        sizePolicy.setHeightForWidth(generateButton->sizePolicy().hasHeightForWidth());
        generateButton->setSizePolicy(sizePolicy);
        generateButton->setMinimumSize(QSize(90, 49));
        generateButton->setMaximumSize(QSize(90, 49));
        splitter_2->addWidget(generateButton);
        closeButton = new QPushButton(splitter_2);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMinimumSize(QSize(90, 49));
        closeButton->setMaximumSize(QSize(90, 49));
        splitter_2->addWidget(closeButton);
        splitter_3->addWidget(splitter_2);
        splitter_4->addWidget(splitter_3);
        textBrowser = new QTextBrowser(splitter_4);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(287, 281));
        textBrowser->setMaximumSize(QSize(287, 281));
        splitter_4->addWidget(textBrowser);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        yLabel->setText(QApplication::translate("MainWindow", "Num of Rows", 0));
        xLabel->setText(QApplication::translate("MainWindow", "Num of Cols", 0));
        generateButton->setText(QApplication::translate("MainWindow", "Generate", 0));
        closeButton->setText(QApplication::translate("MainWindow", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
