#include <iostream>
#include <iomanip>
using namespace std;

struct Time {
    Time () {
        hours = 0;
        minutes = 0;
        seconds = 0;
        msec = 0;
    } 
    unsigned hours: 5;
    unsigned minutes: 6;
    unsigned seconds: 6;
    unsigned msec: 10;
};

void t(Time &time);

int main() {
    struct Time time;
    int i;

    cout << "Введите часы: " << endl;
    cin >> i;
    time.hours = i;
    cout << "Введите минуты: " << endl;
    cin >> i;
    time.minutes = i;
    cout << "Введите секнды: " << endl;
    cin >> i;
    time.seconds = i;
    cout << "Введите милисекунды: " << endl;
    cin >> i;
    time.msec = i;

    t(time);
    
    return 0;
}

void t(Time &time) {
    cout << fixed;
    cout << "Вы ввели: ";
    cout.width(2);
    cout.fill('0');
    cout << time.hours << ":";
    cout.width(2);
    cout.fill('0');
    cout << time.minutes << ":";
    cout.width(2);
    cout.fill('0');
    cout << time.seconds << ":";
    cout.width(4);
    cout.fill('0');
    cout << time.msec << endl;
}