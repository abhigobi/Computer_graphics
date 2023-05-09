# include <stdio.h>
#include <stdlib.h>
# include <GL/glut.h>

int x1,y1,x2,y2;

void drawpixel(int x , int y)
{
    glColor3f(1.0,0.0,0.0);
    glPointSize(3);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void dda( int x1,int y1,int x2,int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
   
    int k;
   
    if(abs(dx) > abs(dy))
    {
        k = abs(dx);
    }
    else
    {
        k = abs(dy);
    }
   
    int Dx = dx/k;
    int Dy = dy/k;
   
    int x = x1 , y =y1;
    drawpixel(x,y);
   
    while(x<x2 || y<y2)
    {
      x = x + Dx;
      y = y + Dy;
      drawpixel(x,y);
    }

};

void display()
{
  glClear(GL_COLOR_BUFFER_BIT); //Refresh the window before any execution  
  dda(x1,y1,x2,y2);
  glFlush();                    // it will ensure all the commands before it are executed properly
}


void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION); // important step to setup opengl rendering pipeline and correctly specifying projection of scene of  
                            // onto 2D viewport
glLoadIdentity();             // used to replace current matrix with identity matrix.
gluOrtho2D(0.0,500.0,0.0,500.0); // necessary for correctly projecting 3D object on 2D view port

}

int main(int argc , char** argv)
{

  printf("Enter value of x1 : ");
  scanf("%d" , &x1);
  printf("Enter value of y1 : ");
  scanf("%d" , &y1);
  printf("Enter value of x2 : ");
  scanf("%d" , &x2);
  printf("Enter value of y2 : ");
  scanf("%d" , &y2);
 
  glutInit(&argc,argv);                         //initialize the glut library,we need to pass pointers of both so we use & in first
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //arguments are nothing but he flags,RGB is color model
  glutInitWindowSize(500,500);                  //initialize the initial window position
  glutInitWindowPosition(0,0);                  //initialize the initial window position
  glutCreateWindow("DDA");                      //Actual function used to create the window,takes the parameter to name the window
 
 
  init();
 
  glutDisplayFunc(display);
  glutMainLoop();                                //for continously running of the program otherwise window will shutdown quickly
   
 
}
