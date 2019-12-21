#include "socketConnect.h"

SocketConnect::SocketConnect (QObject* parent) : QObject (parent)
{
	socket = nullptr;
}

SocketConnect::SocketConnect (const QString& ip, const uint32_t& port, QObject* parent) : QObject (parent)
{
	Connect (ip, port);
}

SocketConnect::~SocketConnect ()
{
	if (socket)
		socket->close ();
}

bool SocketConnect::Connect (const QString& ip, const uint32_t& port)
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

qint64 SocketConnect::Write (const void* content, const uint32_t& len)
{
	return socket->write ((char*)content, len);
}

qint64 SocketConnect::Read (void* content, const uint32_t& len)
{

	if (socket->waitForReadyRead (3000))
		return socket->read ((char*)content, len);
	else
		return 0;
}

