#include <iostream>
#include <iomanip>

using namespace std;

void vvod_col_rows(int &rows, int &col);
double** create_array (const int &rows, const int&col);
void vvod_koef (double** arr,const int &rows, const int&col);
int no_results (double** arr,const int &rows, const int&col);
void function(double** arr, const int &rows, const int&col);
void print_array (double** arr, const int &rows, const int &col);
void vivod_x (double **arr, const int& rows, const int& col);
void delete_array (double** arr, int rows);

int main () {
    int col, rows;
    int rows_, col_;
   
    vvod_col_rows(rows, col);
    double **arr;

    col++;  

    arr = create_array(rows, col);
    vvod_koef(arr, rows, col);

    
    if (no_results (arr,rows, col)==0) {
        goto l;
    }

    function(arr, rows, col);
    print_array (arr, rows, col);

    vivod_x (arr,rows, col);
    delete_array(arr, rows);
    
    l:
    return 0;
}

void vvod_col_rows(int &rows, int &col) {
    cout << "Введите количество переменных и строк в системе уравнений" << endl;
    cin >> col >> rows;
}

double** create_array (const int &rows, const int&col) {
    double** arr_;
    arr_ = new double*[rows];
    for (int i = 0; i < col; ++i){
        arr_[i] = new double[rows];
    } 
    return arr_;
}

void vvod_koef (double** arr,const int &rows, const int&col) {
    for(int i=0; i < rows; i++)
    {
        cout << "Введите коэффициенты " << i+1 << " строки:" << endl;
        for(int j=0; j < col; j++)
        {
            cin >> arr[i] [j];
        }
    }
} 
int no_results(double** arr, const int &rows, const int &col){
    int counter = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col-1; j++){
            if (arr[i][j] != 0){
                counter = 1;
                break;
            }
        } 
        if ((arr[i][col-1]!=0) && (counter == 0)) {
            cout << "Решений нет.";
            return 0;
        }
    }
} 

void function (double** arr, const int &rows, const int&col) {
    int val;
    double ch;
    for (int i = 0; i < rows; i++) {
        for (int j  = i; j < rows; j++) {
            val = j;
            if (arr[j][i] != 0) {
                break;
            }  
        }
        if (arr[val][i]== 0) {
                val+= 1;
        } else {
            ch = arr[val][i];
            for (int t = i; t < col; t++) {
                arr[val][t] /= ch;
            }
            for (int t = i; t < rows; t++) {
                ch = arr[t][i];
                if (t != val) {
                    for (int s = i; s < col; s++) {
                        arr[t][s] -=arr[val][s]*ch; 
                    }
                }
            }
            if (i != val) {
                for (int t = i; t < col; t++) {
                    arr[i][t] += arr[val][t];
                    arr[val][t] -= arr[val][t];
                }
            }
        }
    }
    for (int i = 1; i < rows; i++) {
        if (arr[i][i] == 0) {
            break;
        } else {
            for (int j=0; j< i; j++) {
                ch = arr[j][i];
                for (int s =i; s < col; s++ ) {
                    arr[j][s]-= arr[i][s]*ch;
                }
            }
        }
    }
}
void print_array (double** arr, const int &rows, const int &col) {
    cout << "Итоговая матрица вида (Е|А): " << endl;
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < col; j ++) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "______________" << endl;
}
void vivod_x (double **arr, const int& rows, const int& col){
     if (arr[rows-1][col-2]==0) {
        cout << "Бесконечно много решений" << endl;
    } else {
        for (int i = 0; i < rows; i++) {
            cout << "x"<< i+1 << " = " << setw(3) << arr[i][col-1] << endl;
        }
    }
}

void delete_array (double** arr, int rows) {
    for (int i = 0; i < rows; ++i){
		delete [] arr[i];
	}
	delete [] arr;
}