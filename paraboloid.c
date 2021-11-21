#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

/*
This program is a solution to Q5a on Exam 2020

It displays a 3D paraboloid.

*/

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pos[4] = {0.0,0.0,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,1.1,1.8,0.0,0.0,0.0,0.0,1.0,0.0);

	//this ensures the Normals have length 1
	glEnable(GL_NORMALIZE); 

	GLfloat x,y,z,x1,y1=0,z1,r1=0,theta=0.0,r=0.0;

	for(int j=0; j<10; j++)
	{	
	r += 0.1;
	y = r*r;
	glBegin(GL_QUAD_STRIP);
	for(int i=0; i <11; i++)
	{
		theta += 2*M_PI/10;
		x=r*cos(theta); z=r*sin(theta);
		x1=r1*cos(theta); z1=r1*sin(theta);
		glNormal3f(x/0.6,0,z/0.6);
		glVertex3f(x,y,z);
		glVertex3f(x1,y1,z1);
	}
	y1=y;	
	r1=r;			
	glEnd();
	}


	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.3,5.0);
//	gluPerspective(60,1.0,0.3,5.0);
	glViewport(0,0,w,h);
	return;
}




int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}