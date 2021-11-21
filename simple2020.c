#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);

	glBegin(GL_POLYGON);
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
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();

	glutPostRedisplay();

	glFlush();	


	return;
}


void MyMouse2(GLint x, GLint y)
{
	if (x > 125 && x < 127 && y > 373 && y < 375)
	{
		glColor3f(1.0,0.0,0.0);
		glPointSize(10.0);
		glBegin(GL_POINTS);
			glVertex2f((x-250.0)/250.0,-(y-250.0)/250.0);
		glEnd();
	}
	glFlush();	

	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("mouse");
	glutDisplayFunc(display);
	glutPassiveMotionFunc(MyMouse);
	glutMotionFunc(MyMouse2);


	glutMainLoop();
}