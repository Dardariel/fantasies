#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>

class ServerThread : public QObject
{
    Q_OBJECT
public:
    ServerThread(int socketDescriptor, QObject *parent = nullptr);

signals:
    void error(QTcpSocket::SocketError socketError);

private:
    int socketDescriptor;
    QTcpSocket *socket;

public slots:
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();


};

#endif // SERVERTHREAD_H
