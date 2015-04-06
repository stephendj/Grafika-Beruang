#include "FrameBuffer.cpp"
#include "Window.hpp"
#include <cstring>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <fstream>

using namespace std;

const float scale = 1.1;
bool quit=false;
int waktu = 25000;
int key;
FrameBuffer FB;
Window window;
View view(Point(620,220),Point(770,370));
vector<Polygon> indonesia;

Polygon pulau1("pulau1");
Polygon pulau2("pulau2");
Polygon pulau3("pulau3");
Polygon pulau4("pulau4");
Polygon pulau5("pulau5");
Polygon kapal("kapal");

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

// Menggambar peta Indonesia
void drawIndonesia()
{
	FB.drawPolygon(pulau1,255,255,0,0);
	FB.drawPolygon(pulau2,255,255,0,0);
	FB.drawPolygon(pulau3,255,255,0,0);
	FB.drawPolygon(pulau4,255,255,0,0);
	FB.drawPolygon(pulau5,255,255,0,0);
}

// Menggambar ulang isi view
void reDrawView() {
	vector<Polygon> clip;
	for(int i=0;i<indonesia.size();i++) {
		int j=0;
		bool found = false;
		while(j<indonesia[i].e.size() && !found) {
			if(not (indonesia[i].e[j].x<window.getTopLeft().x || indonesia[i].e[j].y<window.getTopLeft().y || indonesia[i].e[j].y>window.getBottomRight().y || indonesia[i].e[j].x>window.getBottomRight().x)) {
				found = true;
				clip.push_back(indonesia[i]);
			}
			j++;
		}
	}

	window.computeOnePolygon(kapal);
	if(!window.L.empty()) {
		// Menghitamkan isi view
		FB.drawSquare(Point(view.P1.x+1,view.P1.y+1),Point(view.P2.x-1,view.P2.y-1),0,0,0,0);
	}

	if(!clip.empty()) {
		window.computePolygon(clip);
		if(!window.L.empty()) {
			view.setViewLines(window);
			FB.drawView(view,0,255,255,0);	
			view.L.clear();
			window.L.clear();
			clip.clear();
		}	
	}
}

// Menggambar ulang segalanya jika ada tombol yang ditekan
void doMovement(int key) {
	if(key==65){ /*atas*/
		FB.drawWindow(window,0,0,0,0);
		window.moveUp(18);
		FB.drawWindow(window,0,250,250,0);
	} else if(key==66){ /*bawah*/
		FB.drawWindow(window,0,0,0,0);
		window.moveDown(18);
		FB.drawWindow(window,0,250,250,0);
	} else if(key==68){ /*kiri*/
		FB.drawWindow(window,0,0,0,0);
		window.moveLeft(18);
		FB.drawWindow(window,0,250,250,0);
	} else if(key==67){ /*kanan*/
		FB.drawWindow(window,0,0,0,0);
		window.moveRight(18);
		FB.drawWindow(window,0,250,250,0);
	} else if(key==61){ /*bigger*/
		if(window.changeable(1.1)){
			FB.drawWindow(window,0,0,0,0);
			window.bigger(1.1);
			FB.drawWindow(window,0,250,250,0);
		}else{
			FB.drawWindow(window,0,250,250,0);
		}
	} else if(key==45){ /*smaller*/
		if(window.changeableSmall()){
			FB.drawWindow(window,0,0,0,0);
			window.smaller(1.1);
			FB.drawWindow(window,0,250,250,0);
		}else{
			FB.drawWindow(window,0,250,250,0);
		}
	} else if(key=='q'){
		quit=true;
		system("clear");
	}
	system("clear");

	// Menggambar ulang border peta dan peta
	drawIndonesia();
	FB.drawLine(Point(0,0), Point(0,400), 0, 255, 255,0);
	FB.drawLine(Point(0,0), Point(599,0), 0, 255, 255,0);
	FB.drawLine(Point(599,0), Point(599,400), 0, 255, 255,0);
	FB.drawLine(Point(0,400), Point(599,400), 0, 255, 255,0);
	
	// Menggambar ulang view
	FB.drawLine(view.P1,Point(view.P2.x,view.P1.y),255,255,255,0);
	FB.drawLine(Point(view.P2.x,view.P1.y),view.P2,255,255,255,0);
	FB.drawLine(view.P2,Point(view.P1.x,view.P2.y),255,255,255,0);
	FB.drawLine(Point(view.P1.x,view.P2.y),view.P1,255,255,255,0);

	// Menghitamkan isi view
	FB.drawSquare(Point(view.P1.x+1,view.P1.y+1),Point(view.P2.x-1,view.P2.y-1),0,0,0,0);

	// Menggambar ulang isi view
	reDrawView();

	// Menggambar ulang window
	FB.drawWindow(window,0,250,250,0);
}

// kapal gerak ke atas
void moveKapalUp() {
	if(kbhit()) {
		key=getchar();
		doMovement(key);
	}
	usleep(waktu);
	FB.drawPolygon(kapal,0,0,0,0);
	kapal.moveUp(1);		
	FB.drawPolygon(kapal,255,0,255,0);
	reDrawView();
}

// kapal gerak ke bawah
void moveKapalDown() {
	if(kbhit()) {
		key=getchar();
		doMovement(key);
	}
	usleep(waktu);
	FB.drawPolygon(kapal,0,0,0,0);
	kapal.moveDown(1);		
	FB.drawPolygon(kapal,255,0,255,0);
	reDrawView();
}

// kapal gerak ke kanan
void moveKapalRight() {
	if(kbhit()) {
		key=getchar();
		doMovement(key);
	}
	usleep(waktu);
	FB.drawPolygon(kapal,0,0,0,0);
	kapal.moveRight(1);		
	FB.drawPolygon(kapal,255,0,255,0);
	reDrawView();
}

// kapal gerak ke kiri
void moveKapalLeft() {
	if(kbhit()) {
		key=getchar();
		doMovement(key);
	}
	usleep(waktu);
	FB.drawPolygon(kapal,0,0,0,0);
	kapal.moveLeft(1);		
	FB.drawPolygon(kapal,255,0,255,0);
	reDrawView();
}

// Menampilkan pergerakan kapal
void moveKapal() {
	FB.drawPolygon(kapal,255,0,255,0);

	while(kapal.getMaxX() < 125 && !quit){
		moveKapalRight();
	}
	while(kapal.getMaxY() < 358 && !quit){
		moveKapalDown();		
	}
	while(kapal.getMaxX() < 270 && !quit){
		moveKapalRight();		
	}
	while(kapal.getMinY() > 304 && !quit){
		moveKapalUp();		
	}
	while(kapal.getMaxX() < 422 && !quit){
		moveKapalRight();		
	}
	while(kapal.getMinY() > 113 && !quit){
		moveKapalUp();		
	}
	while(kapal.getMinX() > 321 && !quit){
		moveKapalLeft();		
	}
	while(kapal.getMinY() > 9 && !quit){
		moveKapalUp();		
	}

	while(kapal.getMinX() > 152 && !quit){
		moveKapalLeft();		
	}		
	while(kapal.getMaxY() < 278 && !quit){
		moveKapalDown();		
	}
	while(kapal.getMaxX() < 283 && !quit){
		moveKapalRight();
	}

	while(kapal.getMaxY() < 366 && !quit){
		moveKapalDown();		
	}
	while(kapal.getMinX() > 16 && !quit){
		moveKapalLeft();		
	}
	while(kapal.getMinY() > 301 && !quit){
		moveKapalUp();		
	}
}

int main()
{
	// Push semua pulau ke vector indonesia
	indonesia.push_back(pulau1);
	indonesia.push_back(pulau2);
	indonesia.push_back(pulau3);
	indonesia.push_back(pulau4);
	indonesia.push_back(pulau5);

	system("clear");

	// Menggambar border peta, indonesia, window, dan viewport di kanan layar
	FB.drawLine(Point(0,0), Point(0,400), 0, 255, 255,0);
	FB.drawLine(Point(0,0), Point(599,0), 0, 255, 255,0);
	FB.drawLine(Point(599,0), Point(599,400), 0, 255, 255,0);
	FB.drawLine(Point(0,400), Point(599,400), 0, 255, 255,0);
	FB.drawLine(view.P1,Point(view.P2.x,view.P1.y),255,255,255,0);
	FB.drawLine(Point(view.P2.x,view.P1.y),view.P2,255,255,255,0);
	FB.drawLine(view.P2,Point(view.P1.x,view.P2.y),255,255,255,0);
	FB.drawLine(Point(view.P1.x,view.P2.y),view.P1,255,255,255,0);
	FB.drawWindow(window,0,250,250,0);
	drawIndonesia();

	// Iterasi utama
	while(!quit){
		if(kbhit()){
			key=getchar();
			doMovement(key);
		}
		else
		{
			moveKapal();

			// Menggambar Window dan view
			reDrawView();
			FB.drawWindow(window,0,250,250,0);
		}
	}

	system("clear");
	
	return 0;
}