#include <iostream>

using namespace std;


template <typename T>
class Container{
    private:
    public:
        T* array_;
        int size_;
        Container(){
            array_ = nullptr;
            size_ = 0;
        };
        Container(T* array,int size) {
            array_ = new T[size];
            *array_ = *array;
            size_ = size;
        }
        Container(const Container &my_array) {
            array_ = new T[size_];
            *array_ = *my_array.array_;
            size_ = my_array.size_;
        }; // конструктор копирования
        Container operator=(const Container& my_array) {
            if (&my_array ==this) {
                return *this;
            }
            
            if(array_!=nullptr){
                delete array_;
            }
            size_ = my_array.size_;
            *array_ = *my_array.array_;
            return *this;
        } // оператор копирования присваиванием
        Container(Container&& my_array) {
            for (int i = 0; i < size_; i++) {
                array_[i] = my_array.array_[i];
            }
            my_array.array_ = nullptr;
        } // Конструктор перемещения
        Container operator =(Container&& my_array){
            if(&my_array == this) 
            return *this;
            if(array_!=nullptr){
                delete array_;
            } 
            *array_ = *my_array.array_;
            my_array.array_ = nullptr;
            size_ = my_array.size_;
            return *this;
        } 
        ~Container() {
            delete array_;
        }
        
        void resize(int new_size)
        {
            Container new_array;
            new_array.size_ = new_size;
            new_array.array_ = new T[new_size];
            if (size_>new_size) {
                for(int i = 0; i < new_size; i++){
                    new_array.array_[i] = array_[i];
                }
            } else {
                for(int i = 0; i < size_; i++){
                    new_array.array_[i] = array_[i];
                }
                for (int i = size_; i < new_size; i++){
                    new_array.array_[i] = 0;
                }
            }
            
            delete array_;
            array_ = new T[new_size];
            size_ = new_size;
            for(int i = 0; i < new_size; i++){
                this->array_[i] = new_array.array_[i];
            }           
        }
        void swap(T *a, T *b) 
        {
            a = b;
            b = a;
        };
};

template <>
Container<char>::Container(char* array, int size) {
    int lenght = 0;
    while (array[lenght]!= '\0') {
        ++lenght;
    };
    ++lenght;
    array_ = new char[lenght];
    for (int i = 0; i < lenght; i++) {
        array_[i] = array[i];
    }
};

template <>
Container<char>::~Container() {
    delete [] array_;
}


int main() {

    int *array;
    Container<int> array_1(array, 7);
    for (int i = 0; i < array_1.size_;i++) {
        cin >> array_1.array_[i];
    }
    swap(array_1.array_[3], array_1.array_[2]);
    for (int i = 0; i< array_1.size_; i++) {
        cout << array_1.array_[i] << ' ';
    }
    cout << endl;

    array_1.resize(6);
    for (int i = 0; i< array_1.size_; i++) {
        cout << array_1.array_[i] << ' ';
    }
    cout << endl;

    array_1.resize(8);
    for (int i = 0; i< array_1.size_; i++) {
        cout << array_1.array_[i] << ' ';
    }
    cout << endl;
    cout << "Размер " << array_1.size_ << endl;

    double *array2;
    Container<double> array_2(array2, 4);
    for (int i = 0; i < array_2.size_;i++) {
        cin >> array_2.array_[i];
    }
    array_2.resize(5);
    for (int i = 0; i< array_2.size_; i++) {
        cout << array_2.array_[i] << ' ';
    }
    cout << endl;
    return 0;
}