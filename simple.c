#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glVertex2f(-0.1,-0.1);
		glVertex2f(-0.1,0.1);
		glVertex2f(0.1,0.1);
		glVertex2f(0.1,-0.1);
	glEnd();

	glFlush();
	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutMainLoop();
}