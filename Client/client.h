#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

    bool connectServer(QString hostName, qint16 port);
    bool disconnectServer();



signals:
    void signalLog(QString);

    void signalNewData(QByteArray);

public slots:
    void sendData(QString str);

private slots:
    void disconnected();
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
