#include <iostream>

template<unsigned n> 
struct fib {  
    static const unsigned value = fib<n - 1>::value + fib<n - 2>::value;
}; 


template<> 
struct fib<1> {   
    static const unsigned value = 0;
};

template<> 
struct fib<2> {   
    static const unsigned value = 1;
};

int main() {
    std:: cout << fib<5>::value << std::endl;
    return 0;
}