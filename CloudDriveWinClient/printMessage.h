#pragma once
#include <vector>
#include <string>
#include <QMessageBox>
#include <QString>
#include <map>
using std::string;
using std::vector;
using std::map;
enum MESSAGE
{
	NOUSERNAME,			//û�����û���
	WRONGUSERNAME,		//ע���û������Ϲ淶
	NOPASSWORD,			//û��������
	NOPASSWORD2,		//û��������2
	WRONGPASSWORD,		//ע�����벻�Ϲ淶
	NOEQUPASSWORD,		//�������벻���
	SIGNUPSUCCESSFUL,	//ע��ɹ�
	LOGINFAIL,			//��¼ʧ��
	LOGINSUCCESSFUL,	//��¼�ɹ�
	NETWORKERR,			//tcp�����޷�����
};

//const map<ERRNO, QString>ErrStr{
//	{ERRNO::NOUSERNAME,"�û�������Ϊ��"},
//
//};



void printMessage (MESSAGE megCode);