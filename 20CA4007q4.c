#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

/*
This program is a solution to Q4 Exam 2020.

It you click with the right mouse button near one of the vertices of a polygon, it will select that vertex.
Then if you move the mouse with the button held down,
it will drag the vertex with the mouse.

This program assumes the window size is 500x500.
If you resize the window, it will not work.
*/

//global arrays to store the vertices of the polygon
GLfloat xs[4]={-0.5,-0.5,0.5,0.5};
GLfloat ys[4]={-0.5,0.5,0.5,-0.5};


GLint selected=0,is=0; 
//selected = 1 if a vertex has been selected, else = 0
//is = the index of the selected vertex in the range 0 to 3


void display(void)
{

	GLint i;

	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(i=0; i<4; i++)
		glVertex2f(xs[i],ys[i]);
	glEnd();


	if(selected) //draws point on selected vertex
	{
		glColor3f(0.0,0.0,0.0);
		glPointSize(8.0);
		glBegin(GL_POINTS);
		glVertex2f(xs[is],ys[is]);
		glEnd();
	}
	
	glFlush();
	return;
}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{

	GLfloat xp,yp;
	GLint i;

	selected =0;

	// detects if a vertex has been selected
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		xp=(x-250.0)/250.0; 
		yp=-(y-250.0)/250.0;
		
		//computes distance of mouse to each vertex
		for(i=0;i<4;i++)	
			if((xs[i]-xp)*(xs[i]-xp) 
			  +(ys[i]-yp)*(ys[i]-yp) < 0.001) {
				selected=1; 
				is=i;
			}			
	}
	

	glutPostRedisplay();

	glFlush();

	return;
}


void MyMotion(GLint x, GLint y)
{

	GLfloat xp,yp;

		xp=(x-250.0)/250.0; 
		yp=-(y-250.0)/250.0;
		
		// changes coordinates of vertex if mouse is dragged
		if(selected)
		{
			xs[is]=xp;
			ys[is]=yp;
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
	glutCreateWindow("DragCorner");
	glutDisplayFunc(display);
	glutMouseFunc(MyMouse);
	glutMotionFunc(MyMotion);
	glutMainLoop();
}