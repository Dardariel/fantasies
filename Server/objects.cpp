#include "objects.h"

BaseObject::BaseObject(unsigned int id, unsigned int x, unsigned int y) : ID(id), X(x), Y(y)
{

}

void BaseObject::setId(unsigned int id)
{
    ID=id;
}
unsigned int BaseObject::getId()
{
    return ID;
}
void BaseObject::setCoordinates(unsigned int x, unsigned int y)
{
    X=x;
    Y=y;
}
void BaseObject::setNewCoordinates(unsigned int x, unsigned int y)
{
    new_X=x;
    new_Y=y;
}
unsigned int BaseObject::getCoordinatX()
{
    return X;
}
unsigned int BaseObject::getCoordinatY()
{
    return Y;
}
unsigned int BaseObject::getNewCoordinatX()
{
    return new_X;
}
unsigned int BaseObject::getNewCoordinatY()
{
    return new_Y;
}
TypesObject BaseObject::getType()
{
    return Type;
}
//###################################################
Circle::Circle(unsigned int id, unsigned int x, unsigned int y, unsigned int radius)
    : BaseObject(id, x, y) , Radius(radius)
{

}
void Circle::setRadius(unsigned int radius)
{
    Radius=radius;
}
unsigned int Circle::getRadius()
{
    return Radius;
}
