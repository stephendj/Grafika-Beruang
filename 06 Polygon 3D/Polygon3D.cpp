#include "Polygon3D.hpp"

Polygon3D::Polygon3D() {
	bawah = Polygon();
	atas = Polygon();
}

Polygon3D::Polygon3D(string nama){
	bawah = Polygon(nama);
	atas = Polygon(nama);
	atas.moveUp(15);
	atas.moveRight(10);
	for(int i=0; i<atas.n; i++) {
		L.push_back(Line(atas.e[i],bawah.e[i]));		
	}
	for(int i=0; i<atas.e.size()-1; i++) {
		vector<Point> points;
		points.push_back(atas.e[i]);
		points.push_back(atas.e[i+1]);
		points.push_back(bawah.e[i+1]);
		points.push_back(bawah.e[i]);
		points.push_back(atas.e[i]);
		P.push_back(Polygon(points));
	}
}

Polygon3D::Polygon3D(const Polygon3D& p){
	bawah = p.bawah;
	atas = p.atas;
	L = p.L;
	P = p.P;
}

Polygon3D& Polygon3D::operator=(const Polygon3D& p){
	bawah = p.bawah;
	atas = p.atas;
	L = p.L;
	P = p.P;

	return *this;
}

void Polygon3D::moveUp(int dx){
	int limit_up = 11; //dummy
	if (atas.getMinY() > limit_up && bawah.getMinY() > limit_up){
		bawah.moveUp(dx);
		atas.moveUp(dx);
		for(unsigned int i = 0; i < L.size(); i++){
			L[i].moveUp(dx);
		}
		for(int i=0; i<P.size(); i++) {
			P[i].moveUp(dx);
		} 
	}
}

void Polygon3D::moveDown(int dx){
	int limit_down = 589; //dummy
	if (bawah.getMaxY() < limit_down){
		bawah.moveDown(dx);
		atas.moveDown(dx);
		for(unsigned int i = 0; i < L.size(); i++){
			L[i].moveDown(dx);
		}
		for(int i=0; i<P.size(); i++) {
			P[i].moveDown(dx);
		} 
	}

}

void Polygon3D::moveRight(int dx){
	int limit_right = 789;
	if (bawah.getMaxX() < limit_right && atas.getMaxX() < limit_right){
		bawah.moveRight(dx);
		atas.moveRight(dx);
		for(unsigned int i = 0; i < L.size(); i++){
			L[i].moveRight(dx);
		}
		for(int i=0; i<P.size(); i++) {
			P[i].moveRight(dx);
		} 
	}
}

void Polygon3D::moveLeft(int dx){
	int limit_left = 10;
	if (bawah.getMinX() > limit_left && atas.getMinX() > limit_left){
		bawah.moveLeft(dx);
		atas.moveLeft(dx);
		for(unsigned int i = 0; i < L.size(); i++){
			L[i].moveLeft(dx);
		}
		for(int i=0; i<P.size(); i++) {
			P[i].moveLeft(dx);
		} 
	}
}

void Polygon3D::setZ(int z) {
	bawah.setZ(z);
	atas.setZ(z);
	for(int i=0; i<P.size(); i++) {
		P[i].setZ(z);
	}
}

void Polygon3D::setRGBT(int r, int g, int b, int t) {
	bawah.setRGBT(r, g, b, t);
	atas.setRGBT(r, g, b, t);
	for(int i=0; i<P.size(); i++) {
		P[i].setRGBT(r, g, b, t);
	}
}
