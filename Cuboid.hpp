#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Line.hpp"

class Cuboid {
public:
	Cuboid(); // CTOR

	Cuboid(Point P, int l, int w, int h); // CTOR PARAM

	Cuboid(const Cuboid& c); // CCTOR
	
	Cuboid& operator=(const Cuboid& c); // OPERATOR=

	~Cuboid(); // DTOR

	void setRGBT(int R, int G, int B, int T);

	vector<Point> p;
};

#endif
