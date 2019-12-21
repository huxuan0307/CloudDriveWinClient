#pragma once

#include <qobject.h>
#include <QtNetwork/qtcpsocket.h>

class socketConnect : public QObject
{
	Q_OBJECT
public:
	socketConnect (QObject* parent = nullptr);
	socketConnect (const QString& ip, const uint32_t& port, QObject* parent = nullptr);
	~socketConnect ();

	bool Connect (const QString& ip, const uint32_t& port);
	uint32_t Write (const void* content, const uint32_t& len);
	uint32_t Read (void* content, const uint32_t& len);
private:
	QTcpSocket* socket;
};
