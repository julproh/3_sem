//технические детали классов
//перегрузка операторов
#include <iostream>
#include <cmath>

using namespace std;
class T {
    public:

    T operator + (T rhs);
};


T operator +(T lhs, T rhs) {
}

class Complex {
    private:
        double x_, y_;
    public:
        Complex();
        Complex(double, double);
        Complex(double);

        inline double get_x() const {return x_; };
        inline void set_x (double x) {x_ = x; };

        inline double get_y() const {return y_; };
        inline void set_y (double y) {y_ = y; };

        inline double abs() const {return sqrt(x_*x_+y_*y_);};

        friend Complex operator + (Complex, Complex);
        friend Complex operator * (Complex, Complex);
        friend std::ostream& operator << (std::ostream&, const Complex&);
        Complex operator += (Complex&);
        Complex operator *= (Complex&);
};

Complex:: Complex() : x_(0.0), y_(0.0) {};
Complex:: Complex(double x, double y): x_(x), y_(y) {};
Complex:: Complex(double x) : x_(x), y_(0.0){}; 

Complex operator + (Complex lhs, Complex rhs) {
    return Complex(lhs.x_+rhs.x_, lhs.y_+rhs.y_);
}

Complex operator * (Complex lhs, Complex rhs) {
    return Complex(lhs.x_*rhs.x_-lhs.y_*rhs.y_, lhs.y_*rhs.x_+lhs.x_*rhs.y_);
}

std::ostream& operator << (std::ostream& os, const Complex& rhs){
    os << rhs.x_ << "+" << rhs.y_ << "i";
    return os;
}

Complex Complex::operator += (Complex& rhs){
    Complex tmp = *this+rhs;
    *this = tmp;
    return tmp;
}

Complex Complex::operator *= (Complex& rhs){
    Complex tmp = *this*rhs;
    *this = tmp;
    return tmp;
}


int main () {
    Complex a;
    cout << "a= " <<a << endl;
    Complex b(32.7, 54.6);
    cout << "b = " << b << endl;
    cout << "a+b = " << a+b << endl;
    cout << "a*b = " << a*b << endl;
    cout << "b + 123.5 = " << b+123.5 << endl;
    return 0;
}