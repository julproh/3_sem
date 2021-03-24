#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T MAX(T a, T b) {
    return (a < b) ? b : a;
}

template <>
string MAX (string a, string b) {
    return (a.length() < b.length()) ? b : a;
}

class Cat {
    public:
    int age;
    Cat(int age_) : age(age_){};
    bool operator < (const Cat& rhs) {
        return age < rhs.age;
    };
    friend ostream& operator << (ostream&, const Cat&);
};

int main () {
    cout << MAX < int > (1234, -545) << endl;
    cout << MAX (123.0, -34.4) << endl;
    cout << MAX(Cat(4), Cat(7)) << endl;
    return 0;
}

ostream& operator << (ostream& os, const Cat& right) {
    os << right.age;
    return os;
};