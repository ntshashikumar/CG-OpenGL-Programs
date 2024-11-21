//#include "stdafx.h"
#include<GL/GLUT.H>
#include <stdlib.h>
#include <math.h >
#include<stdio.h>

int i;
float xp, yp, theta, rtheta, x,y;
float p[9][3] = {{100,100}, {200,200},{300,100}};

void myInit(void){
glClearColor(2.0, 2.0, 2.0,4.0);
glColor3f(0,1,0);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-400,400,-400,400);
}

void display (void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_TRIANGLES);
	glVertex2fv(p[0]);
	glVertex2fv(p[1]);
	glVertex2fv(p[2]);
glEnd();
glFlush();

rtheta=theta*3.14/180.0;

for (i=0;i<3; i++)
{
	x=p[i][0];
	y=p[i][1];

p[i][0] = x*cos(rtheta)-y*sin(rtheta)+xp*(1-cos(rtheta))+yp*sin(rtheta);
p[i][1] = x*sin(rtheta)+y*cos(rtheta)+yp*(1-cos(rtheta))-xp*sin(rtheta);
}
glClearColor(2.0, 2.0,2.0,4.0);
glColor3f(0,0,1);
glBegin(GL_TRIANGLES);
	glVertex2fv(p[0]);
	glVertex2fv(p[1]);
	glVertex2fv(p[2]);
glEnd();
glFlush();
}

void main (int argc, char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Triangle Rotation"); 
	glutDisplayFunc(display);
	myInit();
	printf("Enter the pivot point \n"); 
	scanf("%f %f",&xp,&yp),
	printf("Enter the angle \n");
	scanf("%f",&theta); 
	glutMainLoop();
}
