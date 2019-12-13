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
	WRONGPASSWORD,		//注册密码不合规范
	LOGINFAIL,			//登录失败
	LOGINSUCCESSFUL,	//登录成功
	NETWORKERR,			//tcp连接无法建立
};

//const map<ERRNO, QString>ErrStr{
//	{ERRNO::NOUSERNAME,"用户名不能为空"},
//
//};

const QString megStr[]{
	"用户名不能为空",
	"用户名不符合规范",
	"密码不能为空",
	"密码不符合规范",
	"用户名或密码错误",
	"登录成功",
	"请检查网络连接"
};

void printMessage (MESSAGE megCode)
{
	QMessageBox::information (NULL, "提示", megStr[megCode], QMessageBox::Ok, QMessageBox::Ok);
}