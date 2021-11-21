#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

GLfloat xshift=0.0, zshift=0.0;

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
	glutAddMenuEntry("cube",1);
	glutAddMenuEntry("table",2);
	glutAddMenuEntry("chair",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}