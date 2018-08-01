#include "serverthread.h"

#include <QtNetwork>
#include <QDateTime>

ServerThread::ServerThread(int socketDescriptor, QObject *parent)
    : QObject(parent), socketDescriptor(socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)), SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));

}

void ServerThread::disconnected()
{
    emit signalLog(QString("disconnection %1").arg(socketDescriptor));

    emit signalEnd();
    /*
     *connect(st_my, SIGNAL(signalLog(QString)), SIGNAL(signalLog(QString)));
    connect(st_my, SIGNAL(signalEnd()), thread, SLOT(terminate()));
    */

}
void ServerThread::bytesWritten(qint64 bytes)
{
    //emit signalLog(QString("%1 bytes written...").arg(bytes));
}
void ServerThread::readyRead()
{
    emit signalLog(QString("reading... %1").arg(socketDescriptor));

    QString str=QString(socket->readAll());

    emit signalLog(str);

    if(str.compare("exit")==0)
    {
        sendData("bye!");

        socket->close();
        return;
    }

    //sendData(QString(str).toUtf8());
    emit signalSend(str);

}
void ServerThread::sendData(QString str)
{
    socket->write(QString(str + " - " + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzzzzz")).toUtf8());
}
void ServerThread::slotSend(QString str)
{
    sendData(str);
}
