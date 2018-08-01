#include "mainwindow.h"

#include <QWidget>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central_widget = new QWidget;

    te_log = new QTextEdit;
    te_log->setReadOnly(true);

    pb_start = new QPushButton;
    pb_start->setText("Start");
    pb_stop = new QPushButton;
    pb_stop->setText("Stop");
    connect(pb_start, SIGNAL(clicked()), SLOT(slotStart()));
    connect(pb_stop, SIGNAL(clicked()), SLOT(slotStop()));


    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(pb_start);
    hbox->addStretch();
    hbox->addWidget(pb_stop);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(te_log);
    vbox->addLayout(hbox);

    central_widget->setLayout(vbox);
    setCentralWidget(central_widget);

//http://qt-doc.ru/realizacia-servera-s-pomoschu-klassa-qtcpserver.html


    // подготовка и настройка сервера
    srv = new Server(this);
    int nPort=2323;
    if (!srv->listen(QHostAddress::Any, nPort))
    {
        slotAddText("Server Error: Unable to start the server:" + srv->errorString());
        srv->close();
        return;
    }


    slotAddText(QString("port %1").arg(srv->serverPort()));

    connect(srv, SIGNAL(signalLog(QString)), SLOT(slotAddText(QString)));

}

MainWindow::~MainWindow()
{

}
void MainWindow::slotStart()
{
    slotAddText("Start");
}
void MainWindow::slotStop()
{
    slotAddText("Stop");
}
void MainWindow::slotAddText(QString str)
{
    te_log->append(str);
}
