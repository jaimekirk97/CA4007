#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

/* This program is an example soution to Q6 Exam 2020

*/

GLfloat theta=0.0, theta1=0.0; //angles for Idle Function

void sail(GLfloat rot)
{
	
	// creates lattice for sail

	GLfloat x=0.0,y=-0.2;
	GLint i;

	glPushMatrix();

	glRotatef(rot, 0.0,0.0,1.0);
	for(i=0; i<11; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(x,0.2,0.0);
              	glVertex3f(x,-0.2,0.0);
		glEnd();
		x += 0.2;
	}

	for(i=0; i<6; i++)
	{
		glBegin(GL_LINES);
			glVertex3f(0.0,y,0.0);
              	glVertex3f(2.0,y,0.0);
		glEnd();
		y += 0.08;
	}

	glPopMatrix();

	return;
}

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,1.0,4.0,0.0,0.0,0.0,0.0,1.0,0.0);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat pos[4] = {0.0,1.0,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);


	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	glRotatef(theta1,0.0,1.0,0.0); //rotate whole windmill

	glPushMatrix(); //start creating sails

	glTranslatef(0.0,2.0,0.5); //translate to top of cuboid
	glRotatef(theta,0.0,0.0,1.0); //rotate sails

	sail(0.0);
	sail(90.0);
	sail(180.0);
	sail(270.0);
	
	glPopMatrix(); //finish creating sails

	GLUquadricObj *MyCylinder; 
	MyCylinder = gluNewQuadric();
	gluQuadricDrawStyle(MyCylinder, GLU_FILL);
	
	glPushMatrix(); //start creating base
	glRotatef(-90.0,1.0,0.0,0.0);
	gluCylinder(MyCylinder,0.5,0.5,1.0,12,12);
	glPopMatrix(); //finish creating base

	glPushMatrix(); //start creating cuboidal tower
	glTranslatef(0.0,1.2,0.0);
	glScalef(0.5,1.0,0.5);
	glutSolidCube(2.0);
	glPopMatrix(); //finish creating cuboidal tower

	GLUquadricObj *MyCylinder2;
	MyCylinder2 = gluNewQuadric();
	gluQuadricDrawStyle(MyCylinder2, GLU_FILL);
	
	glTranslatef(0.0,2.2,0.0); //start creating cone
	glRotatef(-90.0,1.0,0.0,0.0);
	gluCylinder(MyCylinder2,0.5,0.0,1.0,12,12);
	
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,6.0);


	glViewport(0,0,w,h);
	return;
}

void MyIdle(void)
{
	theta += 0.01;

	theta1 += 0.01;



	glutPostRedisplay();

	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cylinder");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(MyIdle);


	glutMainLoop();
}