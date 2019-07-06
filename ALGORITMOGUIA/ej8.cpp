#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;
void lineas(float px1, float py1, float px2, float py2){
	glBegin(GL_LINES);
	glVertex2f(px1, py1);
	glVertex2f(px2, py2);
	glEnd();
}
void planoCartesiano(float x11, float y11, float x12, float y12, float x21, float y21, float x22, float y22){
	glBegin(GL_LINES);
    glColor3f(1,1,1);
	//plano cartesiano
    lineas(x11, y11, x12, y12);
    lineas(x21, y21, x22, y22);
	//coordenadas x
	//planoCartesiano(-15, 0, 15, 0, 0, 10, 0, -10);
	//for(float i=x11; i<=x12; i++){
	//	lineas(-.5, y11+1, .5, y12+1);
	//}
    glEnd();
}
void bresenham(float xstart, float ystart, float xend , float yend){
	double x=0;
	double y=0;
	double Dx,Dy,P,ultimo;
	Dx=abs(xend-xstart);
	Dy=abs(yend-ystart);
	P=2*Dy-Dx;
	
	if(xstart>xend){
		x=xend;
		y=yend;
		ultimo=xstart;
	}
	else{
		x=xstart;
		y=ystart;
		ultimo=xend;	
	}		 
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2f(x, y);        
    while(x<ultimo){
		x+=.1;
		if(P<0){
			//constante+=2*Dy;
		}
		else{
			y+=.1;
			//constante+=2*(Dy-Dx);
		}
		glBegin(GL_POINTS);
		glVertex2f(x, y);
	}
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
	planoCartesiano(-15, 0, 15, 0, 0, 10, 0, -10);
    bresenham(-5, -5, 5, 5);
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
	glClearColor(0,1,0,0);
    //glClearColor(0, 1, 0, 1);
    glLoadIdentity();
    glOrtho(-15, 15, -10, 10, -10, 10);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1368, 768);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejemplo Puntos");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}