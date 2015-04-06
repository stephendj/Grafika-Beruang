#include "FrameBuffer.cpp"
#include "Window.hpp"
#include <cstring>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

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

int main() {
	FrameBuffer FB;

	system("clear");
	
	// Sumatera
	Polygon3D pulau1("pulau1"); pulau1.setZ(5);

	// Kalimantan
	Polygon3D pulau2("pulau2"); pulau2.setZ(4);

	// Jawa
	Polygon3D pulau3("pulau3"); pulau3.setZ(3);

	// Sulawesi
	Polygon3D pulau4("pulau4"); pulau4.setZ(2);

	// Papua
	Polygon3D pulau5("pulau5"); pulau5.setZ(1);
	
	pulau1.setRGBT(255,0,0,0);
	pulau2.setRGBT(0,255,0,0);
	pulau3.setRGBT(0,0,255,0);
	pulau4.setRGBT(255,255,0,0);
	pulau5.setRGBT(255,0,255,0);

	vector<Polygon3D> a;
	a.push_back(pulau1); 
	a.push_back(pulau2); 
	a.push_back(pulau3);
	a.push_back(pulau4);
	a.push_back(pulau5);
	for(int i=0; i<a.size(); i++) {
		a[i].moveRight(80);
		a[i].moveDown(120);
	}

	system("clear");
	FB.drawPolygonsUsingPainter(a);

	bool quit = false;
	int x;
	while(!quit){
		if (kbhit()){
			x = getchar();

			if (x != 'q'){
				FB.drawSquare(Point(0,0),Point(799,599),0,0,0,0);
				if(x==65){ /*atas*/
					for(int i=0; i<a.size(); i++) {
						a[i].moveUp(10);
					}
				} else if(x==66){ /*bawah*/
					for(int i=0; i<a.size(); i++) {
						a[i].moveDown(10);
					}
				} else if(x==68){ /*kiri*/
					for(int i=0; i<a.size(); i++) {
						a[i].moveLeft(10);
					}
				} else if(x==67){ /*kanan*/
					for(int i=0; i<a.size(); i++) {
						a[i].moveRight(10);
					}
				} 
				FB.drawPolygonsUsingPainter(a);
			}
			else {
				quit = true;
			}
		}
	}
	return 0;
}
