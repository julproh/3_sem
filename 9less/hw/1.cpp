#include <iostream>

using namespace std;

template <typename T,size_t N>
void quickSort(T (&array) [N], int left = 0, int right = N-1 )
{
    int pivot; 
    int l_hold = left; 
    int r_hold = right;
    pivot = array[left];
    while (left < right) 
    {
    while ((array[right] >= pivot) && (left < right))
        right--; 
    if (left != right) {
        array[left] = array[right]; 
        left++; 
    }
    while ((array[left] <= pivot) && (left < right))
        left++; 
    if (left != right) 
    {
        array[right] = array[left]; 
        right--; 
    }
    }
    array[left] = pivot;
    int number = left;
    left = l_hold;
    right = r_hold;
    if (left < number)
    quickSort(array, left, number - 1);
    if (right > number)
    quickSort(array, number + 1, right);
}

template <typename T>
void quickSort(T *array, size_t size, int left , int right )
{
    T pivot; 
    int l_hold = left; 
    int r_hold = right;
    pivot = array[left];
    while (left < right) 
    {
    while ((array[right] >= pivot) && (left < right))
        right--; 
    if (left != right) {
        array[left] = array[right]; 
        left++; 
    }
    while ((array[left] <= pivot) && (left < right))
        left++; 
    if (left != right) 
    {
        array[right] = array[left]; 
        right--; 
    }
    }
    array[left] = pivot;
    int number = left;
    left = l_hold;
    right = r_hold;
    if (left < number)
    quickSort(array, size, left, number - 1);
    if (right > number)
    quickSort(array, size, number + 1, right);
}


int main() {
  
int array[] = {6, 2, 7, 1, 1,  10};
quickSort(array);
cout << "Отсортированный массив: ";
for (int i=0; i<6; i++) {
    cout << array[i] << " ";
} 
cout << endl;

cout << "Введите количество элементов и сами элементы: ";
int n;
cin >> n;
double *arr;
arr = new double[5];
for (int i=0; i<5; i++) {
    cin >> arr[i];
} 
cout << "Отсортированный массив: ";
quickSort(arr, 5, 0, 4);
for (int i=0; i<5; i++) {
    cout << (double)arr[i] << " ";
} 
cout << endl;

delete[] arr;

    return 0;
}