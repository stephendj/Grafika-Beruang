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

using namespace std;

int main()
{
	FrameBuffer FB;
	int input = 0;
	int num_dot, radius;
	FILE *fmouse;
	char b[3];
	fmouse = fopen("/dev/input/mice","r");

	while(input!=999) {
		while(input!=1 && input!=2 && input!=3 && input!=999) {
			system("clear");
			cout << "1. Draw Triangle" << endl;
			cout << "2. Draw Rectangle" << endl;
			cout << "3. Draw Circle" << endl;
			cout << "Input : ";
			cin >> input;	
		}

		if(input==999) {
			exit(0);
		} else if(input==1) {
			num_dot = 3;
		} else if(input==2) {
			num_dot = 4;
		} else if(input==3) {
			num_dot = 1;
			cout << "Masukkan radius : ";
			cin >> radius;
		}

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
			FB.scanLinePolygon(temp, 255, 0, 0, 0);	
		} else {
			FB.drawFilledCircle(Circle(temp.e[0], radius), 255, 0, 0, 0);
		}
		
		getchar();
		getchar();
		input = 0;
	}

	fclose(fmouse);
	return 0; 

}
