#include "server.h"

#include <QThread>

Server::Server(QObject *parent) : QTcpServer(parent)
{

}
void Server::incomingConnection(qintptr socketDescriptor)
{
    signalLog(QString("new connection %1").arg(socketDescriptor));

    QThread *thread = new QThread;
    ServerThread *st_my = new ServerThread(socketDescriptor);
    st_my->moveToThread(thread);
    thread->start();
    connect(st_my, SIGNAL(signalLog(QString)), SIGNAL(signalLog(QString)));
    connect(st_my, SIGNAL(signalEnd()), thread, SLOT(terminate()));

    connect(st_my, SIGNAL(signalSend(QString)), SLOT(slotBroadcast(QString)));
    connect(this, SIGNAL(signalBroadcast(QString)), st_my, SLOT(slotSend(QString)));


}

void Server::slotBroadcast(QString str)
{
    emit signalBroadcast(str);
}
