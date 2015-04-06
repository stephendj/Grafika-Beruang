#include "Point.hpp"

Point::Point() { // CTOR
	x=0;
	y=0;
	z=0;
}

Point::Point(int x, int y) { //CTOR PARAM
	this->x=x;
	this->y=y;
	z=0;
}

Point::Point(int x, int y, int z) { //CTOR PARAM
	this->x=x;
	this->y=y;
	this->z=z;
}

Point::Point(const Point& p) { // CCTOR
	x=p.x;
	y=p.y;
	z=p.z;
}

Point& Point::operator=(const Point& p) { // OPERATOR=
	x=p.x;
	y=p.y;
	z=p.z;

	return *this;
}

Point::~Point() { // DTOR

}
