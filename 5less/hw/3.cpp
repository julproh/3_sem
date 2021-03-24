// параметр  legs (наличие ног) внесла в отдельный класс, и сделала функцию check_lengs  
//дружественной только для этого класса, потэтому она не может получать другие парамтры элемента Furniture

#include <iostream>
using namespace std;


class Limbs {
    public:
    Limbs () : legs(0){};
    Limbs (bool _legs) : legs(_legs){};
    ~Limbs () {};
    bool get_legs () {
        return legs;
    }
    void set_legs(bool _legs) {
        legs = _legs;
    };
    friend void check_legs(Limbs _legs);
    private:
    bool legs;
};

class Furniture {
    public:
    Limbs leg;
    Furniture(): name("Furniture"), color("color"), height(0), length(0), width(0) {
        leg.set_legs(0);
        cout << "Empty furniture is constucted" << endl;
        cout << "Parametrs: " << endl << "name: " << name << endl << "color: "<< color << endl 
        << "size: "<< height << "x" << length << "x" << width << endl;
    }
    Furniture (string _name, string _color, int _height, int _length,int _width){
        name = _name;
        color = _color;
        height = _height;
        length = _length;
        width = _width;
        cout << "Furniture is constructed" << endl;
        cout << "Parametrs: " << endl << "name: " << name << endl << "color: "<< color << endl 
        << "size: "<< height << "x" << length << "x" << width << endl;
    }
    ~Furniture () {
        cout << "Destructing " << name << endl;
    }
    int get_height () {
        return height;
    }
    void set_height (int _height) {
        height = _height;
    }
    string get_name () {
        return name;
    }
    private:
    string name;
    string color;
    int height;
    int length;
    int width;
};

void check_legs(Limbs _legs);



int main () {
    Furniture first;
    cout << first.get_name() << ' ';
    check_legs(first.leg);
    cout << endl;
    Furniture second ("table","black", 70, 70, 80);
    second.leg.set_legs(1);
    second.set_height(60);
    cout << second.get_name() << ' ';
    check_legs(second.leg);
    cout << endl;
    return 0;
}

void check_legs(Limbs _leg) {
    if(true && _leg.legs) {
        cout << " has legs" << endl;
    } else {
        cout << " has not got legs" << endl; 
    }
}