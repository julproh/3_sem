#include <iostream>

using namespace std;

int&& value_func () {
    return 5;
}

int& lvalue_func () {
    static int i = 0;
    return i;
}

int prvalue_func () {
    return 5;
}

int main () {

    double d = 0.0;
    const int i = 0;

    int& lvalue = lvalue_func();
    return 0;
}