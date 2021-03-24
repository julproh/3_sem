#include <iostream>
#include <vector>      

using namespace std;

 
static void merge(vector<int>& array_1, int l, int r, int m);
void merge_sort(vector<int>& array_1, int l, int r);
 
int main()
{
    int n;
    cout << "Введите число элементов массива: ";
    cin >> n;

    vector<int> array(n);
    cout << "Введите элементы массива: ";
    for (auto &i : array){
        cin >> i;
    }

    cout << "Неотсортированный массив: ";
    for (auto i : array){
        cout << i << "  ";
    }
    cout << endl;
 
    merge_sort(array, 0, n-1);
 
    cout << "Отсортированный массив: ";
    for (auto i : array)
    cout << i << "  "; 
    cout << endl;
    
    return 0;
}

void merge_sort(vector<int>& array_1, int l, int r)
{

    if(l >= r) return;
 
    int m = (l + r) / 2;
 
    merge_sort(array_1, l, m);
    merge_sort(array_1, m+1, r);
    merge(array_1, l, r, m);
}
 
static void merge(vector<int>& array_1, int l, int r, int m)
{
    if (l >= r || m < l || m > r) return;
    if (r == l + 1 && array_1[l] > array_1[r]) {
        swap(array_1[l], array_1[r]);
        return;
    }
 
    vector<int> tmp(&array_1[l], &array_1[l] + (r + 1));
 
    for (int i = l, j = 0, k = m - l + 1; i <= r; ++i) {
        if (j > m - l) {      
            array_1[i] = tmp[k++];
        } else if(k > r - l) {
            array_1[i] = tmp[j++];
        } else {
            array_1[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
        }
    }
}

 