#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <string>
#include "lib.h"

using namespace std;

void plano(){

	
	glBegin(GL_LINES);
    glVertex3f(1,50,0);
    glVertex3f(1,-50,0);
    glVertex3f(-1,50,0);
    glVertex3f(-1,-50,0);
    glVertex3f(-100,1,0);
    glVertex3f(100,1,0);
    glVertex3f(-100,-1,0);
    glVertex3f(100,-1,0);
    
    
    /*for(int i =-100;i<=100;i+=5){
		glColor3f(0,1,1);
		glVertex3f(i,50,0);				
		glVertex3f(i,-50,0);
		
		glVertex3f(100,i,0);
		glVertex3f(-100,i,0);
	}*/
    glEnd();
	
}

void carcasa(){
	glBegin(GL_LINES);
	glVertex3f(-102,-40,0);
	glVertex3f(90,-40,0);
	glEnd();
	glPointSize(5);
	glBegin(GL_POINTS);
	for(float i = 90, i2 = 4 ;i<=100;i+=0.01){
		glVertex3f(i,asinh(i2)-42,0);
		i2++;
	}
	glEnd();
	esferas(3,36,36,125,-30, "carD");
	esferas(3,36,36,-125,-30, "carI");
	glBegin(GL_LINES);  		//derecha llanta derecha
	glVertex3f(148,-40,0);
	glVertex3f(160,-40,0);
	glEnd();
	esferas(3,24,18,165,-22,"pDel");
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-148,-40,0);
	glVertex3f(-175,-35,0);//izq llanta
	glVertex3f(-190,-20,0);
	glVertex3f(-180,0,0);
	glVertex3f(-185,35,0);
	glEnd();
	esferas(5,20,4,-165,35,"ar");
	esferas(3,180,90,-48,-40,"techo");
	glBegin(GL_LINE_STRIP);
	glVertex3f(27,42,0); 	//espejo de enfrente
	glVertex3f(60,25,0);
	glVertex3f(157,17,0);
	glVertex3f(175,10,0);
	glVertex3f(185,-12,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(31,40,0);	//parte de el espejo de enfrente
	glVertex3f(21,40,0);
	glVertex3f(55,28,0);
	glVertex3f(40,28,0);
	glVertex3f(20,37,0);
	glVertex3f(37,28.5,0);
	//glVertex3f(25,38,0);		cuadrada por si no puedo curvas
	//glVertex3f(45,28,0);
	glEnd();
	esferas(5,6,6,40,34,"esquinaSI");	//ii
	esferas(5,2,2,22,38,"esquinaII");
	glBegin(GL_LINES);			//vidrio puerta
	glVertex3f(8,40,0);
	glVertex3f(26,28,0);
	glVertex3f(25,26,0);
	glVertex3f(-100,26,0);
	glVertex3f(-100,30,0);
	glVertex3f(8,40,0);
	glVertex3f(-75,26,0);
	glVertex3f(-70,33,0);
	glVertex3f(-65,26,0);
	glVertex3f(-60,34,0);
	
	//puerta
	
	glVertex3f(-65,26,0);
	glVertex3f(-70,16,0);
	glVertex3f(-70,16,0);
	glVertex3f(-65,-11,0);
	glVertex3f(-62,-12,0);
	glVertex3f(24,-12,0);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-70,16,0);
	glVertex3f(-60,16,0);
	glVertex3f(-60,13,0);
	glVertex3f(-70,13,0);
	glEnd();
	esferas(5,6,6,-61,-6,"esquinaSI");
	esferas(5,4,19,24,7,"d");
	esferas(5,2,2,8,38,"esquinaSD");
	esferas(5,1,1,25,27,"esquinaID");
	esferas(5,2,2,-100,28,"i");
	lineasH(-250,-180,-30);
	lineasH(187,250,-30);
	
	
}

void llantas(float pcx,float pcy){
	
	esferas(5,25,25,pcx,pcy,"c");
	esferas(5,16,16,pcx,pcy,"c");
    esferas(5,18,18,pcx,pcy,"c");
    esferas(5,2,2,pcx,pcy,"c");
    esferas(5,4,4,pcx,pcy,"c");
    for(float i = 0;i <=2*M_PI;i+=((2*M_PI)/5)){
		esferas(1,1,1,(7*cos(i))+pcx,(7*sin(i))+pcy,"c"); 				//circulitos
		
	}
}

void carretera(){
	
	lineasH(-250,-138,-52);
	lineasH(-112,112,-52);
	lineasH(136,250,-52);
	lineasH(-200,136,-70);
	lineasH(-160,158,-75);
	
	
}

void edificios(){
	glBegin(GL_LINE_STRIP);
	glVertex3f(-250,100,0);
	glVertex3f(-138,100,0);
	glVertex3f(-138,38,0);
	glEnd();
	rectangulos(-240,-160,90,80);
	rectangulos(-240,-160,70,60);
	rectangulos(-240,-160,50,40);
	lineasV(-230,80,90);
	lineasV(-210,80,90);
	lineasV(-230,60,70);
	lineasV(-210,60,70);
	lineasV(-230,40,50);
	lineasV(-210,40,50);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-138,80,0);
	glVertex3f(0,80,0);
	glVertex3f(0,47,0);
	glEnd();
	rectangulos(-128,-10,70,60);
	rectangulos(-128,-100,56,46);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-5,80,0);
	glVertex3f(-5,120,0);
	glVertex3f(10,120,0);
	glVertex3f(10,45,0);
	glEnd();
	lineasV(-25,80,110);
	esferas(3,20,10,-5,110,"e");
	glBegin(GL_LINE_STRIP);
	glVertex3f(10,110,0);
	glVertex3f(25,110,0);
	glVertex3f(25,42,0);
	glEnd();
	rectangulos(13,18,105,50);
	
	glBegin(GL_LINE_STRIP);
	glVertex3f(55,28,0);
	glVertex3f(55,100,0);
	glVertex3f(130,100,0);
	glVertex3f(130,20,0);
	glEnd();
	rectangulos(60,125,90,80);
	rectangulos(60,125,75,65);
	rectangulos(60,125,60,50);
	rectangulos(60,125,45,35);
	lineasV(80,80,90);
	lineasV(100,80,90);
	lineasV(120,80,90);
	lineasV(80,65,75);
	lineasV(100,65,75);
	lineasV(120,65,75);
	lineasV(80,50,60);
	lineasV(100,50,60);
	lineasV(120,50,60);
	lineasV(80,35,45);
	lineasV(100,35,45);
	lineasV(120,35,45);
	glBegin(GL_LINE_STRIP);
	glVertex3f(130,62.5,0);
	glVertex3f(180,62.5,0);
	glVertex3f(180,47.5,0);
	glVertex3f(250,47.5,0);
	glEnd();
	rectangulos(140,170,55,46);
	rectangulos(140,170,41,32);
	rectangulos(140,170,27,18);
	lineasV(155,46,55);
	lineasV(155,32,41);
	lineasV(155,18,27);
	rectangulos(190,195,40,0);
	rectangulos(195,200,40,0);
}


void carrito(){
	carcasa();
    llantas(125,-30);
    llantas(-125,-30);
    carretera();
    edificios();
	
}

void tractor(){
	glBegin(GL_LINE_LOOP);
	glVertex3f(-25,85,0);
	glVertex3f(-85,90,0);
	glVertex3f(-135,83,0);
	glVertex3f(-135,73,0);
	glVertex3f(-85,80,0);
	glVertex3f(-25,75,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-132,73,0);
	glVertex3f(-132,20,0);
	glVertex3f(-135,20,0);
	glVertex3f(-140,15,0);
	glVertex3f(-140,-10,0);
	glVertex3f(-110,-10,0);
	glVertex3f(-110,20,0);
	glVertex3f(-135,20,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-140,15,0);
	glVertex3f(-115,15,0);
	glVertex3f(-115,-10,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-115,15,0);
	glVertex3f(-110,20,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-110,-10,0);
	glVertex3f(-90,-10,0);
	glVertex3f(-90,73,0);
	glVertex3f(-111,73,0);
	glVertex3f(-129,69,0);
	glVertex3f(-129,20,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-110,20,0);
	glVertex3f(-92,20,0);
	glVertex3f(-92,-8,0);
	glVertex3f(-110,-8,0);
	glEnd();
	glBegin(GL_LINE_LOOP);		//ventanas
	glVertex3f(-110,22,0);
	glVertex3f(-92,22,0);
	glVertex3f(-92,71,0);
	glVertex3f(-110,71,0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-112,71,0);
	glVertex3f(-127,67,0);
	glVertex3f(-127,22,0);
	glVertex3f(-112,22,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-85,80,0);
	glVertex3f(-85,50,0);
	glVertex3f(-65,46,0);
	glVertex3f(-70,35,0);
	glVertex3f(-70,-10,0);
	glVertex3f(-90,-10,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-140,-10,0);
	glVertex3f(-140,-15,0);
	glVertex3f(-65,-15,0);
	glVertex3f(-65,-10,0);
	glVertex3f(-70,-10,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(-65,46,0);
	glVertex3f(-64,47,0);
	glVertex3f(16,47,0);
	glVertex3f(16,-32,0);
	glVertex3f(16,35,0);
	glVertex3f(-70,35,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(16,47,0);
	glVertex3f(74,47,0);
	glVertex3f(74,-32,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-27,75,0);
	glVertex3f(-27,47,0);
	glEnd();	
	glBegin(GL_LINE_LOOP);
	glVertex3f(-29,73,0);
	glVertex3f(-29,49,0);
	glVertex3f(-83,52,0);
	glVertex3f(-83,78,0);
	glEnd();
	glBegin(GL_LINE_STRIP);			//cdnsjc
	glVertex3f(-65,-10,0);
	glVertex3f(-20,-15,0);
	glVertex3f(2,-45,0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(18,45,0);
	glVertex3f(18,-30,0);
	glVertex3f(72,-30,0);
	glVertex3f(72,45,0);
	glEnd();
	glBegin(GL_LINES);
	for(int y = -20;y<=45;y= y + 8){
		for (int x = 20;x<=56;x= x +12){
			glVertex3f(x,y-1,0);
			glVertex3f(x+10,y-1,0);
			
			glVertex3f(x,y-3,0);
			glVertex3f(x+10,y-3,0);
			
			glVertex3f(x+5,y-5,0);
			glVertex3f(x+15,y-5,0);
			
			glVertex3f(x+5,y-7,0);
			glVertex3f(x+15,y-7,0);
			
			//verticales
			glVertex3f(x+3,y-9,0);
			glVertex3f(x+3,y-3,0);
			
			glVertex3f(x+5,y-9,0);
			glVertex3f(x+5,y-3,0);
			
			glVertex3f(x+10,y+1,0);
			glVertex3f(x+10,y-5,0);
			
			glVertex3f(x+12,y+1,0);
			glVertex3f(x+12,y-5,0);
			
		} 
	}
	glEnd();
	esferas(2,19,38,20,-60,"i");
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glVertex3f(20,-22,0);
	glVertex3f(20,-80,0);
	glVertex3f(13,-82,0);
	glVertex3f(15,-90,0);
	glVertex3f(20,-98,0);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(20,-22,0);
	glVertex3f(80,-18,0);
	glVertex3f(85,-13,0);
	glVertex3f(90,-18,0);
	glVertex3f(150,-14,0);
	glVertex3f(155,-9,0);
	glVertex3f(160,-14,0);
	glVertex3f(190,-12,0);
	glEnd();
	esferas(2,19,38,190,-50,"i");
	glBegin(GL_LINE_STRIP);
	glVertex3f(190,-12,0);
	glVertex3f(190,-70,0);
	glVertex3f(183,-72,0);
	glVertex3f(185,-80,0);
	glVertex3f(190,-88,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(20,-98,0);
	glVertex3f(190,-88,0);
	glEnd();
	//esferas(3,80,50,-100,-50,"c");
	glBegin(GL_POINTS);
	//float x = 0;
	//float y = 0;
	/*for(float i = 0; i <=2*M_PI;i = i + 0.05){
		x = 82*cos(i);
		y = 50*sin(i);
			          
			
	}*/
	glEnd();
	
	
	
	
}


void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    //plano();
    //carrito();
    tractor();
    
    glFlush();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-250, 250, -125, 125, -300, 300);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1024,720);
    glutInitWindowPosition (250, 250);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



