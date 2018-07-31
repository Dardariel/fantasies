#include "serverthread.h"

#include <QtNetwork>

ServerThread::ServerThread(int socketDescriptor, QObject *parent)
    : QObject(parent), socketDescriptor(socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    //connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    //connect(socket, SIGNAL(bytesWritten(qint64)), SLOT(bytesWritten(qint64)));
    //connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));

}

void ServerThread::disconnected()
{

}
void ServerThread::bytesWritten(qint64 bytes)
{
    //qDebug() << bytes << " bytes written...";
}
void ServerThread::readyRead()
{
    //qDebug() << "reading...";

    // read the data from the socket
    //qDebug() << socket->readAll();
}
