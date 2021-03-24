#include <iostream>

using namespace std;

enum months {January = 1 ,February, March, April, May, June, July,August, September, October, November, December};

void print_month(months month);

int main () {
    months month;
    cout << "Введите номер месяца: ";
    
    int n;
    cin >> n;
    month = static_cast<months>(n);

    print_month(month);

    return 0;
}

void print_month(months month) {
    switch (month) {
    case 1: {cout << "В январе 31 день" << endl;}; break;
    case 2: {cout << "В феврале 28 или 29 дней" << endl;}; break;
    case 3: {cout << "В марте 31 день" << endl;}; break;
    case 4: {cout << "В апреле 30 дней" << endl;}; break;
    case 5: {cout << "В мае 31 день" << endl;}; break;
    case 6: {cout << "В июне 30 дней" << endl;}; break;
    case 7: {cout << "В июле 31 день" << endl;}; break;
    case 8: {cout << "В августе 31 день" << endl;}; break;
    case 9: {cout << "В сентябре 30 дней" << endl;}; break;
    case 10: {cout << "В октябре 31 день" << endl;}; break;
    case 11: {cout << "В ноябре 30 дней" << endl;}; break;
    case 12: {cout << "В январе 31 день" << endl;}; break;
    default: {cout << "Такого месяца нет" << endl;}; break;
    }
}