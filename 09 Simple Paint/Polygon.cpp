#include "Polygon.hpp"

Polygon::Polygon() {
	n = 0;
}

Polygon::Polygon(string nama) {
	if(nama.compare("pulau1")==0)
	{
		e.push_back(Point(11,43));
		e.push_back(Point(19,51));
		e.push_back(Point(32,53));
		e.push_back(Point(41,58));
		e.push_back(Point(47,68));
		e.push_back(Point(48,76));
		e.push_back(Point(54,85));
		e.push_back(Point(66,99));
		e.push_back(Point(71,111));
		e.push_back(Point(78,120));
		e.push_back(Point(83,116));
		e.push_back(Point(87,123));
		e.push_back(Point(91,121));
		e.push_back(Point(92,123));
		e.push_back(Point(99,134));
		e.push_back(Point(102,142));
		e.push_back(Point(108,145));
		e.push_back(Point(109,154));
		e.push_back(Point(116,156));
		e.push_back(Point(113,168));
		e.push_back(Point(113,179));
		e.push_back(Point(124,187));
		e.push_back(Point(127,192));
		e.push_back(Point(128,213));
		e.push_back(Point(139,217));
		e.push_back(Point(145,228));
		e.push_back(Point(143,286));
		e.push_back(Point(137,278));
		e.push_back(Point(134,286));
		e.push_back(Point(128,282));
		e.push_back(Point(127,289));
		e.push_back(Point(117,269));
		e.push_back(Point(105,257));
		e.push_back(Point(98,241));
		e.push_back(Point(81,215));
		e.push_back(Point(81,202));
		e.push_back(Point(68,170));
		e.push_back(Point(56,152));
		e.push_back(Point(52,124));
		e.push_back(Point(40,113));
		e.push_back(Point(35,99));
		e.push_back(Point(30,92));
		e.push_back(Point(7,51));
		e.push_back(Point(11,43));
	}
	else if(nama.compare("pulau2")==0)
	{
		e.push_back(Point(188,131));
		e.push_back(Point(194,132));
		e.push_back(Point(205,129));
		e.push_back(Point(215,126));
		e.push_back(Point(216,114));
		e.push_back(Point(227,107));
		e.push_back(Point(229,97));
		e.push_back(Point(238,100));
		e.push_back(Point(243,87));
		e.push_back(Point(250,79));
		e.push_back(Point(252,70));
		e.push_back(Point(255,64));
		e.push_back(Point(263,60));
		e.push_back(Point(267,61));
		e.push_back(Point(276,51));
		e.push_back(Point(280,32));
		e.push_back(Point(285,25));
		e.push_back(Point(291,23));
		e.push_back(Point(299,34));
		e.push_back(Point(298,42));
		e.push_back(Point(305,43));
		e.push_back(Point(312,53));
		e.push_back(Point(318,54));
		e.push_back(Point(304,63));
		e.push_back(Point(308,71));
		e.push_back(Point(299,81));
		e.push_back(Point(300,87));
		e.push_back(Point(292,89));
		e.push_back(Point(292,94));
		e.push_back(Point(296,97));
		e.push_back(Point(296,106));
		e.push_back(Point(303,112));
		e.push_back(Point(303,116));
		e.push_back(Point(300,120));
		e.push_back(Point(306,133));
		e.push_back(Point(315,144));
		e.push_back(Point(306,147));
		e.push_back(Point(301,145));
		e.push_back(Point(293,171));
		e.push_back(Point(297,175));
		e.push_back(Point(287,192));
		e.push_back(Point(282,194));
		e.push_back(Point(282,211));
		e.push_back(Point(278,229));
		e.push_back(Point(279,250));
		e.push_back(Point(275,243));
		e.push_back(Point(258,250));
		e.push_back(Point(252,235));
		e.push_back(Point(239,229));
		e.push_back(Point(229,238));
		e.push_back(Point(221,227));
		e.push_back(Point(213,230));
		e.push_back(Point(192,226));
		e.push_back(Point(198,205));
		e.push_back(Point(197,188));
		e.push_back(Point(187,172));
		e.push_back(Point(189,162));
		e.push_back(Point(188,131));
	
	}
	else if(nama.compare("pulau3")==0)
	{
		e.push_back(Point (148,293));
		e.push_back(Point (152,296));
		e.push_back(Point (161,291));
		e.push_back(Point (169,298));
		e.push_back(Point (176,299));
		e.push_back(Point (180,308));
		e.push_back(Point (191,313));
		e.push_back(Point (204,307));
		e.push_back(Point (208,302));
		e.push_back(Point (215,309));
		e.push_back(Point (246,313));
		e.push_back(Point (242,318));
		e.push_back(Point (234,319));
		e.push_back(Point (235,328));
		e.push_back(Point (254,330));
		e.push_back(Point (254,341));
		e.push_back(Point (255,348));
		e.push_back(Point (249,347));
		e.push_back(Point (241,339));
		e.push_back(Point (231,342));
		e.push_back(Point (221,339));
		e.push_back(Point (207,338));
		e.push_back(Point (189,327));
		e.push_back(Point (172,328));
		e.push_back(Point (161,320));
		e.push_back(Point (153,323));
		e.push_back(Point (148,311));
		e.push_back(Point (139,310));
		e.push_back(Point (148,293));

	}
	else if(nama.compare("pulau4")==0)
	{
		e.push_back(Point (392,133));
		e.push_back(Point (392,144));
		e.push_back(Point (374,161));
		e.push_back(Point (365,155));
		e.push_back(Point (353,156));
		e.push_back(Point (349,153));
		e.push_back(Point (344,155));
		e.push_back(Point (335,155));
		e.push_back(Point (329,166));
		e.push_back(Point (329,181));
		e.push_back(Point (334,188));
		e.push_back(Point (338,197));
		e.push_back(Point (348,185));
		e.push_back(Point (352,189));
		e.push_back(Point (369,179));
		e.push_back(Point (370,185));
		e.push_back(Point (366,184));
		e.push_back(Point (346,207));
		e.push_back(Point (347,212));
		e.push_back(Point (353,220));
		e.push_back(Point (354,227));
		e.push_back(Point (359,237));
		e.push_back(Point (355,245));
		e.push_back(Point (364,257));
		e.push_back(Point (348,266));
		e.push_back(Point (346,250));
		e.push_back(Point (339,240));
		e.push_back(Point (342,229));
		e.push_back(Point (336,222));
		e.push_back(Point (330,282));
		e.push_back(Point (320,281));
		e.push_back(Point (323,266));
		e.push_back(Point (322,244));
		e.push_back(Point (319,238));
		e.push_back(Point (312,243));
		e.push_back(Point (312,225));
		e.push_back(Point (318,219));
		e.push_back(Point (321,203));
		e.push_back(Point (321,186));
		e.push_back(Point (325,177));
		e.push_back(Point (327,158));
		e.push_back(Point (336,144));
		e.push_back(Point (340,139));
		e.push_back(Point (351,144));
		e.push_back(Point (364,148));
		e.push_back(Point (377,146));
		e.push_back(Point (392,133));
	}
	else if(nama.compare("pulau5")==0)
	{
		e.push_back(Point (599,233));
		e.push_back(Point (599,361));
		e.push_back(Point (583,339));
		e.push_back(Point (572,344));
		e.push_back(Point (571,316));
		e.push_back(Point (572,311));
		e.push_back(Point (566,299));
		e.push_back(Point (563,285));
		e.push_back(Point (542,269));
		e.push_back(Point (531,262));
		e.push_back(Point (521,260));
		e.push_back(Point (517,250));
		e.push_back(Point (509,247));
		e.push_back(Point (506,234));
		e.push_back(Point (503,234));
		e.push_back(Point (500,253));
		e.push_back(Point (493,249));
		e.push_back(Point (492,237));
		e.push_back(Point (484,228));
		e.push_back(Point (490,224));
		e.push_back(Point (494,225));
		e.push_back(Point (499,220));
		e.push_back(Point (503,222));
		e.push_back(Point (505,214));
		e.push_back(Point (488,216));
		e.push_back(Point (483,200));
		e.push_back(Point (473,202));
		e.push_back(Point (466,185));
		e.push_back(Point (473,186));
		e.push_back(Point (480,181));
		e.push_back(Point (489,174));
		e.push_back(Point (502,184));
		e.push_back(Point (513,191));
		e.push_back(Point (513,224));
		e.push_back(Point (518,224));
		e.push_back(Point (521,240));
		e.push_back(Point (533,226));
		e.push_back(Point (543,217));
		e.push_back(Point (552,211));
		e.push_back(Point (554,203));
		e.push_back(Point (562,199));
		e.push_back(Point (585,218));
		e.push_back(Point (595,218));
		e.push_back(Point (599,233));
	}
	else if (nama.compare("square")==0){
		e.push_back(Point(2,2));
		e.push_back(Point(2,102));
		e.push_back(Point(102,102));
		e.push_back(Point(102,2));
		e.push_back(Point(2,2));
	}
	else if(nama.compare("kapal")==0)
	{
		e.push_back(Point (16,301));
		e.push_back(Point (16,306));
		e.push_back(Point (25,308));
		e.push_back(Point (29,304));
		e.push_back(Point (25,299));
		e.push_back(Point (16,301));
	}
	else if (nama.compare("pesawat") == 0){
		e.push_back(Point(66,364));
		e.push_back(Point(72,369));
		e.push_back(Point(78,360));
		e.push_back(Point(66,364));
	}
	n = e.size();
}

Polygon::Polygon(vector<Point> P) {
	e = P;
	n = P.size();
}

Polygon::Polygon(const Polygon& p) {
	n = p.n;
	e = p.e;
	r = p.r;
	g = p.g;
	b = p.b;
	t = p.t;
}

Polygon& Polygon::operator=(const Polygon& p) {
	n = p.n;
	e = p.e;
	r = p.r;
	g = p.g;
	b = p.b;
	t = p.t;

	return *this;
}

Polygon& Polygon::operator<<(const vector<Point>& P) {
	n = P.size();
	e = P;
	e.push_back(e[0]);

	return *this;
}

void Polygon::setZ(int z) {
	for (int i=0; i<e.size(); ++i) {
		e[i].z=z;
	}
}

void Polygon::setRGBT(int r, int g, int b, int t) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->t = t;
}

void Polygon::insert(Point point) {
	e[n] = point;
	e.push_back(e[0]);
	++n;
}

void Polygon::mirrorTransform() {
	int x = getMidX();
	for(int i=0;i<n;i++) {
		e[i].x = x + (x-e[i].x);
	}
}

float Polygon::getMidY() {
	int i=1;
	float maxY=e[0].y;
	while(i<n) {
		if(e[i].y>maxY) {
			maxY=e[i].y;
		}
		i++;
	}

	i=1;
	float minY=e[0].y;
	while(i<n) {
		if(e[i].y<minY) {
			minY=e[i].y;
		}
		i++;
	}

	return (maxY + minY)/2;
}

float Polygon::getMidX() {
	int i=1;
	float maxX=e[0].x;
	while(i<n) {
		if(e[i].x>maxX) {
			maxX=e[i].x;
		}
		i++;
	}

	i=1;
	float minX=e[0].x;
	while(i<n) {
		if(e[i].x<minX) {
			minX=e[i].x;
		}
		i++;
	}

	return (maxX + minX)/2;
}

float Polygon::getMaxX() {
	int i=1;
	float maxX=e[0].x;
	while(i<n) {
		if(e[i].x>maxX) {
			maxX=e[i].x;
		}
		i++;
	}
	return maxX;
}

float Polygon::getMinX() {
	int i=1;
	float minX=e[0].x;
	while(i<n) {
		if(e[i].x<minX) {
			minX=e[i].x;
		}
		i++;
	}
	return minX;
}

float Polygon::getMaxY() {
	int i=1;
	float maxY=e[0].y;
	while(i<n) {
		if(e[i].y>maxY) {
			maxY=e[i].y;
		}
		i++;
	}
	return maxY;
}

float Polygon::getMinY() {
	int i=1;
	float minY=e[0].y;
	while(i<n) {
		if(e[i].y<minY) {
			minY=e[i].y;
		}
		i++;
	}
	return minY;
}

bool Polygon::isBoundary() {
	int i=0;
	bool found = false;
	while(i<n && !found) {
		if(e[i].x>799 || e[i].x<5 || e[i].y>599 || e[i].y<5) {
			found = true;
		}
		i++;
	}
	return found;
}

void Polygon::moveRight(float dx) {
	int i=0;
	while(i<n)
	{
		e[i].x=e[i].x+dx;
		i++;
	}
}

void Polygon::moveLeft(float dx) {
	int i=0;
	while(i<n)
	{
		e[i].x=e[i].x-dx;
		i++;
	}
}

void Polygon::moveUp(float dy) {
	int i=0;
	while(i<n)
	{
		e[i].y=e[i].y-dy;
		i++;
	}
}

void Polygon::moveDown(float dy) {
	int i=0;
	while(i<n)
	{
		e[i].y=e[i].y+dy;
		i++;
	}
}


void Polygon::rotate(double dg){
	int i=0;
	double con=0.0174532925;
	double tempx,tempy;
	while(i<n){
		tempx= ((cos(dg*con)*(e[i].x - e[0].x)) - (sin(dg*con)*(e[i].y - e[0].y)) + e[0].x)+0.5;
		tempy= ((sin(dg*con)*(e[i].x - e[0].x)) + (cos(dg*con)*(e[i].y - e[0].y)) + e[0].y)+0.5;
		e[i].x = tempx;
		e[i].y = tempy;
		i++;
	}
}