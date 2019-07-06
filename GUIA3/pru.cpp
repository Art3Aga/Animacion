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
GLfloat scale = 1.0f;
 
GLint ancho=0;
GLint alto=0;

int Perpestive= 1 ;
void dis(){

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

    glBegin(GL_POLYGON);
   glColor3f( 1.0,  1.0, 0.0 ); 
   glVertex3f( 0.6, -0.5, -0.5);
   glVertex3f( 0.6, -0.5,  0.5);
   glVertex3f(-0.6, -0.5,  0.5);   
   glVertex3f(-0.6, -0.5, -0.5);

	glEnd();

   glBegin(GL_POLYGON);
   glColor3f( 1.0,  5.0, 0.0 );
   glVertex3f( -0.6, -0.5,  0.5 );
   glVertex3f( -0.6, -0.2,  0.5 );
   glVertex3f( -0.6, -0.2, -0.5 );
   glVertex3f( -0.6, -0.5, -0.5 );

	glEnd();

   glBegin(GL_POLYGON);
   glColor3f( 0.0,  0.1, 0.0 ); 
   glVertex3f( 0.6, -0.5, 0.5 );
   glVertex3f( 0.6, -0.2, 0.5 );
   glVertex3f(-0.6, -0.2, 0.5 );
   glVertex3f(-0.6, -0.5, 0.5 );

	glEnd();

   glBegin(GL_POLYGON);
   glColor3f( 0.1,  0.0, 0.0 ); 
   glVertex3f( 0.6, -0.5,  0.5 );
   glVertex3f( 0.6, -0.2,  0.5 );
   glVertex3f( 0.6, -0.2, -0.5 );
   glVertex3f( 0.6, -0.5, -0.5 );
	glEnd();

   glBegin(GL_POLYGON);
   glColor3f( 0.0,  0.0, 0.1 ); 
   glVertex3f( 0.6, -0.5, -0.5 );
   glVertex3f( 0.6, -0.2, -0.5 );
   glVertex3f(-0.6, -0.2, -0.5 );
   glVertex3f(-0.6, -0.5, -0.5 );

	glEnd();

    glBegin(GL_POLYGON);
   glColor3f( 1.0,  1.0, 1.0 ); 
   glVertex3f( 0.6, -0.5, -0.1 );
   glVertex3f( 0.6, -0.2, -0.1 );
   glVertex3f( 0.0, -0.2, -0.1 );
   glVertex3f( 0.0, -0.5, -0.1 );

	glEnd();

   glBegin(GL_POLYGON);
   glColor3f( 1.0,  1.0, 1.0 ); 
   glVertex3f( -0.6, -0.5, -0.1 );
   glVertex3f( -0.6, -0.2, -0.1 );
   glVertex3f( -0.1, -0.2, -0.1 );
   glVertex3f( -0.1, -0.5, -0.1 );

	glEnd();

   glBegin(GL_POLYGON);
   glColor3f( 1.0,  1.0, 0.0 ); 
   glVertex3f( 0.6, 0.5, -0.5);
   glVertex3f( 0.6, 0.5,  0.5);
   glVertex3f(-0.6, 0.5,  0.5);   
   glVertex3f(-0.6, 0.5, -0.5);

	glEnd();
   glFlush ();
   glutSwapBuffers();

}
void lin(){
 /*
    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);

    glPointSize(0.9);
   glBegin(GL_LINE_LOOP);
   glColor3f (0.0, 0.0, 0.0);
   glVertex3f( 0.6, -0.5, -0.5);
   glVertex3f( 0.6, -0.5,  0.5);
   glVertex3f(-0.6, -0.5,  0.5);   
   glVertex3f(-0.6, -0.5, -0.5);

	glEnd();
   glFlush ();


   glBegin(GL_LINE_LOOP);
        glColor3f (0.0, 0.0, 0.0);

   glVertex3f( -0.6, -0.5,  0.5 );
   glVertex3f( -0.6, -0.1,  0.5 );
   glVertex3f( -0.6, -0.1, -0.5 );
   glVertex3f( -0.6, -0.5, -0.5 );

	glEnd();
   glFlush ();


    glBegin(GL_LINE_LOOP);
     glColor3f (0.0, 0.0, 0.0);
   glVertex3f( 0.6, -0.5, 0.5 );
   glVertex3f( 0.6, -0.1, 0.5 );
   glVertex3f(-0.6, -0.1, 0.5 );
   glVertex3f(-0.6, -0.5, 0.5 );

	glEnd();
   glFlush ();


  glBegin(GL_LINE_LOOP);
        glColor3f (0.0, 0.0, 0.0);
   glVertex3f( 0.6, -0.5,  0.5 );
   glVertex3f( 0.6, -0.1,  0.5 );
   glVertex3f( 0.6, -0.1, -0.5 );
   glVertex3f( 0.6, -0.5, -0.5 );
	glEnd();
   glFlush ();


 glBegin(GL_LINE_LOOP);
        glColor3f (0.0, 0.0, 0.0);
   glVertex3f( 0.6, -0.5, -0.5 );
   glVertex3f( 0.6, -0.1, -0.5 );
   glVertex3f(-0.6, -0.1, -0.5 );
   glVertex3f(-0.6, -0.5, -0.5 );

	glEnd();
   glFlush ();


glBegin(GL_LINE_LOOP);
        glColor3f (0.0, 0.0, 0.0);
   glVertex3f( 0.6, -0.5, -0.2 );
   glVertex3f( 0.6, -0.1, -0.2 );
   glVertex3f( 0.2, -0.1, -0.2 );
   glVertex3f( 0.2, -0.5, -0.2 );

	glEnd();
   glFlush ();


  glBegin(GL_LINE_LOOP);
        glColor3f (0.0, 0.0, 0.0);

   glVertex3f( -0.6, -0.5, -0.2 );
   glVertex3f( -0.6, -0.1, -0.2 );
   glVertex3f( -0.2, -0.1, -0.2 );
   glVertex3f( -0.2, -0.5, -0.2 );

	glEnd();
   glFlush ();

    glBegin(GL_LINE_LOOP);
    glColor3f (0.0, 0.0, 0.0);

   glVertex3f( 0.6, 0.5, -0.5);
   glVertex3f( 0.6, 0.5,  0.5);
   glVertex3f(-0.6, 0.5,  0.5);   
   glVertex3f(-0.6, 0.5, -0.5);

	glEnd();
   glFlush ();*/
}

// Función para controlar teclas especiales
void specialKeys( int key, int x, int y ){
 
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;
 
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;
 
    //  Solicitar actualización de visualización
    glutPostRedisplay();
 
}
 
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y){
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 's':
        scale=0.5;
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
 

void reshape(int width,int height){
	ancho=400;
	alto=400;
	 glOrtho(-4,4,-4,4,-4,4);
	 glViewport(0,0, alto, ancho);
	 glMatrixMode(GL_PROJECTION);
	 if(Perpestive)
		gluPerspective(60.0f,(GLfloat)width/(GLfloat)height,1.0f,20.0f ) ;
		
	 else
	 glOrtho(-4,4,-4,4,-4,4);
	 glMatrixMode(GL_MODELVIEW);
}

void inid(){
    

	ancho=800;
	alto=800;
	glMatrixMode(GL_BUFFER);
	//glClearColor(1 ,1 ,1 ,0);	
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	
}

void display(void)
{
    dis();
    lin();

}


int main(int argc, char* argv[])
{
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (ancho,alto);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Cubo controlado por teclas");
 
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
 
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

inid();
    // Pasar el control de eventos a GLUT
    glutMainLoop(); 
    // Regresar al sistema operativo
    return 0;
}