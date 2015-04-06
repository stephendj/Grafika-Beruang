#ifndef POLYGON3D_H
#define POLYGON3D_H

#include "Polygon.hpp"
#include "Line.hpp"
#include <vector>

class Polygon3D {
	public:
		Polygon3D();
		Polygon3D(string nama);
		Polygon3D(const Polygon3D& p);
		Polygon3D& operator=(const Polygon3D& p);

		void moveUp(int);
		void moveDown(int);
		void moveRight(int);
		void moveLeft(int);
		void removeHiddenLines();
		void setZ(int z);
		void setRGBT(int r, int g, int b, int t);

		Polygon bawah;
		Polygon atas;
		vector<Line> L;
		vector<Polygon> P;
};

#endif
