#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "esfera.h"
using namespace std;


void cuadros(){

    //cuadro izquierda mediano
    lineas(-17.95, 8.13, -13.97, 9.17);
    lineas(-17.95, 8.13, -13.75, 5.158);
    lineas(-13.75, 5.158, -9.015, 6.399);
    lineas(-13.975, 9.17, -9.015, 6.399);
    lineas(-13.975, 9.17, -9.015, 6.399);


    lineas(-17.95, 8.13, -18.134, 0.05);
    lineas(-13.75, 5.158, -13.83, -4.76);
    lineas(-9.015, 6.399, -8.94, -2.9385);


    lineas(-18.13, 0.0524, -13.83, -4.76);
    lineas(-13.83, -4.76, -8.94, -2.9385);

    //cuadro izquierda grande
    lineas(-14.95, 9.11, -14.92, 10.849);
    lineas(-14.92, 10.849, -12.5087, 11.4018);
    lineas(-14.92, 10.849, -9.015, 7.7122);
    lineas(-9.015, 7.7122, -9.015, -5.8565);
    lineas(-9.015, -5.8565, -5.1489, -4.1787);
    lineas(-9.015, -5.8565, -11.1856, -3.884);
    lineas(-9.015, 7.7122, -2.887, 9.39);
    //lineas(-5.7325, 10.77, -2.887, 9.39);
    lineas(-6.016, 10.8849, -2.887, 9.39);
    lineas(-2.887, 9.39, -2.84075, 1.5061);


    //cono
    lineas(-5.1489, -4.1787, 2.033, 13.2480);
    lineas(2.033, 13.2480, 10.7543, -4.03280);
    esferas(1, 8, 4, 2.9, -4.1787, "ab");

    //esfera
    esferas(1, 3.6, 4.2, -9.2, 13, "c");

    //cubo pequeño central
    lineas(-4.1276, 17.9983, -1.866, 17.7065);
    lineas(-4.1276, 17.9983, -1.6472,  18.5089);
    lineas(-1.866, 17.7065, 0.6871, 18.07128);
    lineas(-1.6472, 18.5089, 0.6871, 18.07128);
    lineas(-4.1276, 17.9983, -4.1276, 15.4450);
    lineas(-1.866, 17.7065, -1.866, 15);
    lineas(0.6871, 18.07128, 0.76, 15.518);
    lineas(-4.1276, 15.4450, -1.866, 15);
    lineas(-1.866, 15, 0.76, 15.518);

    //cilindro pequeño
    lineas(13.38, 8.077, 13.5264, -2.7196);
    lineas(5.0584, 7.9057, 5.0584, 7.3974);
    esferas(1, 4.15, 1, 9.2, 8, "c");
    esferas(1, 2.9, 1, 10.6, -2.7, "4ta3");


    //cilindro grande
    lineas(8.2, 16.247, 8.277, 9.0354);
    lineas(16.517, 16.32, 16.517, 2.82456);
    esferas(1, 4.15, 1, 12.4, 16.2, "c");
    esferas(1, 2.9, 1, 13.6, 2.8, "4ta3");


    //cuadro pequeño esquina derecha
    lineas(14.62, 1.657, 14.62, -0.8229);
    lineas(16.225, 1.0737, 16.225, -1.4795);
    lineas(14.62, 1.657, 16.225, 1.0737);
    lineas(14.62, -0.8229, 16.225, -1.4795);
    lineas(16.225, 1.0737, 17.6117, 2.095);
    lineas(14.62, 1.657, 16, 2.8245);
    lineas(16, 2.8245, 17.611, 2.09505);
    lineas(16.225, -1.4795, 17.657, -0.604);
    lineas(17.611, 2.09505, 17.657,  -0.604);
}

void planoCartesiano(){
	lineas(0 ,20 ,0 ,-10);
	lineas(-20 ,5 ,20 ,5);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    planoCartesiano();
    cuadros();
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
	glClearColor(0.6,0.4,0.7,1);
    glLoadIdentity();
    glOrtho(-20, 20, -10, 20, -10, 10);
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


