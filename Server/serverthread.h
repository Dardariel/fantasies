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

    void signalLog(QString);
    void signalEnd();

    void signalSend(QString);

private:
    int socketDescriptor;
    QTcpSocket *socket;

    void sendData(QByteArray barr);

public slots:
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

    void slotSend(QString str);
    void slotSend(QByteArray barr);


};

#endif // SERVERTHREAD_H
