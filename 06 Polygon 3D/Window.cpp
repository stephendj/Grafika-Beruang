#include "Window.hpp"

Window::Window(){
	square = Polygon("square");
}
void Window::moveRight(float dx){
	if(square.getMaxX()<580){
		square.moveRight(dx);
	}
}
void Window::moveLeft(float dx){
	if(square.getMinX()>19){
		square.moveLeft(dx);
	}
}
void Window::moveUp(float dx){
	if(square.getMinY()>19){
		square.moveUp(dx);
	}
}
void Window::moveDown(float dx){
	if(square.getMaxY()<380){
		square.moveDown(dx);
	}
}
Point Window::getMidPoint(){
	return Point(square.getMidX(), square.getMidY());
}
Point Window::getTopLeft(){
	return square.e[0];
}
Point Window::getBottomRight(){
	return square.e[2];
}
bool Window::changeable(float k){
	bool changeable;
	changeable=true;
	int i;
	int midX = getMidPoint().x;
	int midY = getMidPoint().y;
	vector<Point> temp;
	/*ngopy vector*/
	for(i=0;i<square.n;i++){
		temp.push_back(Point(square.e[i].x,square.e[i].y));
	}
	/*cek changeable*/
	for(i=0;i<square.n;i++) {
		temp[i].x = (temp[i].x - midX) * k + midX;
		temp[i].y = (temp[i].y - midY) * k + midY;
		if((temp[i].x<0) || (temp[i].x>599) ||(temp[i].y<0)||(temp[i].y>399) ){
			changeable=false;
		}
	}
	if(getBottomRight().x - getTopLeft().x <10) {
		changeable=false;
	}
	return changeable;
}
bool Window::changeableSmall(){
	bool changeable;
	changeable=true;
	if(getBottomRight().x - getTopLeft().x <20) {
		changeable=false;
	}
	return changeable;
}
void Window::bigger(float k){
	int i;
	int midX = getMidPoint().x;
	int midY = getMidPoint().y;

	for(i=0;i<square.n;i++) {
		square.e[i].x = (square.e[i].x - midX) * k + midX;
		square.e[i].y = (square.e[i].y - midY) * k + midY;
	}
}
void Window::smaller(float k){
	int i;
	int midX = getMidPoint().x;
	int midY = getMidPoint().y;

	for(i=0;i<square.n;i++) {
		square.e[i].x = (square.e[i].x - midX) / k + midX;
		square.e[i].y = (square.e[i].y - midY) / k + midY;
	}
}

int Window::computeOutCode(Point P) {
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

void Window::computeLine(Line l) {
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
       L.push_back(l);
    }
}

void Window::computeOnePolygon(Polygon P) {
	for(int j=0; j<P.n-1; j++) {
		computeLine(Line(Point(P.e[j].x,P.e[j].y),Point(P.e[j+1].x,P.e[j+1].y)));
	}
}

void Window::computePolygon(vector<Polygon> VP) {
	int c = 1;
	if(!VP.empty()) {
		for(int i=0; i<VP.size(); i++) {
			for(int j=0; j<VP[i].n-1; j++) {
				computeLine(Line(Point(VP[i].e[j].x,VP[i].e[j].y),Point(VP[i].e[j+1].x,VP[i].e[j+1].y)));
			}
		}
	}
}
