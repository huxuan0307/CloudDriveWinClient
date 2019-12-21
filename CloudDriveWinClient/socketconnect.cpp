#include "socketConnect.h"

socketConnect::socketConnect (QObject* parent) : QObject (parent)
{
	socket = nullptr;
}

socketConnect::socketConnect (const QString& ip, const uint32_t& port, QObject* parent) : QObject (parent)
{
	Connect (ip, port);
}

socketConnect::~socketConnect ()
{
	if (socket)
		socket->close ();
}

bool socketConnect::Connect (const QString& ip, const uint32_t& port)
{
	socket = new QTcpSocket (this);
	socket->connectToHost (ip, port);

	if (socket->waitForConnected (3000)) {
		qDebug () << "Connected!";

		return true;
	}
	else {
		qDebug () << "Not connected!";

		return false;
	}
}

uint32_t socketConnect::Write (const void* content, const uint32_t& len)
{
	return socket->write ((char*)content, len);
}

uint32_t socketConnect::Read (void* content, const uint32_t& len)
{

	if (socket->waitForReadyRead (3000))
		return socket->read ((char*)content, len);
	else
		return 0;
}

