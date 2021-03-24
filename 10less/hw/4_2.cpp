#include <iostream>
using namespace std;


class Cat
{   
    public:
    virtual ~ Cat() {};
    virtual void say_kitten(){};
    virtual void print_kitten (){};
};

class Kitten : public Cat
{
    public:
    Kitten(){};
    ~Kitten(){};
    void say_kitten() override {
        cout << "Mow-mow" << endl;
    }
    void print_kitten () override {
        cout << "It is kitten" << endl;
    }
};

int main() {
    Kitten Masha;
    Masha.say_kitten();
    Masha.print_kitten();
    return 0;
}



