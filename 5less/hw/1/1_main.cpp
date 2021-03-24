#include <iostream>
#include "1.h"


using namespace std;

int islegs = 1;

int main () {

    furniture first;
    check_legs(first, islegs);
    cout << endl;
    furniture second ("table","black", 70, 70, 80, 1 );
    second.set_height(60);
    check_legs(second, islegs);
    cout << endl;
    return 0;
}