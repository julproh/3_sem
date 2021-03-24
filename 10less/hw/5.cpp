
// Mixin-based
// MixIn - метод заключается в том, чтобы наследовать функционал класса от
// класса, заданного параметром шаблона. При этом переопределяются виртуальные функции
// класса и происходит вызов их предков. Таким образом дочерние классы расширяют функционал
// выбранного базового класса.

// CRTP
// В CRTP-классах базовый класс представляет собой шаблонный класс с параметром,
// функции которого вызываются в функциях базового класса. Дочерние классы наследуются
// от базового класса, параметризованного дочерним классом. Выходит так, что функционал
// дочернего класса расширяется в базовом классе. Как можно видеть, получается
// MixIn-наоборот.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// оценка сложности складыается из дз/ экз/зачет/дифф преп
template <typename D>
class base_marking
{   public:
    void print_information(){
        static_cast<D*>(this)-> information_subject();
    };
    void print_how_hard () {
        static_cast<D*>(this) -> getting_marks();
    };
    string name;
    int hours;
    int kind_of_mark; // exam = 5 // diff = 3 /not_diff_offset = 1
    string teacher_surname;
};

class English : public base_marking<English>
{   public:
    string name = "English";
    int hours = 140;
    int kind_of_mark; // exam = 5 // diff = 3 /not_diff_offset = 1
    string teacher_surname;
    English(int _mark, string _surname): kind_of_mark(_mark), teacher_surname(_surname){};
    void information_subject() {
        cout << name << endl << "working hours:" << hours << endl;
        switch (kind_of_mark)
        {
        case 5: cout << "exam" << endl;
            break;
        case 3: cout << "offset with a mark"<< endl;
            break;
        case 1: cout << "offset without a mark"<< endl;
            break;
        }
        cout<< "Teacher - " << teacher_surname << endl;
    }
    void getting_marks () {
        double hours_weiht = hours*0.1;
        double examination = kind_of_mark*2;
        double teacher_point;
        if (teacher_surname == "Ivanov") {
            teacher_point = 1;
        } else if (teacher_surname == "Loginova") {
            teacher_point = 2;
        } else if (teacher_surname == "Afanasev") {
            teacher_point = 3;
        } else {
            teacher_point = 2.5;
        }
        cout << "Тяжесть: " << fixed<< setprecision(1)<<(hours_weiht+examination+teacher_point)/30*10 << endl;
    }
};

class PE : public base_marking<English>
{   public:
    string name = "PE";
    int hours = 70;
    int kind_of_mark = 1; // exam = 5 // diff = 3 /not_diff_offset = 1
    string teacher_surname;
    PE(string _surname): teacher_surname(_surname){};
    void information_subject() {
        cout << name << endl << "working hours:" << hours << endl;
        switch (kind_of_mark)
        {
        case 5: cout << "exam" << endl;
            break;
        case 3: cout << "offset with a mark"<< endl;
            break;
        case 1: cout << "offset without a mark"<< endl;
            break;
        }
        cout<< "Teacher - " << teacher_surname << endl;
    }
    void getting_marks () {
        double hours_weiht = hours*0.1;
        double examination = kind_of_mark*2;
        double teacher_point;
        if (teacher_surname == "Ivanov") {
            teacher_point = 1;
        } else if (teacher_surname == "Kolotov") {
            teacher_point = 2;
        } else if (teacher_surname == "Afanasev") {
            teacher_point = 3;
        } else {
            teacher_point = 2.5;
        }
        cout << "Тяжесть: " << fixed<< setprecision(1)<<(hours_weiht+examination+teacher_point)/30*10 << endl;
    }
};

template <typename subject>
void all_about_subject (subject& s) {
    s.print_information();
    s.print_how_hard();
}


int main() {

    English s1(1, "Logiova");
    PE s2("Afanasov");
    all_about_subject(s1);
    cout << endl;
    all_about_subject(s2);

    return 0;
}