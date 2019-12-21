#pragma once

#include <QDialog>
#include "uic/ui_SignupDialog.h"
#include "printMessage.h"
namespace Ui { class SignupDialog; };

class SignupDialog : public QDialog
{
	Q_OBJECT

public:
	SignupDialog(QWidget *parent = Q_NULLPTR);
	~SignupDialog();
	QString username;
	QString password;
	QString password2;


private:
	Ui::SignupDialog *ui;
	bool preSignUpCheck ();

private slots:

	void on_signupBtn_clicked ();
	void on_cancelBtn_clicked ();


};
