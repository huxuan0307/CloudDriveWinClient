#pragma once

#include <qobject.h>
#include <QtNetwork/qtcpsocket.h>

class SocketConnect : public QObject
{
	Q_OBJECT
public:
	SocketConnect (QObject* parent = nullptr);
	SocketConnect (const QString& ip, const uint32_t& port, QObject* parent = nullptr);
	~SocketConnect ();

	bool Connect (const QString& ip, const uint32_t& port);
	qint64 Write (const void* content, const uint32_t& len);
	qint64 Read (void* content, const uint32_t& len);
private:
	QTcpSocket* socket;
};
