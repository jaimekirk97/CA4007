#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

GLfloat xshift=0.0, yshift=0.0;

GLfloat objects[10][30];

GLint k=0,nobjects=0,item=1;

void cube(GLfloat x,GLfloat y, GLfloat z)
{
	glPushMatrix();
	glTranslatef(x,y,z);
	glPushMatrix();
	glutWireCube(1);
	glPopMatrix();
}

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,4.0,0.0,0.0,0.0,0.0,1.0,0.0);

	GLfloat pos[4] = {0.0,0.7,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	

	//glutWireCube(1);
	

	//glTranslatef(0.0,0.7,0.0);
	//glRotatef(45.0,0.0,0.0,1.0);
	//glTranslatef(xshift,yshift,0.0);
	//glScalef(0.5,1.0,1.0);
	
	//glutWireCube(0.5);


	//glPopMatrix();
	//glTranslatef(0.0,0.7,0.0);
	//glutWireCube(0.5);

	for(k=0; k<nobjects; k++)
	{	
	if(objects[0][k] == 1)
		cube(objects[1][k],objects[2][k],0.0);
	}
	
	if(item == 1)
		cube(xshift,yshift,0.0);
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
	//glFrustum(-1.0,1.0,-1.0,1.0,0.3,5.0);
	gluPerspective(75,1.0,0.3,10.0);
	glViewport(0,0,w,h);
	return;
}

void MySpecial(GLint key, GLint x, GLint y)
{


if(key == GLUT_KEY_RIGHT) xshift += 0.1;
else if(key == GLUT_KEY_LEFT) xshift -= 0.1;
if(key == GLUT_KEY_UP) yshift += 0.1;
else if(key == GLUT_KEY_DOWN) yshift -= 0.1;

glutPostRedisplay();
glFlush();
return;
}

void mymenu(int value)
{
item=value;
glutPostRedisplay();
return;
}

void MyKeyboard(unsigned char key, GLint x, GLint y)
{

if(key == 'q') 
{
objects[0][k]=item;
objects[1][k]=xshift;
objects[2][k]=yshift;
objects[3][k]=0.0;
nobjects++;
}

glutPostRedisplay();
glFlush();
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
	glutSpecialFunc(MySpecial);
	glutKeyboardFunc(MyKeyboard);

	glutCreateMenu(mymenu);
	glutAddMenuEntry("cube",1);
	glutAddMenuEntry("reset",2);
	glutAddMenuEntry("exit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}