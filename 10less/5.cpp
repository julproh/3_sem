//
#include <iostream>
using namespace std;

template <typename T>
class Counter {
    private:
    inline static size_t counter = 0;
    public:
    Counter () {
        counter++;
    }
    Counter(const Counter<T>&) {
        ++counter;
    }
    Counter(const Counter<T>&&) {
        ++counter;
    }
    ~Counter() {
        --counter;
    }
    static const size_t count(){
        return counter;
    };
};

template <typename T>
class A : public Counter<A<T>> {};

template <typename T>
class B : public Counter<B<T>> {};


int main() {

    Counter<int> c;
    return 0;
}