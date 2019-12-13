#include "LoginWindow.h"
#include "ui_LoginWindow.h"

LoginWindow::LoginWindow (QWidget* parent)
	: QWidget (parent), head (PackageType::SIGNIN)
{

	ui = new Ui::LoginWindow ();
	ui->setupUi (this);
	this->port = 0;

	tcp->abort ();



}

LoginWindow::~LoginWindow ()
{
	delete ui;
}
// 检查用户名和密码
bool LoginWindow::preLoginCheck ()
{
	username = ui->lineEditUserName->text ().toStdString ();
	if (username.empty ()) {
		msgcode = MESSAGE::NOUSERNAME;
		return false;
	}
	password = ui->lineEditPassword->text ().toStdString ();
	if (password.empty ()) {
		msgcode = MESSAGE::NOPASSWORD;
		return false;
	}
	return true;
}

void LoginWindow::login ()
{
	if (!this->preLoginCheck ()) {
		printMessage (this->msgcode);
		return;
	}
	tcp->connectToHost (address, port);
	if (tcp->waitForConnected (1000)) {
		printMessage (MESSAGE::NETWORKERR);
		return;
	}

	strcpy (req.Username, username.data ());
	strcpy (req.Password, password.data ());
	tcp->write ((char*)&head, sizeof (head));
	tcp->write ((char*)&req, sizeof (req));
	connect (tcp, &QTcpSocket::readyRead, this, &LoginWindow::loginRes);

}

void LoginWindow::loginRes ()
{
	QByteArray buffer = tcp->read (sizeof (UniformHeader));
	if (!buffer.isEmpty ()) {
		const UniformHeader* headp = (UniformHeader*)buffer.data ();
		if (headp->p == PackageType::SIGNIN_RES) {
			buffer = tcp->read (headp->len);
			if (!buffer.isEmpty ()) {
				const SigninresBody* signinresp = (SigninresBody*)buffer.data ();
				if (signinresp->code == SigninCodes::SIGNIN_SUCCESS) {
					this->loginSucc ();
				}
				else {
					this->loginFailed (signinresp->code);
				}
			}
			else {
				qCritical () << "loginRes() buffer为空 2";
			}
		}
		else {
			qCritical () << "收到非SIGNIN_RES包";
		}

	}
	else {
		qCritical () << "loginRes() buffer为空 1";
	}
}

inline void LoginWindow::loginSucc ()
{
	qInfo () << "登录成功";
	printMessage (MESSAGE::LOGINSUCCESSFUL);
}

inline void LoginWindow::loginFailed (SigninCodes code)
{
	if (code == SigninCodes::SIGNIN_UNEXIST_USERNAME) {
		qWarning () << "登录失败，用户名不存在";
	}
	else if (code == SigninCodes::SIGNIN_INCORRECT_PASSWORD) {
		qWarning () << "登录失败，密码错误";
	}
	else {
		qWarning () << "登录失败，未知错误";
	}
	printMessage (MESSAGE::LOGINFAIL);
}