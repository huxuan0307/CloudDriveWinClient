#include "CloudDriveWinClient.h"
//#include "checkBoxHeader.h" // ���鸴ѡ��ʧ�ܡ���������
using MainWindow = CloudDriveWinClient;

CloudDriveWinClient::CloudDriveWinClient (const string& config_file, QWidget* parent)
	: QMainWindow (parent), hasSignedin (false)
{
	ui.setupUi (this);
	this->readConfig (config_file);
	this->currentDir = "/";
	connect (ui.toolButtonLogin, &QToolButton::clicked, this, &CloudDriveWinClient::on_signinBtn_clicked);
	connect (ui.toolButtonReg, &QToolButton::clicked, this, &CloudDriveWinClient::on_signupBtn_clicked);
	connect (ui.toolButtonDelete, &QToolButton::clicked, this, &CloudDriveWinClient::on_deleteBtn_clicked);
	connect (ui.toolButtonLogout, &QToolButton::clicked, this, &CloudDriveWinClient::on_logoutBtn_clicked);
	connect (ui.toolButtonMKDir, &QToolButton::clicked, this, &CloudDriveWinClient::on_mkdirBtn_clicked);

	//--------------------- ����ļ�������
	//this->fileinfov.push_back (FileInfo{ string ("1.txt"),20,string ("2019-10-10 20:58:21"),true });
	//this->fileinfov.push_back (FileInfo{ string ("2.txt"),20,string ("2019-10-10 20:58:21"),true });
	//this->fileinfov.push_back (FileInfo{ string ("3.txt"),20,string ("2019-10-10 20:58:21"),true });
	//this->fileinfov.push_back (FileInfo{ string ("4.txt"),20,string ("2019-10-10 20:58:21"),true });
	this->fillTableView ();
	this->ui.toolButtonLogout->setVisible (false);
}

void CloudDriveWinClient::openRegWindow ()
{
	//this->loginWindow.reset (new Ui::LoginWindow ());
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
		return true;
	}
	else if (this->signupresPacket.code == SIGNUP_EXISTED_USERNAME) {
		QMessageBox::information (nullptr, QString::fromLocal8Bit ("ע��"),
			QString::fromLocal8Bit ("ע��ʧ�ܣ��û����Ѵ���"), QMessageBox::Ok);
		qInfo () << "sign up failed!!" << endl;
		return false;
	}
	qWarning () << "sign up failed, code do not handled!!" << endl;
	return false;
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
		hasSignedin = true;
		ui.toolButtonLogin->setVisible (false);
		ui.toolButtonReg->setVisible (false);
		ui.toolButtonLogout->setVisible (true);
		ui.labelWelcome->setText (username);
		// ��¼session
		strncpy (session, signinresPacket.Session, SessionLength);
		this->Syn ();
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
	qDebug () << QString::fromLocal8Bit ("username: ") + username + ", password:" << password << endl;

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

void CloudDriveWinClient::fillTableView ()
{
	auto& tableView = ui.tableView;
	QStandardItemModel* standItemModel = new QStandardItemModel ();
	standItemModel->setColumnCount (4);
	standItemModel->setHeaderData (0, Qt::Horizontal, QStringLiteral ("���"));
	standItemModel->setHeaderData (1, Qt::Horizontal, QStringLiteral ("�ļ���"));   //���ñ�ͷ����
	standItemModel->setHeaderData (2, Qt::Horizontal, QStringLiteral ("��С"));
	standItemModel->setHeaderData (3, Qt::Horizontal, QStringLiteral ("����ʱ��"));
	QStandardItem* itemFilename;
	QStandardItem* itemSize;
	QStandardItem* itemCtime;
	QStandardItem* itemFlag;

	if (currentDir == "/") {
		itemFilename = new QStandardItem ("/");
	}
	else {
		itemFilename = new QStandardItem ("..");
	}
	itemFlag = new QStandardItem ("D");
	itemSize = new QStandardItem ("-");
	standItemModel->setItem (0, 0, itemFlag);
	standItemModel->setItem (0, 1, itemFilename);
	standItemModel->setItem (0, 2, itemSize);
	int i = 1;
	for (auto& fileinfo : this->fileinfov) {
		itemFilename = new QStandardItem (QString::fromLocal8Bit (fileinfo.name.data ()));
		itemSize = new QStandardItem (tr ("%1B").arg (fileinfo.size));
		itemCtime = new QStandardItem (QString (fileinfo.ctime.data ()));
		itemFlag = new QStandardItem (fileinfo.isFile ? QString ("F") : QString ("D"));
		standItemModel->setItem (i, 0, itemFlag);
		standItemModel->setItem (i, 1, itemFilename);
		standItemModel->setItem (i, 2, itemSize);
		standItemModel->setItem (i, 3, itemCtime);
		++i;
	}
	tableView->setModel (standItemModel);
	tableView->horizontalHeader ()->setDefaultAlignment (Qt::AlignCenter);        //��ͷ��Ϣ��ʾ����
	//tableView->horizontalHeader ()->setSectionResizeMode (0, QHeaderView::Fixed);  //�趨��ͷ�п��ɱ�
	//tableView->horizontalHeader ()->setSectionResizeMode (1, QHeaderView::Fixed);
	tableView->horizontalHeader ()->setSectionResizeMode (2, QHeaderView::Stretch);//�趨��2�б�ͷ��������
	tableView->setColumnWidth (0, 100);       //�趨����0�п��
	tableView->setColumnWidth (1, 200);
	tableView->verticalHeader ()->hide ();    //����Ĭ����ʾ����ͷ
	tableView->setSelectionBehavior (QAbstractItemView::SelectRows); //����ѡ��ʱ����ѡ��
	tableView->setEditTriggers (QAbstractItemView::NoEditTriggers);  //���ñ������ֻ�������ܱ༭
	//tableView->setHorizontalHeader (new checkBoxHeader (Qt::Horizontal, tableView));

}

void CloudDriveWinClient::on_refreshBtn_clicked ()
{

}

void CloudDriveWinClient::on_deleteBtn_clicked ()
{
	auto rows = this->getSelectedRow ();
	for (auto& item : rows) {
		fileinfov[item - 1].selected = true;
	}
	for (auto& file : fileinfov) {
		if (file.selected) {
			qDebug () << file.name.data ();
		}
	}
}

void CloudDriveWinClient::on_mkdirBtn_clicked ()
{
	//this->SendMkdir()
}

QSet<int> CloudDriveWinClient::getSelectedRow ()
{
	auto selections = ui.tableView->selectionModel ();
	auto modelList = selections->selectedIndexes ();
	QSet<int> rows;
	for (auto& item : modelList) {
		rows.insert (item.row ());
	}
	return rows;
}

void CloudDriveWinClient::on_logoutBtn_clicked ()
{
	this->tcp.disconnect ();
	ui.toolButtonLogin->setVisible (true);
	ui.toolButtonReg->setVisible (true);
	ui.toolButtonLogout->setVisible (false);
	ui.labelWelcome->setText (QString::fromLocal8Bit ("���ȵ�¼"));
}

void CloudDriveWinClient::SendSynReq ()
{
	headPacket.p = pType::SYN_REQ;
	headPacket.len = pMap.at (pType::SYN_REQ);
	strcpy (this->synReqPacket.path, "/");
	strncpy (this->synReqPacket.Session, session, SessionLength);
	this->tcp.Write (&headPacket, sizeof (headPacket));
	this->tcp.Write (&synReqPacket, headPacket.len);
}

void CloudDriveWinClient::RecvSynResp ()
{
	tcp.Read (&headPacket, sizeof (headPacket));
	if (headPacket.p != pType::SYN_RESP) {
		qCritical () << "RecvSynResp recv wrong pType";
	}
	tcp.Read (&synRespPacket, headPacket.len);
}

void CloudDriveWinClient::RecvSynPush ()
{
	for (int i = 0; i < synRespPacket.childNum; ++i) {
		tcp.Read (&headPacket, sizeof (headPacket));
		tcp.Read (&synPushPacket, headPacket.len);
		// sizeof (synPushPacket) = 520
		this->fileinfov.push_back ({ synPushPacket.name,0/*sizeû����*/,string{}/*�޸�ʱ��*/,(bool)synPushPacket.isFile });
	}
}

// ͬ������
void CloudDriveWinClient::Syn ()
{
	fileinfov.clear ();
	SendSynReq ();
	RecvSynResp ();
	RecvSynPush ();
	this->fillTableView ();
}

void CloudDriveWinClient::SendMkdir (const QString& dirName)
{
	headPacket.p = pType::MKDIR;
	headPacket.len = pMap.at (pType::MKDIR);
	strcpy (this->mkdirPacket.dirName, dirName.toLocal8Bit ());
	strcpy (this->mkdirPacket.path, this->currentDir.data ());
	strncpy (mkdirPacket.Session, this->session, SessionLength);
	tcp.Write (&headPacket, sizeof (headPacket));
	tcp.Write (&mkdirPacket, headPacket.len);
}

void CloudDriveWinClient::RecvMkdirResp ()
{
	tcp.Read (&headPacket, sizeof (headPacket));
	if (headPacket.p != pType::SYN_RESP) {
		qCritical () << "RecvSynResp recv wrong pType";
	}
	tcp.Read (&mkdirRespPacket, headPacket.len);
}