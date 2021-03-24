#include "Figures.h"
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

void Figures::about()
{
	cout << "FIGURES" << endl;
}
double Figures::area()
{
	return 0;
}

double Figures::perimeter()
{
	return 0;
}

Figures::Figures(vector <Point> _coordinates) {
    for(auto i: _coordinates) {
        coordinates.push_back(i);
    }
}

const double Figures::pi = 3.1415;

std::ostream& operator << (std::ostream& os, Figures& figure) {
	figure.about();
	return os;
}

Ellipse::Ellipse(vector <Point> _coordinates):Figures(_coordinates){};

void Ellipse::about()
{
	cout << "Ellipse." << endl;
	cout << "semi-major axis: " << coordinates[2].x - coordinates[0].x << endl;
	cout << "minor semiaxis: " << coordinates[1].y - coordinates[0].y << endl;
	cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << endl;
	cout << "Coordinates: " << endl;
	cout << "centre: (" << coordinates[0].x <<';' << coordinates[0].y <<')'<< endl;
    cout << "other: (" <<  coordinates[1].x <<';' << coordinates[1].y <<"), (" << coordinates[2].x <<';' << coordinates[2].y << ')';
    
}

double Ellipse::area()
{
	return pi*(coordinates[1].y - coordinates[0].y)*(coordinates[2].x - coordinates[0].x);
}

double Ellipse::perimeter()
{
	return pi*(coordinates[2].x - coordinates[0].x+coordinates[1].y - coordinates[0].y);
}


void Circle::about()
{
	cout << "Circle." << endl;
	cout << "Radius " << coordinates[2].x - coordinates[0].x << endl;

	cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << endl;
	cout << "Coordinates: ";
	cout << "Coordinates: " << endl;
	cout << "centre: (" << coordinates[0].x <<';' << coordinates[0].y <<')'<< endl;
    cout << "other: (" <<  coordinates[1].x <<';' << coordinates[1].y <<')' << endl;
	cout << endl;
}

Parallelogram::Parallelogram(vector <Point> _coordinates): Figures(_coordinates){};

double Parallelogram::h() {
    double c1, c2, denominator;
    c1 = (coordinates[0].x-coordinates[1].x)*coordinates[0].x +(coordinates[0].y-coordinates[1].y)*coordinates[0].y;
    c2 = (coordinates[0].x-coordinates[1].x)*coordinates[2].x +(coordinates[0].y-coordinates[1].y)*coordinates[2].y;
    denominator = sqrt(pow(coordinates[0].x-coordinates[1].x, 2)+pow(coordinates[0].y-coordinates[1].y, 2));
    return abs(c1-c2)/denominator;
};
double Parallelogram::l1() {
    return sqrt(pow(coordinates[0].x-coordinates[1].x, 2)+pow(coordinates[0].y-coordinates[1].y,2));
};
double Parallelogram::l2() {
    return sqrt(pow(coordinates[0].x-coordinates[3].x, 2)+pow(coordinates[0].y-coordinates[3].y,2));
};

double Parallelogram::area()
{   
	return l1()*h(); 
}

double Parallelogram::perimeter()
{   
	return 2*(l1()+l2());
}
double Parallelogram::angle()
{   Point v1 = {coordinates[0].x-coordinates[1].x, coordinates[0].y-coordinates[1].y};
    Point v2 = {coordinates[0].x-coordinates[3].x, coordinates[0].y-coordinates[3].y};
    double denominator = sqrt(pow(v1.x, 2)+pow(v1.y, 2))+ sqrt(pow(v2.x, 2)+pow(v2.y, 2));
	return  acos((v1.x*v2.x+v1.y*v2.y)/denominator) * (180 / pi);
}


void Parallelogram::about()
{   
	cout << "Parallelogram." << endl;
	cout << "Sides of a parallelogram: " << l1() << " and " << l2()<< endl;
	cout << "Parallelogram height: " << h() << endl;
	cout << "Parallelogram angles: " << angle() << " and " << 180 - angle() << endl;
	cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << endl;
	cout << "Cordinates: ";
	for (auto i: coordinates) {
        cout << '(' << i.x <<';' <<i.y << "), " ;
    }
	cout << endl;
}

Rhombus::Rhombus(vector <Point> _coordinates): Parallelogram(_coordinates){};

void Rhombus::about()
{
	cout << "Rhombus." << endl;
	cout << "Sides of a Rhombus: " << l1() << endl;
	cout << "Rhombus height: " << h() << endl;
	cout << "Rhombus angles: " << angle() << " and " << 180 - angle() << endl;
	cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << endl;
	cout << "Cordinates: ";
	for (auto i: coordinates) {
        cout << '(' << i.x <<';' <<i.y << "), " ;
    }
	cout << endl;
}

Rectangle::Rectangle(vector <Point>_coordinates):Parallelogram(_coordinates){};

void Rectangle::about()
{
	cout << "Rectangle." << endl;
	cout << "Sides of a Rectangle: " << l1() << " and " << l2() << endl;
	cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << endl;
	cout << "Cordinates: ";
	for (auto i: coordinates) {
        cout << '(' << i.x <<';' <<i.y << "), " ;
    }
	cout << endl;
}

Square::Square(vector <Point> _coordinates):Rectangle(_coordinates){};

void Square::about()
{
	cout << "Square." << endl;
	cout << "Sides of a Square: " << l1() << endl;
	cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << endl;
	cout << "Cordinates: ";
	for (auto i: coordinates) {
        cout << '(' << i.x <<';' <<i.y << "), " ;
    }
	cout << endl;
}

Triangle::Triangle(vector <Point> _coordinates):Figures(_coordinates){};

vector <double> Triangle::sides() {
    vector <double> v;
    for (int i = 0; i < 3; i++) {
        v.push_back(sqrt(pow(coordinates[i%3].x-coordinates[(i+1)%3].x,2)+pow(coordinates[i%3].y-coordinates[(i+1)%3].y,2)));
    }
    return v;
}
double Triangle::area(){
    
    return sqrt(perimeter()*(perimeter()-sides()[0])*(perimeter()-sides()[1])*(perimeter()-sides()[2])); 
}

double Triangle::perimeter()
{   
	return sides()[0]+sides()[1]+sides()[2];
}
vector <double> Triangle::angle()
{
    vector <double> v;
    Point v1 = {coordinates[0].x-coordinates[1].x, coordinates[0].y-coordinates[1].y};
    Point v2 = {coordinates[0].x-coordinates[2].x, coordinates[0].y-coordinates[2].y};
    Point v3 = {coordinates[1].x-coordinates[2].x, coordinates[1].y-coordinates[2].y};
    double denominator1 = sqrt(pow(v1.x, 2)+pow(v1.y, 2))+ sqrt(pow(v2.x, 2)+pow(v2.y, 2));
    double denominator2 = sqrt(pow(v1.x, 2)+pow(v1.y, 2))+ sqrt(pow(v3.x, 2)+pow(v3.y, 2));
    v.push_back(acos((v1.x*v2.x+v1.y*v2.y)/denominator1) * (180 / pi));
    v.push_back(acos((v1.x*v3.x+v1.y*v3.y)/denominator2) * (180 / pi));
	return  v;
}

void Triangle::about()
{   
	cout << "Triangle." << endl;
	cout << "Sides of a triangle: " << sides()[0] << " " << sides()[1] << " " << sides()[2] << endl;
	cout << "Triangle angles: " << angle()[0] << " " << angle()[1] << "and "<< 180 - angle()[0]-angle()[1] << endl;
	cout << "Area:" << area() << "  Perimeter: " << perimeter()
			  << endl;
	cout << "Cordinates: ";
	for (auto i: coordinates) {
        cout << '(' << i.x <<';' <<i.y << "), " ;
    }
	cout << endl;
}