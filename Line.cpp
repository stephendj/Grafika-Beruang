#include "Line.hpp"

Line::Line() { // CTOR
	src = Point();
	dest = Point();
	r = 255;
	g = 255;
	b = 255;
	t = 0;
}

Line::Line(Point src, Point dest) { // CTORPARAM
	this->src = src;
	this->dest = dest;
	r = 255;
	g = 255;
	b = 255;
	t = 0;
}

Line::Line(const Line& l) { // CCTOR
	src = l.src;
	dest = l.dest;
	r = l.r;
	g = l.g;
	b = l.b;
	t = l.t;
}

Line& Line::operator=(const Line& l) { // OPERATOR=
	src = l.src;
	dest = l.dest;
	r = l.r;
	g = l.g;
	b = l.b;
	t = l.t;

	return *this;
}

Line::~Line() { // DTOR

}

void Line::moveLeft(float dx) {
	src.x -= dx;
	dest.x -= dx;
}

void Line::moveRight(float dx) {
	src.x += dx;
	dest.x += dx;
}

void Line::moveUp(float dy) {
	src.y -= dy;
	dest.y -= dy;
}

void Line::moveDown(float dy) {
	src.y += dy;
	dest.y += dy;
}

void Line::setRGBT(int r, int g, int b, int t) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->t = t;
}
