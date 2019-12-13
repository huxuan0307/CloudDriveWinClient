#include "CloudDriveWinClient.h"
#include <QtWidgets/QApplication>
#include "LogMessage.h"
int main(int argc, char *argv[])
{
	qInstallMessageHandler (MessageOutPut);
	QApplication a(argc, argv);
	CloudDriveWinClient w;
	w.show();
	return a.exec();
}
