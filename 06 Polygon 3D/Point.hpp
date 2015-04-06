#ifndef POINT_HPP
#define POINT_HPP

#include "header.h"

class Point {
public:
	Point();

	Point(int x, int y);

	Point(int x, int y, int z);

	Point(const Point& p);

	Point& operator=(const Point& p);

	~Point();

	int x;
	int y;
	int z;

private:

};

#endif
