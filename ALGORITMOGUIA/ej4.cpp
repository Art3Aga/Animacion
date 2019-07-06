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
void graficando(string grafica, float posX, float posY){
    //float xmax = 2*M_PI;
    //float xmin = -2*M_PI;
    //float incrementar = (xmax-xmin)/1000;
    //float x = xmin;
    //glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    if(grafica == "senh"){
        for(float i=-2; i<=2; i+=0.01){
            //float angle = i*(2.0*M_PI/1000);
            //float y = log((i) + sqrtf(i^2));
            float y = log(i+ sqrt(pow(i, 2)+1));
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(-14, 5, -6 ,5, -10, 9, -10 ,1);
    }
    if(grafica == "cosh"){
        for(float i=-2; i<=2; i+=0.01){
            float y = log(i+ sqrt(pow(i, 2)-1));
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(-5, 5, 3 ,5, -1, 9, -1 ,1);
    }
    if(grafica == "tanh"){
        for(float i=-2.5; i<=2.5; i+=0.01){
            float y = (0.5)*log((1+i)/(1-i));
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(4, 5, 12 , 5, 8, 9, 8 ,1);
    }
    if(grafica == "coth"){
        for(float i=-2; i<=2; i+=0.01){
            float y = (0.5)*log((i+1)/(i-1));
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(-14, -5, -6 , -5 , -10 , -1, -10 , -9);
    }
    if(grafica == "sech"){
        for(float i=-3; i<=3; i+=0.01){
            //secante hiperbolica
            //float y = (2)/(pow(exp(1), i) + pow(exp(1), -i));
            //float y = log((1/i)+ (sqrt(1/pow(i, 2) + 1))); sin tantos puntos en 4 y 6 del ejercicio 3
             float y = log((1/i)+ (sqrt(1/pow(i, 2) - 1)));
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(-5, -5, 3 , -5 , -1, -1, -1 , -9);
    }
    if(grafica == "cosech"){
        for(float i=-2; i<=2; i+=0.01){
            float y = log((1/i) + (sqrt(1/pow(i, 2) + 1)));
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(4, -5, 12 , -5, 8, -1, 8 ,-9);
    }
    

    //for(int i = 0; i <= 1000; i++){
        //float y = sin(x);
        //x = x +incrementar;
        //glVertex2f(x, y);
    //}
    
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //senoh
    graficando("senh", -10, 5);
    //cosenoh
    graficando("cosh", -1, 5);
    //cosenoh
    graficando("tanh", 8, 5);
    //cotangenteh
    graficando("coth", -10, -5);
    //secanteh
    graficando("sech", -1, -5);
    //secanteh
    graficando("cosech", 8, -5);
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
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

