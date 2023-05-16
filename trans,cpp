#include<iostream>
#include<GL/glut.h>
#include<vector>
#include<math.h>
using namespace std;

int pntX1 , pntY1;
vector<int> pntX;
vector<int> pntY;
int transX , transY;
double scaleX,scaleY;
double angle,angleRad;
int edges;

void drawpolygon()
{
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,0.0,0.0);
    glPointSize(4);
    for(int i=0;i<edges;i++)
    {
      glVertex2i(pntX[i],pntY[i]);
    }
    glEnd();
}

void drawpolygontrans(int x,int y)
{
     glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,1.0);
    glPointSize(4);
    for(int i=0;i<edges;i++)
    {
      glVertex2i(pntX[i] + x, pntY[i] + y);
    }
    glEnd();
}

void drawpolygonscale(double x , double y)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,1.0);
     glPointSize(4);
    for(int i=0;i<edges;i++)
    {
      glVertex2i(pntX[i] * x, pntY[i] * y);
    }
    glEnd();
}

void drawpolygonrotate(double angle)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,1.0);
     glPointSize(4);
    for(int i=0;i<edges;i++)
    {
      glVertex2d((pntX[i] * cos(angleRad))- (pntY[i]* sin(angleRad))), ((pntX[i] *sin(angleRad)) + (pntY[i] * cos(angleRad)));
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    drawpolygon();
    //drawpolygontrans(transX,transY);
    //drawpolygonscale(scaleX,scaleY);
    drawpolygonrotate(angleRad);
    glFlush();
}
void init()
{
  glClearColor(0.0,0.0,0.0,0.0);
  glPointSize(4);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,500,0,500);
}

int main(int argc , char** argv)
{

    cout <<"Enter the Number of edges";
    cin>>edges;
   
    for(int i=0;i<edges;i++)
    {
        cout<<"Now enter the co-ordinates";
        cin>>pntX1;
        cin>>pntY1;
       
        pntX.push_back(pntX1);
        pntY.push_back(pntY1);
    }
   
   /* cout<<"Enter the translation factor";
    cin>>transX;
    cin>>transY;
    */
   /* cout<<"Enter scaling factor";
    cin>>scaleX;
    cin>>scaleY;
    */
   
    cout <<"Enter the angle for rotation";
    cin>>angle;
    angleRad = angle * (3.1416/180);
   
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Transformation");
   
    init();
   
    glutDisplayFunc(display);
    glutMainLoop();

}f
