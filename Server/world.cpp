#include "world.h"


World::World(unsigned int x, unsigned int y, QObject *parent): QObject(parent), LenghtX(x), LenghtY(y)
{
    LastId=0;
    TypeOperation=OperationsObject::DELETE;
}
void World::setAreaWorld(uint x, uint y)
{
    LenghtX=x;
    LenghtY=y;
    entranceAllObjects();
}
void World::setTypeOperation(OperationsObject type)
{
    TypeOperation=type;
}
bool World::enterNewObjectCircle(unsigned int x, unsigned int y, unsigned int radius, TypesObject type)
{
    switch(type)
    {
        case TypesObject::CIRCLE:
            Circle *new_circle = new Circle(LastId++, x, y, radius);
            if(entrance(new_circle))
            {
                ObjectsLists.append(new_circle);
                return true;
            }
    }
    return false;
}
bool World::entrance(Circle *object)
{
    switch(object->getType())
    {
    case TypesObject::CIRCLE:
        {
            if((object->getCoordinatX()-object->getRadius()>=0)
                    &&(object->getCoordinatX()+object->getRadius()<=LenghtX)
                    &&(object->getCoordinatY()-object->getRadius()>=0)
                    &&(object->getCoordinatY()+object->getRadius()<=LenghtY))
            {
                return true;
            }
        }
    }
    return false;
}
void World::entranceAllObjects()
{
    for(unsigned int i=ObjectsLists.count()-1; i>=0; --i)
    {
        switch(ObjectsLists.at(i)->getType())
        {
        case TypesObject::CIRCLE:
            {
                if(!entrance(ObjectsLists.at(i)))
                {
                    switch(TypeOperation)
                    {
                    case OperationsObject::DELETE:
                        {
                            ObjectsLists.removeAt(i);
                        }
                    case OperationsObject::REMAP:
                        {
                            //ObjectsLists.at(i)->setCoordinatX(LenghtX-ObjectsLists.at(i)->getRadius());
                            //ObjectsLists.at(i)->setCoordinatY(LenghtY-ObjectsLists.at(i)->getRadius());
                        }
                    }

                }
            }
        }
    }

}

