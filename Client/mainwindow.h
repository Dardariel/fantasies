#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ui_mainwindow.h"

#include "client.h"



class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotConnect();
    void slotLog(QString str);
    void slotRunSpam(int st);
    void slotSend();
    void slotTimerSpam();

signals:
    void signalSend(QString);

private:
    Client *client;
    QTimer *timer;

};

#endif // MAINWINDOW_H
