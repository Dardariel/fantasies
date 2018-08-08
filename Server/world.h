#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include <QList>
#include <QTimer>
#include "objects.h"

enum OperationsObject
{
    DELETE,
    REMAP
};

class World : public QObject
{
    Q_OBJECT
public:
    World(unsigned int x, unsigned int y, QObject *parent = nullptr);

    bool enterNewObjectCircle(unsigned int x, unsigned int y, unsigned int radius, TypesObject type=TypesObject::CIRCLE);

    bool entrance(Circle *object);

    void sendState();

signals:
    void sendStateWorld(QByteArray);

public slots:
    void setAreaWorld(unsigned int x, unsigned int y);
    void setTypeOperation(OperationsObject type);

    void startWorld();
    void pauseWorld();

private slots:
    void slotTimer();

private:
    unsigned int LenghtX;
    unsigned int LenghtY;

    unsigned int LastId;

    OperationsObject TypeOperation;

    QList<Circle *> ObjectsLists;


    QTimer *timer;

    void entranceAllObjects();

};

#endif // WORLD_H
