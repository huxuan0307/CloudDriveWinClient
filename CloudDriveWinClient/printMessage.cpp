#include "printMessage.h"

const char* megStr[]{
	"�û�������Ϊ��",
	"�û��������Ϲ淶",
	"���벻��Ϊ��",
	"���벻���Ϲ淶",
	"�û������������",
	"��¼�ɹ�",
	"������������"
};

void printMessage (MESSAGE megCode)
{
	QMessageBox::information (NULL, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit(megStr[megCode]), QMessageBox::Ok, QMessageBox::Ok);
}