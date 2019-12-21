/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEditUserName;
    QLabel *label;
    QLineEdit *lineEditPassword;
    QToolButton *toolButtonLogin;
    QToolButton *toolButtonCancel;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(672, 430);
        layoutWidget = new QWidget(LoginWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 130, 225, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditUserName = new QLineEdit(layoutWidget);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));

        gridLayout->addWidget(lineEditUserName, 0, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));

        gridLayout->addWidget(lineEditPassword, 1, 2, 1, 1);

        toolButtonLogin = new QToolButton(LoginWindow);
        toolButtonLogin->setObjectName(QStringLiteral("toolButtonLogin"));
        toolButtonLogin->setGeometry(QRect(230, 270, 47, 21));
        toolButtonCancel = new QToolButton(LoginWindow);
        toolButtonCancel->setObjectName(QStringLiteral("toolButtonCancel"));
        toolButtonCancel->setGeometry(QRect(370, 270, 47, 21));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        toolButtonLogin->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        toolButtonCancel->setText(QApplication::translate("LoginWindow", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
