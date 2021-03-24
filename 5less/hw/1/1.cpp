#include <iostream>
#include "1.h"

using namespace std;


    furniture::furniture(): name("furniture"), color("color"), height(0), length(0), width(0), legs(0) {
        cout << "Empty furniture is constucted" << endl;
        cout << "Parametrs: " << endl << "name: " << name << endl << "color: "<< color << endl 
        << "size: "<< height << "x" << length << "x" << width << endl;
    }
    furniture::furniture (string _name, string _color, int _height, int _length,int _width , int legs) : 
    name(_name), color(_color), height(_height), length(_length), width(_width){
        cout << "furniture is constructed" << endl;
        cout << "Parametrs: " << endl << "name: " << name << endl << "color: "<< color << endl 
        << "size: "<< height << "x" << length << "x" << width << endl;
    }
    furniture::~furniture () {
        cout << "Destructing " << name << endl;
    }
    int furniture::get_height() {
        return height;
    }
    void furniture::set_height(int _height) {
        height = _height;
    }

void check_legs(furniture &furnit, int islegs) {
    if(islegs && furnit.legs) {
        cout << furnit.name << " has legs" << endl;
    } else {
        cout << furnit.name << " has not got legs" << endl; 
    }
}
