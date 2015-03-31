#include "Point.hpp"

Point::Point() { // CTOR
	x=0; y=0; z=0;
	R=0; G=0; B=0; T=0;
}

Point::Point(int x, int y) { //CTOR PARAM
	this->x=x;
	this->y=y;
	z=0;
	R=0; G=0; B=0; T=0;
}

Point::Point(int x, int y, int z) { //CTOR PARAM
	this->x=x;
	this->y=y;
	this->z=z;
	R=0; G=0; B=0; T=0;
}

Point::Point(const Point& p) { // CCTOR
	x=p.x;
	y=p.y;
	z=p.z;
	R=p.R;
	G=p.G;
	B=p.B;
	T=p.T;
}

Point& Point::operator=(const Point& p) { // OPERATOR=
	x=p.x;
	y=p.y;
	z=p.z;
	R=p.R;
	G=p.G;
	B=p.B;
	T=p.T;

	return *this;
}

Point::~Point() { // DTOR

}

void Point::setRGBT(int R, int G, int B, int T) {
	this->R=R;
	this->G=G;
	this->B=B;
	this->T=T;
}
