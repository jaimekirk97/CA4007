#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
GLint offset;
/* offset is used to change the origin from the
world coordinates (lower-left) to the
screen coordinates (upper-left)
*/
/*
This program illustrates the use of the Reshape Callback,
which is called whenever the window is resized.
It contains the functions gluOrtho2D and glViewport.
The parameters of gluOrtho2D are set so that the square
will remain the same size on the screen when the window
is resized.
It also contains a passive mouse callback which causes
the square to change colour when the mouse enters it.
*/
void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,-0.5);
	glEnd();
	glFlush();
	return;
}

void MyMouse(GLint x, GLint y)
{
	if (x > 125 && x < 375 && (y + (500-offset)) > 125 && (y + (500-offset)) < 375)
	glColor3f(0.0,1.0,0.0);
	else
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5,-0.5);
	glVertex2f(-0.5,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,-0.5);
	glEnd();
	glFlush();
	return;
}

void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,-1.0+2.0*w/500.0,-1.0,-1.0+2.0*h/500.0);
	glViewport(0,0,w,h);
	offset=h;
	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("Reshape2");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutPassiveMotionFunc(MyMouse);
	glutMainLoop();
}
