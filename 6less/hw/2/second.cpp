#include "second.h"
using namespace std;

    rational::Rational::Rational() :p(0), q(1) {}
    rational::Rational::Rational(int numerator, int denominator) {
    	if (denominator == 0) {
    		cout << "Некорректные данные" << endl;
    	}
        int a = numerator, b = denominator, c = 0;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        if (denominator / a < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        p = numerator / a;
        q = denominator / a;
        
    }
    rational::Rational::Rational(int numerator) : p(numerator), q(1){};
    rational::Rational::Rational(const Rational &rational) = default;
    rational::Rational& rational::Rational::operator=(const Rational& rational) = default;
    //  {
    //     if (&rational ==this) {
    //         return *this;
    //     }
    //     p = rational.p;
    //     q = rational.q;
    //     return *this;
    // } // оператор копирования присваиванием
    rational::Rational::Rational(Rational&& rational) = default;
    rational::Rational & rational::Rational::operator=(Rational&& rational)=default; //{
    //     if(&rational == this) {
    //         return *this;
    //     }

    //     p = move(rational.p);
    //     q = move(rational.q);
    //     return *this;
    //     } 
    rational::Rational modification (int numerator, int denominator) {
        int a = numerator, b = denominator, c = 0;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        if (denominator / a < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        rational::Rational R;
        R.set_numerator(numerator / a);
        R.set_denominator(denominator / a);
        return R;
    }
    int rational::Rational::Numerator() const {
        return p;
    }

    int rational::Rational::Denominator() const {
        return q;
    }
    void rational::Rational::set_numerator(int numerator){
        p = numerator;
    }
    void rational::Rational::set_denominator (int denominator){
        q = denominator;
    }

rational::Rational rational::operator / (rational::Rational& lhs, rational::Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return modification(lhs.Numerator() * rhs.Denominator(),lhs.Denominator() * rhs.Numerator());
}
rational::Rational rational::operator + (rational::Rational & a, rational::Rational & b) { 
    return modification(a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator(),a.Denominator() * b.Denominator());
}
rational::Rational rational::operator + (rational::Rational & a, int n) { 
    return modification(a.Numerator() + n * a.Denominator(),a.Denominator());
}
rational::Rational rational::operator - (rational::Rational & a, rational::Rational & b) {
    return modification(a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator(),a.Denominator() * b.Denominator());
}
rational::Rational rational::operator * (rational::Rational & a, rational::Rational & b) {
    return modification(a.Numerator()*b.Numerator(),a.Denominator() * b.Denominator());
}

rational::Rational operator += (rational::Rational & lhs, rational::Rational & rhs){
    return modification(lhs.Numerator() * rhs.Denominator() + lhs.Numerator() * rhs.Denominator(),lhs.Denominator() * rhs.Denominator());
};

rational::Rational operator -= (rational::Rational & lhs, rational::Rational & rhs){
    return modification(lhs.Numerator() * rhs.Denominator() - lhs.Numerator() * rhs.Denominator(),lhs.Denominator() * rhs.Denominator());
};

rational::Rational rational::operator *= (rational::Rational & a, rational::Rational & b) {
    return modification(a.Numerator()*b.Numerator(),a.Denominator() * b.Denominator());
};

rational::Rational rational::operator /= (rational::Rational& lhs, rational::Rational& rhs) {
    return modification(lhs.Numerator() * rhs.Denominator(),lhs.Denominator() * rhs.Numerator());
}

rational::Rational operator ++ (rational::Rational & R) {
    return modification(R.Numerator()+R.Denominator(), R.Denominator());
};

rational::Rational operator -- (rational::Rational & R) {
    return modification(R.Numerator() - R.Denominator(), R.Denominator());
};

bool rational::operator == (rational::Rational &lhs, rational::Rational &rhs)
{
    if ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator())) {
        return true;
    } else {
        return false;
    }

};

bool rational::operator != (rational::Rational &lhs, rational::Rational &rhs)
{
    if (lhs == rhs) {
        return false;
    } else {
        return true;
    }

};


istream& rational::operator >> (istream& stream, rational::Rational& r) {
    int p, q;
    if (stream >> p && stream.ignore(1) && stream >> q) {
        r = { p, q };
    }
    return stream;
}
 
ostream& rational::operator << (ostream& stream, const rational::Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool rational::operator > (rational::Rational a, rational::Rational b) {
    return (a.Numerator() * b.Denominator()) > (b.Numerator() * a.Denominator());
}

bool rational::operator >= (rational::Rational a, rational::Rational b) {
    return (a.Numerator() * b.Denominator()) >= (b.Numerator() * a.Denominator());
}

bool rational::operator <= (rational::Rational a, rational::Rational b) {
    return (a.Numerator() * b.Denominator()) <= (b.Numerator() * a.Denominator());
}

int rational::integral(rational::Rational &R) {
    int n = 0;
    while (R.Numerator()>=R.Denominator()) {
        n++;
        R.set_numerator(R.Numerator() - R.Denominator());
    }
    return n;
};

double rational::in_ten (rational::Rational & R) {
    return static_cast<double>(R.Numerator())/R.Denominator();
};

void rational::action (rational::Rational &r1, rational::Rational &r2, const char & c) {
    cout <<"result: ";
    if ( c == '+') {
        cout << r1+r2 << endl;
    } else if ( c == '-') {
        cout << r1-r2 << endl;
    } else if (c == '*') {
        cout << r1*r2 << endl;
    } else if (c =='/'){
        cout << r1/r2 << endl;
    } else {
        cout << "Wrong operation" << endl;
    }
};
