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
struct is_const: false_type {};

template<typename T>
struct is_const<const T> : true_type {};

//

int main () {
    std::cout << std::boolalpha;
    std::cout << is_const<int>::value << std::endl;
    std::cout << is_const< const int>::value << std::endl;
    return 0;
}