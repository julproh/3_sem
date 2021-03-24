#include <iostream>
// вычисление простых чисел на этапе компиляции


template <int p, int d>
struct check_is_prime {

    static constexpr bool value = (p % d != 0) && check_is_prime<p , d-1>::value;
}
;

template <int p>
struct check_is_prime<p, 2> {
    
    static constexpr bool value = (p%2 !=0);
};

template <int p>
struct is_prime {
    static constexpr bool value = check_is_prime <p, p/2> :: value;
};

template <>
struct is_prime<0> {
    static constexpr bool value = false;
};

template <>
struct is_prime<1> {
    static constexpr bool value = false;
};

template <>
struct is_prime<2> {
    static constexpr bool value = true;
};

template <>
struct is_prime<3> {
    static constexpr bool value = true;
};


constexpr bool Check_is_prime(int p, int d) {
    return (d !=2)?(p%d !=0)&& Check_is_prime(p, d-1):(p%2 !=0);
}

constexpr bool Is_prime(int p) { //c++ 11
    return (p < 4) ? !(p <2) : Check_is_prime(p, p/2);
}

constexpr bool Is_prime(int p) { //c++ 14
    for (int d =  2; d <= p/2; ++d){
        if (p%d ==0){
            return false;
        }
    };
    return p>1;
}

constexpr bool Is_prime(int p) { //c++ 14
    for (int d =  2; d <= p/2; ++d){
        if (p%d ==0){
            return false;
        }
    };
    return p>1;
}

int && f()
 {
     return 100;
 }
int main () {
    std:: cout << is_prime<0>::value << std::endl;
    std:: cout << is_prime<1>::value << std::endl;
    std:: cout << is_prime<2>::value << std::endl;
    std:: cout << is_prime<3>::value << std::endl;
    std:: cout << is_prime<654>::value << std::endl;
    std:: cout << is_prime<17>::value << std::endl;
    std:: cout << is_prime<555>::value << std::endl;
    std:: cout << is_prime<37>::value << std::endl;

    std:: cout << Is_prime(1) << std::endl;
    std:: cout << Is_prime(37) << std::endl;

    decltype (78+5) n = 54;
    auto m = f();
    decltype(f()) n = f();
    decltype(auto) p = f();
    return 0;
}