//SFINAE
//substitution failure is not a error

#include <iostream>
#include <type_traits>
// int f(int n);
// double f(int n);

template <typename T>
typename T::type f(T n) {
    std:: cout << "f(T n) \n";
    return 0;
}

template <typename ...>
int f(...) {
    std::cout << "int f(...) \n";
    return 0;
}

class X{};

template <typename T>
struct is_class
{   
    template <typename C>
    static int detect(int C::*p) {
        return 0;
    };
    template <typename ...>
    static char detect(...) {
        return '0';
    };

    constexpr static bool value = (sizeof(detect<T>(0))== sizeof(int));
};

class Warrior {
    public:
        void strike(Warrior& target) {};
};

template <typename T>
T  declval();

template <typename T>
struct has_strike_method {
    private:
        static int detect(...);

    template <typename U>
    static decltype(declval<U>().strike(declval<U&>())) detect(const U&);
public:
    static constexpr bool value = std::is_same<void, decltype(detect(declval<T>()))>::value;
};

template <bool B, typename T>
struct enable_if {};

template <typename T>
struct enable_if <true, T> {
    using type = T;
};

template <typename T>
typename enable_if<has_strike_method<T>::value, void>::type fight(T& w1, T& w2) {
    std::cout << "fight" << std:: endl;
    w1.strike(w2);
    w2.strike(w1);
}

template <typename T>
typename enable_if<!has_strike_method<T>::value, void>::type fight(T& w1, T& w2) {
    std::cout << "can't" << std:: endl;
}
int main () {
    std::cout << std::boolalpha;
    std::cout<< is_class<std::string>::value << std::endl;
    std::cout <<is_class<int> :: value << std::endl;

    std::cout << has_strike_method<int>::value << std::endl;
    std::cout << has_strike_method<Warrior>::value << std::endl;

    Warrior w1, w2;
    fight(w1, w2);
    int a = 34, b = 7;
    fight(a, b);

    return 0;
}