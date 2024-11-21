#include<stdlib.h>
#include<GL/glut.H>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1,1,1);
	glBegin(GL_LINES);
		glVertex3f(-1,0,0);
		glVertex3f(1,0,0);
		glVertex3f(0,1,0);
		glVertex3f(0,-1,0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex2f(0.3,0.2);
		glVertex2f(0.6,0.6);
		glVertex2f(0.6,0.2);
	glEnd();

	glPushMatrix();
	glTranslatef(0.3,0.2,0.0);
	glRotatef(90,0,0,1);
	glTranslatef(-0.3,-0.2,0.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.3,0.2);
		glVertex2f(0.6,0.6);
		glVertex2f(0.6,0.2);
	glEnd();
	glPopMatrix();

	glRotatef(90,0,0,1);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.3,0.2);
		glVertex2f(0.6,0.6);
		glVertex2f(0.6,0.2);
	glEnd();

	glFlush();
}

void main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Triangle");
	//glLineWidth(2);
	//glClearColor(1,1,1,0);
	glutDisplayFunc(display);
	glutMainLoop();
}
