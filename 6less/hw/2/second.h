#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <utility>

using namespace std;
namespace rational {
class Rational {
public:
    Rational() ;
    Rational(int numerator, int denominator);
    Rational(int numerator);
    Rational(const Rational &rational); // конструктор копирования
    Rational& operator=(const Rational& rational); // оператор копирования присваиванием
    Rational(Rational&& rational); // Конструктор перемещения
    ~Rational()= default;
    Rational modification (int numerator, int denominator);
    Rational & operator=(Rational&& rational); 
    int Numerator() const ;

    int Denominator() const;
    void set_numerator(int numerator);
    void set_denominator (int denominator);
    friend void action (const rational::Rational &r1, const rational::Rational &r2, const char & c);
    friend Rational operator += (rational::Rational &, rational::Rational &);
    friend Rational operator -= (rational::Rational &, rational::Rational &);
    friend Rational operator *= (rational::Rational &, rational::Rational &);
    friend Rational operator /= (rational::Rational &, rational::Rational &);
    friend Rational operator ++ (rational::Rational &);
    friend Rational operator -- (rational::Rational &);
    friend bool operator == (rational::Rational &, rational::Rational &);
    friend bool operator != (rational::Rational &, rational::Rational &);
    friend int integral(rational::Rational &);
    friend double in_ten (rational::Rational &);

    
private:
    int p;
    int q;
};
//}
rational::Rational operator / (rational::Rational& lhs, rational::Rational& rhs);
rational::Rational operator + (rational::Rational&, rational::Rational &);
rational::Rational operator + (rational::Rational & a, int n);
rational::Rational operator - (rational::Rational &, rational::Rational &);
rational::Rational operator * (rational::Rational &, rational::Rational &);
rational::Rational operator += (rational::Rational &, rational::Rational &);
rational::Rational operator -= (rational::Rational &, rational::Rational &);
rational::Rational operator *= (rational::Rational &, rational::Rational &);
rational::Rational operator /= (rational::Rational &, rational::Rational &);
rational::Rational operator ++ (rational::Rational &);
rational::Rational operator -- (rational::Rational &);
bool operator == (rational::Rational &, rational::Rational &);
bool operator != (rational::Rational &, rational::Rational &);
int integral(rational::Rational &);
double in_ten (rational::Rational &);

istream& operator >> (istream& stream, rational::Rational& r);
 
ostream& operator << (ostream& stream, const rational::Rational& r);

bool operator > (rational::Rational a, rational::Rational b);
bool operator >= (rational::Rational a, rational::Rational b);
bool operator < (rational::Rational a, rational::Rational b);
bool operator <= (rational::Rational a, rational::Rational b);

void action (rational::Rational &r1, rational::Rational &r2, const char & c);
}
#endif //MYCLASS