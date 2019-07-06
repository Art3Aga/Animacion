#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "esfera.h"
using namespace std;

void campana(){
	//marcoPuerta_Ventana(-1, 8.3, -0.45, 0.6, -0.6, 0.45, 2, 0.4);
	curvas(-1.4, 7.9, -0.6, 7.9);
	curvas(-1.45, 8, -0.55, 8);
	//campana2(0.4, 5);
	//marcoPuerta_Ventana(-1, 8.3, -0.95, 0.4, -0.4, 0.95, 2, 0.7);
	esferas(2, 0.4, 0.2, 0, 8.8, "ab");
	esferas(2, 1.4, 1, 0, 7.8, "ab");
	esferas(2, 0.5, 0.35, 0, 8.7, "ar");

	esferas(2, 0.5, 0.3, 0, 8.8, "ab");
	esferas(2, 1.5, 1.1, 0, 7.8, "ab");
	esferas(2, 0.5, 0.45, 0, 8.7, "ar");

	rectangulo(-0.03, 9, -0.03, 9.3, 0.03, 9, 0.03, 9.3);
	esferas(2, 0.1, 0.2, 0, 9.5, "c");
	esferas(2, 0.15, 0.25, 0, 9.5, "c");
	rectangulo(-0.03, 9.7, -0.03, 10.3, 0.03, 9.7, 0.03, 10.3);
	esferas(2, 0.1, 0.2, 0, 10.5, "c");
	esferas(2, 0.15, 0.25, 0, 10.5, "c");
}
void torresLaterales(){
	//izquierda
	//base
	rectangulo(-4.2, 1.5, -2.2, 1.5, -4.2, 0.55, -2.2, 0.55);
	//flecha
	lineas(-2.2, 2, -4.2, 2);
	lineas(-4.2, 2, -4.4, 1.65);
	lineas(-4.2, 1.5, -4.4, 1.65);
	//esfera
	esferas(2, 0.9, 1.8, -3.2, 2, "ar");
	esferas(2, 0.8, 1.6, -3.2, 2, "ar");
	//bandera
	rectangulo(-3.15, 3.8, -3.15, 4.2, -3.25, 3.8, -3.25, 4.2);
	esferas(2, 0.1, 0.2, -3.2, 4.5, "c");
	esferas(2, 0.16, 0.3, -3.2, 4.5, "c");
	rectangulo(-3.15, 3.8, -3.15, 4.2, -3.25, 3.8, -3.25, 4.2);
	rectangulo(-3.15, 4.8, -3.15, 5.4, -3.25, 4.8, -3.25, 5.4);
	
	
	//derecha
	//base
	rectangulo(4.2, 1.5, 2.2, 1.5, 4.2, 0.55, 2.2, 0.55);
	//flecha
	lineas(2.2, 2, 4.2, 2);
	lineas(4.2, 2, 4.4, 1.65);
	lineas(4.2, 1.5, 4.4, 1.65);
	//esfera
	esferas(2, 0.9, 1.8, 3.2, 2, "ar");
	esferas(2, 0.8, 1.6, 3.2, 2, "ar");
	//bandera
	rectangulo(3.15, 3.8, 3.15, 4.2, 3.25, 3.8, 3.25, 4.2);
	esferas(2, 0.1, 0.2, 3.2, 4.5, "c");
	esferas(2, 0.16, 0.3, 3.2, 4.5, "c");
	rectangulo(3.15, 3.8, 3.15, 4.2, 3.25, 3.8, 3.25, 4.2);
	rectangulo(3.15, 4.8, 3.15, 5.4, 3.25, 4.8, 3.25, 5.4);

}
void torrePrincipal(){
	//marcoPuerta_Ventana(0, 3, -0.5, 0.1, -0.1, 0.5, 0.2, 0.9); PARA LAS VENTANAS
	//marcoPuerta_Ventana(-0.65, 8, -2, 2, -2, 2, 1.25, 1);
	campana();
	//esferas(2, 1.8, 3, -1.2, 4, "4ta");
	

	//izquierda
	esferas(2, 1.2, 2.8, -1.6, 5.2, "4ta");
	esferas(2, 1.1, 2.7, -1.6, 5.2, "4ta");
	//derecha
	esferas(2, 1.1, 2.7, 1.6, 5.2, "4ta2");
	esferas(2, 1.2, 2.8, 1.6, 5.2, "4ta2");
	//esferas(2, 1.5, 3, -1.2, 3, "4ta");
	//esferas(2, 1, 3, -2.3, 6, "4ta");
	//torreArriba(-2.3,5);
}
void puertas(){
	//puerta grande
	marcoPuerta_Ventana(-0.65, -1, -0.95, 0.6, -0.6, 0.95, 1.25, 0.4);
	lineas(-1.57, -2.4, -1.57, -8);
	lineas(1.52, -2.4, 1.52, -8);
	marcoPuerta_Ventana(-0.65, -0.85, -0.99, 0.6, -0.6, 0.99, 1.25, 0.4);
	lineas(-1.63, -2.4, -1.63, -8);
	lineas(1.58, -2.4, 1.58, -8);
	//puerta mediana
	esferas(2, 1.2, 1.5, 0, -3.5, "ar");
	lineas(-1.2, -3.5, -1.2, -8);
	lineas(1.2, -3.5, 1.2, -8);
	esferas(2, 1.28, 1.6, 0, -3.5, "ar");
	lineas(-1.28, -3.5, -1.28, -8);
	lineas(1.28, -3.5, 1.28, -8);
	//puerta pequeña
	esferas(2, 0.7, 1, 0, -5.5, "ar");
	lineas(-0.7, -5.5, -0.7, -8);
	lineas(0.7, -5.5, 0.7, -8);
	esferas(2, 0.6, 0.9, 0, -5.5, "ar");
	lineas(-0.6, -5.5, -0.6, -8);
	lineas(0.6, -5.5, 0.6, -8);
}
void ventanas(){
	//marcoPuerta_Ventana(-5.7, -4, -0.9, 0.5, -0.5, 0.9, 0.9, 0.9);
	//ventana arriba pared izquierda
	esferas(2, 0.45, 3, -5.8, -4, "ar");
	lineas(-6.25, -4, -5.35, -4);
	//ventana abajo pared izquierda
	esferas(2, 0.45, 3, -5.8, -8, "ar");


	//ventana arriba pared central
	esferas(2, 0.45, 3, -3.8, -4, "ar");
	lineas(-3.35, -4, -4.25, -4);
	//ventana abajo pared central
	esferas(2, 0.45, 3, -3.8, -8, "ar");

	//ventana arriba pared derecha
	esferas(2, 0.45, 3, 5.8, -4, "ar");
	lineas(6.25, -4, 5.35, -4);
	//ventana abajo pared derecha
	esferas(2, 0.45, 3, 5.8, -8, "ar");

	//ventana arriba pared central
	esferas(2, 0.45, 3, 3.8, -4, "ar");
	lineas(3.35, -4, 4.25, -4);
	//ventana abajo pared central
	esferas(2, 0.45, 3, 3.8, -8, "ar");
}
void puertas_ventanas(){
	ventanas();
	puertas();
}
void cabecera(){
	//rectangulo mayor central
	rectangulo(-2.2, 3, 2.2, 3, -2.2, 0.55, 2.2, 0.55);
	rectangulo(-2.25, 3.1, 2.25, 3.1, -2.25, 0.65, 2.25, 0.65);
	//rectangulo central
	rectangulo(-1.7, 2.6, 1.7, 2.6, -1.7, 1, 1.7, 1);
	rectangulo(-1.75, 2.7, 1.75, 2.7, -1.75, 0.9, 1.75, 0.9);
}
void baseCastillo(){
    rectangulo(-9, -8, 9, -8, -9, -10, 9, -10);
	rectangulo(-9.05, -7.9, 9.05, -7.9, -9.05, -10.05, 9.05, -10.05);
	escaleras();
    glEnd();
}
void columnas(){
	//izquierda
	//rectangulo(-8.5, 1.5, -8.7, -8, -7.5, 1.5, -7.3, -8);
	//rectangulo(-8.55, 1.6, -8.75, -8.05, -7.55, 1.6, -7.35, -8.05);
	rectangulo(-8.2, 1.5, -8.4, -8, -7.5, 1.5, -7.3, -8);
	rectangulo(-8.25, 1.6, -8.45, -8.05, -7.55, 1.6, -7.35, -8.05);
	ovalos(-7.9, 1.5, 1, 0.35, 1);
	ovalos(-7.91, 1.5, 1, 0.42, 1.1);
	rectangulo(-7.83, 2.6, -7.93, 2.6, -7.83, 3.5, -7.93, 3.5);
	//derecha
	//rectangulo(8.5, 1.5, 8.7, -8, 7.5, 1.5, 7.3, -8);
	//rectangulo(8.55, 1.6, 8.75, -8.05, 7.55, 1.6, 7.35, -8.05);
	rectangulo(8.2, 1.5, 8.4, -8, 7.5, 1.5, 7.3, -8);
	rectangulo(8.25, 1.6, 8.45, -8.05, 7.55, 1.6, 7.35, -8.05);
	ovalos(7.9, 1.5 , 1, 0.35, 1);
	ovalos(7.91, 1.5, 1, 0.42, 1.1);
	rectangulo(7.83, 2.6, 7.93, 2.6, 7.83, 3.5, 7.93, 3.5);
}
void adornosColumnas(){
	//izquierda
	float i=1.53;
	while(i>=-8.05){
		rectangulo(-8.5, i, -7.3, i, -8.2, i-0.5, -7.55, i-0.5);
		rectangulo(-8.55, i, -7.25, i, -8.25, i-0.6, -7.5, i-0.6);
		i-=2.5;
	}
	//derecha
	float j=1.53;
	while(j>=-8.05){
		rectangulo(8.5, j, 7.3, j, 8.2, j-0.5, 7.55, j-0.5);
		rectangulo(8.55, j, 7.25, j, 8.25, j-0.6, 7.5, j-0.6);
		j-=2.5;
	}
}
void castillito(){
	//pared izquierda
	rectangulo(-6.5, 0, -6.5, -8, -5, 0.5, -5, -8);
	rectangulo(-6.55, 0.1, -6.55, -8.05, -4.95, 0.6, -4.95, -8.05);
	//pared derecha
	rectangulo(6.5, 0, 6.5, -8, 5, 0.5, 5, -8);
	rectangulo(6.55, 0.1, 6.55, -8.05, 4.95, 0.6, 4.95, -8.05);
	//pared principal
	rectangulo(-4.95, 0.6, 4.95, 0.6, -4.95, -8.05, 4.95, -8.05);
	rectangulo(-4.95, 0.5, 4.95, 0.5, -4.95, -8.05, 4.95, -8.05);
	columnas();
	adornosColumnas();
	cabecera();
	puertas_ventanas();
	torrePrincipal();
	torresLaterales();
}


void planoCartesiano(){
	glBegin(GL_LINES);
	lineas(0 ,10 ,0 ,-10);
	lineas(-10 ,0 ,10 ,0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    planoCartesiano();
    baseCastillo();
	castillito();
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    //glClearColor(0.5, 0.8, 0.6, 1);
	glClearColor(1,1,1,1);
    glLoadIdentity();
    glOrtho(-15, 15, -15, 15, -10, 10);
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


