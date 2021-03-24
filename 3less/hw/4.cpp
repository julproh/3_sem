#include <iostream>
#include <functional>
#include <iomanip>
#include <vector>

using namespace std;
double calculate (double a, double b,function<double(double, double)> f){
    f(a, b);
}

int main () {
    cout << "Введите два числа: ";
    double a1,b1;
    cin >> a1 >> b1;

    vector <function<double(double, double)>>  func = {[](double a, double b){cout << "Сложение: "; return a+b;},
    [](double a, double b){cout << endl << "Вычитание: "; return a-b;}, 
    [](double a, double b){cout << endl<< "Умножение: "; return a*b;}, [](double a, double b){cout << endl << "Деление: "; return (a/b);} };
    
    for (auto i: func) {
        double res = calculate(a1, b1, i);
        cout.precision(5);
        cout << fixed << res << " ";
    }
    cout << endl;
    
    return 0;
}