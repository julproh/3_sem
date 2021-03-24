#include <iostream>
#include <functional>

using namespace std;


void print1(int a, int b, int c){
    cout<<a<<" "<<b<<" "<<c<<" ";
}

template <typename T, typename ...Args>
void foo (function<T(Args...)> f, Args...args) {
    f(args...);
}

int main () {
    function<void(int,int,int)> p = print1;
    foo(p, 1, 2, 3 );
    return 0;
}