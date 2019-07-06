#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
 
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0;
 
void rectangulosuperior(){

// Primera cara, se identica por multiples colores

glBegin(GL_POLYGON);
 
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.3, 0.4, -0.0 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.3,  0.42, -0.0 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.3,  0.42, -0.0);      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.3, 0.4, -0.0 );      // V4 rojo
 
    glEnd();
 
    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.3, 0.4, 0.6 );
    glVertex3f( 0.3, 0.42, 0.6 );
    glVertex3f(-0.3, 0.42, 0.6 );
    glVertex3f(-0.3, 0.4, 0.6 );
    glEnd();
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.3, 0.4, -0.0 );
    glVertex3f(0.3, 0.42, -0.0 );
    glVertex3f(0.3, 0.42,  0.6 );
    glVertex3f(0.3, 0.4,  0.6 );
    glEnd();
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.3, 0.4,  0.6 );
    glVertex3f(-0.3, 0.42,  0.6 );
    glVertex3f(-0.3, 0.42, -0.0 );
    glVertex3f(-0.3, 0.4, -0.0 );
    glEnd();
 
    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.3,  0.42,  0.6 );
    glVertex3f(0.3,  0.42, -0.0 );
    glVertex3f(-0.3,  0.42, -0.0 );
    glVertex3f(-0.3,  0.42,  0.6 );
    glEnd();
 
    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.3, 0.4, -0.0 );
    glVertex3f(0.3, 0.4,  0.6 );
    glVertex3f(-0.3, 0.4,  0.6 );
    glVertex3f(-0.3, 0.4, -0.0 );
    glEnd();
 
    glFlush();

}

void paredtrasera(){

// Primera cara, se identica por multiples colores

glBegin(GL_POLYGON);
 
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.3, -0.3, 0.58 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.3, -0.0, 0.58 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.3, -0.0, 0.58);      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.3, -0.3, 0.58 );      // V4 rojo
 
    glEnd();
 
    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.3, -0.3, 0.6 );
    glVertex3f( 0.3,-0.0, 0.6 );
    glVertex3f(-0.3,-0.0, 0.6 );
    glVertex3f(-0.3, -0.3, 0.6 );
    glEnd();
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.3, -0.3, 0.58 );
    glVertex3f(0.3, 0.00, 0.58 );
    glVertex3f(0.3, 0.00,  0.6 );
    glVertex3f(0.3, -0.3,  0.6 );
    glEnd();
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.3, -0.3,  0.6 );
    glVertex3f(-0.3, 0.00,  0.6 );
    glVertex3f(-0.3, 0.00, 0.58 );
    glVertex3f(-0.3, -0.3, 0.58 );
    glEnd();
 
    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.3, 0.00,  0.6 );
    glVertex3f(0.3, 0.00, 0.58 );
    glVertex3f(-0.3, 0.00, 0.58 );
    glVertex3f(-0.3, 0.00,  0.6 );
    glEnd();
 

    glFlush();

}
void paredcentral1(){

// Primera cara, se identica por multiples colores

glBegin(GL_POLYGON);
 
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.3, -0.3, 0.28 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.3, -0.0, 0.28 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( 0.1, -0.0, 0.28);      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( 0.1, -0.3, 0.28 );      // V4 rojo
 
    glEnd();
 
    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.3, -0.3, 0.3 );
    glVertex3f( 0.3,-0.0, 0.3 );
    glVertex3f(0.1,-0.0, 0.3 );
    glVertex3f(0.1, -0.3, 0.3 );
    glEnd();
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.3, -0.3, 0.28 );
    glVertex3f(0.3, 0.00, 0.28 );
    glVertex3f(0.3, 0.00,  0.3 );
    glVertex3f(0.3, -0.3,  0.3 );
    glEnd();
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(0.1, -0.3,  0.3 );
    glVertex3f(0.1, 0.00,  0.3 );
    glVertex3f(0.1, 0.00, 0.28 );
    glVertex3f(0.1, -0.3, 0.28 );
    glEnd();
 
    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.3, 0.00,  0.3 );
    glVertex3f(0.3, 0.00, 0.28 );
    glVertex3f(0.1, 0.00, 0.28 );
    glVertex3f(0.1, 0.00,  0.3 );
    glEnd();
 

    glFlush();

}

void paredcentral2(){

// Primera cara, se identica por multiples colores

glBegin(GL_POLYGON);
 
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  -0.3, -0.3, 0.28 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  -0.3, -0.0, 0.28 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.1, -0.0, 0.28);      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.1, -0.3, 0.28 );      // V4 rojo
 
    glEnd();
 
    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( -0.3, -0.3, 0.3 );
    glVertex3f( -0.3,-0.0, 0.3 );
    glVertex3f(-0.1,-0.0, 0.3 );
    glVertex3f(-0.1, -0.3, 0.3 );
    glEnd();
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(-0.3, -0.3, 0.28 );
    glVertex3f(-0.3, 0.00, 0.28 );
    glVertex3f(-0.3, 0.00,  0.3 );
    glVertex3f(-0.3, -0.3,  0.3 );
    glEnd();
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.1, -0.3,  0.3 );
    glVertex3f(-0.1, 0.00,  0.3 );
    glVertex3f(-0.1, 0.00, 0.28 );
    glVertex3f(-0.1, -0.3, 0.28 );
    glEnd();
 
    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(-0.3, 0.00,  0.3 );
    glVertex3f(-0.3, 0.00, 0.28 );
    glVertex3f(-0.1, 0.00, 0.28 );
    glVertex3f(-0.1, 0.00,  0.3 );
    glEnd();
 

    glFlush();

}
void paredfrontal(){

// Primera cara, se identica por multiples colores

glBegin(GL_POLYGON);
 
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.3, -0.3, 0.00 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.3, -0.0, 0.00 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.3, -0.0, 0.00);      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.3, -0.3, 0.00 );      // V4 rojo
 
    glEnd();
 
    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.3, -0.3, 0.02 );
    glVertex3f( 0.3,-0.0, 0.02 );
    glVertex3f(-0.3,-0.0, 0.02 );
    glVertex3f(-0.3, -0.3, 0.02 );
    glEnd();
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.3, -0.3, 0.02 );
    glVertex3f(0.3, 0.00, 0.02 );
    glVertex3f(0.3, 0.00,  0.0 );
    glVertex3f(0.3, -0.3,  0.0 );
    glEnd();
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.3, -0.3,  0.0 );
    glVertex3f(-0.3, 0.00,  0.0 );
    glVertex3f(-0.3, 0.00, 0.02 );
    glVertex3f(-0.3, -0.3, 0.02 );
    glEnd();
 
    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.3, 0.00,  0.0 );
    glVertex3f(0.3, 0.00, 0.02 );
    glVertex3f(-0.3, 0.00, 0.02 );
    glVertex3f(-0.3, 0.00,  0.0 );
    glEnd();
 

    glFlush();

}

void rectanguloinferior(){

// Primera cara, se identica por multiples colores

glBegin(GL_POLYGON);
 
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.3, -0.3, -0.0 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.3, -0.28, -0.0 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.3, -0.28, -0.0);      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.3, -0.3, -0.0 );      // V4 rojo
 
    glEnd();
 
    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.3, -0.3, 0.6 );
    glVertex3f( 0.3,-0.28, 0.6 );
    glVertex3f(-0.3,-0.28, 0.6 );
    glVertex3f(-0.3, -0.3, 0.6 );
    glEnd();
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.3, -0.3, -0.0 );
    glVertex3f(0.3,-0.28, -0.0 );
    glVertex3f(0.3,-0.28,  0.6 );
    glVertex3f(0.3, -0.3,  0.6 );
    glEnd();
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.3, -0.3,  0.6 );
    glVertex3f(-0.3,-0.28,  0.6 );
    glVertex3f(-0.3,-0.28, -0.0 );
    glVertex3f(-0.3, -0.3, -0.0 );
    glEnd();
 
    // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f(0.3, -0.28,  0.6 );
    glVertex3f(0.3, -0.28, -0.0 );
    glVertex3f(-0.3, -0.28, -0.0 );
    glVertex3f(-0.3, -0.28,  0.6 );
    glEnd();
 
    // LADO INFERIOR: lado rojo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  0.0,  0.0 );
    glVertex3f(0.3, -0.3, -0.0 );
    glVertex3f(0.3, -0.3,  0.6 );
    glVertex3f(-0.3, -0.3,  0.6 );
    glVertex3f(-0.3, -0.3, -0.0 );
    glEnd();
 
    glFlush();

}

void paredizq(){

// Primera cara, se identica por multiples colores

glBegin(GL_POLYGON);
 
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f( -0.3, -0.3, 0.00 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  -0.3, -0.0, 0.00 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -0.28, -0.0, 0.00);      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( -0.28, -0.3, 0.00 );      // V4 rojo
 
    glEnd();
 
    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( -0.3, -0.3, 0.6 );
    glVertex3f( -0.3,-0.0, 0.6 );
    glVertex3f(-0.28,-0.0, 0.6 );
    glVertex3f(-0.28, -0.3, 0.6 );
    glEnd();
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(-0.3, -0.3, 0.6 );
    glVertex3f(-0.3, 0.00, 0.6 );
    glVertex3f(-0.3, 0.00,  0.0 );
    glVertex3f(-0.3, -0.3,  0.0 );
    glEnd();
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(-0.28, -0.3,  0.0 );
    glVertex3f(-0.28, 0.00,  0.0 );
    glVertex3f(-0.28, 0.00, 0.6 );
    glVertex3f(-0.28, -0.3, 0.6 );
    glEnd();
    
        // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(-0.3,  0.00,  0.6 );
    glVertex3f(-0.3,  0.00, -0.0 );
    glVertex3f(-0.28,  0.00, -0.0 );
    glVertex3f(-0.28,  0.00,  0.6 );
    glEnd();
 
 

 

    glFlush();

}



void paredder(){

// Primera cara, se identica por multiples colores

glBegin(GL_POLYGON);
 
    glColor3f( 1.0, 1.0, 1.0 );
    glVertex3f(  0.3, -0.3, 0.00 );      // V1 Blanco
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.3, -0.0, 0.00 );      // V2 Amarillo
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( 0.28, -0.0, 0.00);      // V3 es azul
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f( 0.28, -0.3, 0.00 );      // V4 rojo
 
    glEnd();
 
    // LADO TRASERO: lado blanco
    glBegin(GL_POLYGON);
    glColor3f( 1.0,  1.0, 1.0 );
    glVertex3f( 0.3, -0.3, 0.6 );
    glVertex3f( 0.3,-0.0, 0.6 );
    glVertex3f(0.28,-0.0, 0.6 );
    glVertex3f(0.28, -0.3, 0.6 );
    glEnd();
 
    // LADO DERECHO: lado verde
    glBegin(GL_POLYGON);
    glColor3f( 0.0,  1.0,  0.0 );
    glVertex3f(0.3, -0.3, 0.6 );
    glVertex3f(0.3, 0.00, 0.6 );
    glVertex3f(0.3, 0.00,  0.0 );
    glVertex3f(0.3, -0.3,  0.0 );
    glEnd();
 
    // LADO IZQUIERDO: lado Amarillo
    glBegin(GL_POLYGON);
    glColor3f(1.0,  1.0,  0.0 );
    glVertex3f(0.28, -0.3,  0.0 );
    glVertex3f(0.28, 0.00,  0.0 );
    glVertex3f(0.28, 0.00, 0.6 );
    glVertex3f(0.28, -0.3, 0.6 );
    glEnd();
    
        // LADO SUPERIOR: lado azul
    glBegin(GL_POLYGON);
    glColor3f(0.0,  0.0,  1.0 );
    glVertex3f(0.3,  0.00,  0.6 );
    glVertex3f(0.3,  0.00, -0.0 );
    glVertex3f(0.28,  0.00, -0.0 );
    glVertex3f(0.28,  0.00,  0.6 );
    glEnd();
 
 

 

    glFlush();

}



void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    rectangulosuperior();
    rectanguloinferior();
    paredtrasera();
    paredfrontal();
    paredder();
    paredizq();
    paredcentral1();
    paredcentral2();
    glutSwapBuffers();
 
}
 
// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
 
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 1;
 
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 1;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 1;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 1;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 1;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 1;
 
    //  Solicitar actualización de visualización
    glutPostRedisplay();
 
}
 
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 's':
        scale=0.42;
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 'q':
        exit(0);			// exit
    }
    glutPostRedisplay();
}
 
 
 
int main(int argc, char* argv[])
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Cubo controlado por teclas");
 
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
 
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}
