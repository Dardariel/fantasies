/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *te_log;
    QHBoxLayout *horizontalLayout;
    QLineEdit *le_text;
    QPushButton *pb_send;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cb_spam;
    QLabel *label_3;
    QSpinBox *sb_interval;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *le_host;
    QLabel *label_2;
    QLineEdit *le_port;
    QPushButton *pb_connect;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(524, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        te_log = new QTextEdit(centralWidget);
        te_log->setObjectName(QStringLiteral("te_log"));

        verticalLayout->addWidget(te_log);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        le_text = new QLineEdit(centralWidget);
        le_text->setObjectName(QStringLiteral("le_text"));

        horizontalLayout->addWidget(le_text);

        pb_send = new QPushButton(centralWidget);
        pb_send->setObjectName(QStringLiteral("pb_send"));

        horizontalLayout->addWidget(pb_send);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cb_spam = new QCheckBox(centralWidget);
        cb_spam->setObjectName(QStringLiteral("cb_spam"));

        horizontalLayout_2->addWidget(cb_spam);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        sb_interval = new QSpinBox(centralWidget);
        sb_interval->setObjectName(QStringLiteral("sb_interval"));
        sb_interval->setMinimum(1);
        sb_interval->setMaximum(10000);

        horizontalLayout_2->addWidget(sb_interval);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        le_host = new QLineEdit(centralWidget);
        le_host->setObjectName(QStringLiteral("le_host"));

        horizontalLayout_3->addWidget(le_host);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        le_port = new QLineEdit(centralWidget);
        le_port->setObjectName(QStringLiteral("le_port"));

        horizontalLayout_3->addWidget(le_port);

        pb_connect = new QPushButton(centralWidget);
        pb_connect->setObjectName(QStringLiteral("pb_connect"));

        horizontalLayout_3->addWidget(pb_connect);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pb_send->setText(QApplication::translate("MainWindow", "send", nullptr));
        cb_spam->setText(QApplication::translate("MainWindow", "Time spam", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Interval spam", nullptr));
        label->setText(QApplication::translate("MainWindow", "Host:", nullptr));
        le_host->setText(QApplication::translate("MainWindow", "localhost", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Port:", nullptr));
        le_port->setText(QApplication::translate("MainWindow", "2323", nullptr));
        pb_connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
