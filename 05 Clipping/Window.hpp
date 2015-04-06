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

class Window {
	public:
		Polygon square;
		vector<Line> L;

		Window();

		void moveRight(float dx);
		void moveLeft(float dx);
		void moveUp(float dx);
		void moveDown(float dx);
		Point getMidPoint();
		Point getTopLeft();
		Point getBottomRight();
		bool changeable(float k);
		bool changeableSmall();
		void bigger(float k);
		void smaller(float k);
		
		// Menghitung OutCode dari sebuah Point (Posisi terhadap Window)
		int computeOutCode(Point P);

		// Menentukan garis yang harus digambar dalam Window
		void computeLine(Line l);

		// Menentukan seluruh garis pada polygon yang harus digambar dalam Window
		void computeOnePolygon(Polygon P);

		// Menentukan seluruh garis pada sejumlah polygon yang harus digambar dalam Window
		void computePolygon(vector<Polygon> VP);
};

#endif