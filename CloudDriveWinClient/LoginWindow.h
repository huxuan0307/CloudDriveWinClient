#pragma once

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QToolButton>
#include <QDialog>
#include <string>
#include "uic/ui_LoginWindow.h"
#include "include/Package/Package.h"
#include "printMessage.h"

namespace Ui { class LoginWindow; };
using std::string;
class LoginWindow : public QDialog
{
	Q_OBJECT

public:
	LoginWindow (QWidget* parent = Q_NULLPTR);
	~LoginWindow ();
	QString username;
	QString password;

private:
	Ui::LoginWindow* ui;
	//MESSAGE msgcode;		//´íÎóÂë


	//IPv4Protocol;
	bool preLoginCheck ();

	//void loginRes ();
	//void loginSucc ();
	//void loginFailed (SigninCodes);
private slots:

	/*void login ();*/
	void on_cancelBtn_clicked ();
	void on_signinBtn_clicked ();

};
