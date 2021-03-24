#include <iostream>

using namespace std;

template<int n>
class Factorial {
    public:
        static const int f = Factorial<n-1>::f*n;
};

template <>
class Factorial<0> 
{
    public:
    static const int f =1;
};

int main() {
    cout << Factorial<5>::f << endl;
    return 0;
}