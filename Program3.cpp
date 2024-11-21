#include<stdlib.h>
#include<GL/glut.H>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex3f(-1,0,0);
		glVertex3f(1,0,0);
		glVertex3f(0,1,0);
		glVertex3f(0,-1,0);
	glEnd();

	glPushMatrix();
	glLoadIdentity();
	glRotatef(10,1,0,0);
	glRotatef(20,0,1,0);
	glTranslatef(0,0,0);
	glColor3f(1,0,0);
	glutWireCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	glRotatef(10,1,0,0);
	glRotatef(20,0,1,0);
	glTranslatef(-0.3,0,0);
	glColor3f(0,0,1);
	glutWireCube(0.2);
	glPopMatrix();

	glFlush();
}

void main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cube");
	glLineWidth(2);
	glClearColor(1,1,1,0);
	glutDisplayFunc(display);
	glutMainLoop();
}
