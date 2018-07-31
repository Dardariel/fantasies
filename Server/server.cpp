#include "server.h"

#include <QThread>

Server::Server(QObject *parent) : QTcpServer(parent)
{

}
void Server::incomingConnection(qintptr socketDescriptor)
{
    //QThread *thread = new QThread;
    //ServerThread *st_my = new ServerThread(socketDescriptor);

    //st_my->moveToThread(thread);
    //thread->start();



    /*
    QString fortune = fortunes.at(QRandomGenerator::global()->bounded(fortunes.size()));
    FortuneThread *thread = new FortuneThread(socketDescriptor, fortune, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
    */
}
