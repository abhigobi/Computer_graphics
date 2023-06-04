#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#define R (3.14/180)

int n;

void koch(float xa ,float ya,float xb,float yb,int n)
{
    float xc,yc,xd,yd,midx,midy;
    
    xc=(2*xa+xb)/3;
    yc=(2*ya+yb)/3;
    xd=(2*xb+xa)/3;
    yd=(2*yb+ya)/3;
    
    midx=xc +((xd-xc)*cos(60*R))+((yd-yc)*sin(60*R));
    midy=yc -((xd-xc)*sin(60*R))+((yd-yc)*cos(60*R));
    
    if(n>0)
    {
        koch(xa,ya,xc,yc,n-1);
        koch(xc,yc,midx,midy,n-1);
        koch(midx,midy,xd,yd,n-1);
        koch(xd,yd,xb,yb,n-1);
    }
    else
    {
        glVertex2f(xa,ya);
        glVertex2f(xc,yc);
        
        glVertex2f(xc,yc);
        glVertex2f(midx,midy);
        
        glVertex2f(midx,midy);
        glVertex2f(xd,yd);
        
        glVertex2f(xd,yd);
        glVertex2f(xb,yb); 
    }
  }  
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    koch(600,100,800,400,n);
    koch(800,400,400,400,n);
    koch(400,400,600,100,n);
    glEnd();
    glFlush();
}


int main(int argc,char** argv)
{
    printf("Enter the number of iterations");
    scanf("%d",&n);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Koch");
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(0,1000,0,10z00);
    glutDisplayFunc(draw);
    
    glutMainLoop();
    return 0;
}
