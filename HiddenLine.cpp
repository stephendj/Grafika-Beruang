#include "HiddenLine.hpp"

HiddenLine::HiddenLine(Polygon _clipsquare) {
	clipsquare = _clipsquare;
}

Point HiddenLine::getTopLeft() {
	return clipsquare.e[0];
}

Point HiddenLine::getBottomRight() {
	return clipsquare.e[2];
}

int HiddenLine::computeOutCode(Point P) {
	int code;
 
	code = INSIDE;          // initialised as being inside of clip window
 
	if (P.x < getTopLeft().x)           // to the left of clip window
		code |= LEFT;
	else if (P.x > getBottomRight().x)      // to the right of clip window
		code |= RIGHT;
	if (P.y < getTopLeft().y)           // below the clip window
		code |= BOTTOM;
	else if (P.y > getBottomRight().y)      // above the clip window
		code |= TOP;
 
	return code;
}

void HiddenLine::computeLine(Line l) {
	int outcode0 = computeOutCode(l.src);
	int outcode1 = computeOutCode(l.dest);
	bool accept = false;
 	
	while (true) {
		if (!(outcode0 | outcode1)) { // Bitwise OR is 0. Trivially accept and get out of loop
			accept = true;
			break;
		} else if (outcode0 & outcode1) { // Bitwise AND is not 0. Trivially reject and get out of loop
			break;
		} else {
			float x, y;
 
			// At least one endpoint is outside the clip rectangle; pick it.
			int outcodeOut = outcode0 ? outcode0 : outcode1;
 
			// Now find the intersection point;
			if (outcodeOut & TOP) {           // point is above the clip rectangle
				x = l.src.x + (l.dest.x - l.src.x) * (getBottomRight().y - l.src.y) / (l.dest.y - l.src.y);
				y = getBottomRight().y;
			} else if (outcodeOut & BOTTOM) { // point is below the clip rectangle
				x = l.src.x + (l.dest.x - l.src.x) * (getTopLeft().y - l.src.y) / (l.dest.y - l.src.y);
				y = getTopLeft().y;
			} else if (outcodeOut & RIGHT) {  // point is to the right of clip rectangle
				y = l.src.y + (l.dest.y - l.src.y) * (getBottomRight().x - l.src.x) / (l.dest.x - l.src.x);
				x = getBottomRight().x;
			} else if (outcodeOut & LEFT) {   // point is to the left of clip rectangle
				y = l.src.y + (l.dest.y - l.src.y) * (getTopLeft().x - l.src.x) / (l.dest.x - l.src.x);
				x = getTopLeft().x;
			}
 
			// and get ready for next pass.
			if (outcodeOut == outcode0) {
				l.src.x = x;
				l.src.y = y;
				outcode0 = computeOutCode(l.src);
			} else {
				l.dest.x = x;
				l.dest.y = y;
				outcode1 = computeOutCode(l.dest);
			}
		}
	}
	if (accept) {
		L.push_back(l_awal);
		if(l_awal.src.x!=l.src.x || l_awal.src.y!=l.src.y || l_awal.dest.x!=l.dest.x || l_awal.dest.y!=l.dest.y) {
			l.setRGBT(0,0,0,0);
			L.push_back(l);
		}
    }
}