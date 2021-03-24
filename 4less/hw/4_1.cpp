#include <iostream>

using namespace std;

enum months {None, January ,February, March, April, May, June, July,August, September, October, November, December};

void print_month(months month);
months defined_month(int n);

int main () {
    months month;
    cout << "Введите номер месяца: ";
    
    int n;
    cin >> n;

    month = defined_month(n);
    print_month(month);

    return 0;
}

void print_month(months month) {
    switch (month) {
    case 0: {cout << "Вы ввели неверные данные" << endl;}; break;
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
    }
}

months defined_month(int n) {
    switch (n) {
    case 1: {return January;}; break;
    case 2: {return February;}; break;
    case 3: {return March;}; break;
    case 4: {return April;}; break;
    case 5: {return March;}; break;
    case 6: {return May;}; break;
    case 7: {return June;}; break;
    case 8: {return July;}; break;
    case 9: {return August;}; break;
    case 10: {return September;}; break;
    case 11: {return October;}; break;
    case 12: {return November;}; break;
    default: {return None;}; break;
    }
}