
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
using namespace std;


class Point
{
    public:
        Point(){}
        Point(int _x, int _y)
        {
            x=_x;
            y=_y;
        }
    public:
        int x;
        int y;
};

vector <Point> points;

// Window/viewport
const int startwinsize = 480; // Starting window width & height, in pixels
int winw, winh;

// Mouse
bool mouseleftdown = false;   // True if mouse LEFT button is down.
                              // Saved by mouse.
int mousex, mousey;           // Mouse x,y coords, in GLUT format (pixels from upper-left corner).
                              // Only guaranteed to be valid if a mouse button is down.
                              // Saved by mouse, motion.              // Window width & height, in pixels, saved by reshape
// Other
const double pointsize = 10;  // Size of point

void myInit()
{
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0 , 0.0, 0.0);
    glPointSize(10.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 480, 0, 480);

}

void myDisplay()
{
    if (mouseleftdown)
    {
      // Convert mouse position to OpenGL's coordinate system
     // double oglx = double(mousex)/winw;
     // double ogly = 1-double(mousey)/winh;

      // Draw the box
      glColor3f(1.0, 0.0, 0.0);
      glPointSize(pointsize);


      //glBegin(GL_POINTS);
        // glVertex2d(oglx, ogly);
      //glEnd();

        //cout<<"----"<<endl;
      glBegin(GL_LINE_STRIP);
      for(unsigned int i=0; i<points.size();i++){
        double x = double(points.at(i).x)/winw;
        double y = 1-double(points.at(i).y)/winh;

        glVertex2d(x, y);
        //cout<<x<<" "<<y<<endl;

      }
      glEnd();
    }
    glutSwapBuffers();

}

// reshape
// The GLUT reshape function
void myReshape(int w, int h)
{
   // Set the viewport to be the entire drawing area of the window
   glViewport(0, 0, w, h);

   // Save the window size
   winw = w;
   winh = h;

   // Set up the projection
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, 1.0, 0.0, 1.0);

   glMatrixMode(GL_MODELVIEW);  // Always go back to model/view mode
}

void myMouse(int button, int state, int x, int y)
{
    // Save the left button state
   if (button == GLUT_LEFT_BUTTON)
   {
        mouseleftdown = (state == GLUT_DOWN);
        if(mouseleftdown){
            Point point(x,y);
            points.push_back(point);
            //cout<<"x: "<<x << " y: "<<y<<endl;
        }else{
            points.clear();
        }


        glutPostRedisplay();  // Left button has changed; redisplay!
   }
   else if (button == GLUT_RIGHT_BUTTON)
   {
        glClear(GL_COLOR_BUFFER_BIT);
        //glClearColor(1.0, 1.0, 1.0, 0.0);
   }

   // Save the mouse position
   mousex = x;
   mousey = y;
}


// motion
// The GLUT motion function

void myMotion(int x, int y)
{
   // We only do anything if the left button is down
   if (mouseleftdown)
   {
        Point point(x,y);
        points.push_back(point);
        //cout<<"--x: "<<x << " y: "<<y<<endl;
        glutPostRedisplay();
   }


   // Save the mouse position
   mousex = x;
   mousey = y;
}

void myKeyboard(unsigned char key, int mouseX, int mouseY)
{

    switch(key)
    {
        case 'e':
            exit(-1);
    }
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(480,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("FREEHAND TOOL");

    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKeyboard);
    glutMotionFunc(myMotion);
    myInit();

    glutMainLoop();
}



