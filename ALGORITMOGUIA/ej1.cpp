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

void serieFourier(){
    glPointSize(3.0);
    glBegin(GL_POINTS);
    float tetamin=(-2.5*M_PI);
    float tetamax = (2.5*M_PI);
    float i = tetamin;
    while(i<=tetamax){
        float y = (-2/1)*(cos((i)*M_PI));
        glVertex2f(i, y);
        i+=.0001;
    }
    glEnd();
    glFlush();
}

void fourier(){
    glPointSize(3.0);
    glBegin(GL_POINTS);
    float bn,fx, tetamin=(-1*M_PI), tetamax=(1*M_PI);;
    //for(float i=tetamin; i<=0; i+=.001){
        //bn = (2/(i*M_PI))*(1-(pow((-1), i)))*sin(i*(1*M_PI));
      //  glVertex2f(1, bn);
        
    //}
    for(int i=-10; i<=10; i++){
        //bn = (2/(i*M_PI))*(1-(pow((-1), i)));
        //bn = (2/(i*M_PI))*(1-(pow((-1), i)))*sin(i);
        //fx = (.5)*((2/3)*pow(M_PI, 2))
        //fx = ((1/3)*pow(M_PI, 2)) + ((4/pow(i,2))*(pow(-1, i))*cos(i*2));
        //float sumatoria = ((4)/(pow(i,2))*(pow(-1,i))*cos(i*(2*M_PI)/2));
        float sumatoria = ((4)*((pow(-1,i))/(pow(i,2)))/((pow(i,2))))*(cos(i*(2*M_PI)/2));
        fx = (pow(M_PI,2)/3) + sumatoria;


        //fx = ((2/i)*pow((-1), i+1)* sin(i));
        glVertex2f(i, fx);
        //for(float j=0; j<=M_PI; i+=.001){
          //  fx = (pow(M_PI,2)/3)+((4)/(pow(i,2))*(pow(-1,i))*cos(i*j));
           // glVertex2f(i, fx);
       // }
    }
    //for(float i=0; i<=3; i+=.001){
      //  float y = (pow(i,3));
        //glVertex2f(i,y);
    //}
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    planoCartesiano(-15, 0, 15, 0, 0, 10, 0, -10);
    //fourier();
    serieFourier();
    //circulo_lleno(50, 100, 20);
    //rosaPolar(3, 8);
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glClearColor(0, 0, 1, 0);
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