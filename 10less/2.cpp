//Вариативные шаблоны

#include <iostream>
#include <string>
#include <memory>

using namespace std;

// template <typename T>
// void print (T arg) {
//     cout << arg;
// }

// template <typename T, typename ...Args>
// void print (T arg, Args ...args) 
// {
//     cout << arg << " ";
//     print(args...);
// }

template <typename ...Args>
void print (Args ...args) 
{
    (cout << ... << args) ;
}

// template <typename T>
// auto Sum(T arg) {
//     return arg;
// }

// template <typename T, typename ...Args>
// auto Sum (T arg, Args ...args) 
// {
//     return arg + Sum(args...);
// }

template <typename ...Args>
auto Sum (Args ...args) 
{
    return (args + ...); // можно (... + args)
}

template <typename ...Args>
auto Average (Args ... args) {
    return Sum(args...)/sizeof...(args);
}

int main () {

    print(324, "345", -657398239, -908);
    cout << endl;

    cout << Sum(23.7, 78, -0.984, 0) << endl;

    cout << Average(1.0, 2, 4) << endl;
    return 0;

}
