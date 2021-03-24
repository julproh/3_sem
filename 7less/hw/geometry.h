#ifndef GEOMERTY_H
#define GEOMETRY_H

#include <utility>
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    double x;
    double y;
};

class Triangle : virtual private Geometry
{
private:
    double perimeter();
    double square();
public:
    void set_coordinates();
    Triangle();
    ~Triangle();
};


class Rectangle : virtual private Geometry
{
private:
public:
    double square();
    double perimeter();
    void set_coordinates();
    Rectangle();
    ~Rectangle();
};

class Ellipse : virtual private Geometry
{
private:
    double square();
    double perimeter();
public:
    void set_coordinates();
    Ellipse();
    ~Ellipse();
};

class Square : virtual public Rectangle
{
private:
public:
    Square();
    ~Square();
};

class Circle : virtual private Geometry
{
private:
    double square();
    double perimeter();
public:
    void set_coordinates();
    Circle();
    ~Circle();
};

class Geometry
{
public:
    vector <Point> coordinates;
    virtual void set_coordinates();
    Geometry();
    Geometry(vector <Point> _coordinates);
    ~Geometry();
    double square();
    double perimeter();
    
};





#endif //GEOMETRY