#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"

class Circle{
	public:
		Point P;
		int r;

		Circle();
		Circle(Point _P, int _r);
		Circle(const Circle& c);
		Circle& operator=(const Circle& c);
		void moveRight(float dx);
		void moveLeft(float dx);
		void moveUp(float dy);
		void moveDown(float dy);
};

#endif
