#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

using namespace std;
float alpha = 90;
float beta = -1;

//float alpha = 0;
//float beta = 0;

int x0, y0;

GLfloat X = 0;
GLfloat Y = 0;
GLfloat Z = 0;

GLfloat xn = -12;
GLfloat xp = 12;
GLfloat yn = xn;
GLfloat yp = xp;
GLfloat z = 0;
GLfloat pc = 0;
GLfloat aum = 15;

GLuint texture[0];

void specialKey(int key, int x, int y) { 

// The keys below are using the gluLookAt() function for navigation
// Check which key is pressed

switch(key) {
    
    case GLUT_KEY_LEFT : 
    X -= 1;
    break;
    case GLUT_KEY_RIGHT :
    X += 1;
    break;
    case GLUT_KEY_UP :  
    Y += 1;
    break;
    case GLUT_KEY_DOWN :
    Y -= 1;
    break; 
    case GLUT_KEY_PAGE_UP: 
    Z -= 1;
    break;
    case GLUT_KEY_PAGE_DOWN:
    Z += 1;
    
    break;
}
    glutPostRedisplay(); // Redraw the scene
} 

void cubo(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf){
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
glVertex3f(xi,yf,zi);
glVertex3f(xi,yi,zi);
glVertex3f(xf,yi,zi);
glVertex3f(xf,yf,zi);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(xi,yf,zi);
glVertex3f(xi,yi,zi);
glVertex3f(xi,yi,zf);
glVertex3f(xi,yf,zf);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(xf,yi,zi);
glVertex3f(xf,yf,zi);
glVertex3f(xf,yf,zf);
glVertex3f(xf,yi,zf);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(xi,yi,zf);
glVertex3f(xi,yf,zf);
glVertex3f(xf,yf,zf);
glVertex3f(xf,yi,zf);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(xi,yi,zi);
glVertex3f(xi,yi,zf);
glVertex3f(xf,yi,zf);
glVertex3f(xf,yi,zi);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(xi,yf,zi);
glVertex3f(xi,yf,zf);
glVertex3f(xf,yf,zf);
glVertex3f(xf,yf,zi);
glEnd();
	
	}


void paredes(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf){
	if(zf == 0){
		glBegin(GL_POLYGON);
		glTexCoord2f(0,0);
glVertex3f(xi,yf,zi);
glTexCoord2f(0,8);
glVertex3f(xi,yi,zi);
glTexCoord2f(8,8);
glVertex3f(xf,yi,zi);
glTexCoord2f(8,0);
glVertex3f(xf,yf,zi);
glEnd();
	}
	else{
		if(zf == 1){zf =0;};
		glBegin(GL_POLYGON);
		glTexCoord2f(0,0);
glVertex3f(xi,yf,zi);
glTexCoord2f(0,8);
glVertex3f(xi,yi,zi);
glTexCoord2f(8,8);
glVertex3f(xf,yi,zf);
glTexCoord2f(8,0);
glVertex3f(xf,yf,zf);
glEnd();
	}
	
}


void display(void) {
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

    

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 //glFrustum(-10,10,-10,10,0.1,100);
 glOrtho(-450,450,-450,450,-600,600);
 //gluPerspective(20.0f, 1.0f, 1.0f, 10.0f);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 glTranslatef(X,Y,Z);
 //glPushMatrix();
 gluLookAt(0.0f, 0.0f, 1.0f,
 0.0f, 0.0f, 0.0f,
 0.0f, 1.0f, 0.0f);
 glRotatef(alpha, 1.0f, 0.0f, 0.0f); 
 glRotatef(beta, 0.0f, 1.0f, 0.0f);
 /*glPointSize(5);
 
glBegin(GL_POINTS);
glColor3f(1,1,0);
glVertex3f(10,0,0);
glColor3f(0,1,1);
glVertex3f(-10,0,0);

glColor3f(1,1,1);
glVertex3f(0,0,0);

glColor3f(1,0,1);
glVertex3f(0,10,0);
glColor3f(1,0,0);
glVertex3f(0,-10,0);

glColor3f(0,0,1);
glVertex3f(0,0,10);
glColor3f(0,1,0);
glVertex3f(0,0,-10);
glEnd();*/

 texture[1] = SOIL_load_OGL_texture //Llamamos a la imagen
                     (
                "windows.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
        glPushMatrix();
 	//glTranslatef(-47,0.0,-60.0);
 	glEnable(GL_TEXTURE_2D);
 	glBindTexture(GL_TEXTURE_2D, texture[1]);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
 	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	
 	glEnable(GL_BLEND);
 	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 	paredes(-250,0,-300,-100,-200,0);
//glColor3f(1,0,1);
paredes(0,0,-300,-100,-200,-150);
//glColor3f(0,1,0);
paredes(0,50,-300,-100,-150,0);
//glColor3f(0,1,1);
paredes(50,50,-300,-100,-150,-200);
paredes(50,350,-300,-100,-200,0);
paredes(350,350,-300,-200,-200,1);
paredes(350,400,-300,-250,0,1);
paredes(400,400,-300,-250,0,200);
paredes(350,400,-300,-250,200,0);
paredes(350,0,-300,-200,200,0);
paredes(0,0,-300,-200,200,240);
paredes(0,-150,-300,-200,240,0);
paredes(-150,-150,-300,-200,200,240);
paredes(-150,-350,-300,-200,200,0);
paredes(-350,-350,-300,-100,200,1);
paredes(-350,-250,-300,-100,0,0);
paredes(-250,-250,-300,-100,0,-50);
paredes(-250,-300,-300,-100,-50,0);
paredes(-300,-300,-300,-100,-50,-150);
paredes(-300,-250,-300,-100,-150,0);
paredes(-250,-250,-300,-100,-150,-200);
 	/*glBegin(GL_QUADS);
 
 		glColor3f(1.0f, 1.0f, 1.0f);
 		glTexCoord2f(0.00f,00.0f); glVertex3f(-0.0f, 0.0f,-0.5f);
 		glTexCoord2f(0.00f,1.0f); glVertex3f(-0.0f, 200.0f,-50);
 		glTexCoord2f(1.0f,1.0f); glVertex3f( 0.0f, 200,50);
 		glTexCoord2f(1.0f,0.0f); glVertex3f( 0.0f, 0.0f,50);
 	glEnd();*/
 	

glBegin(GL_LINE_LOOP);
glNormal3f( 1.0f, 0.0f, 1.0f);

//glColor3f(1,1,0);
glTexCoord2f(0,0);
glVertex3f(-250,-300,-200);
glVertex3f(0,-300,-200);
glVertex3f(0,-300,-150);
glVertex3f(50,-300,-150);
glVertex3f(50,-300,-200);
glTexCoord2f(0,10);
glVertex3f(350,-300,-200);
glVertex3f(350,-300,0);
glVertex3f(400,-300,0);
glTexCoord2f(10,10);
glVertex3f(400,-300,200);
glVertex3f(0,-300,200);
glVertex3f(0,-300,240);
glVertex3f(-150,-300,240);
glVertex3f(-150,-300,200);
glTexCoord2f(10,0);
glVertex3f(-350,-300,200);
glVertex3f(-350,-300,0);
glVertex3f(-250,-300,0);
glVertex3f(-250,-300,-50);
glVertex3f(-300,-300,-50);
glVertex3f(-300,-300,-150);
glVertex3f(-250,-300,-150);
glEnd();
glDisable(GL_BLEND);
 	glDisable(GL_TEXTURE_2D);
 	glPopMatrix();
//glColor3f(1,0,0);






 glFlush();
 glutSwapBuffers();
}

 void onMouse(int button, int state, int x, int y) {
 if ( (button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN) ) {
 x0 = x; y0 = y;
 }
}

void onMotion(int x, int y) {
alpha = (alpha + (y - y0));
beta = (beta + (x - x0));
 x0 = x;
 y0 = y;
 glutPostRedisplay();
}

void init(void){

	
}

/*void resize(int h, int w) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (float)w / (float)h, 1.0, 180.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}*/


int main(int argc, char* argv[]){
	 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(1366, 768);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Desvelada Prrona #3");
 init();
 //glutReshapeFunc(resize);
 glutDisplayFunc(display);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    //glClearDepth(0.5f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
 glutMouseFunc(onMouse); 
 glutMotionFunc(onMotion);
 glutSpecialFunc(specialKey); 
 glutMainLoop();
 return 0;
}
