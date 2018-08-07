#include "processing.h"



Processing::Processing(QObject *parent) : QObject(parent)
{
    world = new World(30, 30, this);

    world->enterNewObjectCircle(3, 3, 2);
    world->enterNewObjectCircle(7, 7, 2);
    world->enterNewObjectCircle(3, 3, 2);
    world->enterNewObjectCircle(7, 7, 2);
    world->enterNewObjectCircle(3, 3, 2);
    world->enterNewObjectCircle(7, 7, 2);
    world->startWorld();

}

