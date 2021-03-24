#ifndef FIRST_H
#define FIRST_H

#include <iostream>

using namespace std;


class furniture {
    public:
    furniture();
    furniture (string _name, string _color, int _height, int _length,int _width , int legs);
    ~furniture ();
    int get_height();
    void set_height(int _hieght);
    friend void check_legs(furniture &furnit, int islegs);
    private:
    string name;
    string color;
    int height;
    int length;
    int width;
    bool legs;
};

void check_legs(furniture &furnit, int islegs);

#endif // POINT_N