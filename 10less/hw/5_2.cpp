#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class base_marking
{   public:
    virtual ~ base_marking(){};
    virtual void information_subject(){};
    virtual void getting_marks() {};
    private:
    string name;
    int hours;
    int kind_of_mark; // exam = 1 // diff = 2 /not_diff_offset = 3
    string teacher_surname;
};

class English : public base_marking
{   public:
    English(int _mark, string _surname) {
        kind_of_mark = _mark;
        teacher_surname = _surname;
    };
    ~English(){};
    void information_subject() override {
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
    void getting_marks () override {
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
    string name = "English";
    int hours = 140;
    int kind_of_mark; // exam = 5 // diff = 3 /not_diff_offset = 1
    string teacher_surname;
};

class PE : public base_marking
{   public:
    
    PE(string _surname){
        teacher_surname = _surname;
    };
    ~PE(){};
    void information_subject() override {
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
    void getting_marks () override {
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
        cout << "Тяжесть: " << fixed<< setprecision(1) << (hours_weiht+examination+teacher_point)/30*10 << endl;
    }
    private:
    string name = "PE";
    int hours = 70;
    int kind_of_mark = 1; // exam = 5 // diff = 3 /not_diff_offset = 1
    string teacher_surname;
};

template <typename subject>
void all_about_subject (subject& s) {
    s.information_subject();
    s.getting_marks();
}


int main() {

    English s1(1, "Logiova");
    PE s2("Afanasov");
    
    all_about_subject(s1);
    cout << endl;
    all_about_subject(s2);

    return 0;
}