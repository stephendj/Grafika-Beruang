#ifndef VIEW_H
#define VIEW_H

#include "Window.hpp"
#include <vector>

class View {
	public:
		Point P1;
		Point P2;
		vector<Line> L;

		View();
		View(Point,Point);
		void setViewLines(Window W);
};

#endif