#include "CloudDriveWinClient.h"

using MainWindow = CloudDriveWinClient;

CloudDriveWinClient::CloudDriveWinClient (const string& config_file, QWidget* parent)
	: QMainWindow (parent)
{
	ui.setupUi (this);
	this->readConfig (config_file);

	connect (ui.toolButtonLogin, &QToolButton::clicked, this, &CloudDriveWinClient::on_signinBtn_clicked);
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

bool CloudDriveWinClient::checkSigninReps ()
{
	if (this->signinresPacket.code == SIGNIN_SUCCESS) {
		//QMessageBox::information(nullptr, QString::fromLocal8Bit ("��¼"),
		//	QString::fromLocal8Bit ("��¼�ɹ�"), QMessageBox::Ok);
		printMessage (LOGINSUCCESSFUL);
		qInfo () << "sign in successfully!!" << endl;
		memcpy (session, signinresPacket.Session, SessionLength);
		return true;
	}
	else if (this->signinresPacket.code == SIGNIN_INCORRECT_PASSWORD) {

		QMessageBox::information (nullptr, QString::fromLocal8Bit ("��¼"),
			QString::fromLocal8Bit ("��¼ʧ�ܣ��������"), QMessageBox::Ok);
		qWarning () << "sign in failed, password error!!" << endl;
		return false;
	}
	else if (this->signinresPacket.code == SIGNIN_UNEXIST_USERNAME) {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("��¼"),
			QString::fromLocal8Bit ("��¼ʧ�ܣ��û�������"), QMessageBox::Ok);
		qWarning () << "sign in failed, user do not exist!!" << endl;
		return false;
	}
	qWarning () << "sign in failed, code do not handled!!" << endl;
	return false;
}

bool CloudDriveWinClient::checkSignupReps ()
{
	if (this->signupresPacket.code == SIGNUP_SUCCESS) {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("ע��"),
			QString::fromLocal8Bit ("ע��ɹ�"), QMessageBox::Ok);
		qInfo () << "sign up successfully!!" << endl;
		memcpy (session, signupresPacket.Session, SessionLength);
		return true;
	}
	qWarning () << "sign in failed, code do not handled!!" << endl;
	return false;
}


void CloudDriveWinClient::ReadError (QAbstractSocket::SocketError)
{

}

void CloudDriveWinClient::on_signinBtn_clicked ()
{
	LoginWindow loginwin;
	loginwin.exec ();
	QString username = loginwin.username;
	QString password = loginwin.password;
	if (username.isEmpty ()) {
		return;
	}
	qDebug () << "username:" + username + ", password:" << password << endl;
	//QMessageBox::information (nullptr, QString::fromLocal8Bit ("�û�������"),
	//	QString::fromLocal8Bit ("�û���") + username
	//	+ QString::fromLocal8Bit ("\n����") + password, QMessageBox::Ok);
	if (this->tcp.Connect (this->ip, this->port)) {

	}
	else {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("��¼"),
			QString::fromLocal8Bit ("����������ʧ��"), QMessageBox::Ok);
		qCritical () << QString::fromLocal8Bit ("����������ʧ��") << endl;
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
		return;
	}
	len = tcp.Write (&signinPacket, headPacket.len);
	if (len != headPacket.len) {
		qCritical () << QString ("write signupPacket len=") + len << endl;
		return;
	}
	// �ȴ���ȡsigninresBody
	len = tcp.Read (&headPacket, sizeof (headPacket));
	if (len != sizeof (headPacket)) {
		qCritical () << QString ("read headPacket len=") + len << endl;
		return;
	}
	if (headPacket.p != pType::SIGNIN_RES) {
		qCritical () << "read headPacket p != SIGNIN_RES" << endl;
		return;
	}
	len = tcp.Read (&signinresPacket, headPacket.len);
	if (len != headPacket.len) {
		qCritical () << QString ("read signinresPacket len=") << len << endl;
		return;
	}
	if (checkSigninReps ()) {
		qInfo () << QString ("login susseccful!!!");
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
	qDebug () << QString::fromLocal8Bit ("��ȡ�����û�����") + username + "�����룺" << password << endl;

	if (this->tcp.Connect (this->ip, this->port)) {

	}
	else {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("ע��"),
			QString::fromLocal8Bit ("����������ʧ��"), QMessageBox::Ok);
		qCritical () << QString::fromLocal8Bit ("����������ʧ��") << endl;

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
	sizeof (signupPacket);
	len = tcp.Write (&signupPacket, headPacket.len);
	if (len != headPacket.len) {
		qCritical () << "write signupPacket len=" << len << endl;
	}
	// �ȴ���ȡsignupresBody
	len = tcp.Read (&headPacket, sizeof (headPacket));
	if (len != sizeof (headPacket)) {
		qCritical () << "read headPacket len=" << len << endl;
	}
	sizeof (signupresPacket);
	len = tcp.Read (&signupresPacket, headPacket.len);
	if (len != headPacket.len) {
		qCritical () << "read headPacket len=" << len << endl;
	}
	if (checkSignupReps ()) {
		qInfo () << "sign up successful" << endl;
	}
}

