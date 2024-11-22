#include<GLUT.H>
#include<Windows.h>
#include<stdio.h>

int r=0;

void myinit(){
	glClearColor(1,1,1,1);
	glColor3f(1,0,0);
}

void spin(){
	r+=1;
	if(r>360)
	    r-=360;
	glutPostRedisplay();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(r,0,0,1);
	glRectf(-0.5,0.5,0.5,-0.5);
	
	glFlush();
}

void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Square");
	myinit();
	glutDisplayFunc(draw);
	glutIdleFunc(spin);
	glutMainLoop();
}
