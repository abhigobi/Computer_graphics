#include <GL/gl.h>   //opengl library
#include <GL/glu.h>  //
#include <GL/glut.h> //above two library are already present in the glut library.

void display();
void init()
{
  glClearColor(1.0,1.0,0.0,1.0);                       //It takes four arguments 1)red,2)green,3)blue,4)alpha first three specify the color
}

int main(int argc ,char**argv)
{
    glutInit(&argc,argv);           //initialize the glut library,we need to pass pointers of both so we use & in first 
    
    glutInitDisplayMode(GLUT_RGB);   //arguments are nothing but he flags,RGB is color model

    glutInitWindowPosition(200,100);        //initialize the initial window position
    glutInitWindowSize(500,500);                //initialize the initial window size in width and height in px

    glutCreateWindow("Window 1");             //Actual function used to create the window,takes the parameter to name the window
    
    glutDisplayFunc(display);
    init();
    glutMainLoop();                        //for continously running of the program otherwise window will shutdown quickly
    
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);              //used to clear the buffer memory initially left behind set pixels to its default settings
    glLoadIdentity();                          //used for clearing the matrix,reset any transformation initially present
    
    //drawing color
    glFlush();                            //actually displays the frame buffer on the screen.
}
