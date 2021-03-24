#include <iostream>
#include <vector>

using namespace std;

int searching (const vector<int> &arr, const int &n);
void print_answer (const vector<int> &arr, const int &n, const int& l);

int main() {
    cout << "Введите количество элементов массива: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Введите элементы отсортированного массива: ";
    for (auto &i : arr) {
        cin >> i;
    } 

    cout << "Введите значение элемента, который надо найти: ";
    cin >> n;

    int l = searching(arr, n);
    print_answer(arr, n, l);

    return 0;
}

int searching (const vector<int> &arr, const int &n){
    int l = 0, r =arr.size()-1;

    while (l < r) {
        int num = (l+r)/2;

        if (arr[num] < n ) {
            l = num + 1;
        } else if (arr[num] > n) {
            r = num - 1;
        } else {
            l = num;
            break;
        }
    }
    return l;
}

void print_answer (const vector<int> &arr, const int &n, const int& l) {
     if (arr[l] == n) {
        cout << "Данный элемент найден на " << l+1 << "-ом месте" << endl;  
    } else {
        cout << "Данный элемент не найден" << endl;
    }
}