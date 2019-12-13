#pragma once

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <string>
#include "package.h"
#include "printMessage.h"

namespace Ui { class LoginWindow; };
using std::string;
class LoginWindow : public QWidget
{
	Q_OBJECT

public:
	LoginWindow (QWidget* parent = Q_NULLPTR);
	~LoginWindow ();

private:
	Ui::LoginWindow* ui;
	QTcpSocket* tcp;
	QHostAddress address;
	quint16 port;
	MESSAGE msgcode;		//´íÎóÂë

	UniformHeader head;
	SigninBody req;
	string username;
	string password;
	//IPv4Protocol;
	bool preLoginCheck ();
	void loginRes ();
	void loginSucc ();
	void loginFailed (SigninCodes);

private slots:

	void login ();

};
