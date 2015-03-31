#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"

class Line {
public:
	Line(); // CTOR

	Line(Point src, Point dest); // CTOR PARAM

	Line(const Line& l); // CCTOR

	Line& operator=(const Line& l); // OPERATOR=

	~Line(); // DTOR

	void moveLeft(float dx);
	
	void moveRight(float dx);
	
	void moveUp(float dy);
	
	void moveDown(float dy);

	void setRGBT(int r, int g, int b, int t);

	Point src, dest;
	int r, g, b, t;

private:

};

#endif
