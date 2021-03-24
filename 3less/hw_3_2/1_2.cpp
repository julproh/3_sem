#include <iostream>

using namespace std;

void function(char c = 'c', int i = 1) {
    cout << "1-ая функция" << endl;
}

void function (int i = 1, char c = 'c') {
    cout << "2-ая функция" << endl;
}

int main () {
    function();
    return 0;
}