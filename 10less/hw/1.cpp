#include <iostream>

using namespace std;

// template <typename T>
// auto memory (T arg) {
//     return sizeof(arg);
// }
// template <typename T, typename ...Args>
// auto memory (T arg , Args ...args) {
//     return sizeof(arg)+memory(args...);
// }

template <typename ...Args>
auto memory (Args ...args) 
{
    return (sizeof(args) + ...); // можно (... + args)
}

int main () {
    int a=0, b =9;
    char c;
    cout << memory(a, b, c ) << endl;
    return 0;
}