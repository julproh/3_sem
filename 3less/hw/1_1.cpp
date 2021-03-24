#include <iostream>

using namespace std;

void function(float i, double j) {
    cout << "float - double" << endl;
}

void function(double i, float j) {
    cout << "double - float" << endl;
}

int main () {
    function(10.0, 9.5);
    function(10, 2.0); 
    return 0;
}
