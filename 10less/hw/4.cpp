#include <iostream>
using namespace std;


template <typename D>
class Cat
{   
    public:
    void say_smth (){
        static_cast<D*>(this)-> say_kitten();
    };
    void print () {
        static_cast<D*>(this) -> print_kitten();
    };
};

class Kitten : public Cat<Kitten>
{
    public:
    Kitten(){};
    void say_kitten() {
        cout << "Mow-mow" << endl;
    }
    void print_kitten () {
        cout << "It is kitten" << endl;
    }
};

int main() {
    Kitten Masha;
    Masha.say_kitten();
    Masha.print();
    return 0;
}






















