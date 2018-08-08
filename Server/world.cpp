#include "world.h"

#include <QDebug>
//#include <QRandomGenerator>
#include <cstdlib>
#include <iostream>
#include <ctime>

World::World(unsigned int x, unsigned int y, QObject *parent): QObject(parent), LenghtX(x), LenghtY(y)
{
    LastId=0;
    TypeOperation=OperationsObject::DELETE;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(slotTimer()));


}
void World::startWorld()
{
    if(!ObjectsLists.count())
    {
        qDebug()<<"NOT Object";
        return;
    }
    timer->start(10);
}
void World::pauseWorld()
{
    timer->stop();
}
void World::slotTimer()
{
    std::srand(unsigned(std::time(0)));
    for(int i=0; i<ObjectsLists.count(); i++)
    {
        //switch((int)(QRandomGenerator::system()->generate()  %4))
        switch(std::rand()%4)
        {
        case 0: //-y
            if((ObjectsLists.at(i)->getCoordinatY()-ObjectsLists.at(i)->getRadius()-1)>0)
            {
                ObjectsLists.at(i)->setCoordinates(ObjectsLists.at(i)->getCoordinatX(), ObjectsLists.at(i)->getCoordinatY()-1);
            }
            break;
        case 1: //+x
            if((ObjectsLists.at(i)->getCoordinatX()+ObjectsLists.at(i)->getRadius()+1)<LenghtX)
            {
                ObjectsLists.at(i)->setCoordinates(ObjectsLists.at(i)->getCoordinatX()+1, ObjectsLists.at(i)->getCoordinatY());
            }
            break;
        case 2: //+y
            if((ObjectsLists.at(i)->getCoordinatY()+ObjectsLists.at(i)->getRadius()+1)<LenghtY)
            {
                ObjectsLists.at(i)->setCoordinates(ObjectsLists.at(i)->getCoordinatX(), ObjectsLists.at(i)->getCoordinatY()+1);
            }
            break;
        case 3: //-x
            if((ObjectsLists.at(i)->getCoordinatX()-ObjectsLists.at(i)->getRadius()-1)>0)
            {
                ObjectsLists.at(i)->setCoordinates(ObjectsLists.at(i)->getCoordinatX()-1, ObjectsLists.at(i)->getCoordinatY());
            }
            break;
        }
    }
    sendState();
    /*
    qDebug()<<"--- debug output ----";
    for(int i=0; i<ObjectsLists.count(); i++)
    {
       qDebug()<<ObjectsLists.at(i)->getId()
              << ObjectsLists.at(i)->getRadius()
              <<ObjectsLists.at(i)->getCoordinatX()
             <<ObjectsLists.at(i)->getCoordinatY();

    }
    qDebug()<<"--- end ----";
    */
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
    qDebug()<<"enterNewObjectCircle";
    switch(type)
    {
        case TypesObject::CIRCLE:
            Circle *new_circle = new Circle(LastId++, x, y, radius);
            //if(entrance(new_circle))
            //{
                qDebug()<<"add new object";
                ObjectsLists.append(new_circle);
                return true;
            //}
            //else
                //delete new_circle;
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

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

void World::sendState()
{
    QJsonDocument jsonResponse;
    QJsonObject *jsonObject, jsonMainObject;

    jsonObject=new QJsonObject;
    jsonObject->insert("x", QJsonValue((int)LenghtX));
    jsonObject->insert("y", QJsonValue((int)LenghtY));
    jsonMainObject.insert("world", QJsonValue(*jsonObject));

    for(int i=0; i<ObjectsLists.count(); i++)
    {
        //delete jsonObject;
        //jsonObject->insert("id", QJsonValue((int)ObjectsLists.at(i)->getId()));
        jsonObject->insert("x", QJsonValue((int)ObjectsLists.at(i)->getCoordinatX()));
        jsonObject->insert("y", QJsonValue((int)ObjectsLists.at(i)->getCoordinatY()));
        jsonObject->insert("radius", QJsonValue((int)ObjectsLists.at(i)->getRadius()));

        jsonMainObject.insert(QString("%1").arg(ObjectsLists.at(i)->getId()), QJsonValue(*jsonObject));
    }
    //delete jsonObject;
    jsonResponse.setObject(jsonMainObject);

    emit sendStateWorld(jsonResponse.toBinaryData());

    qDebug()<<jsonResponse;
}

