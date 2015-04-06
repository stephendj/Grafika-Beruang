#include "Box.hpp"

Box::Box(){
	square = Polygon("square");
}
Box::Box(string nama){
	square = Polygon(nama);
}
void Box::moveRight(int dx, int batas){
	if(square.getMaxX()+dx<batas){
		square.moveRight(dx);
	}
}
void Box::moveLeft(int dx, int batas){
	if(square.getMinX()-dx>batas){
		square.moveLeft(dx);
	}
}
void Box::moveUp(int dx, int batas){
	if(square.getMinY()-dx>batas){
		square.moveUp(dx);
	}
}
void Box::moveDown(int dx, int batas){
	if(square.getMaxY()+dx<batas){
		square.moveDown(dx);
	}
}
Point Box::getMidPoint(){
	return Point(square.getMidX(), square.getMidY());
}
Point Box::getTopLeft(){
	return square.e[0];
}
Point Box::getBottomRight(){
	return square.e[2];
}