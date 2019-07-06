
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>


using namespace std;
float alpha = 0;
float beta = 0;
GLint texture[0];
//float alpha = 0;
//float beta = 0;

int x0, y0;

float tcx = 0; //trasladar cara
float tcy = 100;
float tcz = 0;

float mix = 0; //trasladar mano
float miy = 0;
float miz = 0;

float mdx = 0; //trasladar mano
float mdy = 0;
float mdz = 0;

float pdx = 0; //trasladar mano
float pdy = -300;
float pdz = 0;

float pix = 0; //trasladar mano
float piy = -300;
float piz = 0;

float tx = 0; //trasladar mano
float ty = 0;
float tz = 0;


float rcx = 0; //rotar cara
float rcy = 0;
float rcz = 0;

int ambasm = 0;



void cubo(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf, GLfloat k){
	GLfloat nx = (xf-xi)/k;
	GLfloat ny = (yf-yi)/k;
	GLfloat nz = (zf-zi)/k;
	glColor3f(1,1,1);
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
	
void piso(){
	glEnable(GL_TEXTURE_2D);
 	glBindTexture(GL_TEXTURE_2D, texture[1]);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
 	glEnable(GL_BLEND);
 	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	cubo(-250,250,-310,-312,-250,250,70);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}



int animacion = 0;



void enderezar(){
	rcz = 0;
}


void specialKey(int key, int x, int y) { 

// The keys below are using the gluLookAt() function for navigation
// Check which key is pressed

switch(key) {
    
    case GLUT_KEY_LEFT : 
    //moverCi();
    tx--;
   //si();
   /*rcy--;
   cout << rcy << endl;*/
    break;
    case GLUT_KEY_RIGHT :
    //rcy += 2;

    tx++;
   //rcy++;
    //cout << rcy << endl;
    //SX += 10;
    break;
    case GLUT_KEY_UP :  
    tz = tz -5;;
    break;
    case GLUT_KEY_DOWN :
    tz = tz + 5;
    //SY -= 10;
    break; 
    case GLUT_KEY_PAGE_UP: 
    if(rcz <= 30){
		rcz++;
	}
    break;
    case GLUT_KEY_PAGE_DOWN:
	if(rcz >= -30){
		rcz--;
	}
    break;
    
    
}
    glutPostRedisplay(); // Redraw the scene
} 



void celda(GLfloat xi, GLfloat xf, GLfloat yi, GLfloat yf, GLfloat zi, GLfloat zf){
	
	glBegin(GL_LINE_LOOP);
	glVertex3f(xi,yi,zi);
	glVertex3f(xf,yi,zi);
	glVertex3f(xf,yf,zi);
	glVertex3f(xi,yf,zi);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glVertex3f(xi,yi,zi);
	glVertex3f(xi,yi,zf);
	glVertex3f(xi,yf,zf);
	glVertex3f(xi,yf,zi);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glVertex3f(xf,yi,zi);
	glVertex3f(xf,yi,zf);
	glVertex3f(xf,yf,zf);
	glVertex3f(xf,yf,zi);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glVertex3f(xi,yi,zf);
	glVertex3f(xf,yi,zf);
	glVertex3f(xf,yf,zf);
	glVertex3f(xi,yf,zf);
	glEnd();
	
	}
	

void mano(GLfloat xi, GLfloat xf, GLfloat y, int m){
	GLfloat yf;
	if (m == 1){
		yf = mdy;
	}
	else{
		yf = miy;
	}
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex3f(xi,y,0);
	glVertex3f(xf,yf,0);
	glEnd();
	glTranslatef(xf,yf,0);
	glutSolidSphere(10,50,50);
	glLineWidth(3);
}

void pie(GLfloat xi, GLfloat xf, GLfloat yi, int m){
	GLfloat yf;
	if (m == 1){
		yf = pdy;
	}
	else{
		yf = piy;
	}
	glLineWidth(10);
	glBegin(GL_LINES);
	glVertex3f(xi,yi,0);
	glVertex3f(xf,yf,0);
	glEnd();
	glTranslatef(xf,yf,0);
	glutSolidSphere(10,50,50);
	glLineWidth(3);
}


void monigote(){

glTranslatef(tx,ty,tz);
	//celda(-100,100,-100,100,-100,100);
	//glTranslatef(0,0,0);
	glPushMatrix();
	//if(tcx == 10 ||  rcz
		glTranslatef(tcx,tcy,tcz);
		glRotatef(rcx,1,0,0);
		glRotatef(rcy,0,1,0);
		glRotatef(rcz,0,0,1);
		glutSolidSphere(50,50,50);
		glPushMatrix();
			glTranslatef(-15,25,50);
			glColor3f(1,0,0);
			glutSolidSphere(10,50,50);
			glColor3f(1,1,1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(15,25,50);
			glColor3f(1,0,0);
			glutSolidSphere(10,50,50);
			glColor3f(1,1,1);
		glPopMatrix();
			//pelo prron
		glPushMatrix();
		GLfloat k = 10;
			cubo(-40,-35,10,70,-30,30,k);
			cubo(-30,-25,20,70,-30,30,k);
			cubo(-20,-15,30,70,-30,30,k);
			cubo(-10,-5,30,70,-30,30,k);
			cubo(0,5,30,70,-30,30,k);
			cubo(10,15,30,70,-30,30,k);
			cubo(20,25,30,70,-30,30,k);
			cubo(30,35,20,70,-30,30,k);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(50,0,0);
			glutSolidSphere(10,50,50);
			glTranslatef(-100,0,0);
			glutSolidSphere(10,50,50);
		glPopMatrix();
	glPopMatrix();
	glLineWidth(10);
		glBegin(GL_LINES);
		glVertex3f(0,50,0);
		glVertex3f(0,-250,0);
		glEnd();
		glLineWidth(3);
	glPushMatrix();
	glTranslatef(mix,miy,miz);
	mano(0,-50,0,0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(mdx,mdy,mdz);
	mano(0,50,0,1);
	glPopMatrix();
	glPushMatrix();
	
	pie(0,-50,-250,0);
	glTranslatef(pix,piy,piz);
	glPopMatrix();
	
	pie(0,50,-250,0);
	glTranslatef(pdx,pdy,pdz);
	glPopMatrix();

}




void display(void) {
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

    

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-500,500,-500,500,-500,500);
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

 texture[1] = SOIL_load_OGL_texture //Llamamos a la imagen
                     (
                "piramide.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS  
                     );
                     

 
glPushMatrix();
 monigote();
 glPopMatrix();
 piso();





 glFlush();
 glutSwapBuffers();
}





void si(){
	enderezar();
	animacion = 1;
			rcx++;
			if(rcx == 30){
				rcx = -10;
			}
	
			if(ambasm != 2){
			glutPostRedisplay();
		}
		
		
	
}
void no(){

	enderezar();
	animacion = 1;
		rcy++;
		if(rcy==20){
			rcy = -20;
		}
	
		if(ambasm != 2){
			glutPostRedisplay();
		}
}

void adiosI(){
	enderezar();
	animacion = 1;
			miy++;
			if(miy == 20){
				miy = -10;
			}
			
		
		if(ambasm != 2){
			glutPostRedisplay();
		}
}

void adiosD(){
	enderezar();
	animacion = 1;
			mdy++;
			if(mdy == 20){
				mdy = -10;
			}
			
		if(ambasm != 2){
			glutPostRedisplay();
		}
}

void adios(){
	enderezar();
	animacion = 1;
	//adiosI();
	//adiosD();

			mdy++;
			miy++;
			if(mdy == 20){
				mdy = -10;
				miy = -10;
			}
		
		
if(ambasm != 2){
			glutPostRedisplay();
		}
}



void saltar(){
	enderezar();
	animacion = 1;
	ty += 3;
	if (ty >= 50){
		ty = 0;
	}
	//ambasm = 2;
	adios();
	
	if(ambasm != 2){
			glutPostRedisplay();
		};
}

void correr(){
	
	animacion = 1;
	
		
		
if(ambasm != 2){
			glutPostRedisplay();
		}

	}
	
void alv(){
	
	animacion = 1;
	ty += 3;
	if (ty >= 50){
		ty = 0;
	}
	//ambasm = 2;
	adios();
	
	rcx++;
			if(rcx == 30){
				rcx = -10;
			}
		

	
}
	
	

void onMouse(int button, int state, int x, int y) {
 if ( (button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN) ) {
 x0 = x; y0 = y;
 }
 switch (button) {
 case GLUT_RIGHT_BUTTON:
 if (state == GLUT_DOWN)
 //if(rcz <=-17 && rcz >= 21){
	// rcz = -16;
	 //cout << "adcsoi" << rcz << endl;
 //}
 rcx = 0;
 rcy = 0;
 animacion = 1;
 glutIdleFunc(si);
 break;
 case GLUT_MIDDLE_BUTTON:
 if (state == GLUT_DOWN)
 rcy = 0;
 rcx = 0;
 animacion = 1;
 glutIdleFunc(no);
 break;
 default:
 break;
 }
}

void onMotion(int x, int y) {
alpha = (alpha + (y - y0));
beta = (beta + (x - x0));
//cout << alpha << " " << beta<< endl;
 x0 = x;
 y0 = y;
 glutPostRedisplay();
}

void key(unsigned char key, int x, int y) {
        // La animación inicia al presionar la tecla espaciadora de igual forma se detiene
    if ( key == ' ' ) {
		   glutIdleFunc(NULL);
		   animacion = 0;
	   }
	if (key == 'm'){
		if(miy <=20){
		miy++;
		}
	}
	if (key == 'w'){
		//if(miy <=20){
		alpha++;


	//}
	}
	if (key == 's'){
		//if(miy <=20){
		alpha--;
	//}
	}
	if (key == 'a'){
		//if(miy <=20){
		//
		beta--;
	//}
	}
	if (key == 'd'){
		//if(miy <=20){
		beta++;
	//}
	}
	if (key == 'n'){
		if(miy >=-10){
		miy--;
	}
		
	}
	
	if (key == 'b'){
		//animacion = 1;
		//miy = 19;
		mdy = 0;
		ambasm = 1;
		glutIdleFunc(adiosI);
	}
	if (key == 'v'){
		//animacion = 1;
		//mdy = 19;
		miy = 0;
		ambasm = 1;
		glutIdleFunc(adiosD);
	}
	if (key == 'c'){
		//animacion = 1;
		//mdy = 19;
		miy = 0;
		mdy = 0;
		ambasm = 1;
		glutIdleFunc(adios);
	}
	if (key == 'z'){
		ambasm = 1;
		glutIdleFunc(saltar);
	}
	if (key == 'r'){
		miy = 0;
		mdy = 0;
		ambasm = 1;
		glutIdleFunc(alv);
	}
	
	
	
	if (key == 27){
		exit(0);
	}
	glutPostRedisplay();
}



int main(int argc, char* argv[]){
	 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(1080, 720);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Textura");
 //init();
 //glutReshapeFunc(reshape);
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
 glutKeyboardFunc(key);
 glutSpecialFunc(specialKey); 
 //startAnimation();
 //glutKeyboardFunc(keyboard);
glutMainLoop();
 return 0;
}

