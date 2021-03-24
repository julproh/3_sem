#include "MyClass.h"

        Myclass::Myclass(): arr(nullptr), n(0), v{} {};
        Myclass::Myclass(int*ptr, int _n, vector<int> _v ): arr(ptr), n(_n), v(_v) {};
        Myclass::Myclass(const Myclass &myclass) :n(myclass.n), v(myclass.v){
            arr = new int;
            *arr = *myclass.arr;
        }; // конструктор копирования
        Myclass& Myclass::operator=(const Myclass& myclass) {
            if (&myclass ==this) {
                return *this;
            }

            if(arr!=nullptr){
                delete arr;
            }

            arr = new int;
            *arr = *myclass.arr;
            return *this;
        } // оператор копирования присваиванием
        Myclass::Myclass(Myclass&& myclass) : arr(myclass.arr), n(myclass.n), v(myclass.v) {
            myclass.arr = nullptr;
        } // Конструктор перемещения

        Myclass & Myclass::operator =(Myclass&& myclass){
            if(&myclass == this) 
            return *this;
            if(arr!=nullptr){
                delete arr;
            }

            arr = myclass.arr;
            myclass.arr = nullptr;

            n = myclass.n;
            v = move(myclass.v);
            return *this;
        } 
        Myclass::~Myclass () {
            delete arr;
        }  
        void Myclass::print_arr() {
            for(int i=0; i< n; i++ ) {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        void Myclass::print_v() {
            for(auto i : v) {
                cout << i << ' ';
            }
            cout << endl;
        }


