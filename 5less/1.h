
#ifndef A_H
#define A_H
#include <iostream>

namespace Petye {
class Point
{
private:
    double x, y;
    friend std::ostream& operator << (std::ostream& os, const Point& n);
protected:

public:
    double get_x() {
    }
    void set_x(double _x) {
    }
     double get_y() {
    }
    void set_y(double _y) {
    }
    void print() {
    }
    Point(): x(0.0), y(0.0) {
    }
    Point (double _x, double _y): x(_x), y(_y){
    };
    Point(char* _x, char* _y) {
    }
    ~Point() {
    };
    Point operator + (const Point& b) {
}
};
}

#endif // POINT_N

