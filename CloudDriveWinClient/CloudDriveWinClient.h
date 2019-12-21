#pragma once

#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include <qfile.h>
#include <memory>
#include "LoginWindow.h"
#include "uic/ui_CloudDriveWinClient.h"
#include "uic/ui_LoginWindow.h"
using std::unique_ptr;
class CloudDriveWinClient : public QMainWindow
{
	Q_OBJECT

public:
	CloudDriveWinClient(QWidget *parent = Q_NULLPTR);

private:
	Ui::CloudDriveWinClientClass ui;
	QTcpSocket* tcpClient;
	QFile* qfile;
	//unique_ptr<Ui::LoginWindow> loginWindow;
	//unique_ptr<QDialog> regWindow;
private slots:
	void ReadData ();
	void ReadError (QAbstractSocket::SocketError);

	void on_btnConnect_clicked ();
	void on_btnSend_clicked ();
	void on_pushButton_clicked ();
	void on_loginBtn_clicked ();
	void openRegWindow ();

};
