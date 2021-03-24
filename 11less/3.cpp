#include <iostream>
#include <type_traits>
#include <memory>
#include <vector>

template <typename T>
void f(T a);

//идеальная передача (прямая) perfect forwarding
//SFINAE - выключает какие-то функции 

class X {
    public:
    X() {
        std::cout<< "X()" << std::endl;
    }
};

// void g(int n) {};
// void f(int n) {//обертка над g() wrapper
//     //подготовка
//     g(n);
//     //завершение
// }

void g(const X &x) {
    std::cout << "g() for constant" << std::endl; 
};

void g( X &x) {
    std::cout << "g() for variables" << std::endl; 
};

void g( X &&x) {
    std::cout << "g() for object" << std::endl; 
};
// void g(X x) {
//     std::cout << "g() for x" << std::endl; 
// };
// void f(X x) {//обертка над g() wrapper
//     //подготовка
//     g(x);
//     //завершение
// }

template <typename ... T>
void f (T&& ... arg) { //универсальная ссылка
//правила светртки ссылок
   //T==& => & && => & 
   //T == && => && && =>  &&
    g(std::forward<T>(arg)...);
}

class Y {
    public: 
    Y(int n, double d, char c) {}
    Y() {}
};

int main () {

    auto p1 = std::make_unique<Y>();
    auto p1 = std::make_unique<Y>(34, 43.5, 'f');

    std::vector<X> v ;

    //f(100);
    X obj;
    g(obj);
    g(X());
    v.push_back(X());
    std::vector<Y> v1;
    v1.emplace_back(43, 54,3,'f');
    return 0;
}