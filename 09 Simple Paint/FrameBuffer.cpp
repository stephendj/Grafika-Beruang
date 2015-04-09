#include "Line.hpp"
#include "Polygon.hpp"
#include "Circle.hpp"
#include "Box.hpp"


class FrameBuffer {
public:
	FrameBuffer() {
		fbfd = open("/dev/fb0",O_RDWR);
		if (!fbfd) {
			printf("Error: cannot open framebuffer device.\n");
			exit(1);
		}
		printf ("The framebuffer device was opened successfully.\n");

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
		fbp = (char*)mmap(0, finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);

		if ((int)fbp == -1) {
			printf ("Error: failed to map framebuffer device to memory.\n");
			exit(4);
		}
		printf ("Framebuffer device was mapped to memory successfully.\n");
	}

	~FrameBuffer() {
		munmap(fbp, 0);
		close(fbfd);
	}

	void putPixel(Point P, int r, int g, int b, int t) {
		int location = P.x * 4 + P.y * finfo.line_length;
		*(fbp + location) = b; // blue 
        *(fbp + location + 1) = g;  // green
        *(fbp + location + 2) = r; // red
        *(fbp + location + 3) = t; // transparency
	}

	void drawFilledCircle(Circle C, int r, int g, int b, int t) {
	  int x = C.r;
	  int y = 0;
	  int radiusError = 1-x;
	 
	  while(x >= y)
	  {
    	for (int it = -x; it <= x; ++it)
			putPixel(Point(it+C.P.x, y+C.P.y), r,g,b,t);
		for (int it = -y; it <= y; ++it)
			putPixel(Point(it+C.P.x, x+C.P.y), r,g,b,t);
		for (int it = -x; it <= x; ++it)
			putPixel(Point(it+C.P.x, -y+C.P.y), r,g,b,t);
		for (int it = -y; it <= y; ++it)
			putPixel(Point(it+C.P.x, -x+C.P.y), r,g,b,t);

	    y++;
	    if (radiusError<0)
	    {
	      radiusError += 2 * y + 1;
	    }
	    else
	    {
	      x--;
	      radiusError += 2 * (y - x) + 1;
	    }
	  }
	}

	void drawLine(Point P1, Point P2, int r, int g, int b, int t) {
		int dx =  abs(P2.x-P1.x), sx = P1.x<P2.x ? 1 : -1;
	   	int dy = -abs(P2.y-P1.y), sy = P1.y<P2.y ? 1 : -1; 
	   	int err = dx+dy, e2; /* error value e_xy */
	 
	   	for(;;){  /* loop */
	   		Point Ptemp(P1.x,P1.y);
	    	putPixel(Ptemp,r,g,b,t);

	      	if (P1.x==P2.x && P1.y==P2.y) break;
	      	e2 = 2*err;
	      	if (e2 >= dy) { err += dy; P1.x += sx; } /* e_xy+e_x > 0 */
	      	if (e2 <= dx) { err += dx; P1.y += sy; } /* e_xy+e_y < 0 */
	   	}
	}

	void drawThickLine(Point P1, Point P2, int r, int g, int b, int t) {
		int dx =  abs(P2.x-P1.x), sx = P1.x<P2.x ? 1 : -1;
	   	int dy = -abs(P2.y-P1.y), sy = P1.y<P2.y ? 1 : -1; 
	   	int err = dx+dy, e2; /* error value e_xy */
	 	
	 	float it=1;
	   	for(;;){  /* loop */
	   		Point Ptemp(P1.x,P1.y);

	    	drawFilledCircle(Circle(P1,it),r,g,b,t);
	    	it+=0.07;
	    	
	      	if (P1.x==P2.x && P1.y==P2.y) break;
	      	e2 = 2*err;
	      	if (e2 >= dy) { err += dy; P1.x += sx; } /* e_xy+e_x > 0 */
	      	if (e2 <= dx) { err += dx; P1.y += sy; } /* e_xy+e_y < 0 */
	   	}
	}

	void drawDash(Point P1, Point P2, int r, int g, int b, int t) {
		int dx =  abs(P2.x-P1.x), sx = P1.x<P2.x ? 1 : -1;
	   	int dy = -abs(P2.y-P1.y), sy = P1.y<P2.y ? 1 : -1; 
	   	int err = dx+dy, e2; /* error value e_xy */
	 	int jeda,a;

	 	jeda=30;
	 	a=0;

	 	for(;;){  /* loop */
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

	void drawLinePrimitive(int x1, int y1, int x2, int y2, int r, int g, int b, int t) {
		int dx =  abs(x2-x1), sx = x1<x2 ? 1 : -1;
	   	int dy = -abs(y2-y1), sy = y1<y2 ? 1 : -1; 
	   	int err = dx+dy, e2; /* error value e_xy */
	 
	   	for(;;){  /* loop */
	   		Point P(x1,y1);
	    	putPixel(P,r,g,b,t);
	      	if (x1==x2 && y1==y2) break;
	      	e2 = 2*err;
	      	if (e2 >= dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
	      	if (e2 <= dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
	   	}
	}

	void drawPolygon(Polygon P, int r, int g, int b, int t) {
		for (int i=1; i<P.n; ++i) {
			drawLine(P.e[i-1], P.e[i], r, g, b, t);
		}
	}

	/*void drawPolygon3D(Polygon3D P3d, int r, int g, int b, int t){
		drawPolygon(P3d.atas,r,g,b,t);
		drawPolygon(P3d.bawah,r,g,b,t);
		for(int i=0; i<P3d.P.size(); i++){
			drawPolygon(P3d.P[i],r,g,b,t);
		}
		for(int i=0; i<P3d.L.size(); i++){
			drawLine(P3d.L[i].src, P3d.L[i].dest, 255, 255, 255, 0);
		}
	}*/

/*	void drawPolygonsUsingPainter(vector<Polygon3D> ps) {
		// bubble sort
		for (int i=0; i<ps.size()-1; ++i) {
			for (int j=i+1; j<ps.size(); ++j) {
				Polygon3D temp;
				if (ps[i].bawah.e[0].z > ps[j].bawah.e[0].z) {
					temp = ps[i];
					ps[i] = ps[j];
					ps[j] = temp;
				}
			}
		}

		for (int i=0; i<ps.size(); ++i) {
			drawPolygon3D(ps[i], ps[i].bawah.r, ps[i].bawah.g, ps[i].bawah.b, ps[i].bawah.t);
			scanLinePolygon(ps[i].bawah, ps[i].bawah.r, ps[i].bawah.g, ps[i].bawah.b, ps[i].bawah.t);
			for(int j=0; j<ps[i].L.size(); j++) {
				drawLine(ps[i].L[j].src, ps[i].L[j].dest, 0, 0, 0, 0);
			}
			for(int j=0; j<ps[i].P.size(); j++) {
				scanLinePolygon(ps[i].P[j], 100, 100, 100, 0);
			}
			scanLinePolygon(ps[i].atas, ps[i].atas.r, ps[i].atas.g, ps[i].atas.b, ps[i].atas.t);
		}
	}*/

/*
	void drawBaling(Baling baling, int r, int g, int b, int t) {
		drawPolygon(baling.baling1,r,g,b,t);
		drawPolygon(baling.baling2,r,g,b,t);
		drawPolygon(baling.baling3,r,g,b,t);
		DrawCircle(baling.poros.P.x,baling.poros.P.y,baling.poros.r,r,g,b,t);
	}*/

	void drawSquare(Point P1, Point P2, int r, int g, int b, int t) {
		for(int i=P1.x;i<=P2.x;i++) {
			for(int j=P1.y;j<=P2.y;j++) {
				Point temp(i,j);
				putPixel(temp,r,g,b,t);
			}
		}
	}

	void DrawCircle(int x0, int y0, int radius, int r, int g, int b, int t)
	{
	  int x = radius;
	  int y = 0;
	  int radiusError = 1-x;
	 
	  while(x >= y)
	  {
	    putPixel(Point(x + x0, y + y0), r,g,b,t);
	    putPixel(Point(y + x0, x + y0), r,g,b,t);
	    putPixel(Point(-x + x0, y + y0), r,g,b,t);
	    putPixel(Point(-y + x0, x + y0), r,g,b,t);
	    putPixel(Point(-x + x0, -y + y0), r,g,b,t);
	    putPixel(Point(-y + x0, -x + y0), r,g,b,t);
	    putPixel(Point(x + x0, -y + y0), r,g,b,t);
	    putPixel(Point(y + x0, -x + y0), r,g,b,t);
	    y++;
	    if (radiusError<0)
	    {
	      radiusError += 2 * y + 1;
	    }
	    else
	    {
	      x--;
	      radiusError += 2 * (y - x) + 1;
	    }
	  }
	}
	
/*	void drawBalloon(Balloon balloon, int r, int g, int b, int t) {
		drawLine(balloon.l[0].src, balloon.l[0].dest, r, g, b, t);
		drawLine(balloon.l[1].src, balloon.l[1].dest, r, g, b, t);
		//drawFilledCircle(balloon.c, r, g, b, t);
		drawPolygon(balloon.cp, r, g, b, t);
		drawPolygon(balloon.p, r, g, b, t);
		scanLinePolygon(balloon.p, r, g, b, t);
	}

	bool isShot(int x, int y, Helikopter p) {
		int maxX = p.getBodyMaxX();
		int maxY = p.getBodyMaxY();
		int minX = p.getBodyMinX();
		int minY = p.getBodyMinY();

		if(x>minX && x<maxX && y>minY && y<maxY) {
			return true;
		} else {
			return false;
		}
	}*/

	void scanLinePolygon(Polygon polygon, int r, int g, int b, int t) {
		int x,y;
		int n = polygon.n-1;

		
		//Process
		float slope[n];
		int line[n];
		for (int i=0; i<n; ++i) {
			int dx = polygon.e[i+1].x - polygon.e[i].x;
			int dy = polygon.e[i+1].y - polygon.e[i].y;

			if (dy == 0) slope[i] = 1;
			if (dx == 0) slope[i] = 0;

			//Calculate inverse slope
			if (dx != 0 && dy != 0) {
				slope[i] = (float) dx/dy;
			}
		}

		vector<Line> lines;
		for (int y=0; y<600; ++y) {
			int k = 0;
			// Cari titik perpotongan
			for (int i=0; i<n; ++i) {
				if (polygon.e[i].y <= y && polygon.e[i+1].y > y || 
					polygon.e[i+1].y <= y && polygon.e[i].y > y) {
					line[k] = (int) (polygon.e[i].x + slope[i] * (y - polygon.e[i].y));
					++k;
				}
			}

			// Arrange x-intersections in order
			for (int j=0; j<k-1; ++j) {
				for (int i=0; i<k-1; ++i) {
					if (line[i] > line[i+1]) {
						int temp = line[i];
						line[i] = line[i+1];
						line[i+1] = temp;
					}
				}
			}

			for (int i=0; i<k; i+=2) {
				drawLine(Point(line[i], y), Point(line[i+1], y), r, g, b, t);
			}
		}
		//Draw polygon
		drawPolygon(polygon, r, g, b, t);

	}

	int getBlue(int x, int y){
		int blue;
		int rumus = x * 4 + y * finfo.line_length;
		blue = *(fbp + rumus); if(blue<0){blue+=256;}
		return blue;
	}
	int getGreen(int x, int y){
		int green;
		int rumus = x * 4 + y * finfo.line_length;
		green = *(fbp + rumus + 1); if(green<0){green+=256;}	
		return green;	
	}	
	int getRed(int x, int y){
		int red;
		int rumus = x * 4 + y * finfo.line_length;
		red = *(fbp + rumus + 2); if(red<0){red+=256;}
		return red;
	}		
		
	int getTransparent(int x, int y){
		int trns;
		int rumus = x * 4 + y * finfo.line_length;
		trns = *(fbp + rumus + 3); if(trns<0){trns+=256;}
		return trns;
	}

	void floodFillPolygon(int x, int y, int r_new, int g_new, int b_new, int t_new, int r_old, int g_old, int b_old, int t_old){
		int r=getRed(x,y);
		int g=getGreen(x,y);
		int b=getBlue(x,y);
		int t=getTransparent(x,y);
		if (r==r_old && g==g_old && b==b_old && t==t_old){
			putPixel(Point(x,y),r_new,g_new,b_new,t_new);
			floodFillPolygon(x-1,y,r_new,g_new,b_new,t_new,r_old,g_old,b_old,t_old);
			floodFillPolygon(x,y-1,r_new,g_new,b_new,t_new,r_old,g_old,b_old,t_old);
			floodFillPolygon(x+1,y,r_new,g_new,b_new,t_new,r_old,g_old,b_old,t_old);
			floodFillPolygon(x,y+1,r_new,g_new,b_new,t_new,r_old,g_old,b_old,t_old);
		}
	}

/*	void drawPatternedPolygon(int x, int y, Pattern pattern, int pa_r, int pa_g, int pa_b, int pa_t, int po_r, int po_g, int po_b, int po_t) {
		//drawPolygon(polygon,po_r,po_g,po_b,po_t);
		Point mid(x%15,y%15);
		if(pattern.M[mid.y][mid.x]==1) {
			int r=getRed(x,y);
			int g=getGreen(x,y);
			int b=getBlue(x,y);
			int t=getTransparent(x,y);
			if (r==0 && g==0 && b==0 && t==0){
				putPixel(Point(x,y),pa_r,pa_g,pa_b,pa_t);
				drawPatternedPolygon(x-1,y,pattern,pa_r,pa_g,pa_b,pa_t,po_r,po_g,po_b,po_t);
				drawPatternedPolygon(x,y-1,pattern,pa_r,pa_g,pa_b,pa_t,po_r,po_g,po_b,po_t);
				drawPatternedPolygon(x+1,y,pattern,pa_r,pa_g,pa_b,pa_t,po_r,po_g,po_b,po_t);
				drawPatternedPolygon(x,y+1,pattern,pa_r,pa_g,pa_b,pa_t,po_r,po_g,po_b,po_t);
			}
		} else if(pattern.M[mid.y][mid.x]==0) {
			int r=getRed(x,y);
			int g=getGreen(x,y);
			int b=getBlue(x,y);
			int t=getTransparent(x,y);
			if (r==0 && g==0 && b==0 && t==0){
				putPixel(Point(x,y),po_r,po_g,po_b,po_t);
				drawPatternedPolygon(x-1,y,pattern,pa_r,pa_g,pa_b,pa_t,po_r,po_g,po_b,po_t);
				drawPatternedPolygon(x,y-1,pattern,pa_r,pa_g,pa_b,pa_t,po_r,po_g,po_b,po_t);
				drawPatternedPolygon(x+1,y,pattern,pa_r,pa_g,pa_b,pa_t,po_r,po_g,po_b,po_t);
				drawPatternedPolygon(x,y+1,pattern,pa_r,pa_g,pa_b,pa_t,po_r,po_g,po_b,po_t);
			}
		}
	}

	void drawHelikopter(Helikopter H,int r,int g,int b,int t) {
		drawPolygon(H.head,r,g,b,t);
		drawPolygon(H.tail,r,g,b,t);
		drawBaling(H.baling,r,g,b,t);
	}

	void drawView(View V, int r, int g, int b, int t) {
		if(!V.L.empty()) {
			for(int i=0 ;i<V.L.size(); i++) {
				drawLine(V.L[i].src,V.L[i].dest,r,g,b,t);
			}	
		}
	}

	void drawWindow(Window w, int r, int g, int b, int t){
		drawPolygon(w.square,r,g,b,t);
<<<<<<< HEAD
	}*/
	//warnain box colorpicker
	
	void drawBox(Box box, int r, int g, int b, int t){
		drawPolygon(box.square,r,g,b,t);
	}

	fb_var_screeninfo getvinfo() {
		return vinfo;
	}

	fb_fix_screeninfo getfinfo() {
		return finfo;
	}

	int getfbfd() {
		return fbfd;
	}

	char* getfbp() {
		return fbp;
	}

private:
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	int fbfd;					/* frame buffer file descriptor */
	char* fbp;
};
