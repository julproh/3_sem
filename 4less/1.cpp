#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person(): name("Bob"), surname("Marley"), age(30) {}
    Person (string _name, string _surname, unsigned _age){
        name = _name;
        surname = "Marley";
        age = 30;
    }
    ~Person () {
        cout << "Destructing person " << name << endl;
    }
    string name;
    string surname;
    unsigned age;
};

int main () {
    Person bob("Q", "Y", 2);
    cout  << "name " << bob.name << endl;

    Person *t = new Person();
    delete t;
    return 0;
}