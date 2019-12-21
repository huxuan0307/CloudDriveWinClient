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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QTabWidget *tabWidget;
    QWidget *tabFileList;
    QTableView *tableView;
    QToolButton *toolButtonDelete;
    QWidget *tabUpload;
    QToolButton *toolButtonLogout;
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
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(70, 80, 831, 461));
        tabFileList = new QWidget();
        tabFileList->setObjectName(QStringLiteral("tabFileList"));
        tableView = new QTableView(tabFileList);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(25, 71, 771, 351));
        toolButtonDelete = new QToolButton(tabFileList);
        toolButtonDelete->setObjectName(QStringLiteral("toolButtonDelete"));
        toolButtonDelete->setGeometry(QRect(600, 30, 47, 21));
        tabWidget->addTab(tabFileList, QString());
        tabUpload = new QWidget();
        tabUpload->setObjectName(QStringLiteral("tabUpload"));
        tabWidget->addTab(tabUpload, QString());
        toolButtonLogout = new QToolButton(centralWidget);
        toolButtonLogout->setObjectName(QStringLiteral("toolButtonLogout"));
        toolButtonLogout->setGeometry(QRect(860, 50, 51, 21));
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CloudDriveWinClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *CloudDriveWinClientClass)
    {
        CloudDriveWinClientClass->setWindowTitle(QApplication::translate("CloudDriveWinClientClass", "CloudDriveWinClient", Q_NULLPTR));
        toolButtonLogin->setText(QApplication::translate("CloudDriveWinClientClass", "\347\231\273\345\275\225", Q_NULLPTR));
        labelWelcome->setText(QApplication::translate("CloudDriveWinClientClass", "\350\257\267\345\205\210\347\231\273\345\275\225", Q_NULLPTR));
        toolButtonReg->setText(QApplication::translate("CloudDriveWinClientClass", "\346\263\250\345\206\214", Q_NULLPTR));
        toolButtonDelete->setText(QApplication::translate("CloudDriveWinClientClass", "\345\210\240\351\231\244", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabFileList), QApplication::translate("CloudDriveWinClientClass", "\347\275\221\347\233\230\346\226\207\344\273\266\345\210\227\350\241\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tabUpload), QApplication::translate("CloudDriveWinClientClass", "\344\270\212\344\274\240\345\210\227\350\241\250", Q_NULLPTR));
        toolButtonLogout->setText(QApplication::translate("CloudDriveWinClientClass", "\347\231\273\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CloudDriveWinClientClass: public Ui_CloudDriveWinClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDDRIVEWINCLIENT_H
