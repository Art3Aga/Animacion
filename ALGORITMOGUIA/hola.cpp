#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void lineas(float px1, float py1, float px2, float py2){
	glBegin(GL_LINES);
	glVertex2f(px1, py1);
	glVertex2f(px2, py2);
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
void furier(){
    glPointSize(1.5);
	glBegin(GL_POINTS);
    
    glEnd();
}

void planoCartesiano(){
	glBegin(GL_LINES);
	//glVertex2f(-10, 0);
	lineas(0 ,10 ,0 ,-10);
	lineas(-10 ,0 ,10 ,0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    planoCartesiano();
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    //glClearColor(0, 1, 0, 1);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1368, 768);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejemplo Puntos");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

