#include <exception>
#include <iostream>
#include <vector>

using namespace std;


double divizion (double x, double y) {
    if (y == 0) {
        throw runtime_error("Divizion by zero!");
    }
    return x/y;
}

void get_number(char n) {
    if (n<'0'||n>'9') {
        throw logic_error("Incorrect data");
    }
    cout << "Символ: " << n << endl;
}
int main () {

    try {
        cout << "Результат деления" << divizion(12, 3.0);
    }
    catch (const runtime_error &ex) {
        cerr << ex.what() << endl;
    }    

        try {
        cout << "Результат деления" << divizion(12, 0.0);
    }
    catch (const runtime_error &ex) {
        cerr << ex.what() << endl;
    }  

    vector <int> v(10);

    try {
        v[9] = 10;
        cout << v[9] << endl;
        v[100] = 8;
        cout << v[100] << endl;
    } catch (const out_of_range &ex) {
        cerr << ex.what() << endl;
    };

    try {
        get_number('*');
    } catch(const logic_error &ex) {
        cerr << ex.what() << endl;
    }

    try {
        get_number('2');
        get_number(2);
    } catch(const logic_error &ex) {
        cerr << ex.what() << endl;
    }

    try {
        int* gfg_array = new int[100000000000];
    } catch (std::bad_alloc & ba){
        std::cerr << "bad_alloc caught: " << ba.what() << endl;
    } 

    return 0;
}