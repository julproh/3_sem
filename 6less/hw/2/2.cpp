#include <iostream>
#include <utility>
#include "second.h"

using namespace std;
using namespace rational;

int main () {
    Rational r1, r2;
    char c;
    cin >> r1 >> c >> r2;
    action(r1, r2, c);
    
    Rational my(1,2);
    Rational my_2(my);
    cout << "my_2: "<< my_2 << endl;
    Rational my_3(1,10);
    my = my_3;
    cout<< "my: " << my << endl;

    cout <<"my+2: " <<my + 2 << endl;

    Rational R(21,8);
    cout << "R = " << R << endl;
    cout << "Целая часть R: "<< integral(R) << endl;

    Rational T(1, 3);
    cout << "Десятичная запись T: " << in_ten(T) << endl;
    return 0;
}
