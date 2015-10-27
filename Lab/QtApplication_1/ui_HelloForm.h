/********************************************************************************
** Form generated from reading UI file 'HelloForm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOFORM_H
#define UI_HELLOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloForm
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *helloEdit;
    QLineEdit *nameEdit;

    void setupUi(QDialog *HelloForm)
    {
        if (HelloForm->objectName().isEmpty())
            HelloForm->setObjectName(QStringLiteral("HelloForm"));
        HelloForm->resize(400, 300);
        widget = new QWidget(HelloForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 381, 67));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        helloEdit = new QLineEdit(widget);
        helloEdit->setObjectName(QStringLiteral("helloEdit"));

        verticalLayout->addWidget(helloEdit);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        verticalLayout->addWidget(nameEdit);


        retranslateUi(HelloForm);

        QMetaObject::connectSlotsByName(HelloForm);
    } // setupUi

    void retranslateUi(QDialog *HelloForm)
    {
        HelloForm->setWindowTitle(QApplication::translate("HelloForm", "HelloForm", 0));
        label->setText(QApplication::translate("HelloForm", "Enter your name below", 0));
    } // retranslateUi

};

namespace Ui {
    class HelloForm: public Ui_HelloForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOFORM_H
