#pragma once

#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include <qfile.h>
#include <memory>
#include <string>
#include <QStandardItemModel>
#include <QTableView>
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
	struct FileInfo
	{
		string name;
		uint64_t size;	// Bytes
		string ctime;	// 创建时间
		bool isFile;
		bool selected;
	};


private:
	Ui::CloudDriveWinClientClass ui;
	QFile* qfile;
	SocketConnect tcp;
	QString ip;
	uint32_t port;
	void readConfig (const string&);
	bool hasSignedin;
	string currentDir;

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
	CopyBody        copyPacket;
	DeleteBody      deletePacket;
	MoveBody        movePacket;
	MkdirBody       mkdirPacket;
	SYNReqBody      synReqPacket;
	CopyRespBody        copyRespPacket;
	DeleteRespBody      deleteRespPacket;
	MkdirRespBody       mkdirRespPacket;
	MoveRespBody        moveRespPacket;
	SYNRespBody      synRespPacket;
	SYNPushBody		synPushPacket;
	QVector<FileInfo> fileinfov;
	char session[SessionLength];

	bool checkSignupReps ();
	bool checkSigninReps ();

private slots:
	void on_signinBtn_clicked ();
	void on_signupBtn_clicked ();
	void fillTableView ();
	void on_refreshBtn_clicked ();
	void on_deleteBtn_clicked ();
	QSet<int> getSelectedRow ();
	void on_logoutBtn_clicked ();
	void SendSynReq ();
	void RecvSynResp ();
	void RecvSynPush ();
	void Syn ();
	void SendMkdir (const QString& dirName);
	void RecvMkdirResp ();
	void openRegWindow ();

};
