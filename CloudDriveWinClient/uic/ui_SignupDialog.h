/********************************************************************************
** Form generated from reading UI file 'SignupDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignupDialog
{
public:
    QToolButton *toolButtonCancel;
    QToolButton *toolButtonSignUp;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEditUserName;
    QLabel *label;
    QLineEdit *lineEditPassword;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditPassword_2;

    void setupUi(QDialog *SignupDialog)
    {
        if (SignupDialog->objectName().isEmpty())
            SignupDialog->setObjectName(QStringLiteral("SignupDialog"));
        SignupDialog->resize(673, 432);
        toolButtonCancel = new QToolButton(SignupDialog);
        toolButtonCancel->setObjectName(QStringLiteral("toolButtonCancel"));
        toolButtonCancel->setGeometry(QRect(350, 270, 47, 21));
        toolButtonSignUp = new QToolButton(SignupDialog);
        toolButtonSignUp->setObjectName(QStringLiteral("toolButtonSignUp"));
        toolButtonSignUp->setGeometry(QRect(250, 270, 47, 21));
        layoutWidget = new QWidget(SignupDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 110, 251, 131));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEditUserName = new QLineEdit(layoutWidget);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));

        gridLayout->addWidget(lineEditUserName, 0, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));

        gridLayout->addWidget(lineEditPassword, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEditPassword_2 = new QLineEdit(layoutWidget);
        lineEditPassword_2->setObjectName(QStringLiteral("lineEditPassword_2"));

        gridLayout->addWidget(lineEditPassword_2, 2, 2, 1, 1);


        retranslateUi(SignupDialog);

        QMetaObject::connectSlotsByName(SignupDialog);
    } // setupUi

    void retranslateUi(QDialog *SignupDialog)
    {
        SignupDialog->setWindowTitle(QApplication::translate("SignupDialog", "SignupDialog", Q_NULLPTR));
        toolButtonCancel->setText(QApplication::translate("SignupDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        toolButtonSignUp->setText(QApplication::translate("SignupDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("SignupDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("SignupDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("SignupDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignupDialog: public Ui_SignupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
