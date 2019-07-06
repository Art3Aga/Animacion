#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "esfera.h"
using namespace std;

void puertas(float x1, float x2, float x11, float x21, float distancia){

    lineas(x1, x2, x11, x21);
    lineas(-4.8, 5.7, -4.8, 10);
    lineas(-1.73, 5.55, -1.73, 10);
    lineas(-1.73, 10, -4.8, 10);
}
void puerta(){
    lineas(-4.8, 5.7, -4.8, 10);
    lineas(-1.73, 5.55, -1.73, 10);
    lineas(-1.73, 10, -4.8, 10);

    lineas(-5.3, 5.7, -5.3, 10.7);
    lineas(-1.33, 5.55, -1.33, 10.7);
    lineas(-1.33, 10.7, -5.3, 10.7);
    //puerta principal
    rectangulo(-5.68, 3.1, -1.45, 2.8, -5.6, -5.3, -1.45, -5.85);
    lineas(-5.9, 3.53, -1.11, 3.23);
    lineas(-5.9, 3.35, -5.8, -5.85);
    lineas(-1.2, 2.95, -1.28, -6);

    //rectangulo(-5.4, 3.17, -1.11, 2.8, -5.46, -5.4, -1.28, -6.029);
    
}
void escalera(){
    rectangulo(-6.05, -2.87, -13.2, -16.47, -6, -4, -12.62, -16.54);
    rectangulo(-10.3, -15.6, -6.59, -16.46, -12.6, -16.4, -7.4, -17.96);
    //rectangulo(-0.2741, -3.58, -7.34, -18.02, 0.1528, -3.16, -6.94, -18.19);
    rectangulo(-0.2741, -3.58, -7.4, -18.02, 0.1528, -3.16, -6.94, -18.19);
    rectangulo(0.74, -7.4, -4, -18, 0.06, -3.6, -6.92, -18.19);
}
void barandales(){
    //izquierda
    rectangulo(-16.97, -2.1, -16.98, -5.85, -6.015, -2.9, -8.34, -7.03);
    rectangulo(-16.52, -2.55, -16.42, -5.11, -6.47, -3.59, -7.88, -6.27);
    //derecha
    rectangulo(1.2, -4.259, 1.28, -7.275, 14.725, -1.2439, 14.89, -3.74);
    rectangulo(0.81, -3.57, 15.63, -0.468, 1.197, -8.137, 15.63, -4.04);

    //columnas
    //rectangulo(-0.23, -9.395, 0, -14, 0.81, -8.22, 0.85, -14.01);
    //rectangulo(-0.23, -9.395, 0, -14, 0.81, -8.22, 0.85, -14.01);
    lineas(-0.23, -9.395, 0, -14);
    lineas(0.7, -7.6, 0.85, -14.01);
    rectangulo(7.72, -6.36, 8, -12, 8.61, -6.16, 8.84, -11.86);
    rectangulo(14.38, -4.57, 14.66, -10.218, 15.27, -4.38, 15.50, -10.08);
    rectangulo(-16.46, -6.17, -16.47, -11.82, -15.73, -6.23, -15.50, -11.94);
    lineas(-8.95, -6.97, -8.91, -8.32);
    //rectangulo(-16.74, -1.89, -5.8, -2.9, -16.9, -5.8, -7.9, -6.87);

    //rectangulo(3.1, -4.11, 3.1, -7.15, 3.61, -3.93, 3.63, -6.96);
    rectangulo(3.1, -3.9, 3.1, -6.8, 3.61, -3.9, 3.63, -6.8);
    rectangulo(5.04, -3.29, 5.02, -6.36, 5.68, -3.18, 5.68, -6.16);
    rectangulo(7.37, -2.81, 7.35, -5.73, 8, -2.7, 7.98, -5.57);
    rectangulo(9.69, -2.34, 9.65, -5.17, 10.33, -2.23, 10.3, -4.98);
    rectangulo(11.83, -1.75, 11.8, -4.61, 12.47, -1.8, 12.46, -4.45);
    rectangulo(13.78, -1.55, 13.77, -3.95, 14.41, -1.44, 14.43, -3.9);
}
void barrotes(){
    //rectangulo(-15, -2.55, -14.4, -2.62, -15, -5.1, -14.4, -5.1);
    //rectangulo(-15, -2.36, -14.41, -2.44, -15, -4.85, -14.48, -4.97);
    rectangulo(-14.98, -2.73, -14.98, -5.22, -14.4, -2.8, -14.43, -5.33);
    rectangulo(-12.63, -2.96, -12.71, -5.6, -12, -3, -12.03, -5.71);
    rectangulo(-10.38, -3.26, -10.46, -5.89, -9.76, -3.29, -9.8, -6.01);
    //rectangulo(-7.967, -3.47, -7.9, -6.29, -7.33, -3.53, -7.74, -6.33);
    lineas(-7.967, -3.47, -7.9, -6.29);
    lineas(-7.44, -3.53, -7.64, -6);
}
void ventana(){
    rectangulo(3.42, 2.5, 10.55, 3.62, 3.45, -1.16, 10.6, 0.13);
    //vidrios
    rectangulo(3.75, 2.1, 5.25, 2.35, 3.8, 0.85, 5.3, 1.05);  
    rectangulo(5.65, 2.4, 6.95, 2.6, 5.7, 1.15, 7, 1.35);
    rectangulo(7.3, 2.4, 8.6, 2.9, 7.35, 1.45, 8.7, 1.67);
    rectangulo(9, 3, 10.1, 3.16, 9, 1.79, 10.2, 1.9);

    rectangulo(3.75, 0.4, 5.25, 0.6, 3.8, -0.6, 5.3, -0.38);  
    rectangulo(5.67, 0.75, 6.95, 1.02, 5.7, -0.25, 6.96, -0.03);  
    rectangulo(5.67, 0.75, 6.95, 1.02, 5.7, -0.25, 6.96, -0.03);
    rectangulo(7.34, 1.04, 8.6, 1.28, 7.39, 0.01, 8.65, 0.23);
    rectangulo(9.00, 1.32, 10.2, 1.57, 8.95, 0.3, 10.2, 0.5);
}
void techo(){
    rectangulo(-10, 9, -4, 15, -9.8, 8.8, -3.8, 14.8);
    rectangulo(-4, 15, 2, 8, -4.2, 14.8, 1.8, 7.8);
    rectangulo(-9.8, 8.9, -4, 14.5, -8.5, 8, -3.1, 13.5);
    lineas(-4, 14.9, 2, 14.7);
    lineas(4.5, 14.6, 9, 14.5);
    //lineas(2, 8, 12.5, 9.5);
    //lineas(2, 7.6, 12.5, 9.1);
    rectangulo(2, 7.6, 12.5, 9.1, 2, 8, 12.5, 9.5);
    lineas(12.5, 9.5, 9, 14.5);
    //lineas del techo
    lineas(-0.6, 14.88, 4, 8.35);
    lineas(1.3, 14.8, 5.5, 8.6);
    lineas(4.3, 12.7, 7.2, 8.9);
    lineas(5.05, 14.7, 8.75, 9);
    lineas(6.9, 14.6, 10.5, 9.1);
    //chimenea
    lineas(2, 14.7, 2, 16.1);
    lineas(4.5, 14.6, 4.5, 16);
    lineas(3.2, 12.8, 3.2, 18);
    lineas(3.2, 12.7, 4.5, 12.7);
    lineas(4.5, 12.7, 4.5, 16);
    lineas(3.2, 12.8, 2, 14.7);
    //triangulo chimenea
    lineas(1.9, 16.1, 3.2, 16.2);
    lineas(3.2, 16.2, 4.6, 16.1);
    lineas(1.9, 16.1, 3.2, 18);
    lineas(3.2, 18, 4.6, 16.1);

    //paredes //central
    lineas(-8.5, 8, -8.5, 5.9);
    lineas(2, 7.6, 2, 5.3);
    lineas(11.4, 8.9, 11.4, 6.2);
    puerta();
    rectangulo(-13.57, 6.13, 2.75, 5.13, -13.57, 4.87, 2.75, 3.96);
    rectangulo(2.75, 5.13, 16.26, 6.86, 2.75, 3.96, 16.30, 5.91);
    lineas(-8.45, 4.45, -8.45, -2.4);
    lineas(1.95, 3.95, 1.95, -3.02);

    //columnas
    rectangulo(12.77, 5.31, 12.87, -0.6, 13.45, 5.45, 13.55, -0.33);

    rectangulo(-0.33, 4.05, -0.33, -3.65, 0.63, 4.02, 0.56, -3.42);
    //lineas(12.77, 5.31, 12.87, -0.6);
    //lineas(13.45, 5.45, 13.55, -0.33);
    rectangulo(-10.2, 4.65, -10.2, -2.4, -9.46, 4.61, -9.46, -2.42);
    ventana();
    escalera();
    barandales();
}

void casita(){
    barrotes();
}

void planoCartesiano(){
	lineas(0 ,20 ,0 ,-20);
	lineas(-20 ,0 ,20 ,0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    planoCartesiano();
    techo();
    casita();
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
	glClearColor(0.6,0.4,0.7,1);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -10, 10);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1368, 768);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


