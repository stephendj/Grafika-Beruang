#include "Cuboid.hpp"

Cuboid::Cuboid() { // CTOR
	for (int i=0; i<8; ++i) {
		p.push_back(Point());
	}

	for (int i=0; i<8; ++i) {
		p[i] = Point();
	}
}

Cuboid::Cuboid(Point P, int l, int w, int h) { // CTOR PARAM
	//    3     2	  z
	// 0  |  1  |	   \
	// |  |  |  |		\---- x
	// |  |  |  |		|
	// |  7  |  6		|
	// 4     5		 	y
	for (int i=0; i<8; ++i) {
		p.push_back(P);
	}

	for (int i=0; i<8; ++i) {
		if ((i-1)%4==0 || (i-2)%4==0) {
			p[i].x += l;
		}
		if (i>3) {
			p[i].y += h;
		}
		if (i%4==0 || (i-1)%4==0) {
			p[i].z += w;
		}
	}
}

Cuboid::Cuboid(const Cuboid& c) { // CCTOR
	p = c.p;
}

Cuboid& Cuboid::operator=(const Cuboid& c) { // OPERATOR=
	p = c.p;

	return *this;
}

Cuboid::~Cuboid() { // DTOR

}

void Cuboid::setRGBT(int R, int G, int B, int T) {
	for (int i=0; i<p.size(); ++i) {
		p[i].setRGBT(R, G, B, T);
	}
}
