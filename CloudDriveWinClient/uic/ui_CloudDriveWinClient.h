/********************************************************************************
** Form generated from reading UI file 'CloudDriveWinClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOUDDRIVEWINCLIENT_H
#define UI_CLOUDDRIVEWINCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CloudDriveWinClientClass
{
public:
    QWidget *centralWidget;
    QToolButton *toolButtonLogin;
    QLabel *labelWelcome;
    QToolButton *toolButtonReg;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CloudDriveWinClientClass)
    {
        if (CloudDriveWinClientClass->objectName().isEmpty())
            CloudDriveWinClientClass->setObjectName(QStringLiteral("CloudDriveWinClientClass"));
        CloudDriveWinClientClass->resize(968, 626);
        centralWidget = new QWidget(CloudDriveWinClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toolButtonLogin = new QToolButton(centralWidget);
        toolButtonLogin->setObjectName(QStringLiteral("toolButtonLogin"));
        toolButtonLogin->setGeometry(QRect(830, 50, 51, 21));
        labelWelcome = new QLabel(centralWidget);
        labelWelcome->setObjectName(QStringLiteral("labelWelcome"));
        labelWelcome->setGeometry(QRect(830, 20, 111, 16));
        labelWelcome->setAlignment(Qt::AlignCenter);
        toolButtonReg = new QToolButton(centralWidget);
        toolButtonReg->setObjectName(QStringLiteral("toolButtonReg"));
        toolButtonReg->setGeometry(QRect(890, 50, 51, 21));
        CloudDriveWinClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CloudDriveWinClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 968, 26));
        CloudDriveWinClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CloudDriveWinClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CloudDriveWinClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CloudDriveWinClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CloudDriveWinClientClass->setStatusBar(statusBar);

        retranslateUi(CloudDriveWinClientClass);

        QMetaObject::connectSlotsByName(CloudDriveWinClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *CloudDriveWinClientClass)
    {
        CloudDriveWinClientClass->setWindowTitle(QApplication::translate("CloudDriveWinClientClass", "CloudDriveWinClient", Q_NULLPTR));
        toolButtonLogin->setText(QApplication::translate("CloudDriveWinClientClass", "\347\231\273\345\275\225", Q_NULLPTR));
        labelWelcome->setText(QApplication::translate("CloudDriveWinClientClass", "\350\257\267\345\205\210\347\231\273\345\275\225", Q_NULLPTR));
        toolButtonReg->setText(QApplication::translate("CloudDriveWinClientClass", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CloudDriveWinClientClass: public Ui_CloudDriveWinClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDDRIVEWINCLIENT_H
