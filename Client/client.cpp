#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
}

bool Client::connectServer(QString hostName, qint16 port)
{
    if(socket->isOpen())
    {
        return true;
    }
    socket->connectToHost(hostName, port);
    if(socket->isOpen())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Client::disconnectServer()
{
    if(socket->isOpen())
    {
        socket->disconnectFromHost();
        if(socket->isOpen())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return true;

}

void Client::sendData(QString str)
{
    if(socket->isWritable())
    {
        socket->write(str.toUtf8());
    }
}

void Client::disconnected()
{
    emit signalLog("disconnection from host");
}
void Client::readyRead()
{
    emit signalLog(QString(socket->readAll()));
}
