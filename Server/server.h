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


signals:
    void signalLog(QString);

};

#endif // SERVER_H
