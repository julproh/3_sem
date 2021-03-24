#include <iostream>
#include <string>

template <typename T>
T  declval();

template <typename T>
struct has_compare_method {
    private:
        static char detect(...);

    template <typename U>
    static decltype(declval<U>() == declval<U>()) detect(const U&, const U&);
public:
    static constexpr bool value = std::is_same<bool, decltype(detect(declval<T>(), declval<T>()))>::value;
};

template <bool B, typename T>
struct enable_if {};

template <typename T>
struct enable_if <true, T> {
    using type = T;
};

template <typename T>
typename enable_if<has_compare_method<T>::value, bool>::type compare(const T& a, const T& b) {
    std::cout << "Can compare!" << std:: endl;
    std::cout << (a==b) << std:: endl;
   return (a==b);
}

template <typename T>
typename enable_if<!has_compare_method<T>::value, bool>::type compare(const T& a, const T& b) {
    std::cout << "Can't compare"<< std::endl << false << std:: endl;
    return false;
}

class X{};

int main() {
    std::cout << std::boolalpha;
    const int b = 8, a = 8;
    compare(a, b);

    std::string s = "asd", ss = "qwe";
    compare(s, ss);

    const X q, w;
    compare(q, w);
    return 0;
}