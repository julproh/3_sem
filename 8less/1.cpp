//обработка ошибок
//Предупреждение ошибок
/*
if - проверка
assert - "обещание" assert(n > 0 && "Not positive") (но если #define NDEBUG - ассерт пустая строка)
exit, terminate, abort  - по степениувеличения жетскости
Обработка ошибок
1 - обработка кода возврата 
int f();
2 - int f(, err&); в err  записывается получилось/нет
3 - errno - сюда записывается код последней возникшей ошибки
4 - механизм исключений ecxeptions

Базовый класс для ошибок
std::exeption 
what() - виртуальная
range_error - выход за границу
logic_error - ошибка в логике / пременная принимает не то, что нужно
bed_alloc - неправильно выделенная память
bad_cast - ошибка приведения
runtime_error - хз, что произошло
#include <stdexept>
*/

#include <iostream>
#include <string>

using namespace std;

class DivisionByZeroExeption
{
private:
    /* data */
public:
    string what() const {
        return "Division by zero";
    }

};

class OutOfRAngeExeption
{
private:
    size_t index_;
public:
    OutOfRAngeExeption(size_t index) : index_(index){};
    string what() const {
        return "Out or range"+to_string(index_);
    }
};

class IntArray {
    size_t sz_;
    int *arr;
public: 
    IntArray(size_t size): sz_(size), arr(new int[size]) {};
    ~IntArray() {delete [] arr;};

    int& operator [] (size_t index) {
        if (index > sz_ -1) {
            throw OutOfRAngeExeption(index);
        }
        return arr[index];
    }

};

void f() {
    double a = 0, b = 0;
    if (b == 0) 
            throw DivisionByZeroExeption();
        else a /=b;

}
int main() {
    // throw; - бросить ошибку
    try {
        f();
        } catch(int n) {
            cout << "Error #" << n ;
        }
        catch (const DivisionByZeroExeption& exeption) {
            cout << exeption.what();
        }
    
    IntArray arr(10);
    cout << "обращаемся к 9" << endl;
    arr[9] = 10;
    try {
    cout << "обращаемся к 100" << endl;
    arr[100] = 8;
    } catch (const OutOfRAngeExeption &ex) {
        cerr << ex.what() << endl;
    };
    cout << "Continue.. " <<endl;

    return 0;
}

