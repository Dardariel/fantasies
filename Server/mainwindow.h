#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTextEdit>
#include <QPushButton>

#include <server.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTextEdit *te_log;
    QPushButton *pb_start;
    QPushButton *pb_stop;


public slots:
    void slotStart();
    void slotStop();
    void slotAddText(QString str);

private:
    Server *srv;

};

#endif // MAINWINDOW_H
