#include <unistd.h>
#include <fcntl.h>		/* for fcntl */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>		/* for mmap */
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <iostream>
#include "Point.hpp"
#include "Polygon.hpp"
#include "FrameBuffer.cpp"
<<<<<<< HEAD
#include "Box.hpp"

using namespace std;
FrameBuffer FB;

typedef struct 
{
	int red;
	int green;
	int blue;
	int trans;

}Color;
//color picker
int input_x=0;
int input_y=0;
Color polygonCol;
Box box("pickerBox");
int boxStep = 40;
int batasKananPalet=400;
int batasBawahPalet=360;
int batasKiriPalet=130;
int batasAtasPalet=110;

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

  	if(ch != EOF) {
	    ungetc(ch, stdin);
	    return 1;
  	}
  	return 0;
}




//menampilkan papan warna
void showColorPicker() {
	system("clear");
	FB.drawSquare(Point(0,0), Point(799,599),0,0,0,0);
	int re=20;
	int gr=20;
	int bl=20;
	for(int y=100;y<340;y+=40){
		for(int x=150;x<390;x+=40){
			FB.drawSquare(Point(x,y), Point(x+40,y+40),re,gr,bl,0);
			re += 20;
			gr += 30;
			bl += 40;
		}
			re += 80;
			gr += 60;
			bl += 40;
	}
}

//mengambil warna box
Color pickPolygonColor(){
	bool isPicked=false;
	int key;
	Point boxPos;
	Point oldPos, newPos;
	int oldRed, oldGreen, oldBlue;
	int newRed, newGreen, newBlue;

	while(!isPicked)
		{
			/*untuk pergeseran picker color*/
			if(kbhit()){
				key=getchar();
				// cout << "key : " << key << endl;
				if(key==65){ /*atas*/
					oldPos=box.getMidPoint();
					oldRed = FB.getRed(oldPos.x, oldPos.y);
					oldGreen = FB.getGreen(oldPos.x, oldPos.y);
					oldBlue = FB.getBlue(oldPos.x, oldPos.y);
					FB.drawBox(box,oldRed,oldGreen,oldBlue,0);
					box.moveUp(boxStep,batasAtasPalet);
					newPos=box.getMidPoint();
					newRed = FB.getRed(newPos.x, newPos.y);
					newGreen = FB.getGreen(newPos.x, newPos.y);
					newBlue = FB.getBlue(newPos.x, newPos.y);
					//FB.drawPolygon(P,newRed,newGreen,newBlue,0);
					//FB.floodFillPolygon(P.getMidX(), P.getMidY(), newRed,newGreen,newBlue,0, oldRed,oldGreen,oldBlue,0);
					FB.drawBox(box,250,250,250,0);
				} else if(key==66){ /*bawah*/
					oldPos=box.getMidPoint();
					oldRed = FB.getRed(oldPos.x, oldPos.y);
					oldGreen = FB.getGreen(oldPos.x, oldPos.y);
					oldBlue = FB.getBlue(oldPos.x, oldPos.y);
					FB.drawBox(box,oldRed,oldGreen,oldBlue,0);
					box.moveDown(boxStep,batasBawahPalet);
					newPos=box.getMidPoint();
					newRed = FB.getRed(newPos.x, newPos.y);
					newGreen = FB.getGreen(newPos.x, newPos.y);
					newBlue = FB.getBlue(newPos.x, newPos.y);
					//FB.drawPolygon(P,newRed,newGreen,newBlue,0);
					//FB.floodFillPolygon(P.getMidX(), P.getMidY(), newRed,newGreen,newBlue,0, oldRed,oldGreen,oldBlue,0);
					FB.drawBox(box,250,250,250,0);
				} else if(key==68){ /*kiri*/
					oldPos=box.getMidPoint();
					oldRed = FB.getRed(oldPos.x, oldPos.y);
					oldGreen = FB.getGreen(oldPos.x, oldPos.y);
					oldBlue = FB.getBlue(oldPos.x, oldPos.y);
					FB.drawBox(box,oldRed,oldGreen,oldBlue,0);
					box.moveLeft(boxStep,batasKiriPalet);
					newPos=box.getMidPoint();
					newRed = FB.getRed(newPos.x, newPos.y);
					newGreen = FB.getGreen(newPos.x, newPos.y);
					newBlue = FB.getBlue(newPos.x, newPos.y);
					//FB.drawPolygon(P,newRed,newGreen,newBlue,0);
					//FB.floodFillPolygon(P.getMidX(), P.getMidY(), newRed,newGreen,newBlue,0, oldRed,oldGreen,oldBlue,0);
					FB.drawBox(box,250,250,250,0);
				} else if(key==67){ /*kanan*/
					oldPos=box.getMidPoint();
					oldRed = FB.getRed(oldPos.x, oldPos.y);
					oldGreen = FB.getGreen(oldPos.x, oldPos.y);
					oldBlue = FB.getBlue(oldPos.x, oldPos.y);
					FB.drawBox(box,oldRed,oldGreen,oldBlue,0);
					box.moveRight(boxStep,batasKananPalet);
					newPos=box.getMidPoint();
					newRed = FB.getRed(newPos.x, newPos.y);
					newGreen = FB.getGreen(newPos.x, newPos.y);
					newBlue = FB.getBlue(newPos.x, newPos.y);
					//FB.drawPolygon(P,newRed,newGreen,newBlue,0);
					//FB.floodFillPolygon(P.getMidX(), P.getMidY(), newRed,newGreen,newBlue,0, oldRed,oldGreen,oldBlue,0);
					FB.drawBox(box,250,250,250,0);
				} else if(key==10){
					isPicked=true;
				}
			}
		}

		boxPos=box.getMidPoint();
		polygonCol.red = FB.getRed(boxPos.x, boxPos.y);
		polygonCol.green = FB.getGreen(boxPos.x, boxPos.y);
		polygonCol.blue = FB.getBlue(boxPos.x, boxPos.y);
		polygonCol.trans = FB.getTransparent(boxPos.x, boxPos.y);

		// cout << endl << endl << ">" << polygonCol.red << "." << polygonCol.green << "." << polygonCol.blue << "." << polygonCol.trans << endl;
		//FB.floodFillPolygon(pesawatSample.getMidX, pesawatSample.getMidY, pesawatRed, pesawatGreen, pesawatBlue, pesawatTransparent, 0,0,0,0);
		return polygonCol;
}

int main()
{
	
=======

using namespace std;

int main()
{
	FrameBuffer FB;
>>>>>>> dee2d0843cb129d6123aaf066d8dc96ca3a07af9
	int input = 0;
	int num_dot, radius;
	FILE *fmouse;
	char b[3];
<<<<<<< HEAD
=======
	fmouse = fopen("/dev/input/mice","r");
>>>>>>> dee2d0843cb129d6123aaf066d8dc96ca3a07af9

	while(input!=999) {
		while(input!=1 && input!=2 && input!=3 && input!=999) {
			system("clear");
			cout << "1. Draw Triangle" << endl;
			cout << "2. Draw Rectangle" << endl;
			cout << "3. Draw Circle" << endl;
			cout << "Input : ";
			cin >> input;	
		}
<<<<<<< HEAD
		
		Color temp1;		
		showColorPicker();
		FB.drawBox(box,255,255,255,0);
		
		fmouse = fopen("/dev/input/mice","r");
		
=======

>>>>>>> dee2d0843cb129d6123aaf066d8dc96ca3a07af9
		if(input==999) {
			exit(0);
		} else if(input==1) {
			num_dot = 3;
<<<<<<< HEAD
			getchar();
			temp1 = pickPolygonColor();
		} else if(input==2) {
			num_dot = 4;
			getchar();
			temp1 = pickPolygonColor();
		} else if(input==3) {
			num_dot = 1;
			getchar();
			temp1 = pickPolygonColor();
=======
		} else if(input==2) {
			num_dot = 4;
		} else if(input==3) {
			num_dot = 1;
>>>>>>> dee2d0843cb129d6123aaf066d8dc96ca3a07af9
			cout << "Masukkan radius : ";
			cin >> radius;
		}

<<<<<<< HEAD
		FB.drawSquare(Point(0,0), Point(799,599),0,0,0,0);
=======
>>>>>>> dee2d0843cb129d6123aaf066d8dc96ca3a07af9
		Polygon cursor ("mouse");
		FB.drawPolygon(cursor, 0,255,100,0);

		vector<Point> listOfPoints;
		while(listOfPoints.size() < num_dot){
			fread(b,sizeof(char),3,fmouse);
			
			int xd=0,yd=0; //x/y movement delta
			int xo=0,yo=0; //x/y overflow (out of range -255 to +255)
			int lb=0,mb=0,rb=0,hs=0,vs=0; //left/middle/right mousebutton
			int run=0;

			lb=(b[0]&1)>0;
			rb=(b[0]&2)>0;
			mb=(b[0]&4)>0;
			hs=(b[0]&16)>0;
			vs=(b[0]&32)>0;
			xo=(b[0]&64)>0;
			yo=(b[0]&128)>0;
			xd=b[1];
			yd=b[2];

			FB.drawPolygon(cursor, 0,0,0,0);

			if(xd < 0) {
				if(cursor.getMinX() > 10) {
					cursor.moveRight(xd);	
				}
			} else {
				if(cursor.getMaxX() < 789) {
					cursor.moveRight(xd);	
				}
			}
			if(yd < 0) {
				if(cursor.getMaxY() < 589) {
					cursor.moveUp(yd);	
				}
			} else {
				if(cursor.getMinY() > 10) {
					cursor.moveUp(yd);	
				}
			}

			FB.drawPolygon(cursor, 0,255,100,0);
			
	        if((b[0]&1)>0) {
				FB.drawSquare(Point(cursor.getMinX()-1, cursor.getMinY()-1), Point(cursor.getMinX()+1, cursor.getMinY()+1), 0, 255, 100, 0);
				listOfPoints.push_back(Point(cursor.getMinX(), cursor.getMinY()));
			}

			if(listOfPoints.size()>0) {
				Point src(listOfPoints[listOfPoints.size()-1].x, listOfPoints[listOfPoints.size()-1].y);
				Point dest(Point(cursor.getMinX(), cursor.getMinY()));
				
				FB.drawThickLine(Point(src.x, src.y), Point(dest.x, dest.y), 0, 0, 0, 0);
				
				FB.drawLine(src, Point(cursor.getMinX(), cursor.getMinY()), 255, 0, 0, 0);
			}
		}
		
		Polygon temp(listOfPoints);
		if(input!=3) {
<<<<<<< HEAD
			FB.scanLinePolygon(temp, temp1.red, temp1.green, temp1.blue, temp1.trans);	
		} else {
			FB.drawFilledCircle(Circle(temp.e[0], radius), temp1.red, temp1.green, temp1.blue, temp1.trans);
		}
		
		getchar();
=======
			FB.scanLinePolygon(temp, 255, 0, 0, 0);	
		} else {
			FB.drawFilledCircle(Circle(temp.e[0], radius), 255, 0, 0, 0);
		}
		
		getchar();
		getchar();
>>>>>>> dee2d0843cb129d6123aaf066d8dc96ca3a07af9
		input = 0;
	}

	fclose(fmouse);
	return 0; 

}
