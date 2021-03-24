#include <iostream>
#include <vector>

using namespace std;

template <typename T, size_t sz_>
class Array  {
    T arr_[sz_];
    public:
    T& operator[] (size_t);
    const T& operator[] (size_t) const;
};

template <typename T, size_t sz_>
T& Array <T, sz_>:: operator[] (size_t index) {
    if (index > sz_ - 1)
        throw std::out_of_range("Out of range at index" + to_string(index));
    else return arr_ [index]; 
}

template <typename T, size_t sz_>
const T& Array <T, sz_>:: operator[] (size_t index) const {
    if (index > sz_ - 1)
        throw std::out_of_range("Out of range at index" + to_string(index));
    else return arr_ [index]; 
}

int main () {
    Array<int, 100> arr;
    return 0;
}