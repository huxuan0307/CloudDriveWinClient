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
	NOUSERNAME,			//没输入用户名
	WRONGUSERNAME,		//注册用户名不合规范
	NOPASSWORD,			//没输入密码
	NOPASSWORD2,		//没输入密码2
	WRONGPASSWORD,		//注册密码不合规范
	NOEQUPASSWORD,		//两个密码不相符
	SIGNUPSUCCESSFUL,	//注册成功
	LOGINFAIL,			//登录失败
	LOGINSUCCESSFUL,	//登录成功
	NETWORKERR,			//tcp连接无法建立
};

//const map<ERRNO, QString>ErrStr{
//	{ERRNO::NOUSERNAME,"用户名不能为空"},
//
//};



void printMessage (MESSAGE megCode);