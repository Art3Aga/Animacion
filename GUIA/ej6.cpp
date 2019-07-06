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
    lineas(x11, y11, x12, y12);
    lineas(x21, y21, x22, y22);
    glEnd();
}
void rosaPolar(int n_petalos, float medida){
    glPointSize(4.0);
    glBegin(GL_POINTS);
    float x, y, a, teta90 = (1*M_PI)/2, tetamin = (0*M_PI)/2, tetamax = (2*M_PI)/2;
    float i = tetamin;
    float j=teta90;
    while(i<=teta90){
        x = medida*(cos(n_petalos*i))*cos(i);
        y = medida*(cos(n_petalos*i))*sin(i);
        glVertex2f(x,y);
        i+=.0001;
    }
    while(j<=tetamax){
        x = medida*(cos(n_petalos*j))*cos(j);
        y = medida*(cos(n_petalos*j))*sin(j);
        glVertex2f(x,y);
        j+=.0001;
    }
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    planoCartesiano(-15, 0, 15, 0, 0, 10, 0, -10);
    rosaPolar(3, 8);
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glClearColor(0, 1, 0, 1);
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