#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Point
{
    double x;
    double y;
};

class Figures
{
	protected:
	vector <Point> coordinates;
	static const double pi;
	public:
	Figures(vector<Point> _coordinates);
	virtual ~Figures(){};
	virtual void about();
	virtual double area();
	virtual double perimeter();

};

std::ostream& operator << (std::ostream& os, Figures& figure);

class Ellipse : public Figures
{
	public:
	Ellipse(vector <Point> _coordinates); // координаты центра, вехней и правой точек
	virtual ~Ellipse(){}
	virtual void about() override;
	virtual double  area() override;
	virtual double perimeter() override;


};

class Circle : public Ellipse
{
	public:
	Circle(vector <Point> _coordinates):
		Ellipse(_coordinates)
	{}
	virtual ~Circle(){}

	virtual void about() override;
};

class Parallelogram : public Figures
{
	public:
	Parallelogram(vector <Point> _coordinates);

	virtual ~Parallelogram(){};
	virtual double h();
	virtual double l1();
	virtual double l2();
	virtual void about();
	virtual double  area() override;
	virtual double perimeter() override;
	double angle();
};

class Rhombus : public Parallelogram
{
	public:
	Rhombus(vector <Point> _coordinates);
	virtual ~Rhombus(){};
	virtual void about() override;

};

class Rectangle: public Parallelogram
{
	public:
		Rectangle(vector <Point>_coordinates);
		virtual ~Rectangle(){};

		virtual void about() override;
};

class Square: public Rectangle
{
	public:
	Square(vector <Point> _coordinates);
	virtual ~Square(){};
	virtual void about() override;
};

class Triangle : public Figures {
	public:
	Triangle(vector <Point> _coordinates);
	virtual ~Triangle(){};
	virtual void about() override;
	virtual double  area() override;
	virtual double perimeter() override;
	vector <double> sides();
	vector <double> angle();
};

#endif //FIGURES