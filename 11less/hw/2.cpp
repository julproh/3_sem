#include <iostream>

template <typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant<T, v>;
    constexpr operator T() {return v;}
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

//

template<typename T>
struct is_lvalue : false_type {};

template<typename T>
struct is_lvalue<T&> : true_type {};

//

template <typename T> 
struct is_rvalue : false_type {};

template <typename T> 
struct is_rvalue<T&&> : true_type {};

//

template <typename T>
struct is_reference : integral_constant<bool, is_lvalue<T>::value || is_rvalue<T>::value> {};

//

template <typename T>
struct is_constant : false_type {};

//

template <typename T>
struct is_constant<const T> : true_type {};

//

template <typename T>
struct is_function : false_type {};

template <typename T, typename ... Args>
struct is_function <T(Args...)> : integral_constant<bool, !is_constant<T>::value && !is_reference<T>::value>
{
    using return_type = is_function;
};

int f(int a) {
    return 0;
}

int main () {
    std::cout << is_function<int(int, char)>::value << std::endl;
    std::cout << is_function<int()>::value << std::endl;
    std::cout << is_function<int>::value << std::endl;
    return 0;
}