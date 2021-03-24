#ifndef FORTH_H
#define FORTH_H

#include <iostream>

using namespace std;

int islegs;// ее определения нет в 4.cpp -> возникает ошибка "с неразрешенным внешним символом" (нужно инициализировать ее в срр)


class furniture {
    public:
    furniture(){}; //  {} - вызовут переопрееление конструктора -> 
    //возникнет ошибка "обнаружение многократно определенного внешнего символа"
    // для того, чтобы исправить проблему достаточно убрать {}
    furniture (string _name, string _color, int _height, int _length,int _width , int legs);
    ~furniture ();
    int get_height();
    void set_height(int _hieght);
    friend void check_legs(furniture &furnit, int islegs);
    private:
    string name;
    string color;
    int height;
    int length;
    int width;
    bool legs;
};

void check_legs(furniture &furnit, int islegs); // ее определения нет в 4.cpp -> возникает ошибка "с неразрешенным внешним символом"
// для решения проблемы нужно описать функцию в 4.cрр

#endif // 