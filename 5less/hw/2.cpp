#include <iostream>
#include <math.h>

using namespace std;


class Energy {
    private:
        double energy_dg;
        static const int dg_erg;
        static const double dg_kgsm;
        static const double dg_kal;
        static const long long dg_ev;
    public:
    Energy () : energy_dg (0) {};
    Energy (double _energy):energy_dg(_energy){};
    ~Energy(){};
    void set_dg (double _energy) {
        energy_dg = _energy;
    } 
    void set_erg (double _energy) {
        energy_dg = _energy/dg_erg;
    } 
    void set_kgsm (double _energy) {
        energy_dg = _energy/dg_kgsm;
    }
    void set_kal (double _energy) {
        energy_dg = _energy/dg_kal;
    }
    void set_ev (double _energy) {
        energy_dg = _energy/dg_ev;
    }
    double get_dg (){
        return energy_dg;
    }
    double get_erg () {
        return energy_dg*dg_erg;
    }
    double get_kgsm () {
        return energy_dg*dg_kgsm;
    }
    double get_kal () {
        return energy_dg*dg_kal;
    }
    double get_ev () {
        return energy_dg*dg_ev;
    }
};

const int Energy::dg_erg = pow(10, 7);
const double Energy::dg_kgsm = 1/9.81;
const double Energy::dg_kal = 1/4.1868;
const long long Energy::dg_ev = pow(10, 19)/1.6;

void body_of_the_program(Energy &energy);

int main () {
    Energy energy;
    body_of_the_program(energy);
    return 0;
}

void body_of_the_program(Energy &energy){
    int n = 0 ;
    double value;
    do {
        cout << "Введите номер действия, которое хотите произвести:" << endl <<
        "0 - закончить " << endl << "1 - Ввести значение энергии в Дж" << endl << "2 - Ввести значение энергии в эрг" <<
        endl << "3 - Ввести значение энергии в кгсм" << endl << "4 - Ввести значение энергии в кал" << endl << "5 - Ввести значение энергии в эВ" 
        << endl << "6 - Вывести значение энергии в Дж" << endl << "7 - Вывести значение энергии в эрг" << endl
        << "8 - Вывести значение энергии в кгсм" << endl << "9 - Вывести значение энергии в кал" << endl << "10 - Ввести значение энергии в эВ" << endl; 
        cin >> n;
        cout << endl;
        switch (n) {
            case(1) : {cout << "Введите значение: "; cin >> value; energy.set_dg(value);}; break;
            case(2) : {cout << "Введите значение: "; cin >> value; energy.set_erg(value);}; break;
            case(3) : {cout << "Введите значение: "; cin >> value; energy.set_kgsm(value);}; break;
            case(4) : {cout << "Введите значение: "; cin >> value; energy.set_kal(value);}; break;
            case(5) : {cout << "Введите значение: "; cin >> value; energy.set_ev(value);}; break;
            case(6) : {cout << "Значение энергии: " << energy.get_dg() << " Дж" << endl;}; break;
            case(7) : {cout << "Значение энергии: " << energy.get_erg() << " эрг" << endl;}; break;
            case(8) : {cout << "Значение энергии: " << energy.get_kgsm() << " кгсм"<< endl;}; break;
            case(9) : {cout << "Значение энергии: " << energy.get_kal() << " кал" << endl;;}; break;
            case(10) : {cout << "Значение энергии: " << energy.get_ev() << " эВ"<< endl;}; break;
        }
        cout << endl;
    } 
    while (n);
}