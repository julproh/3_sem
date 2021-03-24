#include <iostream>

using namespace std;

void countme () {
    static int counter = 0;
    cout << counter++ << endl;
}
int main () {
    for (int i= 0; i < 10; i++) {
        countme();
    }
    return 0;
}

int fib( int n) {
    return (n > 2) ? fib(n-1)+fib(n-2) :1
}