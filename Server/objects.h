#ifndef OBJECTS_H
#define OBJECTS_H

#include <QObject>

class Objects : public QObject
{
    Q_OBJECT
public:
    explicit Objects(QObject *parent = nullptr);

signals:

public slots:
};

#endif // OBJECTS_H