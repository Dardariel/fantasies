#ifndef OBJECTS_H
#define OBJECTS_H

enum TypesObject
{
    BASE,
    CIRCLE
};

class BaseObject
{

public:
    explicit BaseObject(unsigned int id=0, unsigned int x=0, unsigned int y=0);

private:
    unsigned int ID;
    unsigned int X, Y;
    TypesObject Type;

public:
    void setId(unsigned int id);
    unsigned int getId();
    TypesObject getType();
    void setCoordinates(unsigned int x, unsigned int y);
    unsigned int getCoordinatX();
    unsigned int getCoordinatY();
};
//###################################################
class Circle : public BaseObject
{
public:
    explicit Circle(unsigned int id=0, unsigned int x=0, unsigned int y=0, unsigned int radius=0);

private:
    unsigned int Radius;

public:
    void setRadius(unsigned int radius);
    unsigned int getRadius();

};



#endif // OBJECTS_H
