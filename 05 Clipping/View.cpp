#include "View.hpp"

View::View() {

}

View::View(Point _P1, Point _P2) {
	P1.x = _P1.x;
	P1.y = _P1.y;
	P2.x = _P2.x;
	P2.y = _P2.y;
}

void View::setViewLines(Window W) {
	if(!W.L.empty()) {
		// Mengcopy vector of line di Window ke vector Line di View
		for(int i=0; i<W.L.size(); i++) {
			L.push_back(W.L[i]);
		}
		// Menghitung faktor skala
		float dx = (float) (P2.x - P1.x)/(W.getBottomRight().x - W.getTopLeft().x);
		float dy = (float) (P2.y - P1.y)/(W.getBottomRight().y - W.getTopLeft().y);
		
		// Menghitung skala dari masing - masing garis
		for(int i=0; i<L.size(); i++) {
			
			// Menghitung transformasi total
			L[i].src.x = dx * (L[i].src.x - W.getTopLeft().x) + P1.x;
			L[i].src.y = dy * (L[i].src.y - W.getTopLeft().y) + P1.y;
			L[i].dest.x = dx * (L[i].dest.x - W.getTopLeft().x) + P1.x;
			L[i].dest.y = dy * (L[i].dest.y - W.getTopLeft().y) + P1.y;
		}
	}
}