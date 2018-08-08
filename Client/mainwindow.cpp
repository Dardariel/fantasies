#include "mainwindow.h"

#include <QDateTime>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    connect(pb_connect, SIGNAL(clicked()), SLOT(slotConnect()));
    connect(pb_send, SIGNAL(clicked()), SLOT(slotSend()));
    connect(cb_spam, SIGNAL(stateChanged(int)), SLOT(slotRunSpam(int)));

    client = new Client(this);
    connect(client, SIGNAL(signalLog(QString)), SLOT(slotLog(QString)));
    connect(this, SIGNAL(signalSend(QString)), client, SLOT(sendData(QString)));
    connect(client, SIGNAL(signalNewData(QByteArray)), SLOT(slotUpdate(QByteArray)));

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), SLOT(slotTimerSpam()));


    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 10, 10);
    gv_show->setScene(scene);

    col=7;

}

MainWindow::~MainWindow()
{

}

void MainWindow::slotConnect()
{
    if(pb_connect->text()=="Connect")
    {
        if(client->connectServer(le_host->text(), le_port->text().toInt()))
        {
            pb_connect->setText("Disconnect");
        }
    }
    else
    {
        client->disconnectServer();
        pb_connect->setText("Connect");
    }

}
void MainWindow::slotLog(QString str)
{
    te_log->append(str+ " - " +QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzzzzz"));
}
void MainWindow::slotRunSpam(int st)
{
    if(st)
    {
        timer->start(sb_interval->value());
    }
    else
    {
        timer->stop();
    }
}
void MainWindow::slotSend()
{
    emit signalSend(le_text->text());
}
void MainWindow::slotTimerSpam()
{
    emit signalSend(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzzzzz"));
}
void MainWindow::slotUpdate(QByteArray barr)
{
    QGraphicsEllipseItem *item;

    QJsonDocument jsonResponse = QJsonDocument::fromBinaryData(barr);
    qDebug()<<jsonResponse;
    QJsonObject jsonObject = jsonResponse.object(); // все один большой объект

    // запрос world
    //jsonObject.value("world").toObject().value("x").toInt();

    QStringList keys = jsonObject.keys();
    QString str;

    for(int i=0; i<keys.count(); i++)
    {
        str=keys.at(i);
        if(str=="world")
        {
            scene->setSceneRect(0,
                                0,
                                jsonObject.value(str).toObject().value("x").toInt(),
                                jsonObject.value(str).toObject().value("y").toInt());
        }
        else
        {
            if(lst_item.count()>str.toInt())
            {
                item=lst_item.at(str.toInt());
            }
            else
            {
                item=new QGraphicsEllipseItem();
                item->setBrush(QBrush(QColor(Qt::red)));
                item->setRect(1,1,1,1);
                scene->addItem(item);
                lst_item.append(item);
            }
             item->setRect(jsonObject.value(str).toObject().value("x").toInt(),
                          jsonObject.value(str).toObject().value("y").toInt(),
                          jsonObject.value(str).toObject().value("radius").toInt(),
                          jsonObject.value(str).toObject().value("radius").toInt());
        }
    }
}
