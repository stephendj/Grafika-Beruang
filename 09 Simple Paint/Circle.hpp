#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Point.hpp"

class Circle {

	public:
		Circle();
		Circle(Point _P, int _r);
		Circle(const Circle& c);
		Circle& operator=(const Circle& c);
		~Circle();

		void moveRight(float dx);
		void moveLeft(float dx);
		void moveUp(float dy);
		void moveDown(float dy);

		Point P;
		int r;

	private:
		
};

#endif
