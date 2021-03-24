#include <iostream>

using namespace std;

template <typename T>
class Repository{
    private:
        T value_;
    public:
        Repository(T value) {
            value_ = value;
        }
        ~Repository() {};
        void print() {
            cout << value_ <<  endl;
        }
        T get_value() const { return value_;};
};

template <typename T>
class Repository<T*> {
    private:
        T* value_;
    public:
        Repository(T* value) {
            value_ = new T;
            *value_ = *value;
        }
        ~Repository() {
            delete value_;
        }
        void print() const {
            cout << value_ << endl;
        }
        T* get_value() const { return value_;}
};

template <>
Repository<char*>::Repository(char* value) {
    int lenght = 0;
    while (value[lenght]!= '\0') {
        ++lenght;
    };
    ++lenght;
    value_ = new char[lenght];
    for (int i = 0; i < lenght; i++) {
        value_[i] = value[i];
    }
};

template <>
Repository<char*>::~Repository() {
    delete [] value_;
}

template <>
void Repository<char*>::print() const {
    cout << value_;
}


int main () {
    Repository<int> rep(100);
    rep.print();

    int *pi = new int;
    *pi = 100;
    Repository<int*> rep_(pi);
    delete pi;
    cout << *(rep_.get_value()) << endl;
    rep_.print();

    char* pi_= "queu3";
    Repository<char*> rep2(pi_);
    cout << *(rep2.get_value()) << endl;
    rep2.print();
    cout << endl;

    return 0;


}
