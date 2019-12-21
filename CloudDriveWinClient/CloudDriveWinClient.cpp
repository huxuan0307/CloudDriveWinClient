#include "CloudDriveWinClient.h"

using MainWindow = CloudDriveWinClient;

CloudDriveWinClient::CloudDriveWinClient (QWidget* parent)
	: QMainWindow (parent)
{
	ui.setupUi (this);
	tcpClient = new QTcpSocket (this);
	//tcpClient->abort ();
	//connect (tcpClient, &QTcpSocket::readyRead, this, &MainWindow::ReadData);
	//tcpClient->error (QAbstractSocket::SocketError (0));
	//connect (tcpClient, qOverload< QAbstractSocket::SocketError>.of (&QAbstractSocket::error), this, &MainWindow::ReadError);

	connect (ui.toolButtonLogin, &QToolButton::clicked, this, &CloudDriveWinClient::on_loginBtn_clicked);

}

void CloudDriveWinClient::openRegWindow ()
{
	//this->loginWindow.reset (new Ui::LoginWindow ());
}

void CloudDriveWinClient::ReadData ()
{
	
	QByteArray buffer = this->tcpClient->readAll ();
	if (!buffer.isEmpty ()) {
		
	}
}

void CloudDriveWinClient::ReadError (QAbstractSocket::SocketError)
{

}

void CloudDriveWinClient::on_btnConnect_clicked ()
{ }

void CloudDriveWinClient::on_btnSend_clicked ()
{ }

void CloudDriveWinClient::on_pushButton_clicked ()
{ }

void CloudDriveWinClient::on_loginBtn_clicked ()
{ 
	LoginWindow loginwin;
	loginwin.exec ();
	QString username = loginwin.username;
	QString password = loginwin.password;
	QMessageBox::information (nullptr, "”√ªß√˚√‹¬Î", username + password, QMessageBox::Ok);

}

