#include "geometry.h"
#include <math.h>

Geometry::Geometry(vector <Point> _coordinates) {
    for(auto i: _coordinates) {
        coordinates.push_back(i);
    }
}
void Geometry::set_coordinates(){
    cout << "Введите координаты фигуры (по завершении введите ""*""): ";
        while (/*get_char() !='*'*/ true) {
            static int n = 0;
            cin >> coordinates[n].x >> coordinates[n].y;
        }
};

void Triangle::set_coordinates () {
    cout << "Введите координаты треугольника: ";
    for (int i = 0; i < 3; i++){
        cin >> coordinates[i].x >> coordinates[i].y;
    }

};

void Rectangle::set_coordinates() {
    cout << "Введите кооринаты 3-х точек прямоугольника: ";
    for (int i = 0; i < 3; i++){
        cin >> coordinates[i].x >> coordinates[i].y;
    }
};

void Ellipse::set_coordinates() {
    cout << "Введите кооринаты эллипса (центр, верхнюю и правую точки): ";
    for (int i = 0; i < 3; i++){
        cin >> coordinates[i].x >> coordinates[i].y;
    }

}

void Circle::set_coordinates() {
    cout << "Введите кооринаты окружности (центр и точка на окружности): ";
    for (int i = 0; i < 2; i++){
        cin >> coordinates[i].x >> coordinates[i].y;
    }
}

double Geometry::square(){
    return 0;
}
double Triangle::square(){
    return sqrt(0);
};

double Circle::square() {
    return 3,14*(sqrt(coordinates[0].x-coordinates[1].x)+sqrt(coordinates[0].y-coordinates[1].y));
}

double Ellipse::square() {
    return 3,14*(sqrt(coordinates[0].x-coordinates[1].x)+sqrt(coordinates[0].y-coordinates[1].y)); //поправить вычисление площади
}

double Rectangle::square() {
    cout << "Площадь прямоугольника: ";
    double square;
    return (sqrt(coordinates[0].x-coordinates[1].x)+sqrt(coordinates[0].y-coordinates[1].y))
    *(sqrt(coordinates[0].x-coordinates[2].x)+sqrt(coordinates[0].y-coordinates[2].y));
}

