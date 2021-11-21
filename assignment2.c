#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <stdio.h>


// Adam Herd - 17364786
// Jaime Kirk - 17922982

// When starting the program, you will see an empty room. You can move the camera around by using the W A S D
// keys. To zoom in, use the + and - keys.
// Right click to see the menu. Here you can choose 2D view whcih will show a 2D view of the current room.
// Press 3D to get back to you original 3D view.
// When you click on the chair option, a chair will appear in the room. You can move this chair around
// using the arrow keys on the keyboard.
// Similarly, when you click on the table option, a table will appear and can be moved around in the exact
// same way as the chair.
// You can continue moving the camera around with the W A S D keys while moving the objects.

int menuOption;
GLfloat xshift=0.0f,yshift=0.0f,zshift=30.0f, chairshiftx=0.0f, chairshiftz=-10.0f, tableShiftx=0.0f, tableShiftz=-20.0f;

void display()
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(xshift, yshift, zshift, xshift, yshift, 1.0f, 0.0f, 1.0f, zshift);

	// 2D VIEW
	if(menuOption == 1){

		gluLookAt(0.0f, 50.0f, -16.0f, 0.0f, -150.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// 3D VIEW. DEFAULT VIEW SO DO NOT NEED TO CHANGE ANYTHING HERE
	}else if(menuOption == 2){
		
	}

	glPushMatrix();
	glTranslatef(0.0f, -20.0f, -20.0f);

	// FLOOR AND WALLS OF ROOM USING QUADS
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(-35, -5, -35);
		glVertex3f(35, -5, -35);
		glVertex3f(35, -5, 35);
		glVertex3f(-35, -5, 35);

		glColor3f(0.0,0.0,0.0);
		glVertex3f(-35,-10,35);
		glVertex3f(35,-10,35);
		glVertex3f(35,10,35);
		glVertex3f(-35,10,35);

		glVertex3f(-35,-10,-35);
		glVertex3f(35,-10,-35);
		glVertex3f(35,10,-35);
		glVertex3f(-35,10,-35);

		glVertex3f(35,10,35);
		glVertex3f(35,-10,35);
		glVertex3f(35,-10,-35);
		glVertex3f(35,10,-35);

		glVertex3f(-35,10,35);
		glVertex3f(-35,-10,35);
		glVertex3f(-35,-10,-35);
		glVertex3f(-35,10,-35);
	glEnd();
	glPopMatrix();


	if(menuOption == 3){

		glPushMatrix();

		glTranslatef(chairshiftx, -4.0f, chairshiftz);

		// CHAIR LEGS USING CYLINDERS
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glTranslatef(0.0f, -20.0f, 0.0f);
		GLUquadricObj *MyCylinder;
		MyCylinder = gluNewQuadric();
		glRotatef(-90.0,1.0,0.0,0.0);
		gluCylinder(MyCylinder,0.5,0.5,3.0,12,12);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glTranslatef(3.0f, -20.0f, 0.0f);
		glRotatef(-90.0,1.0,0.0,0.0);
		gluCylinder(MyCylinder,0.5,0.5,3.0,12,12);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glTranslatef(0.0f, -20.0f, 3.0f);
		glRotatef(-90.0,1.0,0.0,0.0);
		gluCylinder(MyCylinder,0.5,0.5,3.0,12,12);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glTranslatef(3.0f, -20.0f, 3.0f);
		glRotatef(-90.0,1.0,0.0,0.0);
		gluCylinder(MyCylinder,0.5,0.5,3.0,12,12);
		glPopMatrix();


		// SEAT AND BACK SUPPORT USING QUADS
		glTranslatef(1.5f, -17.0f, 1.7f);
		glBegin(GL_QUAD_STRIP);

			glColor3f(0.5f, 0.35f, 0.05f);

			glVertex3f(-2.0f, -0.2f, 2.0f);
			glVertex3f(2.0f, -0.2f, 2.0f);
			glVertex3f(2.0f, 0.2f, 2.0f);
			glVertex3f(-2.0f, 0.2f, 2.0f);

			glVertex3f(2.0f, -0.2f, -2.0f);
			glVertex3f(2.0f, 0.2f, -2.0f);
			glVertex3f(2.0f, 0.2f, 2.0f);
			glVertex3f(2.0f, -0.2f, 2.0f);

			glVertex3f(-2.0f, -0.2f, -2.0f);
			glVertex3f(-2.0f, 0.2f, -2.0f);
			glVertex3f(2.0f, 0.2f, -2.0f);
			glVertex3f(2.0f, -0.2f, -2.0f);

			glVertex3f(-2.0f, -0.2f, -2.0f);
			glVertex3f(-2.0f, -0.2f, 2.0f);
			glVertex3f(-2.0f, 0.2f, 2.0f);
			glVertex3f(-2.0f, 0.2f, -2.0f);

			glVertex3f(2.0f, 0.2f, 2.0f);
			glVertex3f(-2.0f, 0.2f, 2.0f);
			glVertex3f(-2.0f, 0.2f, -2.0f);
			glVertex3f(2.0f, 0.2f, -2.0f);

			glVertex3f(2.0f, -0.2f, 2.0f);
			glVertex3f(-2.0f, -0.2f, 2.0f);
			glVertex3f(-2.0f, -0.2f, -2.0f);
			glVertex3f(2.0f, -0.2f, -2.0f);

			glVertex3f(1.8f, 0.2f, -2.0f);
			glVertex3f(1.8f, 3.5f, -2.0f);
			glVertex3f(-1.8f, 3.5f, -2.0f);

			glVertex3f(-1.8f, 3.5f, -2.0f);
			glVertex3f(-1.8f, 3.5f, -1.8f);
			glVertex3f(-1.8f, 0.2f, -1.8f);

			glVertex3f(1.8f, 0.2f, -2.0f);
			glVertex3f(1.8f, 3.5f, -2.0f);
			glVertex3f(1.8f, 3.5f, -1.8f);
			glVertex3f(1.8f, 0.2f, -1.8f);

			glVertex3f(-1.8f, 3.5f, -2.0f);
			glVertex3f(-1.8f, 3.5f, -1.8f);
			glVertex3f(1.8f, 3.5f, -1.8f);
			glVertex3f(1.8f, 3.5f, -2.0f);
		glEnd();
		glPopMatrix();
	}


	if(menuOption == 4){

		glPushMatrix();

		// MOVE THE POSITION OF THE TABLE BASED ON THE ARROW KEY PRESSES
		glTranslatef(tableShiftx, -25.0f, tableShiftz);

		// TABLE LEGS USING CYLINDERS
		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		GLUquadricObj *MyCylinder;
		MyCylinder = gluNewQuadric();
		glTranslatef(3.0f, 0.0f, 4.0f);
		glRotatef(-90.0,1.0,0.0,0.0);
		gluCylinder(MyCylinder,0.5,0.5,3.0,12,12);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glTranslatef(6.0f, 0.0f, 4.0f);
		glRotatef(-90.0,1.0,0.0,0.0);
		gluCylinder(MyCylinder,0.5,0.5,3.0,12,12);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glTranslatef(3.0f, 0.0f, 12.0f);
		glRotatef(-90.0,1.0,0.0,0.0);
		gluCylinder(MyCylinder,0.5,0.5,3.0,12,12);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5f, 0.35f, 0.05f);
		glTranslatef(6.0f, 0.0f, 12.0f);
		glRotatef(-90.0,1.0,0.0,0.0);
		gluCylinder(MyCylinder,0.5,0.5,3.0,12,12);
		glPopMatrix();


		// TABLE TOP USING QUADS
		glTranslatef(4.5f, 3.0f, 7.5f);
		glBegin(GL_QUAD_STRIP);

			glColor3f(0.5f, 0.35f, 0.05f);

			glVertex3f(-2.0f, -0.2f, 5.0f);
			glVertex3f(2.0f, -0.2f, 5.0f);
			glVertex3f(2.0f, 0.2f, 5.0f);
			glVertex3f(-2.0f, 0.2f, 5.0f);

			glVertex3f(2.0f, -0.2f, -5.0f);
			glVertex3f(2.0f, 0.2f, -5.0f);
			glVertex3f(2.0f, 0.2f, 5.0f);
			glVertex3f(2.0f, -0.2f, 5.0f);

			glVertex3f(-2.0f, -0.2f, -5.0f);
			glVertex3f(-2.0f, 0.2f, -5.0f);
			glVertex3f(2.0f, 0.2f, -5.0f);
			glVertex3f(2.0f, -0.2f, -5.0f);

			glVertex3f(-2.0f, -0.2f, -5.0f);
			glVertex3f(-2.0f, -0.2f, 5.0f);
			glVertex3f(-2.0f, 0.2f, 5.0f);
			glVertex3f(-2.0f, 0.2f, -5.0f);

			glVertex3f(2.0f, 0.2f, 5.0f);
			glVertex3f(-2.0f, 0.2f, 5.0f);
			glVertex3f(-2.0f, 0.2f, -5.0f);
			glVertex3f(2.0f, 0.2f, -5.0f);

			glVertex3f(2.0f, -0.2f, 5.0f);
			glVertex3f(-2.0f, -0.2f, 5.0f);
			glVertex3f(-2.0f, -0.2f, -5.0f);
			glVertex3f(2.0f, -0.2f, -5.0f);
		glEnd();
		glPopMatrix();
	}

	glFlush();
}

// RESHAPE FUNCTION
void MyReshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, (double)w/(double)h, 1.0, 200.0);
}


// MENU FOR CHOOSING DIFFERENT VIEWPOINTS AND OBJECTS
void mymenu(int value)
{
	if(value == 1) 
	{
		menuOption = 1;
		glutPostRedisplay();
	}
	else if(value == 2) 
	{
		menuOption = 2;
		glutPostRedisplay();
	}
	else if(value == 3) 
	{
		menuOption = 3;
		glutPostRedisplay();
	}
	else if(value == 4) 
	{
		menuOption = 4;
		glutPostRedisplay();
	}
}


// FUNCTION FOR MOVING THE CHAIR AND TABLE.
// THEY USE THE SAME KEYS BUT ARE DISTINGUISHED BY
// THE MENU OPTION NUMBER, MEANING YOU CAN'T
// MOVE A CHAIR WHILE ALSO MOVING A TABLE
void MySpecial2(GLint key, GLint x, GLint y)
{

	if(key == GLUT_KEY_RIGHT && menuOption == 3){
		chairshiftx += 1.0;
	}
	else if(key == GLUT_KEY_LEFT && menuOption == 3){
		chairshiftx -= 1.0;
	}
	else if(key == GLUT_KEY_DOWN && menuOption == 3){
		chairshiftz += 1.0;
	}
	else if(key == GLUT_KEY_UP && menuOption == 3){
		chairshiftz -= 1.0;
	}

	if (key == GLUT_KEY_PAGE_UP){
		zshift -= 1.0;
	}
	else if (key == GLUT_KEY_PAGE_DOWN){
		zshift += 1.0;
	}

	if(key == GLUT_KEY_RIGHT && menuOption == 4){ 
		tableShiftx	+= 1.0;
	}
	else if(key == GLUT_KEY_LEFT && menuOption == 4){
		tableShiftx	-= 1.0;
	}
	else if(key == GLUT_KEY_DOWN && menuOption == 4){
		tableShiftz	+= 1.0;
	}
	else if(key == GLUT_KEY_UP && menuOption == 4){
		tableShiftz	-= 1.0;
	}
	glutPostRedisplay();
}


// FUNCTION FOR ALLOWING CAMERA MOVEMENT AROUND THE ROOM
void keyboard(unsigned char key, int x, int y){

	if (key == 'a'){
        xshift -= 1.0;
	}
    else if (key == 'd'){
    	xshift += 1.0;
    }
    else if(key == 's'){
    	yshift -= 1.0;
    }
    else if (key == 'w'){
    	yshift += 1.0;
    }
    else if (key == '+'){
    	zshift -= 1.0;
    }
    else if (key == '-'){
    	zshift += 1.0;
    }

    glutPostRedisplay();
}


int main(int argc, char **argv)
{
	GLint id;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(350,200);
	glutCreateWindow("Interior Design Tool");
	glutDisplayFunc(display);
	id = glutCreateMenu(mymenu);
	glutAddMenuEntry("2D View", 1);
	glutAddMenuEntry("3D View (Move screen with W A S D and + -)", 2);
	glutAddMenuEntry("Chair (Move with keyboard)", 3);
	glutAddMenuEntry("Table (Move with keyboard)", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MySpecial2);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
}