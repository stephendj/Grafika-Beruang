#ifndef POINT_HPP
#define POINT_HPP

#include "Header.hpp"

class Point {
public:
	Point(); // CTOR

	Point(int x, int y); // CTOR PARAM

	Point(int x, int y, int z); // CTOR PARAM

	Point(const Point& p); // CCTOR

	Point& operator=(const Point& p); // OPERATOR=

	~Point();

	void setRGBT(int R, int G, int B, int T);

	float x, y, z;
	int R, G, B, T;

private:

};

#endif
