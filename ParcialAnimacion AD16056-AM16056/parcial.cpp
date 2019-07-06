#include <iostream>
#include <unistd.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define RUTA_AUDIO "imperial.wav" //nombre del archivo de audio
// funcion para cargar audio
void my_audio_callback(void *userdata, Uint8 *stream, int len);
// variables para audio
static Uint8 *audio_pos; 
static Uint32 audio_len; 

using namespace std;

float alpha = 0;
float beta = 0;
int xii;
int yii;
GLint texture[0];
GLfloat xfps = 300;
GLfloat xips = -400;
GLfloat zps = 50;
GLfloat xip = 300;
GLfloat xfp = 350;

GLfloat yipi = 280;
GLfloat yfpi = 100;
GLfloat xipi = 300;
GLfloat xfpi = 350;
GLfloat zipi = -25;
GLfloat zfpi = 25;

GLfloat ang = 0.0;
GLfloat rpsz = 0;
/*////////////////
125,325
-75,-325
225,125
-175,-225
*/

GLfloat cubosx[] = {125,-75,225,-175};
GLfloat cubosz[] = {300,50,125,-225};

GLint nc = 0;

void cubo(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf, GLfloat k){
	GLfloat nx = (xf-xi)/k;
	GLfloat ny = (yf-yi)/k;
	GLfloat nz = (zf-zi)/k;

	glBegin(GL_POLYGON);
	glTexCoord2f(0,0);
glVertex3f(xi,yf,zi);
glTexCoord2f(0,ny);
glVertex3f(xi,yi,zi);
glTexCoord2f(nx,ny);
glVertex3f(xf,yi,zi);
glTexCoord2f(nx,0);
glVertex3f(xf,yf,zi);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0,0);
glVertex3f(xi,yf,zi);
glTexCoord2f(0,ny);
glVertex3f(xi,yi,zi);
glTexCoord2f(nz,ny);
glVertex3f(xi,yi,zf);
glTexCoord2f(nz,0);
glVertex3f(xi,yf,zf);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0,0);
glVertex3f(xf,yi,zi);
glTexCoord2f(0,ny);
glVertex3f(xf,yf,zi);
glTexCoord2f(nz,ny);
glVertex3f(xf,yf,zf);
glTexCoord2f(nz,0);
glVertex3f(xf,yi,zf);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0,0);
glVertex3f(xi,yi,zf);
glTexCoord2f(0,ny);
glVertex3f(xi,yf,zf);
glTexCoord2f(nx,ny);
glVertex3f(xf,yf,zf);
glTexCoord2f(nx,0);
glVertex3f(xf,yi,zf);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0,0);
glVertex3f(xi,yi,zi);
glTexCoord2f(0,nz);
glVertex3f(xi,yi,zf);
glTexCoord2f(nx,nz);
glVertex3f(xf,yi,zf);
glTexCoord2f(nx,0);
glVertex3f(xf,yi,zi);
glEnd();
glBegin(GL_POLYGON);
glTexCoord2f(0,0);
glVertex3f(xi,yf,zi);
glTexCoord2f(0,nz);
glVertex3f(xi,yf,zf);
glTexCoord2f(nx,nz);
glVertex3f(xf,yf,zf);
glTexCoord2f(nx,0);
glVertex3f(xf,yf,zi);
glEnd();
	
}

void display(){
	
	glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

    

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-600,600,-600,600,-600,600);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();

 //glPushMatrix();
 gluLookAt(0.0f, 0.0f, 1.0f,
0.0f, 0.0f, 0.0f,
 0.0f, 1.0f, 0.0f);
 //X = alpha;
 //Y = beta;
 glRotatef(alpha, 1.0f, 0.0f, 0.0f); 
 glRotatef(beta, 0.0f, 1.0f, 0.0f);
 ///////////piso
glColor3f(1,1,1);
cubo(-600,600,-51,-50,-1000,1000,0);


 glColor3f(0,0,1);
cubo(-450,-250,-50,50,-50,50,0);
glColor3f(0,1,1);
cubo(-300,-400,50,400,-50,50,0);
glColor3f(1,0,1);

cubo(xips,xfps,400,450,zps-100,zps,0);//////
cubo(xip,xfp,480,280,-50,zps,zps-50);//
glColor3f(1,1,0);
cubo(xipi+20,xfpi-20,yfpi,yipi,zipi+20,zfpi-20,0);//pita
glColor3f(1,0,0);
cubo(xipi,xfpi,yfpi,yfpi-50,zipi,zfpi,0);//iman
//glPopMatrix();

///////////////////////cubos
glColor3f(0,0,1);
cubo(100,200,-50,0,350,300,0);
glColor3f(1,0,0);
cubo(-100,0,-50,0,-350,-300,0);
glColor3f(0,1,0);
cubo(200,300,-50,0,100,150,0);
glColor3f(0,1,0);
cubo(-200,-100,-50,0,-200,-250,0);
/*////////////////
125,325
-75,-325
225,125
-175,-225
*/




	 glFlush();
 glutSwapBuffers();
}

void encogerP(){
	if(yfpi <=280){
		yfpi -= 2;
	}
	
}

void alargarP(){
	if(yipi <=280){
		yfpi+= 2;
	}
	
}

void encoger(){
	//xfps++;
	//if(xfps >=-200){
	xfps--;
	xip--;
	xfp--;
	xipi--;
	xfpi--;
	
	//}
	
}

void alargar(){
	if(xfps <=400){
		xfps++;
	xip++;
	xfp++;
	xipi++;
	xfpi++;
	}
	
}
void acercar(){
	
		zps--;
	
}
void alv();
void subir();
void buscar();


void alv(){
	
	if(yfpi>=0)
	{
		yfpi--;
	}
	else{
			glutIdleFunc(subir);
	}



				glutPostRedisplay();
	
}

void subir(){
	
	if(yfpi<=100)
	{
		yfpi++;
	}
	else{
		nc++;
		xfps = 300;
		 xip = 300;
 xfp = 350;
  yipi = 280;
 yfpi = 100;
 xipi = 300;
 xfpi = 350;
		glutPostRedisplay();
	glutIdleFunc(buscar);


	}
				glutPostRedisplay();
	
}

void buscar(){
//glutPostRedisplay();
	int n = sizeof(cubosx);
	if(!nc>n-1){
		glutIdleFunc(NULL);
		return;
	}
	if(nc<sizeof(cubosx)){
	//for(int i = 0;i<=n;i++){
		if(xfps != cubosx[nc]){
			cout << cubosx[nc] << endl;
		encoger();
		}
		else{
			glutIdleFunc(alv);
		}
	//}
	
	
	
}
	
	glutPostRedisplay();
}

void keyboard(int key, int x, int y)
{


  switch (key) {
    case GLUT_KEY_LEFT :
    nc = 0;
		buscar();
    break;
    case GLUT_KEY_RIGHT :
		alargar();
    break;
      case GLUT_KEY_UP :
		alargarP();
    break;
      case GLUT_KEY_DOWN :
		encogerP();
    break;
    }
    glutPostRedisplay();
}

void onMouse(int button, int state, int x, int y) {
 if ( (button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN) ) {
 xii = x; yii = y;
 
 }
}

void onMotion(int x, int y) {
alpha = (alpha + (y - yii));
beta = (beta + (x - xii));
 xii = x;
 yii = y;
 //XXX++;
 glutPostRedisplay();
}


void keys(unsigned char key, int x, int y) {
        // La animación inicia al presionar la tecla espaciadora de igual forma se detiene
    if ( key == 'B' || key == 'b' ) {
			nc = 0;
			SDL_PauseAudio(0);
		   glutIdleFunc(buscar);
		   
	   }

	glutPostRedisplay();
}


int main(int argc, char **argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("Animacion Grua Mario Alvarenga, Albery Arteaga");
  // sonido
        // Inicializar SDL.
        if (SDL_Init(SDL_INIT_AUDIO) < 0)
                return 1;

        // Variables locales
        static Uint32 wav_length; // Longitud de nuestra muestra
        static Uint8 *wav_buffer; // Buffer que contiene nuestro archivo de audio
        static SDL_AudioSpec wav_spec; // Las especificaciones de nuestra pieza de música

        /* Cargar el WAV */
        // Las especificaciones, la longitud y el búfer de nuestro wav se llenan
        if( SDL_LoadWAV(RUTA_AUDIO, &wav_spec, &wav_buffer, &wav_length) == NULL )
        {
                return 1;
        }
        // Establecer la función de devolución de llamada
        wav_spec.callback = my_audio_callback;
        wav_spec.userdata = NULL;

        // Establecer nuestras variables estáticas globales
        audio_pos = wav_buffer; // Copia el buffer de sonido
        audio_len = wav_length; // Copia la longitud del archivo

        /*Abrir el dispositivo de audio */
        if ( SDL_OpenAudio(&wav_spec, NULL) < 0 )
        {
                fprintf(stderr, "No se pudo abrir el audio: %s\n", SDL_GetError());
                exit(-1);
        }

  // register callbacks
  glutDisplayFunc(display);
  //glutReshapeFunc(camara);
  //glutKeyboardFunc(keyboard);
  glutSpecialFunc(keyboard);
	glutKeyboardFunc(keys); 
  // OpenGL init

   glutMouseFunc(onMouse); 

glutMotionFunc(onMotion);

  glutMainLoop();
  return 0;
  //SDL_PauseAudio(0);
        while ( audio_len > 0 )
        {
                SDL_Delay(100); // espera un segundo para la pausa
        }
        SDL_CloseAudio();
        SDL_FreeWAV(wav_buffer);
}
//Función de devolución de llamada de audio donde se recoren los valores del bufer
void my_audio_callback(void *userdata, Uint8 *stream, int len)
{

        if (audio_len ==0)
                return;

        len = ( len > audio_len ? audio_len : len );

        SDL_memcpy (stream, audio_pos, len); // Simplemente copie desde un buffer en el otro
        //SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME / 2); // Mezclar de un buffer a otro

        audio_pos += len;
        audio_len -= len;
}
