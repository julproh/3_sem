#include "1.h"
#include <iostream>
using namespace std;

int main () {

    Petye::Point a;
    Petye::Point b(4.2, 3.09);
    a.set_y(0);
    a.set_x(3);
    cout << "x = " << a.get_x() << endl;
    a.print();
    cout << endl;
    Petye::Point c;
    c = a + b;
    c.print();
    cout << endl;
    cout << c << endl;
    return 0;
}