#ifndef BOX_H
#define BOX_H

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

#include "Line.hpp"
#include "Polygon.hpp"
#include <vector>

class Box {
	public:
		Polygon square;
		vector<Line> L;

		Box();
		Box(string nama);
		void moveRight(int dx, int batas);
		void moveLeft(int dx, int batas);
		void moveUp(int dx, int batas);
		void moveDown(int dx, int batas);
		Point getMidPoint();
		Point getTopLeft();
		Point getBottomRight();
};

#endif