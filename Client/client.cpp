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



    /*

    чтение объектов


QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    qDebug()<<jsonResponse;

    QJsonObject jsonObject = jsonResponse.object(); // все один большой объект


    foreach (const QJsonValue & object, jsonObject) // перебираем все элементы базового объекта 
    {
        qDebug()<<"\nforeach"<<object.toObject(); // по хорошему бло бы неплохо определять что перед нами по функции type() и enum и выполнять соответствующие действия
        foreach (const QJsonValue & val, object.toObject()) // можно сделать рекурсией и выводить все. В конкретном случае читаем все элементы вложенного объекта
        {
            qDebug()<<"value"<<val<<val.type();
        }

    }


     * /

}
