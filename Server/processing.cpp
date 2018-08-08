#include "processing.h"



Processing::Processing(QObject *parent) : QObject(parent)
{
    world = new World(400, 400, this);
    connect(world, SIGNAL(sendStateWorld(QByteArray)), SIGNAL(sendChange(QByteArray)));

    world->enterNewObjectCircle(110, 110, 10);
    world->enterNewObjectCircle(110, 110, 12);
    world->enterNewObjectCircle(110, 110, 14);
    world->enterNewObjectCircle(110, 110, 16);
    world->enterNewObjectCircle(110, 110, 18);
    world->enterNewObjectCircle(110, 110, 20);
    world->enterNewObjectCircle(110, 110, 10);
    world->enterNewObjectCircle(110, 110, 12);
    world->enterNewObjectCircle(110, 110, 14);
    world->enterNewObjectCircle(110, 110, 16);
    world->enterNewObjectCircle(110, 110, 18);
    world->enterNewObjectCircle(110, 110, 20);
    world->enterNewObjectCircle(110, 110, 10);
    world->enterNewObjectCircle(110, 110, 12);
    world->enterNewObjectCircle(110, 110, 14);
    world->enterNewObjectCircle(110, 110, 16);
    world->enterNewObjectCircle(110, 110, 18);
    world->enterNewObjectCircle(110, 110, 20);
    world->enterNewObjectCircle(110, 110, 10);
    world->enterNewObjectCircle(110, 110, 12);
    world->enterNewObjectCircle(110, 110, 14);
    world->enterNewObjectCircle(110, 110, 16);
    world->enterNewObjectCircle(110, 110, 18);
    world->enterNewObjectCircle(110, 110, 20);
    world->enterNewObjectCircle(110, 110, 10);
    world->enterNewObjectCircle(110, 110, 12);
    world->enterNewObjectCircle(110, 110, 14);
    world->enterNewObjectCircle(110, 110, 16);
    world->enterNewObjectCircle(110, 110, 18);
    world->enterNewObjectCircle(110, 110, 20);
    world->enterNewObjectCircle(110, 110, 10);
    world->enterNewObjectCircle(110, 110, 12);
    world->enterNewObjectCircle(110, 110, 14);
    world->enterNewObjectCircle(110, 110, 16);
    world->enterNewObjectCircle(110, 110, 18);
    world->enterNewObjectCircle(110, 110, 20);
    world->startWorld();

}

