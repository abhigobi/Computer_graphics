#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;
int xc,yc,r;
int xa,ya,xb,yb;
int Round(float a){
return (int)(a+0.5);
}
void B_circle(int xc,int yc,int r)
{

int x=0;
int y=r;
int d=3-(2*r);

do{
/*glVertex2d(x+xc+320,y+yc+240);
glVertex2d(y+xc+320,x+yc+240);
glVertex2d(-x+xc+320,y+yc+240);
glVertex2d(x+xc+320,-y+yc+240);
glVertex2d(-y+xc+320,x+yc+240);
glVertex2d(y+xc+320,-x+yc+240);
glVertex2d(-x+xc+320,-y+yc+240);
glVertex2d(-y+xc+320,-x+yc+240);*/

glVertex2d(x+xc,y+yc);
glVertex2d(y+xc,x+yc);
glVertex2d(-x+xc,y+yc);
glVertex2d(x+xc,-y+yc);
glVertex2d(-y+xc,x+yc);
glVertex2d(y+xc,-x+yc);
glVertex2d(-x+xc,-y+yc);
glVertex2d(-y+xc,-x+yc);

if(d<0){
x++;
d+=4*x+6;
}else{
x++;
y--;
d+=4*(x-y)+10;

}

}while(y>=x);

}

void dda(int xa,int ya,int xb,int yb){
int dx=xb-xa;
int dy=yb-ya;

int p;
if(abs(dx)>abs(dy)){
p=dx;
}else{
p=dy;
}
float delx,dely;
delx=dx/(float)(p);
dely=dy/(float)(p);

float x=xa;
float y=ya;
glVertex2d(Round(x),Round(y));
for(int i=0;i<p;i++){
x+=delx;
y+=dely;
glVertex2d(Round(x),Round(y));
}
}
void myMouse(int button,int state,int x,int y){
y=480-y;
if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
xc=x;
yc=y;

glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
B_circle(xc,yc,r);
glEnd();
glFlush();
}
}
void draw(){
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
dda(0,240,640,240);
dda(320,0,320,480);
//B_circle(xc,yc,r);
glEnd();
glFlush();
}
int main(int argc,char** argv){

/*cout<<"Enter the value of x1 and y1";
cin>>xc>>yc;*/
cout<<"Enter the value of r";
cin>>r;
//cout<<"Enter the choice : "<<endl;
//cin>>choice;
glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitWindowPosition(0,0);
glutCreateWindow("Bresenhams Circle");
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
gluOrtho2D(0,640,0,480);
glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
glutDisplayFunc(draw);
glutMouseFunc(myMouse);
glutMainLoop();
return 0;
}
