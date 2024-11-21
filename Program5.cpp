#include<Windows.h>
#include<GL/GLUT.H>
#include<stdlib.h>

int red=1; //Global Variables
int green=1;
int blue=1;
int submenu;

void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);

	glLoadIdentity();
	glRotatef(10,1.0,0.0,0.0);
	glRotatef(20,0.0,1.0,0.0);
	
	glColor3f(red,green,blue);
	//glutSolidCube(1);
	//glutWireCube(1);
	//glutSolidTetrahedron();
	glutWireTetrahedron();
	glFlush();
}

void color_menu(int id){
	switch(id){
	case 2:red=1;
		green=0;
		blue=0;
		break;
	case 3:red=0;
		green=1;
		blue=0;
		break;
	case 4:red=0;
		green=0;
		blue=1;
		break;
	}
	glutPostRedisplay();
}

void top_menu(int id){
	switch(id){
	case 1:exit(0);
		break;
	default:color_menu(id);
		break;
	}
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Square");

	submenu=glutCreateMenu(color_menu);
	glutAddMenuEntry("red",2);
	glutAddMenuEntry("green",3);
	glutAddMenuEntry("blue",4);

	glutCreateMenu(top_menu);
	glutAddMenuEntry("Quit",1);
	glutAddSubMenu("Color",submenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(mydisplay);
	glutMainLoop();
}
