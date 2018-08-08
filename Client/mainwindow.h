#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ui_mainwindow.h"

#include "client.h"

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QGraphicsScene *scene;
    QList<QGraphicsEllipseItem *> lst_item;


public slots:
    void slotConnect();
    void slotLog(QString str);
    void slotRunSpam(int st);
    void slotSend();
    void slotTimerSpam();

    void slotUpdate(QByteArray barr);

signals:
    void signalSend(QString);

private:
    Client *client;
    QTimer *timer;

    int col;

};

#endif // MAINWINDOW_H
