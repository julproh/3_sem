#include <iostream>
using namespace std;

char myfunc (unsigned char ch, int i = 1) {
    cout << "unsigned char: ";
    return ch;
}

char myfunc(char ch, double i = 2){
    cout << "signed char: ";
    return ch;
}


int main()
{
    cout << myfunc('p', 2) << endl; 
    return 0;
}
