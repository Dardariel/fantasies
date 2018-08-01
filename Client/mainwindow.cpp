#include "mainwindow.h"

#include <QDateTime>

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

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), SLOT(slotTimerSpam()));

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
        if(client->disconnectServer())
        {
            pb_connect->setText("Connect");
        }
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
