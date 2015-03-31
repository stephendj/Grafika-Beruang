#include "Line.hpp"
#include "Cuboid.hpp"
#include "HiddenLine.hpp"

class FrameBuffer {
public:
	FrameBuffer() {
		fbfd = open("/dev/fb0", O_RDWR);
		if (!fbfd) {
			printf("Error: cannot open framebuffer device.\n");
			exit(1);
		}
		printf("The framebuffer device was opened successfully.\n");

		/* get the fixed screen information */
		if (ioctl (fbfd, FBIOGET_FSCREENINFO, &finfo)) {
			printf("Error reading fixed information.\n");
			exit(2);
		}

		/* get variable screen information */
		if (ioctl (fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
			printf("Error reading variable information.\n");
			exit(3);
		}

		/* map the device to memory */
		fbp = (char*) mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);

		if ((int) fbp == -1) {
			printf("Error: failed to map framebuffer device to memory.\n");
			exit(4);
		}
		printf("Framebuffer device was mapped to memory successfully.\n");
	}

	~FrameBuffer() {
		munmap(fbp, 0);
		close(fbfd);
	}

	void putPixel(Point P, int r, int g, int b, int t) {
		int location = P.x * 4 + P.y * finfo.line_length;
		*(fbp + location) = b;		// blue 
		*(fbp + location + 1) = g;	// green
		*(fbp + location + 2) = r;	// red
		*(fbp + location + 3) = t;	// transparency
	}

	void drawLine(Line l) {
		int dx =  abs(l.dest.x-l.src.x), sx = l.src.x<l.dest.x ? 1 : -1;
		int dy = -abs(l.dest.y-l.src.y), sy = l.src.y<l.dest.y ? 1 : -1; 
		int err = dx+dy, e2; /* error value e_xy */
	 
		for(;;){ /* loop */
			Point Ptemp(l.src.x, l.src.y);
			putPixel(Ptemp, l.r, l.g, l.b, l.t);

			if (l.src.x==l.dest.x && l.src.y==l.dest.y) break;
			e2 = 2*err;
			if (e2 >= dy) { err += dy; l.src.x += sx; } /* e_xy+e_x > 0 */
			if (e2 <= dx) { err += dx; l.src.y += sy; } /* e_xy+e_y < 0 */
		}
	}

	void drawLinePrimitive(int x1, int y1, int x2, int y2, int r, int g, int b, int t) {
		int dx =  abs(x2-x1), sx = x1<x2 ? 1 : -1;
		int dy = -abs(y2-y1), sy = y1<y2 ? 1 : -1; 
		int err = dx+dy, e2; /* error value e_xy */
	 
		for(;;){ /* loop */
			Point P(x1,y1);
			putPixel(P,r,g,b,t);
			if (x1==x2 && y1==y2) break;
			e2 = 2*err;
			if (e2 >= dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
			if (e2 <= dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
		}
	}

	void drawDash(Point P1, Point P2, int r, int g, int b, int t) {
		int dx =  abs(P2.x-P1.x), sx = P1.x<P2.x ? 1 : -1;
		int dy = -abs(P2.y-P1.y), sy = P1.y<P2.y ? 1 : -1; 
		int err = dx+dy, e2; /* error value e_xy */
		int jeda,a;

		jeda=30;
		a=0;

		for(;;){ /* loop */
			if(a>5) {
				Point Ptemp(P1.x,P1.y);
				putPixel(Ptemp,r,g,b,t);
			} else if(a>0) {
				a-=1;
			} else {
				a = jeda;
				jeda-=5;
			}

			if (P1.x==P2.x && P1.y==P2.y) break;
			e2 = 2*err;
			if (e2 >= dy) { err += dy; P1.x += sx; } /* e_xy+e_x > 0 */
			if (e2 <= dx) { err += dx; P1.y += sy; } /* e_xy+e_y < 0 */
		}	
	}

	void drawCuboid(Cuboid c, Point p0, int r, int g, int b, int t) {
		// perspective projection
		// http://web.iitd.ac.in/~hegde/cad/lecture/L9_persproj.pdf
		vector<Point> points;

		for (int i=0; i<c.p.size(); ++i) {
			double xp = (double) (c.p[i].x*p0.z-c.p[i].z*p0.x)/(p0.z-c.p[i].z);
			double yp = (double) (c.p[i].y*p0.z-c.p[i].z*p0.y)/(p0.z-c.p[i].z);
			points.push_back(Point(xp, yp, 0));
		}

		// Hidden Line Algorithm
		// vector<Point> frontsquare;
		// frontsquare.push_back(points[0]);
		// frontsquare.push_back(points[1]);
		// frontsquare.push_back(points[5]);
		// frontsquare.push_back(points[4]);
		// frontsquare.push_back(points[0]);
		// HiddenLine hl(frontsquare);

		vector<Line> lines;
		// lines.push_back(Line(points[0],points[3]));
		// lines.push_back(Line(points[1],points[2]));
		// lines.push_back(Line(points[3],points[7]));
		// lines.push_back(Line(points[3],points[2]));
		// lines.push_back(Line(points[4],points[7]));
		// lines.push_back(Line(points[5],points[6]));
		// lines.push_back(Line(points[2],points[6]));
		// lines.push_back(Line(points[7],points[6]));
		
		// for(int i=0;i<8;i++) {
		// 	hl.l_awal = lines[i];
		// 	hl.computeLine(lines[i]);
		// }

		// // Draw all lines

		// hl.L.push_back(Line(points[0], points[1]));
		// hl.L.push_back(Line(points[0], points[4]));
		// hl.L.push_back(Line(points[1], points[5]));
		// hl.L.push_back(Line(points[4], points[5]));
		
		// for(int i=0; i<hl.L.size(); i++) {
		// 	if(hl.L[i].r==0 && hl.L[i].g==0 && hl.L[i].b==0 && hl.L[i].t==0) {
		// 		// Do nothing
		// 	} else {
		// 		hl.L[i].setRGBT(r,g,b,t);
		// 	}
		// 	drawLine(hl.L[i]);
		// }

		lines.push_back(Line(points[0],points[3]));
		lines.push_back(Line(points[1],points[2]));
		lines.push_back(Line(points[3],points[7]));
		lines.push_back(Line(points[3],points[2]));
		lines.push_back(Line(points[4],points[7]));
		lines.push_back(Line(points[5],points[6]));
		lines.push_back(Line(points[2],points[6]));
		lines.push_back(Line(points[7],points[6]));
		lines.push_back(Line(points[0], points[1]));
		lines.push_back(Line(points[0], points[4]));
		lines.push_back(Line(points[1], points[5]));
		lines.push_back(Line(points[4], points[5]));

		for(int i=0; i<lines.size(); i++) {
			lines[i].setRGBT(r, g, b, t);
			drawLine(lines[i]);
		}
	}

	int getBlue(int x, int y) {
		int blue;
		int rumus = x * 4 + y * finfo.line_length;
		blue = *(fbp + rumus); if(blue<0){blue+=256;}
		return blue;
	}

	int getGreen(int x, int y) {
		int green;
		int rumus = x * 4 + y * finfo.line_length;
		green = *(fbp + rumus + 1); if(green<0){green+=256;}	
		return green;	
	}

	int getRed(int x, int y) {
		int red;
		int rumus = x * 4 + y * finfo.line_length;
		red = *(fbp + rumus + 2); if(red<0){red+=256;}
		return red;
	}		

	int getTransparent(int x, int y) {
		int trns;
		int rumus = x * 4 + y * finfo.line_length;
		trns = *(fbp + rumus + 3); if(trns<0){trns+=256;}
		return trns;
	}

	char* getfbp() {
		return fbp;
	}

	int getfbfd() {
		return fbfd;
	}

	fb_fix_screeninfo getfinfo() {
		return finfo;
	}

	fb_var_screeninfo getvinfo() {
		return vinfo;
	}

private:
	char* fbp;
	int fbfd;	/* frame buffer file descriptor */
	struct fb_fix_screeninfo finfo;
	struct fb_var_screeninfo vinfo;
};
