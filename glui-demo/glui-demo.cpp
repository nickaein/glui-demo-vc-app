#define GLUIDLL 

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

#include <GL/glut.h>
#include <GL/glui.h>

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(0, 0, -5);
	glRotatef(30, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (GLfloat i = -4; i <= 4; i += 0.5) {
		glVertex3f(i, 0, 4); glVertex3f(i, 0, -4);
		glVertex3f(4, 0, i); glVertex3f(-4, 0, i);
	}
	glEnd();
}


void init() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0, 0, 0);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2, 2, -2, 2, 1, 100);
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	int window = glutCreateWindow("glui demo application");
	glutDisplayFunc(display);

	int x = 0, y = 0;
	long flags = 0;
	GLUI *glui = ::GLUI_Master.create_glui("name", flags, x, y);//here
	glui->set_main_gfx_window(window);//here

	init();
	glutMainLoop();
	return EXIT_SUCCESS;
}
