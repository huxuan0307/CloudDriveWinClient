#include "CloudDriveWinClient.h"

using MainWindow = CloudDriveWinClient;

CloudDriveWinClient::CloudDriveWinClient (const string& config_file, QWidget* parent)
	: QMainWindow (parent)
{
	ui.setupUi (this);
	this->readConfig (config_file);

	connect (ui.toolButtonLogin, &QToolButton::clicked, this, &CloudDriveWinClient::on_loginBtn_clicked);
	connect (ui.toolButtonReg, &QToolButton::clicked, this, &CloudDriveWinClient::on_signupBtn_clicked);

}

void CloudDriveWinClient::openRegWindow ()
{
	//this->loginWindow.reset (new Ui::LoginWindow ());
}

void CloudDriveWinClient::ReadData ()
{

}

void CloudDriveWinClient::readConfig (const string& config_file)
{
	Config c (config_file);
	this->ip = QString::fromStdString (c.getValue ("Control", "ip"));
	this->port = static_cast<uint16_t> (atoi (c.getValue ("Control", "port").data ()));

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
	if (username.isEmpty ()) {
		return;
	}
	qDebug () << "username:" + username + ", password:" << password << endl;
	//QMessageBox::information (nullptr, QString::fromLocal8Bit ("用户名密码"),
	//	QString::fromLocal8Bit ("用户名") + username
	//	+ QString::fromLocal8Bit ("\n密码") + password, QMessageBox::Ok);
	if (this->tcp.Connect (this->ip, this->port)) {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("登录"),
			QString::fromLocal8Bit ("服务器连接成功"), QMessageBox::Ok);
	}
	else {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("登录"),
			QString::fromLocal8Bit ("服务器连接失败"), QMessageBox::Ok);
		qCritical () << QString::fromLocal8Bit ("服务器连接失败") << endl;
		return;
	}
	headPacket.p = pType::SIGNIN;
	headPacket.len = pMap.at (pType::SIGNIN);

	qint64 len;
	strncpy (signinPacket.Username, username.toLatin1 (), (size_t)username.size ());
	signinPacket.Username[username.size ()] = '\0';
	strncpy (signinPacket.Password, password.toLatin1 (), (size_t)password.size ());
	signinPacket.Password[password.size ()] = '\0';
	len = tcp.Write (&headPacket, sizeof (headPacket));
	if (len != sizeof (headPacket)) {
		qCritical () << QString ("write headPacket len=") + len << endl;
	}
	len = tcp.Write (&signinPacket, headPacket.len);
	if (len != headPacket.len) {
		qCritical () << QString ("write signupPacket len=") + len << endl;
	}
	// 等待收取signinresBody
	len = tcp.Read (&headPacket, sizeof (headPacket));
	if (len != sizeof (headPacket)) {
		qCritical () << QString ("read headPacket len=") + len << endl;
	}
	if (headPacket.p != pType::SIGNIN_RES) {
		qCritical () << "read headPacket p != SIGNIN_RES" << endl;
	}
	len = tcp.Read (&signinresPacket, headPacket.len);
	if (len != headPacket.len) {
		qCritical () << QString ("read signinresPacket len=") + len << endl;
	}


}

void CloudDriveWinClient::on_signupBtn_clicked ()
{
	SignupDialog signupDialog;
	signupDialog.exec ();
	QString username = signupDialog.username;
	QString password = signupDialog.password;
	if (username.isEmpty ()) {
		return;
	}
	qDebug () << QString::fromLocal8Bit ("获取到的用户名：") + username + "，密码：" << password << endl;
	//QMessageBox::information (nullptr, QString::fromLocal8Bit ("用户名密码"),
	//	QString::fromLocal8Bit ("用户名") + username
	//	+ QString::fromLocal8Bit ("\n密码") + password, QMessageBox::Ok);
	if (this->tcp.Connect (this->ip, this->port)) {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("注册"),
			QString::fromLocal8Bit ("服务器连接成功"), QMessageBox::Ok);
	}
	else {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("注册"),
			QString::fromLocal8Bit ("服务器连接失败"), QMessageBox::Ok);
		qCritical () << QString::fromLocal8Bit ("服务器连接失败") << endl;

		return;
	}
	headPacket.p = pType::SIGNUP;
	headPacket.len = pMap.at (pType::SIGNUP);

	qint64 len;
	strncpy (signupPacket.Username, username.toLatin1 (), (size_t)username.size ());
	signupPacket.Username[username.size ()] = '\0';
	strncpy (signupPacket.Password, password.toLatin1 (), (size_t)password.size ());
	signupPacket.Password[password.size ()] = '\0';
	len = tcp.Write (&headPacket, sizeof (headPacket));
	if (len != sizeof (headPacket)) {
		qCritical () << "write headPacket len=" << len << endl;
	}
	len = tcp.Write (&signupPacket, headPacket.len);
	if (len != headPacket.len) {
		qCritical () << "write signupPacket len=" << len << endl;
	}
	// 等待收取signupresBody
	len = tcp.Read (&headPacket, sizeof (headPacket));
	if (len != sizeof (headPacket)) {
		qCritical () << "read headPacket len=" << len << endl;
	}
	len = tcp.Read (&signupresPacket, headPacket.len);
	if (len != headPacket.len) {
		qCritical () << "read headPacket len=" << len << endl;
	}

}

