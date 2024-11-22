#include<stdio.h>
#include<GL/GLUT.H>
#include<math.h>

#define sign(x) ((x>0)?1:((x<0)?-1:0))
//GLint x1,y1,x2,y2;

void writepixel(GLint x,GLint y)
{
	glPointSize(2.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}

void bres(int x1,int y1,int x2,int y2)
{
	int dx,dy,x,y,d,sdx,sdy,swap=0,temp,t,inE,inNE;

	if(x1>x2)
	{
		bres(x2,y2,x1,y1);
		return;
	}
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	sdx=sign(x2-x1);
	sdy=sign(y2-y1);

	if(x1==x2){
		if(y1>y2){
			t=y1;
			y1=y2;
			y2=t;
		}
	for(int i=y1;i<=y2;i++)
		writepixel(x1,i);
	return;
	}
	if(dy>dx){
		temp=dy;
		dy=dx;
		dx=temp;
		swap=1;
	}
	d=2*dy-dx;
	x=x1;
	y=y1;
	inE=2*dy;
	inNE=2*(dy-dx);

	do{

		writepixel(x,y);
		if(d<0)
			d+=inE;
		else{
			d+=inNE;
			if(swap)
				x=x+sdx;
			else
				y=y+sdy;
		}
		if(swap)
				y=y+sdy;
		else
			x=x+sdx;
				
	}while(x!=x2);
	
	glFlush();
}

void draw(void){
	glClear(GL_COLOR_BUFFER_BIT);

	bres(20,-10,70,-40);
	bres(10,-20,40,-70);
	bres(20,10,70,40);
	bres(40,70,10,20);

	bres(-40,-70,-10,-20);
	bres(-70,-40,-20,-10);
	bres(-70,40,-20,10);
	bres(-40,70,-10,20);

	//Draw Rectangle
	bres(-90,80,90,80);
	bres(90,80,90,-80);
	bres(90,-80,-90,-80);
	bres(-90,-80,-90,80);
	bres(-30,-10,30,10);
	bres(-30,10,30,-10);
	bres(-10,-30,10,30);
	bres(-10,30,10,-30);
	
	//bres(x1,y1,x2,y2);

	glFlush();
}

void init(){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Bresenhams Line Drawing");
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,1.0,1.0);
	gluOrtho2D(-200,200,-200,200);
}

int main(int argc,char **argv){
	glutInit(&argc,argv);
	
	init();
	glutDisplayFunc(draw);

	
	glutMainLoop();
	return 0;
}
