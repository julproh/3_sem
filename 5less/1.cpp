#include <iostream>
#include <string>

using namespace std;


    double Petya::Point::get_x() {
        return x;
    }
    void set_x(double _x) {
        x = _x;
    }
     double get_y() {
        return y;
    }
    void set_y(double _y) {
        y = _y;
    }
    void print() {
        cout << x << ' ' << y << endl;
    }
    Point(): x(0.0), y(0.0) {
        cout << "constructing point by defolt " << endl;
    }
    Point (double _x, double _y): x(_x), y(_y){
        cout << "constructing point" << endl;
    };
    Point(char* _x, char* _y) {
        x = atof(_x);
        y = atof(_y);
    }
    ~Point() {
        cout << "destructing" << endl;
    };
    Point operator + (const Point& b) {
    return Point (x+b.x, y+b.y);
}
};

ostream& operator << (ostream& os, const Petye::Point& n) {
    os << '(' << n.x << ";" << n.y << ')';
    return os;
}
