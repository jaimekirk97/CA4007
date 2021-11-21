#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <stdio.h>

int colours[10][10];
int fillcolour = 0;

void display(void)
{
	float x1,y1,x2,y2;
	int i,j;

	glClear(GL_COLOR_BUFFER_BIT);


	for(i=0; i< 10; i++)
	{
	  for(j=0; j<10; j++)
	  {
		x1=-0.5+0.1*i;
		y1=-0.5+0.1*j;
		x2=x1+0.09;
		y2=y1+0.09;
		
		if(colours[i][j] == 0) glColor3f(1.0,1.0,1.0);
		else if(colours[i][j]==1) glColor3f(1.0,0.0,0.0);
		else if(colours[i][j]==2) glColor3f(0.0,0.0,1.0);

		glBegin(GL_POLYGON);
			glVertex2f(x1,y1);
			glVertex2f(x1,y2);
			glVertex2f(x2,y2);
			glVertex2f(x2,y1);
		glEnd();
	  }
	}	

	glFlush();
	return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
	float x1,y1,x2,y2,xm,ym;
	int i,j;


	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
			xm=(x-250.0)/250.0; 
			ym=-(y-250)/250.0;

			for(i=0; i< 10; i++)
			{
	  		  for(j=0; j<10; j++)
	  		  {
				x1=-0.5+0.1*i;
				y1=-0.5+0.1*j;
				x2=x1+0.09;
				y2=y1+0.09;

				if(x1<xm && xm<x2 && y1<ym && ym<y2)
					colours[i][j]= fillcolour;

						//printf("%d %d\n",i,j);
	  		  }
			}	



			glutPostRedisplay();
		
	}

	return;
}

void mymenu(int value)
{
if(value == 1) fillcolour=0;
if(value == 2) fillcolour=1;
if(value == 3) fillcolour=2;

}

int main(int argc, char **argv)
{
	GLint id;
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutMouseFunc(MyMouse);
	id = glutCreateMenu(mymenu);
	glutAddMenuEntry("red",1);
	glutAddMenuEntry("blue",2);
	glutAddMenuEntry("white",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}