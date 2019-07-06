#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
void esferas(float pz, float rx, float ry, float pcx, float pcy, string tipo ){
	glPointSize(pz);
    glBegin(GL_POINTS);
    float t = 0;
    float an = 0;
	
	if(tipo.compare("d") == 0){
		an = 1.5*M_PI;
		t = 2.5*M_PI;
	}
	if(tipo.compare("c") == 0){
		t = 2*M_PI;
		an = 0;
	}
	if(tipo.compare("i") == 0){
		t = 1.5*M_PI;
		an = 0.5*M_PI;	
	}
	if(tipo.compare("ar") == 0){
		t = M_PI;
		an = 0;
	}
	if(tipo.compare("ab") == 0){
		t = 2*M_PI;
		an = M_PI;
	}
	if(tipo.compare("4ta") == 0){
		t = 1.35*M_PI;
		an = 0.46*M_PI;	
	}
	if(tipo.compare("4ta2") == 0){
		t = 0.54*M_PI;
		an = -0.31*M_PI;	
	}
	if(tipo.compare("4ta3") == 0){
		an = -0.5*M_PI;
		t = 0;
	}

	
    
    for(float ang = an; ang<=t; ang +=0.001){
		float x = rx*cos(ang);
		float y = ry*sin(ang); 
		glVertex3f(x+pcx,y+pcy,0);
	}
    glEnd();
}

void curvas(float posX, float posY, float posX2, float posY2){
	glBegin(GL_POINTS);
	float x=0; 
	float x1=1; 
	while(x<=1){
		float y = pow(x, 6);
		x+=0.001;
		glVertex2f(x+posX, y+posY);
	}
	while(x1<=2){
		float y = pow(x1, -6);
		x1+=0.001;
		glVertex2f(x1+posX2, y+posY2);
	}
	glEnd();
}

void rectangulo(float lStart1, float lEnd1, float lStart2, float lEnd2, float lStart3, float lEnd3, float lStart4, float lEnd4){
	glColor3b(0,0,0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(lStart1,lEnd1);
	glVertex2f(lStart2,lEnd2);
	glVertex2f(lStart3,lEnd3);
	glVertex2f(lStart4,lEnd4);
	//Lineas vertical de Union izquierda
	glVertex2f(lStart1,lEnd1);
	glVertex2f(lStart3,lEnd3);
	//Lineas vertical de Union derecha
	glVertex2f(lStart2,lEnd2);
	glVertex2f(lStart4, lEnd4);
	glEnd();
}
void escaleras(){
	glColor3f(0,0,0);
	rectangulo(-1.5, -8, 1.5, -8, -1.5, -10, 1.5, -10);
	glBegin(GL_LINES);
	float i=-8;
	float j=-8.1;
	while(i>=-10){
		glVertex2f(-1.5, i);
		glVertex2f(1.5, i);
		i-=.55;
	}
	while(j>=-9.9){
		glVertex2f(-1.5, j);
		glVertex2f(1.5, j);
		j-=.58;
	}
	glEnd();
}
void lineas(float px1, float py1, float px2, float py2){
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(px1, py1);
	glVertex2f(px2, py2);
	glEnd();
}
void triangulo(float v11, float v12, float v21, float v22, float v31, float v32){
	glBegin(GL_TRIANGLES);
	glColor3f(0,0,0);
	glVertex3f(v11, v12, 0);
	glVertex3f(v21, v22, 0);
	glVertex3f(v31, v32, 0);
	glEnd();
}
void marcoPuerta_Ventana(float posX, float posY, float inicio, float fin, float inicio1, float fin1, float distancia, float tama){
	glPointSize(2);
	glBegin(GL_POINTS);
	for(float i=inicio; i<=fin; i+=0.001){
        float y = (tama)*log((1+i)/(1-i));
        glColor3f(0,0,0);
        glVertex2f(i+posX , y+posY);
    }
	for(float j=inicio1; j<=fin1; j+=0.001){
        float y = (tama)*log((1-j)/(1+j));
        glColor3f(0,0,0);
        glVertex2f(j+posX+distancia , y+posY);
    }
    glEnd();

}
void torreArriba(float posX, float posY){
	glBegin(GL_POINTS);
	for(float i=0; i<=2; i+=0.001){
        //float y = log(i + sqrt(pow(i, 2)-1)); PARA LAS VENTANAS o -2
		float y = log(i+.2 + pow(i,2));
        glColor3f(0,0,0);
        glVertex2f(i+posX , y+posY);
    }
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
		glColor3f(0,0,0);
		glVertex3f(-x+posX,-y+posY,0.0f);
	}
	}
	else if(position == 0){
		for(int i=500; i<1000; i++){
		float angle = i*(2.0*M_PI/1000);
		float x = cos(angle)*tamaX;
		float y = sin(angle)*tamaY;
		glColor3f(0,0,0);
		glVertex3f(x+posX,y+posY,0.0f);
	
	}
	}
    glEnd();
}