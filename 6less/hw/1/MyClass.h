#ifndef MYCLASS_H
#define MYCLASS_H

#include <utility>
#include <iostream>
#include <vector>

using namespace std;

class Myclass {
    public:
        Myclass();
        Myclass(int*ptr, int _n, vector<int> _v );
        Myclass(const Myclass &myclass); // конструктор копирования
        Myclass& operator=(const Myclass& myclass); // оператор копирования присваиванием
        Myclass (Myclass&& myclass); // Конструктор перемещения

        Myclass & operator=(Myclass&& myclass);
        ~Myclass ();  
        void print_arr();
        void print_v();
    private:
        int *arr;
        int n;
        vector<int> v;
};




#endif //MYCLASS