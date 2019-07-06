#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>

using namespace std;
float alpha = 0;
float beta = 0;

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
GLfloat scale = 1.0f;


	GLuint texture[0];
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 's':
        scale -= 0.1;
        break;
    case 'd':
        scale += 0.1;
        break;
	case 'n':
		scale=1;
		break;
	case 27:
        exit(0);
    }
    glutPostRedisplay();
}
 
void specialKey(int key, int x, int y) { 

// The keys below are using the gluLookAt() function for navigation
// Check which key is pressed

switch(key) {
    
    case GLUT_KEY_LEFT : 
    X -= 30;
    break;
    case GLUT_KEY_RIGHT :
    X += 30;
    break;
    case GLUT_KEY_UP :  
    Y += 30;
    break;
    case GLUT_KEY_DOWN :
    Y -= 30;
    break; 
    case GLUT_KEY_PAGE_UP: 
    Z -= 30;
    break;
    case GLUT_KEY_PAGE_DOWN:
    Z += 30;
    break;

	}
    glutPostRedisplay(); // Redraw the scene
} 


void cubo(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf, float n)
{
	GLfloat nx = (xf-xi)/n;
	GLfloat ny = (yf-yi)/n;
	GLfloat nz = (zf-zi)/n;
		//glColor3f(1,1,1);
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
void ventanas(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf, float n)
{
		//glColor3f(1,1,1);
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);
				glVertex3f(xi,yf,zi);
			glTexCoord2f(0,n);
				glVertex3f(xi,yi,zi);
			glTexCoord2f(n,n);
				glVertex3f(xf,yi,zi);
			glTexCoord2f(n,0);
				glVertex3f(xf,yf,zi);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);
				glVertex3f(xi,yf,zi);
			glTexCoord2f(0,n);
				glVertex3f(xi,yi,zi);
			glTexCoord2f(n,n);
				glVertex3f(xi,yi,zf);
			glTexCoord2f(n,0);
				glVertex3f(xi,yf,zf);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);
				glVertex3f(xf,yi,zi);
			glTexCoord2f(0,n);
				glVertex3f(xf,yf,zi);
			glTexCoord2f(n,n);
				glVertex3f(xf,yf,zf);
			glTexCoord2f(n,0);
				glVertex3f(xf,yi,zf);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);
				glVertex3f(xi,yi,zf);
			glTexCoord2f(0,n);
				glVertex3f(xi,yf,zf);
			glTexCoord2f(n,n);
				glVertex3f(xf,yf,zf);
			glTexCoord2f(n,0);
				glVertex3f(xf,yi,zf);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);
				glVertex3f(xi,yi,zi);
			glTexCoord2f(0,n);
				glVertex3f(xi,yi,zf);
			glTexCoord2f(n,n);
				glVertex3f(xf,yi,zf);
			glTexCoord2f(n,0);
				glVertex3f(xf,yi,zi);
		glEnd();
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);
				glVertex3f(xi,yf,zi);
			glTexCoord2f(0,n);
				glVertex3f(xi,yf,zf);
			glTexCoord2f(n,n);
				glVertex3f(xf,yf,zf);
			glTexCoord2f(n,0);
				glVertex3f(xf,yf,zi);
		glEnd();

}
void techo(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf, float n){

			//zf = (zi - zf)/2;

			glBegin(GL_TRIANGLES);
			//glTexCoord2f(0,0);			
			glTexCoord2f(0,n);			glVertex3f(xi,yf,zi);
			glTexCoord2f(n,n);			glVertex3f(xi,yi,zf);
			glTexCoord2f(n,0);			glVertex3f(xf,yi,zf);
			glEnd();
}
void puertas(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf, float n){

			
			glBegin(GL_QUADS);
			glTexCoord2f(0,0);			glVertex3f(xi,yf,zi);
			glTexCoord2f(0,n);			glVertex3f(xi,yi,zi);
			glTexCoord2f(n,n);			glVertex3f(xf,yi,zf);
			glTexCoord2f(n,0);			glVertex3f(xf,yf,zf);
			glEnd();
}

void paredes(GLfloat xi,GLfloat xf,GLfloat yi,GLfloat yf,GLfloat zi,GLfloat zf, float n){
	GLfloat nx;
	GLfloat ny;
	ny = (yf - yi)/n;
	if(zf == 0){
		nx = (xf - xi)/n;
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);			glVertex3f(xi,yf,zi);
			glTexCoord2f(0,ny);			glVertex3f(xi,yi,zi);
			glTexCoord2f(nx,ny);		glVertex3f(xf,yi,zi);
			glTexCoord2f(nx,0);			glVertex3f(xf,yf,zi);
		glEnd();
	}
	else{
		if(zf == 1){zf =0;};
		nx = (zf - zi)/n;
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);			glVertex3f(xi,yf,zi);
			glTexCoord2f(0,ny);			glVertex3f(xi,yi,zi);
			glTexCoord2f(nx,ny);		glVertex3f(xf,yi,zf);
			glTexCoord2f(nx,0);			glVertex3f(xf,yf,zf);
		glEnd();
		}	
	
}


void display(void) {

glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 //glFrustum(-10,10,-10,10,0.1,100);
 glOrtho(-650,650,-650,650,-3000,3000);
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
 glScalef(scale, scale, scale);

 //glPointSize(5);
	float k = 70;
	float j = 250;
	float r = 200;
	float v = 1;
	texture[0] = SOIL_load_OGL_texture //Llamamos a la imagen
                    (
                "bricks.bmp",
				//"2.bmp",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
					 //////// grama
	texture[1] = SOIL_load_OGL_texture // cargamos la imagen
    				(
        		//"3.bmp",
				"grass.bmp",
        		SOIL_LOAD_AUTO,
        		SOIL_CREATE_NEW_ID,
        		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    				);
					/// puerta
	texture[2] = SOIL_load_OGL_texture // cargamos la imagen
    				(
        		//"3.bmp",roof
				"door.bmp",
        		SOIL_LOAD_AUTO,
        		SOIL_CREATE_NEW_ID,
        		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    				);
					///// acera ////
	texture[3] = SOIL_load_OGL_texture // cargamos la imagen
    				(
        		//"3.bmp",
				"roof.bmp",
        		SOIL_LOAD_AUTO,
        		SOIL_CREATE_NEW_ID,
        		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    				);
					///// techo
	texture[4] = SOIL_load_OGL_texture // cargamos la imagen
    				(
        		//"3.bmp",
				"2.bmp",
        		SOIL_LOAD_AUTO,
        		SOIL_CREATE_NEW_ID,
        		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    				);
					//////// ventanas
	texture[5] = SOIL_load_OGL_texture // cargamos la imagen
    				(
        		//"3.bmp",
				"window.bmp",
        		SOIL_LOAD_AUTO,
        		SOIL_CREATE_NEW_ID,
        		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    				);
////////////////////////////////////////////////////////////////
						///// PAREDES /////////
    	glPushMatrix();
			glEnable(GL_TEXTURE_2D);
 			//glTranslatef(-47,0.0,-60.0);
 			glBindTexture(GL_TEXTURE_2D, texture[0]);
 			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	  		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	  		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			
			paredes(500,40,-300,-100,-200,0,k);//espacio para puerta
			paredes(40,-40,-120,-100,-200,0,k);
			paredes(-40,-500,-300,-100,-200,0,k);
			//paredes(-500,500,-300,-100,-200,0,k);
 	
			paredes(500,500,-300,-100,-200,-210,k);
			paredes(500,540,-300,-100,-210,0,k);
			paredes(540,540,-300,-100,-210,-170,k);
			paredes(540,530,-300,-100,-170,0,k);
			paredes(530,530,-300,-100,-170,330,k);
			paredes(530,540,-300,-100,330,0,k);
			paredes(540,540,-300,-100,330,370,k);
			paredes(540,500,-300,-100,370,0,k);
			paredes(500,500,-300,-100,370,360,k);
			paredes(500,350,-300,-100,360,0,k);
			paredes(350,350,-300,-100,360,370,k);
			paredes(350,310,-300,-100,370,0,k);
			paredes(310,310,-300,-100,370,330,k);
			paredes(310,320,-300,-100,330,0,k);
			paredes(320,320,-300,-100,330,180,k);
			paredes(320,170,-300,-100,180,0,k);
			paredes(170,170,-300,-100,180,220,k);
			paredes(170,130,-300,-100,220,0,k);
			paredes(130,130,-300,-100,220,210,k);

			paredes(130,40,-300,-100,210,0,k);//espacio para puerta
			paredes(40,-40,-120,-100,210,0,k);
			paredes(-40,-130,-300,-100,210,0,k);

			paredes(-130,-130,-300,-100,220,210,k);
			paredes(-170,-130,-300,-100,220,0,k);
			paredes(-170,-170,-300,-100,180,220,k);
			paredes(-320,-170,-300,-100,180,0,k);
			paredes(-320,-320,-300,-100,330,180,k);
			paredes(-310,-320,-300,-100,330,0,k);
			paredes(-310,-310,-300,-100,370,330,k);
			paredes(-350,-310,-300,-100,370,0,k);
			paredes(-350,-350,-300,-100,360,370,k);
			paredes(-500,-350,-300,-100,360,0,k);
			paredes(-500,-500,-300,-100,370,360,k);
			paredes(-540,-500,-300,-100,370,0,k);
			paredes(-540,-540,-300,-100,330,370,k);
			paredes(-530,-540,-300,-100,330,0,k);
			paredes(-530,-530,-300,-100,-170,330,k);
			paredes(-540,-530,-300,-100,-170,0,k);
			paredes(-540,-540,-300,-100,-210,-170,k);
			paredes(-500,-540,-300,-100,-210,0,k);
			paredes(-500,-500,-300,-100,-200,-210,k);

			cubo(-550,-300,-100,-85,240,400,1);
			cubo(-550,550,-100,-85,-220,240,1);
			cubo(300,550,-100,-85,240,400,1);

			glDisable(GL_BLEND);
 			glDisable(GL_TEXTURE_2D);
 		glPopMatrix();

//////////////////////////////////////////////////////////////////////
							///// suelo //////
 		glPushMatrix();
		 glEnable(GL_TEXTURE_2D);
 			//glTranslatef(-47,0.0,-60.0);
 			glBindTexture(GL_TEXTURE_2D, texture[1]);
 			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 	 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			//glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			cubo(-170,-600,-300,-350,-250,400,j);
			cubo(-170,-70,-300,-350,300,400,j);
			cubo(170,70,-300,-350,300,400,j);
			cubo(170,600,-300,-350,-250,400,j);
			cubo(-170,170,-300,-350,-250,210,j);
			cubo(-600,600,-300,-350,500,600,j);
 	/*
		glBegin(GL_POLYGON);
			glTexCoord2f(0,0);			glVertex3f(0,-300,-250);
			glTexCoord2f(0,3);			glVertex3f(0,-300,400);
			glTexCoord2f(3,3);			glVertex3f(-600,-300,400);
			glTexCoord2f(3,0);			glVertex3f(-600,-300,-250);
			glEnd();
*/
			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);
	 	glPopMatrix();
////////////////////////////////////////////////////////////////////////
							///// acera //////

		glPushMatrix();
		 glEnable(GL_TEXTURE_2D);
 			//glTranslatef(-47,0.0,-60.0);
 			glBindTexture(GL_TEXTURE_2D, texture[3]);
 			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 	 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			
			cubo(-130,130,-310,-350,210,220,r);
			cubo(-170,170,-310,-350,220,300,r);
			cubo(-70,70,-310,-350,300,400,r);
			cubo(-600,600,-310,-350,400,500,r);
			
			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);
	 	glPopMatrix();

////////////////////////////////////////////////////////////////////////
							///// puertas //////
glPushMatrix();
		 glEnable(GL_TEXTURE_2D);
 			//glTranslatef(-47,0.0,-60.0);
 			glBindTexture(GL_TEXTURE_2D, texture[2]);
 			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 	 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 	
	 		//paredes(-40,40,-300,-120,-200,0,120);
			puertas(-40,40,-300,-120,-200,-200,1);
			puertas(-40,40,-300,-120,210,210,1);

			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);
	 	glPopMatrix();


////////////////////////////////////////////////////////////////////////
						//// ventanas ////////
glPushMatrix();
		 glEnable(GL_TEXTURE_2D);
 			//glTranslatef(-47,0.0,-60.0);
 			glBindTexture(GL_TEXTURE_2D, texture[5]);
 			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 	 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 	
			ventanas(390,460,-250,-150,355,365,v);
			ventanas(-390,-460,-250,-150,355,365,v);
			ventanas(315,325,-250,-150,330,260,v);
			ventanas(-315,-325,-250,-150,330,260,v);
			ventanas(535,545,-250,-150,330,260,v);
			ventanas(535,545,-250,-150,160,90,v);
			ventanas(535,545,-250,-150,-10,-80,v);

			ventanas(210,280,-250,-150,185,175,v);
			ventanas(-210,-280,-250,-150,185,175,v);
		
			ventanas(-535,-545,-250,-150,330,260,v);
			ventanas(-535,-545,-250,-150,160,90,v);
			ventanas(-535,-545,-250,-150,-10,-80,v);

			//puertas(-40,40,-300,-120,210,210,1);

			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);
	 	glPopMatrix();


////////////////////////////////////////////////////////////////////////
					///// techo //////
glPushMatrix();
		 glEnable(GL_TEXTURE_2D);
 			//glTranslatef(-47,0.0,-60.0);
 			glBindTexture(GL_TEXTURE_2D, texture[4]);
 			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	 	 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
					//techo(40,-40,-100,-50,210,210,1);
					float l = 3;
					glBegin(GL_TRIANGLES);
					glTexCoord2f(0,l); 		glVertex3f(-550,-85,-220);
					glTexCoord2f(l,l); 		glVertex3f(-550,-85,400);
					glTexCoord2f(l,0);		glVertex3f(-400,20,50);
					glEnd();
					glBegin(GL_TRIANGLES);
					glTexCoord2f(0,l); 		glVertex3f(-550,-85,-220);
					glTexCoord2f(l,l);		glVertex3f(-300,-85,-220);
					glTexCoord2f(l,0);		glVertex3f(-400,20,50);
					glEnd();
					glBegin(GL_TRIANGLES);
					glTexCoord2f(0,l); 		glVertex3f(-300,-85,400);
					glTexCoord2f(l,l);		glVertex3f(-300,-85,240);
					glTexCoord2f(l,0);		glVertex3f(-400,20,50);
					glEnd();
					glBegin(GL_TRIANGLES);
					glTexCoord2f(0,l); 		glVertex3f(-550,-85,400);
					glTexCoord2f(l,l);		glVertex3f(-300,-85,400);
					glTexCoord2f(l,0);		glVertex3f(-400,20,50);
					glEnd();
						///// techo central /////
					glBegin(GL_POLYGON);
					glTexCoord2f(0,0);		glVertex3f(-300,-85,240);
					glTexCoord2f(0,l); 		glVertex3f(-400,20,50);
					glTexCoord2f(l,l);		glVertex3f(400,20,50);
					glTexCoord2f(l,0);		glVertex3f(300,-85,240);
					glEnd();
					glBegin(GL_POLYGON);
					glTexCoord2f(0,0);		glVertex3f(-300,-85,-220);
					glTexCoord2f(0,l); 		glVertex3f(-400,20,50);
					glTexCoord2f(l,l);		glVertex3f(400,20,50);
					glTexCoord2f(l,0);		glVertex3f(300,-85,-220);
					glEnd();
						//////////////
					glBegin(GL_TRIANGLES);
					glTexCoord2f(0,l); 		glVertex3f(550,-85,-220);
					glTexCoord2f(l,l);		glVertex3f(500,-85,400);
					glTexCoord2f(l,0);		glVertex3f(400,20,50);
					glEnd();
					glBegin(GL_TRIANGLES);
					glTexCoord2f(0,l); 		glVertex3f(550,-85,-220);
					glTexCoord2f(l,l);		glVertex3f(300,-85,-220);
					glTexCoord2f(l,0);		glVertex3f(400,20,50);
					glEnd();
					glBegin(GL_TRIANGLES);
					glTexCoord2f(0,l); 		glVertex3f(300,-85,400);
					glTexCoord2f(l,l);		glVertex3f(300,-85,240);
					glTexCoord2f(l,0);		glVertex3f(400,20,50);
					glEnd();
					glBegin(GL_TRIANGLES);
					glTexCoord2f(0,l); 		glVertex3f(550,-85,400);
					glTexCoord2f(l,l);		glVertex3f(300,-85,400);
					glTexCoord2f(l,0);		glVertex3f(400,20,50);
					glEnd();
					
			glDisable(GL_BLEND);
			glDisable(GL_TEXTURE_2D);
	 	glPopMatrix();

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
    gluPerspective(90.0, (float)w / (float)h, 1.0, 1k0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}*/

int main(int argc, char* argv[]){
	 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(850, 700);
 glutInitWindowPosition(200, 10);
 glutCreateWindow("Kasita");
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
 glutKeyboardFunc(keyboard);
 glutSpecialFunc(specialKey); 
 glutMainLoop();
 return 0;
}
