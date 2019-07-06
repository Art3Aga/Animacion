#include <GL/glut.h> 
#include <stdio.h> 
#include <math.h> 
#include <SDL2/SDL.h>
#include <SOIL/SOIL.h>
#include <cstring>
#define PI 3.141592 
#define RUTA_AUDIO "cartoon068.wav" //nombre del archivo de audio
int frameNumber;   // Numero de frames
// funcion para cargar audio
void my_audio_callback(void *userdata, Uint8 *stream, int len);   
// variables para audio
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play
bool teclas[5]; 
// --------------- Para animación  ------------------------------------------

int animating = 0;      // 0 sin animación
                        // Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()

void pauseAnimation() {
        // Llamamo a la función para detener la animación
        animating = 0;
}
void updateFrame() {
        // En esta funcion agregamos el codigo que hara la secuencia de cada escena como si fuera un fotograma
        //Verificamos el numero de frames para detener animación
        if(frameNumber==14)
        {
                pauseAnimation();
                //si se detiene la animacion detenemos el audio
                SDL_PauseAudio(1);
                frameNumber=0;
        }
        //Almacenamos el numero de frames
        frameNumber++;
        printf ("Numero de Frame: %d \n", frameNumber);
}

void timerFunction(int timerID) {
        // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones
        if (animating) {
                updateFrame();
                glutTimerFunc(50, timerFunction, 0);
                glutPostRedisplay();
        }
}

void startAnimation() {
        // llamamos la función para iniciar la animación
        if ( !animating ) {
                animating = 1;
                glutTimerFunc(30, timerFunction, 1);
        }
}

class Barra { 
   public: 
      float posicion; 
      bool lado; 
       
      void Iniciar(bool lado_barra) { 
         posicion = 12; 
         lado = lado_barra; 
      } 
       
      void Avanzar(bool arriba, bool abajo) { 
         if (arriba) posicion += 0.5f; 
         if (abajo) posicion -= 0.5f; 
         if (posicion < 0) posicion = 0; 
         if (posicion > 24) posicion = 24; 
      } 
       
      void Pintar(bool lado) { 
         glPushMatrix(); 
         glTranslatef(5+(lado*30),posicion,0); 
         glColor3f(1,0,0); 
         glRectf(-0.25,0,0.25f,1); 
         glColor3f(1,1,1); 
         glRectf(-0.25f,1,0.25f,5); 
         glColor3f(1,0,0); 
         glRectf(-0.25,5,0.25f,6); 
         glPopMatrix(); 
      } 
}; 

class Bola { 
   public: 
      float posicion[2], velocidad, rapida, angulo; 
      bool pausado; 
       
      void Iniciar() { 
         posicion[0] = 20; 
         posicion[1] = 15; 
         velocidad = 0.25f; 
         rapida = 1; 
         angulo = 1.3*PI; 
         pausado = 1; 
      } 
       
      void desPausar(bool pausa) { 
         if (pausa) pausado = 0; 
      } 
       
      void Acelerar() { 
         velocidad += 0.0001f; 
      } 
       
      void Avanzar(int direccion) { 
         posicion[0] += (!pausado)*direccion*rapida*velocidad*cosf(angulo); 
         posicion[1] += (!pausado)*direccion*rapida*velocidad*sinf(angulo); 
      } 
       
      void Rebotar(Barra *bar) { 
         if (posicion[1] > 30 || posicion[1] < 0) { 
            Avanzar(-1); 
            angulo = 2*PI - angulo; 
            Avanzar(1); 
         } 
         if (posicion[0] < 5.5f && posicion[0] > 4.5f && posicion[1] > bar[0].posicion && posicion[1] < bar[0].posicion + 6) { 
            Avanzar(-1); 
            angulo = (-PI/2) + ((PI/8) + ((posicion[1] - bar[0].posicion)/6)*(PI - PI/4)); 
            if (posicion[1] - bar[0].posicion < 1 || posicion[1] - bar[0].posicion > 5){
               rapida = 2; 
               startAnimation();
               SDL_PauseAudio(0);
            } 
            else {
               rapida = 1; 
               startAnimation();
               SDL_PauseAudio(0); 
               //pauseAnimation();
               //SDL_PauseAudio(1);
            }
            Avanzar(1); 
         } 
         if (posicion[0] < 35.5f && posicion[0] > 34.5f && posicion[1] > bar[1].posicion && posicion[1] < bar[1].posicion + 6) { 
            Avanzar(-1); 
            angulo = (-PI/2) - ((PI/8) + ((posicion[1] - bar[1].posicion)/6)*(PI - PI/4)); 
            if (posicion[1] - bar[1].posicion < 1 || posicion[1] - bar[1].posicion > 5) {
               rapida = 2;
               startAnimation();
               SDL_PauseAudio(0);
            } 
            else{
               rapida = 1; 
               startAnimation();
               SDL_PauseAudio(0); 
            } 
            Avanzar(1); 
         } 
      } 
       
      void Pintar() { 
         glPushMatrix(); 
         glColor3f(1,1,1); 
         glTranslatef(posicion[0],posicion[1],0); 
         glBegin(GL_TRIANGLE_FAN); 
            glVertex2f(0,0); 
            for (float ang = 0; ang <= PI*2; ang += PI/8) glVertex2f(0.25*cosf(ang),0.25*sinf(ang)); 
         glEnd(); 
         glPopMatrix(); 
      } 
}; 

class Marcador { 
   public: 
      int jugador[2]; 
       
      void Puntuar(Bola& bola) { 
         if (bola.posicion[0] < 2) { 
            jugador[0]++; 
            //startAnimation();
            //SDL_PauseAudio(0);
            bola.Iniciar(); 
         } 
         if (bola.posicion[0] > 38) { 
            jugador[1]++; 
            bola.Iniciar(); 
         } 
      } 
       
      void Pintar() { 
         char marcador[15]; 
         sprintf(marcador,"J1: %i | J2: %i",jugador[0],jugador[1]); 
         glRasterPos3f(18,29,0); 
         for (int i = 0; i < strlen(marcador); i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, marcador[i]); 
      } 
}; 

Barra barras[2]; 
Bola bola; 
Marcador puntos; 

void PintarEscena() { 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   glOrtho(0,40,0,30,-1,1); 
    
   glMatrixMode(GL_MODELVIEW); 
   glClear(GL_COLOR_BUFFER_BIT); 
   glLoadIdentity(); 
    
   for (int i = 0; i < 2; i++) barras[i].Pintar(i); 
   bola.Pintar(); 
   puntos.Pintar(); 
    
      glutSwapBuffers(); 
} 

void ReProyectar(int w, int h) { 
   glutReshapeWindow(800,600); 
   glViewport(0, 0, w, h); 

      PintarEscena(); 
} 

void Teclas(unsigned char key, int x, int y) { 
   if (key == 13) teclas[0] = 1; 
   if (key == 'w' || key == 'W'){
      teclas[1] = 1;
      //pauseAnimation();
      //SDL_PauseAudio(1);
   } 
   if (key == 's' || key == 'S'){
       teclas[2] = 1;
      //pauseAnimation();
      //SDL_PauseAudio(1);
   }
   if (key == 'i' || key == 'I'){
      teclas[3] = 1;
      //pauseAnimation();
      //SDL_PauseAudio(1);
   }
   if (key == 'k' || key == 'K'){
      teclas[4] = 1;
      //pauseAnimation();
      //SDL_PauseAudio(1);
   }
   else{
      //startAnimation();
      //SDL_PauseAudio(0);
   }
} 

void TeclasUp(unsigned char key, int x, int y) { 
   if (key == 13) teclas[0] = 0; 
   if (key == 'w' || key == 'W') teclas[1] = 0; 
   if (key == 's' || key == 'S') teclas[2] = 0; 
   if (key == 'i' || key == 'I') teclas[3] = 0; 
   if (key == 'k' || key == 'K') teclas[4] = 0; 
} 

void Mover(int value) { 
   glutTimerFunc(17,Mover,1); 
   glutPostRedisplay(); 
    
   barras[0].Avanzar(teclas[1],teclas[2]); 
   barras[1].Avanzar(teclas[3],teclas[4]); 
   bola.Avanzar(1); 
   bola.desPausar(teclas[0]); 
   bola.Rebotar(barras); 
   bola.Acelerar(); 
   puntos.Puntuar(bola); 
} 

int main(int argc, char **argv) { 
      glutInit(&argc,argv); 
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
     glutInitWindowSize(800,600); 
     glutInitWindowPosition(40,40); 
     glutCreateWindow("Pong por HarZe"); 
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
        frameNumber = 0;
    
   for (int i = 0; i < 2; i++) barras[i].Iniciar(i); 
   bola.Iniciar(); 
  
     glutReshapeFunc(ReProyectar); 
   glutDisplayFunc(PintarEscena); 
     glutKeyboardFunc(Teclas); 
     glutKeyboardUpFunc(TeclasUp); 
     glutTimerFunc(17,Mover,1); 

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
