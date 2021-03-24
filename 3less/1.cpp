#include <iostream>

using namespace std;
/*
Функции и лямбды
RT <name> (AT, AT, ..);*/
int fact (int n);

int main () {
    cout << fact(3) << endl;
    return 0;
}

int fact (int n) {
    /*if (n  < 0) {return 0;}
    if (n <= 1 ) {return 1;}
    else { return n*fact(n-1);}  */
    return (n > 1) ? n*fact(n-1) : 1;
}

// inline sum(int a, int b) {
//    return a+b;
//}
// sum (3+4);