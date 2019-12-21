#include "SignupDialog.h"


SignupDialog::SignupDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::SignupDialog();
	ui->setupUi(this);

	connect (ui->toolButtonSignUp, &QToolButton::clicked, this, &SignupDialog::on_signupBtn_clicked);
	connect (ui->toolButtonCancel, &QToolButton::clicked, this, &SignupDialog::on_cancelBtn_clicked);

}

SignupDialog::~SignupDialog()
{
	delete ui;
}

bool SignupDialog::preSignUpCheck ()
{
	username = ui->lineEditUserName->text ();
	if (username.isEmpty ()) {
		printMessage (MESSAGE::NOUSERNAME);
		return false;
	}
	password = ui->lineEditPassword->text ();
	if (password.isEmpty ()) {
		printMessage (MESSAGE::NOPASSWORD);
		return false;
	}
	return true;
}

void SignupDialog::on_cancelBtn_clicked ()
{
	this->reject ();
}

void SignupDialog::on_signupBtn_clicked ()
{ 
	if (this->preSignUpCheck()) {
		this->accept ();
	}
}
