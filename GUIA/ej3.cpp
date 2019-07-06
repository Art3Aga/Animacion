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

void ovalos(float posX, float posY, int position, float tamaX ,float tamaY){
	glPointSize(1.5);
	glBegin(GL_POINTS);
	if(position == 1){
		for(int i=500; i<1000; i++){
		float angle = i*(2.0*M_PI/1000);
		float x = cos(angle)*tamaX;
		float y = sin(angle)*tamaY;
		glColor3f(0,0,1);
		glVertex3f(-x+posX,-y+posY,0.0f);
	}
	}
	else if(position == 0){
		for(int i=500; i<1000; i++){
		float angle = i*(2.0*M_PI/1000);
		float x = cos(angle)*tamaX;
		float y = sin(angle)*tamaY;
		glColor3f(0,0,1);
		glVertex3f(x+posX,y+posY,0.0f);
	
	}
	}
    glEnd();
}

void menu(){
    
}

void graficando(string grafica, float posX, float posY){
    //float xmax = 2*M_PI;
    //float xmin = -2*M_PI;
    //float incrementar = (xmax-xmin)/1000;
    //float x = xmin;
    //glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    if(grafica == "sinh"){
        for(float i=-2; i<=2; i+=.01){
            //float angle = i*(2.0*M_PI/1000);
            float y = sinh(i);
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
            //x+=incrementar;
        }
        glEnd();
        planoCartesiano(-14, 5, -6 ,5, -10, 9, -10 ,1);
    }
    if(grafica == "cosh"){
        for(float i=-2; i<=2; i+=0.01){
            float y = cosh(i);
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(-5, 5, 3 ,5, -1, 9, -1 ,1);
    }
    if(grafica == "tanh"){
        for(float i=-2.5; i<=2.5; i+=0.01){
            float y = tanh(i);
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(4, 5, 12 , 5, 8, 9, 8 ,1);
    }
    if(grafica == "coth"){
        for(float i=-3; i<=-.3; i+=0.01){
            float y = (cosh(i)/sinh(i));
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(-14, -5, -6 , -5 , -10 , -1, -10 , -9);
    }
    if(grafica == "sech"){
        for(float i=-3; i<=3; i+=0.01){
            float y = 1/cosh(i);
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(-5, -5, 3 , -5 , -1, -1, -1 , -9);
    }
    if(grafica == "cosech"){
        for(float i=-2; i<=2; i+=0.01){
            float y = 1/sinh(i);
            glColor3f(0,1,1);
            glVertex2f(i+posX , y+posY);
        }
        glEnd();
        planoCartesiano(4, -5, 12 , -5, 8, -1, 8 ,-9);
    }
    
    glEnd();
}
void cosenoX(){
    glPointSize(2.0);
    glBegin(GL_POINTS);
    for(int i = 0; i <= 1000; i++){
        float x = i*2*M_PI/1000;
        float y = cos(x);
        glVertex2f(x-3, y+4);
    }
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //senoh
    graficando("sinh", -10, 5);
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
    //menu();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

