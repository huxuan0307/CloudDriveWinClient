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
	WRONGPASSWORD,		//ע�����벻�Ϲ淶
	LOGINFAIL,			//��¼ʧ��
	LOGINSUCCESSFUL,	//��¼�ɹ�
	NETWORKERR,			//tcp�����޷�����
};

//const map<ERRNO, QString>ErrStr{
//	{ERRNO::NOUSERNAME,"�û�������Ϊ��"},
//
//};

const QString megStr[]{
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
	QMessageBox::information (NULL, "��ʾ", megStr[megCode], QMessageBox::Ok, QMessageBox::Ok);
}