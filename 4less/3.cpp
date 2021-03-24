#include <iostream>

using namespace std;

union MyUnion {
    int n;
    char c;
};

enum Colors {Red, Green, Blue};

int Blue = 34;

int main () {
    MyUnion un;
    un.n = 2124;
    cout << un.n << endl;
    un.c = 1;
    cout << un.n << endl;


    return 0;
}