#include "printMessage.h"

const char* megStr[]{
	"用户名不能为空",
	"用户名不符合规范",
	"密码不能为空",
	"确认密码不能为空",
	"密码不符合规范",
	"两次输入密码不相符",
	"注册成功",
	"用户名或密码错误",
	"登录成功",
	"请检查网络连接"
};

void printMessage (MESSAGE megCode)
{
	QMessageBox::information (NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit(megStr[megCode]), QMessageBox::Ok, QMessageBox::Ok);
}