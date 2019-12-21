#pragma once

#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include <qfile.h>
#include <memory>
#include <string>
#include "LoginWindow.h"
#include "SignupDialog.h"
#include "socketconnect.h"
#include "Config.h"
#include "uic/ui_CloudDriveWinClient.h"
#include "uic/ui_LoginWindow.h"
using std::unique_ptr;
using std::string;
using std::strtoul;
using pType = PackageType;
//auto &pMap = PackageSizeMap;
class CloudDriveWinClient : public QMainWindow
{
	Q_OBJECT

public:
	CloudDriveWinClient (const string& config_file, QWidget* parent = Q_NULLPTR);

private:
	Ui::CloudDriveWinClientClass ui;
	QFile* qfile;
	SocketConnect tcp;
	QString ip;
	uint32_t port;
	void readConfig (const string&);

	UniformHeader headPacket;
	SigninBody signinPacket;
	SigninresBody signinresPacket;
	SignupBody signupPacket;
	SignupresBody signupresPacket;
	DownloadFetchBody downloadfetchPacket;
	DownloadDoneBody downloaddonePacket;
	DownloadPushBody downloadpushPacket;
	DownloadReqBody downloadreqPacket;
	DownloadRespBody downloadrespPacket;
	UploadReqBody uploadReqPacket;
	UploadRespBody uploadrespPacket;
	UploadFetchBody uploadfetchPacket;
	UploadPushBody uploadpushPacket;
	UploadDoneBody uploadDonePacket;
	FileInfoBody fileInfoPacket;
	char session[SessionLength];

	bool checkSignupReps ();
	bool checkSigninReps ();

private slots:
	void ReadData ();
	void ReadError (QAbstractSocket::SocketError);
	void on_signinBtn_clicked ();
	void on_signupBtn_clicked ();
	void openRegWindow ();

};
