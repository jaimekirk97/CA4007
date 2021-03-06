#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

GLfloat xshift=0.0, zshift=0.0;

GLfloat objects[10][30];

GLint k=0,nobjects=0,item=1;

void tabletop(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.3,0.05,0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void cube(GLfloat x,GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glPushMatrix();
	glutWireCube(0.5);
	glPopMatrix();
}

void tableleg(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.3,0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void table(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	tabletop(0.0,0.325,0.0);
	tableleg(0.15,0.15,0.15);
	tableleg(-0.15,0.15,0.15);
	tableleg(0.15,0.15,-0.15);
	tableleg(-0.15,0.15,-0.15);
	glPopMatrix();

	return;
}


void mattress(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.6,0.2,0.6);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void leg(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.1,0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void bed(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	mattress(0.0,0.2,0.0);
	leg(0.25,0.05,0.25);
	leg(-0.25,0.05,0.25);
	leg(0.25,0.05,-0.25);
	leg(-0.25,0.05,-0.25);
	glPopMatrix();

	return;
}

void chairLeg(GLfloat x,GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.2,0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void chairBase(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.2,0.01,0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void chairBack(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glRotatef(-90.0,1.0,0.0,0.0);
	glScalef(0.2,0.01,0.2);
	glutSolidCube(1.0);
	glPopMatrix();

	return;
}

void chair(GLfloat x, GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	chairBase(0.0,0.15,0.0);
	chairBack(0.0,0.24,-0.1);
	chairLeg(0.08,0.05,0.08);
	chairLeg(-0.08,0.05,0.08);
	chairLeg(0.08,0.05,-0.08);
	chairLeg(-0.08,0.05,-0.08);

	glPopMatrix();

	return;
}

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.7,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

	GLfloat pos[4] = {0.0,0.7,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);	
	

	// FLOOR AND WALLS OF ROOM USING QUADS
	glBegin(GL_QUADS);
		glClearColor(0.0,0.0,1.0,1.0);
		glVertex3f(-2.0,0.0,0.5);
		glVertex3f(2.0,0.0,0.5);
		glVertex3f(2.0,0.0,-1.5);
		glVertex3f(-2.0,0.0,-1.5);
	glEnd();



	for(k=0; k<nobjects; k++)
	{	
	if(objects[0][k] == 1)
		chair(objects[1][k],0.0,objects[3][k]);
	else if(objects[0][k] == 2)
		bed(objects[1][k],0.0,objects[3][k]);
	else 
		table(objects[1][k],0.0,objects[3][k]);
	}
	
	if(item == 1)
		chair(xshift,0.0,zshift);
	else if(item == 2)
		bed(xshift,0.0,zshift);
	else
		table(xshift,0.0,zshift);

	glFlush();
	return;
}

void MySpecial(GLint key, GLint x, GLint y)
{


if(key == GLUT_KEY_RIGHT) xshift += 0.1;
else if(key == GLUT_KEY_LEFT) xshift -= 0.1;
if(key == GLUT_KEY_UP) zshift += 0.1;
else if(key == GLUT_KEY_DOWN) zshift -= 0.1;

glutPostRedisplay();
glFlush();
return;
}

void MyKeyboard(unsigned char key, GLint x, GLint y)
{

if(key == 'q') 
{
objects[0][k]=item;
objects[1][k]=xshift;
objects[2][k]=0.0;
objects[3][k]=zshift;
nobjects++;
}

glutPostRedisplay();
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

void mymenu(int value)
{
item=value;
glutPostRedisplay();
return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("interior3");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MySpecial);
	glutKeyboardFunc(MyKeyboard);

	glutCreateMenu(mymenu);
	glutAddMenuEntry("chair",1);
	glutAddMenuEntry("bed",2);
	glutAddMenuEntry("table",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}