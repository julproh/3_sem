#include <iostream>

template<unsigned N> 
struct factorial {  
    static const unsigned value = N * factorial<N - 1>::value; }; 

template<> 
struct factorial<0> {   
    static const unsigned value = 1; }; 

template<unsigned n, unsigned k> 
struct binomial {
    static const unsigned value = factorial<n>::value / factorial<k>::value / factorial< n-k >::value;
}; 

int main() {
    std:: cout << binomial<3, 2>::value << std::endl;
    return 0;
}