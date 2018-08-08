#ifndef SERVER_H
#define SERVER_H

#include <QObject>

#include <QTcpServer>

#include "serverthread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);


protected:
    void incomingConnection (qintptr socketDescriptor) override;


public slots:
    void slotBroadcast(QString str);
    void slotBroadcast(QByteArray barr);

signals:
    void signalLog(QString);

    void signalBroadcast(QString);
    void signalBroadcast(QByteArray);

};

#endif // SERVER_H
