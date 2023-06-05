#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define R (3.14/180)

float input[2][4];

int n;

void bezir()
{
    float dx,dy;
    for(float i=0;i<=1;i+=0.001)
    {
         dx = (1-i)*(1-i)*(1-i)*input[0][0] + 3*(1-i)*(1-i)*(i)*input[0][1] + 3*(1-i)*(i)*(i)*input[0][2] + (i)*(i)*(i)*input[0][3] ;
         dy = (1-i)*(1-i)*(1-i)*input[1][0] + 3*(1-i)*(1-i)*(i)*input[1][1] + 3*(1-i)*(i)*(i)*input[1][2] + (i)*(i)*(i)*input[1][3] ;
         glVertex2d(dx,dy);
    }
    
    
}

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
    
    glBegin(GL_POINTS);
    glPointSize(3);
    for(int j=0;j<4;j++)
    {
        glColor3f(1.0,0.0,0.0);
        glVertex2d(input[0][j],input[1][j]);
    }
    glColor3f(1.0,1.0,0.0);
    bezir();
    
    glEnd();
    printf("Hello");
    glFlush();
}


int main(int argc,char** argv)
{
    printf("Enter the four points");
    for(int i=0;i<4;i++){
    scanf("%f",&input[0][i]);
    scanf("%f",&input[1][i]);
    }
   /* printf("Enter the number of iterations");
    scanf("%d",&n);*/
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Koch");
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(0,1000,0,1000);
    glutDisplayFunc(draw);
    
    glutMainLoop();
    return 0;
}
