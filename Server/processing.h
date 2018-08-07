#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>

#include "world.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(QObject *parent = nullptr);

signals:

public slots:




private:
    World *world;

};

#endif // PROCESSING_H
