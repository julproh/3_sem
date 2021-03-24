#include <iostream>
#include <vector>
#include "Figures.h"

using namespace std;


int main() {
	Ellipse e({{0.0,0.0},{0.0, 1.0},{1.0, 0.0}});
	Circle c({{0.0,0.0},{0.0, 1.0},{1.0, 0.0}});
	Parallelogram p({{-1.0,-1.0},{-1.0, 1.0},{1.0, 1.0}, {1.0, -1.0}});
	Rhombus rh({{-1.0,-1.0},{-1.0, 1.0},{1.0, 1.0}, {1.0, -1.0}});
	Rectangle r({{-1.0,-1.0},{-1.0, 1.0},{1.0, 1.0}, {1.0, -1.0}});
	Square sq({{-1.0,-1.0},{-1.0, 1.0},{1.0, 1.0}, {1.0, -1.0}});
    Triangle tr ({{0,1},{0, 0},{2, 0}});
	    Figures *figs[] = { &e, &c, &p, &rh, &r, &sq, &tr};
	    for (int i=0; i < 7; ++i)
	    {
	        figs[i]->about();
			cout << endl;
	    }

		cout << e;
	return 0;
}