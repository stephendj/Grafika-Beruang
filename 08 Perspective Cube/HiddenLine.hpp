#ifndef WINDOW_H
#define WINDOW_H

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

#include "Line.hpp"
#include "Polygon.hpp"
#include <vector>

class HiddenLine {
	public:
		Polygon clipsquare;
		vector<Line> L;
		Line l_awal;

		HiddenLine(Polygon _clipsquare);

		Point getTopLeft();
		Point getBottomRight();
		
		// Menghitung OutCode dari sebuah Point (Posisi terhadap Window)
		int computeOutCode(Point P);

		// Menentukan garis yang harus digambar dalam Window
		void computeLine(Line l);
};

#endif