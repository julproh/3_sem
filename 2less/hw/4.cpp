#include <iostream>
#include <vector>
#include <string>

using namespace std;
string new_sequence (const vector<vector<int>> &mlen, const string& sequ1, const string& sequ2);
void max_length (vector<vector<int>> &mlen, const string&sequ1, const string& sequ2);

int main () {
    string sequ1, sequ2;

    cout << "Введите 1-ую последовательность чисел (без пробелов): ";
    cin >> sequ1;
    cout << "Введите 2-ую последовательность чисел ";
    cin >> sequ2;

    vector<vector<int> > mlen;
    mlen.resize(sequ1.size() + 1);
    
    max_length (mlen, sequ1, sequ2);
    if (new_sequence(mlen, sequ1, sequ2)!="") {
        cout << "Общая последовательность наибольшей длины: " << new_sequence(mlen, sequ1, sequ2) << endl;
    } else {
        cout << "Нет общих символов :с" << endl;
    } 
    return 0;
}

void max_length (vector<vector<int>> &mlen, const string&sequ1, const string& sequ2) {
    for(int i = 0; i <= sequ1.size(); i++) {
        mlen[i].resize(sequ2.size() + 1);
        }
    for(int i = sequ1.size() - 1; i >= 0; i--){
        for(int j = sequ2.size() - 1; j >= 0; j--){
            if(sequ1[i] == sequ2[j]){
                mlen[i][j] = 1 + mlen[i+1][j+1];
                }
                else{
                    mlen[i][j] = max(mlen[i+1][j], mlen[i][j+1]);
                }
            }
        }
}

string new_sequence (const vector<vector<int>> &mlen, const string& sequ1, const string& sequ2) {
    string new_sequ;

    for(int i = 0, j = 0; mlen[i][j] != 0 && i < sequ1.size() && j < sequ2.size(); ){
        if(sequ1[i] == sequ2[j]){
            new_sequ.push_back(sequ1[i]);
            i++;
            j++;
        } else {
            if(mlen[i][j] == mlen[i+1][j]){
                i++;
            } else {
                j++;
            }
        }
    }
    return new_sequ;
}