/********************************************************************************
** Form generated from reading UI file 'usercontrolpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCONTROLPANEL_H
#define UI_USERCONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserControlPanel
{
public:
    QTabWidget *tabWidget;
    QWidget *homeTab;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QPushButton *loginCancelButton;
    QPushButton *loginLoginButton;
    QLineEdit *loginPassField;
    QLabel *loginPassValid;
    QLabel *loginEmailValid;
    QLabel *loginEmailLabel;
    QLabel *label;
    QLineEdit *loginEmailField;
    QLabel *loginPassLabel;
    QSpacerItem *verticalSpacer_3;
    QWidget *scoreTab;
    QWidget *registerTab;
    QLabel *regUserLabel;
    QLineEdit *regUserField;
    QLineEdit *regPassField2;
    QLabel *regLNameLabel;
    QLabel *regFNameLabel;
    QLineEdit *regLNameField;
    QLabel *regPassLabel2;
    QLabel *regPassValid;
    QLabel *regFNameValid;
    QLabel *regPassValid2;
    QLabel *regLNameValid;
    QLabel *regUserValid;
    QLabel *regEmailValid;
    QLabel *regTitleLabel;
    QLabel *regPassLabel;
    QLineEdit *regPassField;
    QLabel *regEmailLabel;
    QLineEdit *regEmailField;
    QLineEdit *regFNameField;
    QPushButton *regRegisterButton;
    QPushButton *regCancelButton;

    void setupUi(QDialog *UserControlPanel)
    {
        if (UserControlPanel->objectName().isEmpty())
            UserControlPanel->setObjectName(QStringLiteral("UserControlPanel"));
        UserControlPanel->setWindowModality(Qt::WindowModal);
        UserControlPanel->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserControlPanel->sizePolicy().hasHeightForWidth());
        UserControlPanel->setSizePolicy(sizePolicy);
        UserControlPanel->setMinimumSize(QSize(640, 480));
        UserControlPanel->setMaximumSize(QSize(640, 480));
        UserControlPanel->setModal(true);
        tabWidget = new QTabWidget(UserControlPanel);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 640, 480));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        homeTab = new QWidget();
        homeTab->setObjectName(QStringLiteral("homeTab"));
        sizePolicy.setHeightForWidth(homeTab->sizePolicy().hasHeightForWidth());
        homeTab->setSizePolicy(sizePolicy);
        homeTab->setMinimumSize(QSize(636, 453));
        homeTab->setMaximumSize(QSize(636, 453));
        gridLayout_3 = new QGridLayout(homeTab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(50, -1, 50, -1);
        splitter = new QSplitter(homeTab);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        loginCancelButton = new QPushButton(splitter);
        loginCancelButton->setObjectName(QStringLiteral("loginCancelButton"));
        splitter->addWidget(loginCancelButton);
        loginLoginButton = new QPushButton(splitter);
        loginLoginButton->setObjectName(QStringLiteral("loginLoginButton"));
        splitter->addWidget(loginLoginButton);

        gridLayout_3->addWidget(splitter, 9, 0, 1, 3);

        loginPassField = new QLineEdit(homeTab);
        loginPassField->setObjectName(QStringLiteral("loginPassField"));
        loginPassField->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(loginPassField, 6, 2, 1, 1);

        loginPassValid = new QLabel(homeTab);
        loginPassValid->setObjectName(QStringLiteral("loginPassValid"));
        loginPassValid->setStyleSheet(QStringLiteral("color:#F00;"));

        gridLayout_3->addWidget(loginPassValid, 7, 2, 1, 1);

        loginEmailValid = new QLabel(homeTab);
        loginEmailValid->setObjectName(QStringLiteral("loginEmailValid"));
        loginEmailValid->setStyleSheet(QStringLiteral("color:#F00;"));

        gridLayout_3->addWidget(loginEmailValid, 4, 2, 1, 1);

        loginEmailLabel = new QLabel(homeTab);
        loginEmailLabel->setObjectName(QStringLiteral("loginEmailLabel"));

        gridLayout_3->addWidget(loginEmailLabel, 3, 0, 1, 1);

        label = new QLabel(homeTab);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 2, 0, 1, 3);

        loginEmailField = new QLineEdit(homeTab);
        loginEmailField->setObjectName(QStringLiteral("loginEmailField"));

        gridLayout_3->addWidget(loginEmailField, 3, 2, 1, 1);

        loginPassLabel = new QLabel(homeTab);
        loginPassLabel->setObjectName(QStringLiteral("loginPassLabel"));

        gridLayout_3->addWidget(loginPassLabel, 6, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 1, 0, 1, 1);

        tabWidget->addTab(homeTab, QString());
        scoreTab = new QWidget();
        scoreTab->setObjectName(QStringLiteral("scoreTab"));
        sizePolicy.setHeightForWidth(scoreTab->sizePolicy().hasHeightForWidth());
        scoreTab->setSizePolicy(sizePolicy);
        tabWidget->addTab(scoreTab, QString());
        registerTab = new QWidget();
        registerTab->setObjectName(QStringLiteral("registerTab"));
        sizePolicy.setHeightForWidth(registerTab->sizePolicy().hasHeightForWidth());
        registerTab->setSizePolicy(sizePolicy);
        registerTab->setMinimumSize(QSize(636, 453));
        regUserLabel = new QLabel(registerTab);
        regUserLabel->setObjectName(QStringLiteral("regUserLabel"));
        regUserLabel->setGeometry(QRect(50, 180, 52, 16));
        regUserField = new QLineEdit(registerTab);
        regUserField->setObjectName(QStringLiteral("regUserField"));
        regUserField->setGeometry(QRect(135, 180, 421, 22));
        regPassField2 = new QLineEdit(registerTab);
        regPassField2->setObjectName(QStringLiteral("regPassField2"));
        regPassField2->setGeometry(QRect(135, 362, 421, 22));
        sizePolicy.setHeightForWidth(regPassField2->sizePolicy().hasHeightForWidth());
        regPassField2->setSizePolicy(sizePolicy);
        regPassField2->setEchoMode(QLineEdit::Password);
        regLNameLabel = new QLabel(registerTab);
        regLNameLabel->setObjectName(QStringLiteral("regLNameLabel"));
        regLNameLabel->setGeometry(QRect(50, 119, 50, 16));
        regFNameLabel = new QLabel(registerTab);
        regFNameLabel->setObjectName(QStringLiteral("regFNameLabel"));
        regFNameLabel->setGeometry(QRect(50, 59, 51, 16));
        regLNameField = new QLineEdit(registerTab);
        regLNameField->setObjectName(QStringLiteral("regLNameField"));
        regLNameField->setGeometry(QRect(135, 119, 421, 22));
        regPassLabel2 = new QLabel(registerTab);
        regPassLabel2->setObjectName(QStringLiteral("regPassLabel2"));
        regPassLabel2->setGeometry(QRect(50, 362, 62, 16));
        regPassValid = new QLabel(registerTab);
        regPassValid->setObjectName(QStringLiteral("regPassValid"));
        regPassValid->setGeometry(QRect(135, 334, 421, 16));
        regPassValid->setStyleSheet(QStringLiteral("color:#F00;"));
        regFNameValid = new QLabel(registerTab);
        regFNameValid->setObjectName(QStringLiteral("regFNameValid"));
        regFNameValid->setGeometry(QRect(135, 91, 421, 16));
        regFNameValid->setStyleSheet(QStringLiteral("color:#F00;"));
        regPassValid2 = new QLabel(registerTab);
        regPassValid2->setObjectName(QStringLiteral("regPassValid2"));
        regPassValid2->setGeometry(QRect(135, 394, 421, 16));
        regPassValid2->setStyleSheet(QStringLiteral("color:#F00;"));
        regLNameValid = new QLabel(registerTab);
        regLNameValid->setObjectName(QStringLiteral("regLNameValid"));
        regLNameValid->setGeometry(QRect(135, 151, 421, 16));
        regLNameValid->setStyleSheet(QStringLiteral("color:#F00;"));
        regUserValid = new QLabel(registerTab);
        regUserValid->setObjectName(QStringLiteral("regUserValid"));
        regUserValid->setGeometry(QRect(135, 212, 421, 16));
        regUserValid->setStyleSheet(QStringLiteral("color:#F00;"));
        regEmailValid = new QLabel(registerTab);
        regEmailValid->setObjectName(QStringLiteral("regEmailValid"));
        regEmailValid->setGeometry(QRect(135, 273, 421, 16));
        regEmailValid->setStyleSheet(QStringLiteral("color:#F00;"));
        regTitleLabel = new QLabel(registerTab);
        regTitleLabel->setObjectName(QStringLiteral("regTitleLabel"));
        regTitleLabel->setGeometry(QRect(140, 20, 411, 16));
        regTitleLabel->setAlignment(Qt::AlignCenter);
        regPassLabel = new QLabel(registerTab);
        regPassLabel->setObjectName(QStringLiteral("regPassLabel"));
        regPassLabel->setGeometry(QRect(50, 302, 46, 16));
        regPassField = new QLineEdit(registerTab);
        regPassField->setObjectName(QStringLiteral("regPassField"));
        regPassField->setGeometry(QRect(135, 302, 421, 22));
        regPassField->setEchoMode(QLineEdit::Password);
        regEmailLabel = new QLabel(registerTab);
        regEmailLabel->setObjectName(QStringLiteral("regEmailLabel"));
        regEmailLabel->setGeometry(QRect(50, 241, 24, 16));
        regEmailField = new QLineEdit(registerTab);
        regEmailField->setObjectName(QStringLiteral("regEmailField"));
        regEmailField->setGeometry(QRect(135, 241, 421, 22));
        regFNameField = new QLineEdit(registerTab);
        regFNameField->setObjectName(QStringLiteral("regFNameField"));
        regFNameField->setGeometry(QRect(135, 59, 421, 22));
        regRegisterButton = new QPushButton(registerTab);
        regRegisterButton->setObjectName(QStringLiteral("regRegisterButton"));
        regRegisterButton->setGeometry(QRect(350, 410, 151, 21));
        regCancelButton = new QPushButton(registerTab);
        regCancelButton->setObjectName(QStringLiteral("regCancelButton"));
        regCancelButton->setGeometry(QRect(164, 410, 131, 21));
        tabWidget->addTab(registerTab, QString());
#ifndef QT_NO_SHORTCUT
        regUserLabel->setBuddy(regUserField);
        regLNameLabel->setBuddy(regLNameField);
        regFNameLabel->setBuddy(regFNameField);
        regPassLabel2->setBuddy(regPassField2);
        regPassValid->setBuddy(regPassField);
        regFNameValid->setBuddy(regFNameField);
        regPassValid2->setBuddy(regPassField2);
        regLNameValid->setBuddy(regLNameField);
        regUserValid->setBuddy(regUserField);
        regEmailValid->setBuddy(regEmailField);
        regPassLabel->setBuddy(regPassField);
        regEmailLabel->setBuddy(regEmailField);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(loginEmailField, loginPassField);
        QWidget::setTabOrder(loginPassField, loginLoginButton);
        QWidget::setTabOrder(loginLoginButton, loginCancelButton);
        QWidget::setTabOrder(loginCancelButton, regFNameField);
        QWidget::setTabOrder(regFNameField, regLNameField);
        QWidget::setTabOrder(regLNameField, regUserField);
        QWidget::setTabOrder(regUserField, regEmailField);
        QWidget::setTabOrder(regEmailField, regPassField);
        QWidget::setTabOrder(regPassField, regPassField2);
        QWidget::setTabOrder(regPassField2, regRegisterButton);
        QWidget::setTabOrder(regRegisterButton, regCancelButton);
        QWidget::setTabOrder(regCancelButton, tabWidget);

        retranslateUi(UserControlPanel);

        tabWidget->setCurrentIndex(0);
        regRegisterButton->setDefault(true);


        QMetaObject::connectSlotsByName(UserControlPanel);
    } // setupUi

    void retranslateUi(QDialog *UserControlPanel)
    {
        UserControlPanel->setWindowTitle(QApplication::translate("UserControlPanel", "Dialog", 0));
        loginCancelButton->setText(QApplication::translate("UserControlPanel", "Cancel", 0));
        loginLoginButton->setText(QApplication::translate("UserControlPanel", "Login", 0));
        loginPassValid->setText(QString());
        loginEmailValid->setText(QString());
        loginEmailLabel->setText(QApplication::translate("UserControlPanel", "email", 0));
        label->setText(QApplication::translate("UserControlPanel", "User Login", 0));
        loginPassLabel->setText(QApplication::translate("UserControlPanel", "password", 0));
        tabWidget->setTabText(tabWidget->indexOf(homeTab), QApplication::translate("UserControlPanel", "Home", 0));
        tabWidget->setTabText(tabWidget->indexOf(scoreTab), QApplication::translate("UserControlPanel", "Score", 0));
        regUserLabel->setText(QApplication::translate("UserControlPanel", "User Name", 0));
        regLNameLabel->setText(QApplication::translate("UserControlPanel", "Last Name", 0));
        regFNameLabel->setText(QApplication::translate("UserControlPanel", "First Name", 0));
        regPassLabel2->setText(QApplication::translate("UserControlPanel", "Confirm Pass", 0));
        regPassValid->setText(QString());
        regFNameValid->setText(QString());
        regPassValid2->setText(QString());
        regLNameValid->setText(QString());
        regUserValid->setText(QString());
        regEmailValid->setText(QString());
        regTitleLabel->setText(QApplication::translate("UserControlPanel", "Registration Form", 0));
        regPassLabel->setText(QApplication::translate("UserControlPanel", "Password", 0));
        regEmailLabel->setText(QApplication::translate("UserControlPanel", "Email", 0));
        regRegisterButton->setText(QApplication::translate("UserControlPanel", "Register", 0));
        regCancelButton->setText(QApplication::translate("UserControlPanel", "Cancel", 0));
        tabWidget->setTabText(tabWidget->indexOf(registerTab), QApplication::translate("UserControlPanel", "Register", 0));
    } // retranslateUi

};

namespace Ui {
    class UserControlPanel: public Ui_UserControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCONTROLPANEL_H
