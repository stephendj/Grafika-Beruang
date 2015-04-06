#include "Circle.hpp"

Circle::Circle() {
	P.x = 705;
	P.y = 84;
	r = 10;
}

Circle::Circle(Point _P, int _r) {
	P.x = _P.x;
	P.y = _P.y;
	r = _r;
}


Circle::Circle(const Circle& c) {
	P=c.P;
	r=c.r;
	
}

Circle& Circle::operator=(const Circle& c) {
	P=c.P;
	r=c.r;
	
	return *this;
}

void Circle::moveRight(float dx) {
	P.x = P.x + dx;
}

void Circle::moveLeft(float dx) {
	P.x = P.x - dx;
}

void Circle::moveUp(float dy) {
	P.y = P.y - dy;
}

void Circle::moveDown(float dy) {
	P.y = P.y + dy;
}