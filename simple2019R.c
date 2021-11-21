#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

GLint i = 0;
GLfloat theta;
GLfloat PI = 3.14;
GLint triangleAmount = 20; //# of triangles used to draw circle
int colours[10][10];
int fillcolour;
int i,j;


void display(void)
{
	GLfloat radius = 0.4; //radius
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	GLint i;
	
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.0, 0.0); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            0.0 + (radius * cos(i *  twicePi / triangleAmount)), 
			    0.0 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glFlush();
	return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
	GLfloat twicePi = 2.0f * PI;
	GLfloat radius = 0.4; //radius
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		colours[i][j]= fillcolour;
		if(colours[i][j] == 0) glColor3f(1.0,1.0,1.0);
		else if(colours[i][j]==1) glColor3f(1.0,0.0,0.0);
		else if(colours[i][j]==2) glColor3f(0.0,0.0,1.0);
	}
		

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.0, 0.0); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            0.0 + (radius * cos(i *  twicePi / triangleAmount)), 
			    0.0 + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glFlush();	

	return;
}

void mymenu(int value)
{
if(value == 1) fillcolour=1;
if(value == 2) fillcolour=2;
if(value == 3) fillcolour=0;

}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutMouseFunc(MyMouse);
	glutCreateMenu(mymenu);
	glutAddMenuEntry("red",1);
	glutAddMenuEntry("blue",2);
	glutAddMenuEntry("white",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}