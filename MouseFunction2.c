#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

/*
This program illustrates the Mouse Function Callback.
It uses the right mouse button to select the corners
of a rectangle and then draws the rectangle.

This is a revised version of the program MouseFunction.
This version should work even when the window is resized.
*/

GLfloat x1,x2,y1,y2;
GLfloat hh;

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	glColor3f(1.0,0.0,0.0);

	glBegin(GL_POLYGON);
		glVertex2f(x1,y1);
		glVertex2f(x1,y2);
		glVertex2f(x2,y2);
		glVertex2f(x2,y1);
	glEnd();

	glFlush();
	return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		if (first)
		{
			x1=x; 
			y1=hh-y;
		}
		else
		{
			x2=x;
			y2=hh-y;
			glutPostRedisplay();
		}
		first = !first;
	}

	return;
}

void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLfloat)w,0.0,(GLfloat)h);
	glViewport(0,0,w,h);
	hh=h;
	return;
}

void mymenu(int value)
{
if(value == 1) {glClear(GL_COLOR_BUFFER_BIT); glFlush();}
if(value == 2) exit(0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("mouse");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouse);

	glutCreateMenu(mymenu);
	glutAddMenuEntry("clear",1);
	glutAddMenuEntry("exit",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	glutMainLoop();
}