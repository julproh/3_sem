#include <iostream>
#include <string>

using namespace std;

int islegs = 1;

struct furniture {
    
    furniture(): name("furniture"), color("color"), height(0), length(0), width(0), legs(0) {
        cout << "Empty furniture is constucted" << endl;
        cout << "Parametrs: " << endl << "name: " << name << endl << "color: "<< color << endl 
        << "size: "<< height << "x" << length << "x" << width << endl;
    }
    furniture (string _name, string _color, int _height, int _length,int _width , int legs){
        name = _name;
        color = _color;
        height = _height;
        length = _length;
        width = _width;
        cout << "furniture is constructed" << endl;
        cout << "Parametrs: " << endl << "name: " << name << endl << "color: "<< color << endl 
        << "size: "<< height << "x" << length << "x" << width << endl;
    }
    ~furniture () {
        cout << "Destructing " << name << endl;
    }
    string name;
    string color;
    int height;
    int length;
    int width;
    bool legs;
};

void check_legs(furniture &furnit, int islegs) {
    if(islegs && furnit.legs) {
        cout << furnit.name << " has legs" << endl;
    } else {
        cout << furnit.name << " has not got legs" << endl; 
    }
}

int main () {
    furniture first;
    check_legs(first, islegs);
    cout << endl;
    furniture second ("table","black", 70, 70, 80, 1 );
    second.height = 60;
    check_legs(second, islegs);
    cout << endl;
    return 0;
}