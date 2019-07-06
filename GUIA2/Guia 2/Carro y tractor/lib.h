#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

// point size,radiox, radioy, punto central en x, punto central en y, tipo, d derecha, i izquierda, c completa, ar arrriba y ab abajo
void esferas(float pz, float rx, float ry, float pcx, float pcy, string tipo){
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
	if(tipo.compare("carD") == 0){
		t = M_PI + (M_PI/12);
		an = (M_PI/12)*-1;
	}
	if(tipo.compare("carI") == 0){
		t = M_PI + (M_PI/15);
		an = (M_PI/11)*-1;
	}
	if(tipo.compare("techo") == 0){
		t = M_PI -1;
		an = M_PI -2 ;
	}
	if(tipo.compare("pDel") == 0){
		t = M_PI-2.5;
		an = -1.8;
	}
	if(tipo.compare("esquinaSI") == 0){
		t = M_PI*1.5;
		an = 1.3*M_PI;
	}
	if(tipo.compare("esquinaII") == 0){
		t = M_PI*3.4;
		an = 2.4*M_PI;
	}
	if(tipo.compare("esquinaSD") == 0){
		t = M_PI*2.7;
		an = 2.2*M_PI;
	}
	if(tipo.compare("esquinaID") == 0){
		t = M_PI*2.35;
		an = 1.35*M_PI;
	}
	if(tipo.compare("e") == 0){
		t = M_PI;
		an = 0.5*M_PI;
	}
	
    
    for(float ang = an; ang<=t; ang +=0.001){
		float x = rx*cos(ang);
		float y = ry*sin(ang);
		glVertex3f(x+pcx,y+pcy,0)	;
	}
    glEnd();
}

//bs borde superior, bi borde inferior, p alto en coordenada
void rectangulos(float bs, float bi, float as, float ai){
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(bs,as,0);
	glVertex3f(bs,ai,0);
	glVertex3f(bi,ai,0);
	glVertex3f(bi,as,0);
	glEnd();
}

void lineasV(float px, float py, float py2){
	glBegin(GL_LINES);
	glVertex3f(px,py,0);
	glVertex3f(px,py2,0);
	glEnd();	
}

void lineasH(float px,float px2, float py){
	glBegin(GL_LINES);
	glVertex3f(px,py,0);
	glVertex3f(px2,py,0);
	glEnd();	
}

void lineas(float px1, float py1, float px2, float py2){
	glBegin(GL_LINES);
	glVertex3f(px1,py1,0);
	glVertex3f(px2,py2,0);
	glEnd();	
}
