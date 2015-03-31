#include "FrameBuffer.cpp"

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

int main() {
	FrameBuffer fb;
	int k, x=400, y=300;
	Cuboid c(Point(380,280,90), 40, 40, 40);

	fb.drawCuboid(c, Point(x,y,200), 255, 0, 0, 0);
	string input = "";

	while(!input.equals("exit") == 0) {
		if (kbhit()) {
			k = getchar();
			if (k != 'q'){
				fb.drawCuboid(c, Point(x,y,200), 0, 0, 0, 0);
				if(k==65) { /*atas*/
					y-=4;
				} else if(k==66) { /*bawah*/
					y+=4;
				} else if(k==68) { /*kiri*/
					x-=4;
				} else if(k==67) { /*kanan*/
					x+=4;
				} 
				fb.drawCuboid(c, Point(x,y,200), 255, 0, 0, 0);
			}
			else {
				quit = true;
			}
		}
	}

	return 0;
}
