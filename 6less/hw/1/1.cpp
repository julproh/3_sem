#include <iostream>
#include <vector>
#include <utility>
#include "MyClass.h"
using namespace std;


int main () {
    int n = 4;
    int *array = new int[n];
    for (int i =0; i < n; i++) {
        array[i] = i+1;
    }
    Myclass my(array, 4, {11, 12, 13, 14}); 
    cout << "my array: ";
    my.print_arr();
    Myclass my_2(my);
    cout << "my_2 vector: ";
    my_2.print_v();
    Myclass my_3 = my_2;
    cout << "my_3 vector: ";
    my_3.print_v();
    return 0;
}