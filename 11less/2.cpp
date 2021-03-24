#include <iostream>

template <typename T>
struct remove_reference 
{
    using type = T;

};

template <typename T>
struct remove_reference <T&>
{
    using type = T;

};

template <typename T>
struct remove_reference <T&&>
{
    using type = T;

};

// int main () {
//     remove_reference<int&>::type n; // int n;
//     return 0;
// }

template <typename T>
struct add_lvalue_reference {
    using type = T&;
};

//метафункция
template <typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant<T, v>;
    constexpr operator T() {return v;}
};


using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;
using null_type = integral_constant<int, 0>;

template <typename X, typename Y>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};

template <typename T>
struct is_array : false_type {};

template <typename T, std::size_t N>
struct is_array<T[N]>: true_type {
    using type = T;
    static constexpr std::size_t size = N;
};

template<typename D, typename B>
class is_derived {
    class No {};
    class Yes {
        No no[2];
    };
    static Yes test(B*);
    static No test(...);
    auto value sizeof(test(staic_cast<D*>(0))) == sizeof(Yes);
};

template <bool Condition, typename True, typename False>
struct if_then_else {
    using type = True;
};

template <typename True, typename False> 
struct if_then_else<false, True, False>
{
    using type = False;
};
template <bool Condition, typename True, typename False>
using if_then_else_t = if_then_else<Cond, Trye, False>::type;

int main() {

    std::cout << std::boolalpha;
    int arr[100];
    int arr2[] = {1, 2, 3};
    int n;
    std::cout << is_array<int[100]>::value << std::endl;
    std::cout << is_array<int[]>::value << std::endl;
    std::cout << is_array<int>::value << std::endl;

    // null_type::value;//0
    // null_type::value_type n;
    // integral_constant <int, 1>::value;
    // integral_constant<int, 1>::value_type;
    // integral_constant<int, 1>::type;

    // int m = 423;
    // add_lvalue_reference<int>::type n = m;

    std:: cout << " is_same<int, int> " << is_same<int, int>::value << std:: endl;
    std:: cout << " is_same<int, int&> " << is_same<int, int>::value << std:: endl;
    std:: cout << " is_same<int, double> " << is_same<int, int>::value << std:: endl;
    return 0;
}