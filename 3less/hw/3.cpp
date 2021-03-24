#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    int n1, n2;
    cout << "Введите количество эементов массива для сортировки по возрастанию и по убыванию" << endl;
    cin >> n1 >> n2;

    vector<int> v1(n1), v2(n2);
    cout << "Введите элементы 1-го вектора: ";
    for (auto &i : v1) {
        cin >> i;
    }

    cout << endl << "Введите элементы 2-го вектора: ";
    for (auto &i : v2) {
        cin >> i;
    }

    sort (v1.begin(), v1.end(), [](int a, int b){return (a<=b);});
    
    cout << "Отсортированный по возрастанию массив: ";
    for (auto i: v1) {
        cout << i << " ";
    }
    cout << endl;

    sort (v2.begin(), v2.end(), [](int a, int b){return (a>=b);});
    
    cout << "Отсортированный по убыванию массив: ";
    for (auto i: v2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}