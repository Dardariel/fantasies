#include "processing.h"

Processing::Processing(QObject *parent) : QObject(parent)
{
    world = new World(10, 10, this);
}
