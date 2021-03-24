#include <iostream>

constexpr double exp(double x) { //c++ 14
    double t = 1;
    double x_ = x;
    int n = 1;
    while(t != (t+x_/n)) {
        t += x_/n;
        n *= n+1; 
        x_ *= x; 
    }
    return t;
}

int main() {

    std::cout <<exp(0.3) << std::endl;
    return 0;
}