#include <iostream>
#include <complex>

using namespace std;

class SmartPointer {
    private:
        int *pointer_;
    public:
    SmartPointer();
    ~SmartPointer();
    SmartPointer(const SmartPointer&) = delete;
    int& operator*();
    SmartPointer& operator=(const SmartPointer&) = delete;
};

SmartPointer::SmartPointer() {
    pointer_ = new int;
};

SmartPointer::~SmartPointer() {
    delete [] pointer_;
};

int& SmartPointer:: operator*() {
    return *pointer_;
}

SmartPointer& SmartPointer::operator=(const SmartPointer& rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete pointer_;
    pointer_ = new int;
    
    *pointer_ = *(rhs.pointer_);
    //*(this->pointer_) = *(rhs.pointer_);
    return *this;
};

SmartPointer::SmartPointer(const SmartPointer& rhs) : pointer_(new int) {
        *pointer_ = *(rhs.pointer_);
    }

int main () {
    if(true) {
    SmartPointer sp;
    *sp = 1000;
    cout << "sp= " << *sp << endl;     
    }
    cout << "afterif"  << endl;
    return 0;
}