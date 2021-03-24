#include <iostream>
#include <vector>
#include <array>

using namespace std;

template <typename T, typename ...Args>
T* creation(Args ...args) { 
    T* arr= new T{args...};
    return arr;
}


int main() {
    auto a = creation<array<int, 4>>(1, 2 , 3, 5);
    for (int i = 0; i < 4; i++) {
    cout << (*a)[i] << " ";
    }
    cout << endl;
    return 0;
}