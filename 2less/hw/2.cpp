#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    cout << "Введите количество элементо в массиве: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива:" << endl;
    for (auto &i : arr){
        cin >> i;
    } 
    for(int i=1;i<n;i++) {     
	    for(int j=i;j>0 && arr[j-1] > arr[j];j--){
		    swap(arr[j-1],arr[j]); 
            }
    }
    cout << "Массив отсортирован: ";
    for (auto i: arr){
        cout << i << " ";
    } 
    cout << endl;
    return 0;
}