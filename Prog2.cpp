#include<windows.h>
#include<gl/glut.h>
#include<stdio.h>

GLfloat r,px,py;

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);

	glBegin(GL_TRIANGLES);
		glVertex2f(0.1,0.4);
		glVertex2f(0.7,0.4);
		glVertex2f(0.4,0.8);
	glEnd();

	glColor3f(1,0,0);
	glLoadIdentity();
	glTranslatef(px,py,0);
	glRotatef(r,0,0,1);
	glTranslatef(-px,-py,0);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.1,0.4);
		glVertex2f(0.7,0.4);
		glVertex2f(0.4,0.8);
	glEnd();

	glFlush();
}

int main(int argc,char **argv){

	printf("Enter cordinates pivot points :");
	scanf("%f %f",&px,&py);
	printf("Enter Rotation Degree :");
	scanf("%f",&r);
	glutInit(&argc,argv);
	glutCreateWindow("Triangle Rotation");
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
