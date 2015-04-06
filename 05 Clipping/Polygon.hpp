#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Point.hpp"
#include <string>
#include "math.h"

class Polygon {
public:
	Polygon();

	Polygon(string nama);

	Polygon(vector<Point> P);

	Polygon& operator<<(const vector<Point>& P);
	
	void insert(Point point);

	void mirrorTransform();

	float getMidY();

	float getMidX();

	float getMaxX();

	float getMinX();

	float getMaxY();

	float getMinY();

	bool isBoundary();

	void moveRight(float dx);

	void moveLeft(float dx);

	void moveUp(float dy);

	void moveDown(float dy);

	void rotate(double dg);

	int n;
	vector<Point> e;

private:

};

#endif
