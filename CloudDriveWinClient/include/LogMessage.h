#include <QApplication>
#include <qtransform>
#include <QTranslator>
#include <QDateTime>
#include <QMutex>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

void MessageOutPut (QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    QFile logfile;
    QTextStream outstream;
    logfile.setFileName ("../Log/log.txt");
    logfile.open (QIODevice::WriteOnly | QIODevice::Append);
    outstream.setDevice (&logfile);
    outstream.setCodec (QTextCodec::codecForName ("gbk"));
    QString formatMsg = qFormatLogMessage (type, context, msg);
    outstream << formatMsg.toLocal8Bit ().constData () << endl;
}
