#include <GL/gl.h>
#include <GL/glut.h>
int d=20,p,gx=0,hy=0,hxc=495,gyc=795,ha,gb;
void display(void)
{

glClear (GL_COLOR_BUFFER_BIT);


//Pared izquierda-derecha
glColor3ub (105,87,62);
glBegin(GL_POLYGON);
glVertex3f (0, 250, 0);
glVertex3f (390, 350, 0);
glVertex3f (390, 1000, 0);
glVertex3f (0, 1000, 0);
glEnd();

//Pared derecha-izquierda
glColor3ub (131,108,92);
glBegin(GL_POLYGON);
glVertex3f (390,350, 0);
glVertex3f (1000,250, 0);
glVertex3f (1000, 1000, 0);
glVertex3f (390, 1000, 0);
glEnd();

//Marco de fotos exterior
glColor3ub (255,108,92);
glBegin(GL_POLYGON);
glVertex3f (450,700, 0);
glVertex3f (540,700, 0);
glVertex3f (540, 870, 0);
glVertex3f (450, 870, 0);
glEnd();

//Marco de fotos interior
glColor3ub (178,235,242);
glBegin(GL_POLYGON);
glVertex3f (455,705, 0);
glVertex3f (535,705, 0);
glVertex3f (535, 865, 0);
glVertex3f (455, 865, 0);
glEnd();

//Marco de fotos hombre
glColor3ub (171,39,176);
glBegin(GL_POLYGON);
glVertex3f (455,705, 0);
glVertex3f (535,705, 0);
glVertex3f (535, 745, 0);
glVertex3f (525, 770, 0);
glVertex3f (465, 770, 0);
glVertex3f (455, 745, 0);
glEnd();


//Marco de foto hombre color
glColor3ub (178,235,242);
glBegin(GL_POLYGON);
glVertex3f (485, 770, 0);
glVertex3f (495, 750, 0);
glVertex3f (505, 770, 0);
glEnd();

//Cabeza del marco de foto hombre
glColor3ub (97,97,97);
glBegin(GL_POLYGON);
glVertex3f (485, 770, 0);
glVertex3f (495, 750, 0);
glVertex3f (505, 770, 0);
glVertex3f (505, 795, 0);
glVertex3f (485, 795, 0);
glEnd();

//raiz superior
glColor3ub (155,142,126);
glBegin(GL_POLYGON);
glVertex3f (650, 1000, 0);
glVertex3f (390, 950, 0);
glVertex3f (180, 1000, 0);
glEnd();

//pared derecha - derecha
glColor3ub (195,182,166);
glBegin(GL_POLYGON);
glVertex3f (600, 300, 0);
glVertex3f (1000, 250, 0);
glVertex3f (1000, 1000, 0);
glVertex3f (600, 1000, 0);
glEnd();

//reloj exterior
glColor3ub (55,71,79);
glBegin(GL_POLYGON);
glVertex3f (680, 800, 0);
glVertex3f (630, 800, 0);
glVertex3f (630, 900, 0);
glVertex3f (680, 900, 0);
glEnd();
//reloj interno
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (675, 805, 0);
glVertex3f (635, 805, 0);
glVertex3f (635, 895, 0);
glVertex3f (675, 895, 0);
glEnd();

//segundos del reloj
glColor3ub (0,0,0);
glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
glVertex3f (655, 850, 0);
glVertex3f (655, 890, 0);
glEnd();


//minutos del reloj
glColor3ub (0,0,0);
glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
glVertex3f (655, 850, 0);
glVertex3f (670, 850, 0);
glEnd();


//hora de el reloj
glColor3ub (0,0,0);
glBegin(GL_LINES);
//glBegin(GL_POINT_SIZE);
glVertex3f (655, 850, 0);
glVertex3f (645, 810, 0);
glEnd();

//frente aire acondicionado
glColor3ub (120,144,156);
glBegin(GL_POLYGON);
glVertex3f (700, 850, 0);
glVertex3f (850, 850, 0);
glVertex3f (850, 900, 0);
glVertex3f (700, 900, 0);
glEnd();

//arriba aire acondicionado
glColor3ub (69,90,100);
glBegin(GL_POLYGON);
glVertex3f (710, 920, 0);
glVertex3f (860, 920, 0);
glVertex3f (850, 900, 0);
glVertex3f (700, 900, 0);
glEnd();

//bajo aire acondicionado
glColor3ub (69,90,100);
glBegin(GL_POLYGON);
glVertex3f (700, 850, 0);
glVertex3f (850, 850, 0);
glVertex3f (860, 840, 0);
glVertex3f (710, 840, 0);
glEnd();

//lado aire acondicionado
glColor3ub (38,50,56);
glBegin(GL_POLYGON);
glVertex3f (860, 840, 0);
glVertex3f (850, 850, 0);
glVertex3f (850, 900, 0);
glVertex3f (860, 920, 0);
glEnd();


// pared izquierda - derecha
glColor3ub(201,192,183);
glBegin(GL_POLYGON);
glVertex3f (200, 250, 0);
glVertex3f (0, 250, 0);
glVertex3f (0, 1000, 0);
glVertex3f (200, 1000, 0);
glEnd();


//piso blanco
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (0, 0, 0);
glVertex3f (0, 250, 0);
glVertex3f (390, 350, 0);
glVertex3f (1000, 250, 0);
glVertex3f (1000, 0, 0);
glEnd();
//piso fondo blanco
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (0, 0, 0);
glVertex3f (0, 250, 0);
glVertex3f (390, 350, 0);
glVertex3f (1000, 250, 0);
glVertex3f (1000, 0, 0);
glEnd();
    int i=0;
    int j=0;
    int k=50;
    while(k<=1000){

        glColor3b(0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f (j, 0, 0);
        glVertex3f (j, 50, 0);
        glVertex3f (k, 50, 0);
        glVertex3f (k, 0, 0);
        glEnd();

        glColor3ub (0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f (j, 100, 0);
        glVertex3f (j, 150, 0);
        glVertex3f (k, 150, 0);
        glVertex3f (k, 100, 0);
        glEnd();

        glColor3ub (0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f (j, 200, 0);
        glVertex3f (j, 250, 0);
        glVertex3f (k,250, 0);
        glVertex3f (k,200, 0);
        glEnd();
        j+=100;
        k+=100;
    }
    int x = 50;
    int y = 100;
    while(x<=1000){
        glColor3ub (0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f (x, 50, 0);
        glVertex3f (x, 100, 0);
        glVertex3f (y, 100, 0);
        glVertex3f (y, 50, 0);
        glEnd();
        //cuadritos negros (piso)
        glColor3ub (0,0,0);
        glBegin(GL_POLYGON);
        glVertex3f (x, 150, 0);
        glVertex3f (x, 200, 0);
        glVertex3f (y, 200, 0);
        glVertex3f (y, 150, 0);
        glEnd();
        x+=100;
        y+=100;
    }
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f (200, 300, 0);
    glVertex3f (200, 315, 0);
    glVertex3f (250, 315, 0);
    glVertex3f (250, 300, 0);
    glEnd();
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f (300, 300, 0);
    glVertex3f (300, 328, 0);
    glVertex3f (350, 340, 0);
    glVertex3f (350, 300, 0);
    glEnd();
    glColor3ub (0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f (250, 250, 0);
    glVertex3f (250, 300, 0);
    glVertex3f (300, 300, 0);
    glVertex3f (300, 250, 0);
    glEnd();

//ventana izquierda
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (230, 500, 0);
glVertex3f (325, 520, 0);
glVertex3f (325, 900, 0);
glVertex3f (230, 900, 0);
glEnd();

//ventana izquierda - derecha interior
glColor3ub (131,102,92);
glBegin(GL_POLYGON);
glVertex3f (310, 890, 0);
glVertex3f (325, 900, 0);
glVertex3f (325, 520, 0);
glVertex3f (310, 525, 0);
glEnd();

//ventana izquierda - abajo
glColor3ub (195,182,166);
glBegin(GL_POLYGON);
glVertex3f (230, 500, 0);
glVertex3f (325, 520, 0);
glVertex3f (310, 525, 0);
glVertex3f (230, 510, 0);
glEnd();

//ventana izquierda - superior
glColor3ub (195,182,166);
glBegin(GL_POLYGON);
glVertex3f (230, 900, 0);
glVertex3f (325, 900, 0);
glVertex3f (310, 890, 0);
glVertex3f (230, 890, 0);
glEnd();

//ventana izquierda parrilla-medio-vertical
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (275, 512, 0);
glVertex3f (280, 512, 0);
glVertex3f (280, 895, 0);
glVertex3f (275, 895, 0);
glEnd();

//ventana izquierda parrilla-inferior
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (230, 600, 0);
glVertex3f (320, 615, 0);
glVertex3f (320, 625, 0);
glVertex3f (230, 610, 0);
glEnd();

//ventana izquierda parrila medio
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (230, 700, 0);
glVertex3f (320, 715, 0);
glVertex3f (320, 725, 0);
glVertex3f (230, 710, 0);
glEnd();

//venta izquierda parrila superior horizontal
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (230, 800, 0);
glVertex3f (320, 810, 0);
glVertex3f (320, 820, 0);
glVertex3f (230, 810, 0);
glEnd();

//wear drop front
glColor3ub (89,39,25);
glBegin(GL_POLYGON);
glVertex3f (460, 660, 0);
glVertex3f (470, 670, 0);
glVertex3f (330, 670,0);
glVertex3f (340, 660, 0);
glVertex3f (340, 320, 0);
glVertex3f (460, 320, 0);
glEnd();

//parte delantera cajon 1 exterior
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (455, 431, 0);
glVertex3f (345, 431, 0);
glVertex3f (345, 324, 0);
glVertex3f (455, 324, 0);
glEnd();

//frontal cajon 1 
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (410, 381, 0);
glVertex3f (390, 381, 0);
glVertex3f (390, 375, 0);
glVertex3f (410, 375, 0);
glEnd();

//frontal cajon 2 - exterior
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (455, 435, 0);
glVertex3f (345, 435, 0);
glVertex3f (345, 541, 0);
glVertex3f (455, 541, 0);
glEnd();

// frontal cajon 2
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (410, 481, 0);
glVertex3f (390, 481, 0);
glVertex3f (390, 475, 0);
glVertex3f (410, 475, 0);
glEnd();
// cajon frontal 3 - exterior
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (455, 653, 0);
glVertex3f (345, 653, 0);
glVertex3f (345, 545, 0);
glVertex3f (455, 545, 0);
glEnd();

//cajon frontal 3
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (410, 585, 0);
glVertex3f (390, 585, 0);
glVertex3f (390, 579, 0);
glVertex3f (410, 579, 0);
glEnd();

//latral
glColor3ub (39,32,21);
glBegin(GL_POLYGON);
glVertex3f (470, 670, 0);
glVertex3f (500, 667, 0);
glVertex3f (492, 657, 0);
glVertex3f (492, 330, 0);
glVertex3f (460, 320, 0);
glVertex3f (460, 660, 0);
glEnd();

//tocador -frente
glColor3ub (98,47,29);
glBegin(GL_POLYGON);
glVertex3f (50, 150,0);
glVertex3f (245, 230, 0);
glVertex3f (245, 460, 0);
glVertex3f (50, 400, 0);
glEnd();

//tocador - parte delantera - parte izquierda
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (55, 160,0);
glVertex3f (115, 185, 0);
glVertex3f (115, 410, 0);
glVertex3f (55, 390, 0);
glEnd();
//tocador - parte delantera - parte izquierda - manija delantera
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (70, 305,0);
glVertex3f (75, 305, 0);
glVertex3f (75, 255, 0);
glVertex3f (70, 255, 0);
glEnd();

//tocador - parte delantera - parte izquierda - fondo
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (64, 262,0);
glVertex3f (75, 262, 0);
glVertex3f (75, 255, 0);
glVertex3f (64, 255, 0);
glEnd();

//tocador - parte delantera - parte izquierda - parte superior
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (64, 305,0);
glVertex3f (75, 305, 0);
glVertex3f (75, 310, 0);
glVertex3f (64, 310, 0);
glEnd();

//lado del tocador
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (50, 150, 0);
glVertex3f (20, 170, 0);
glVertex3f (20, 420, 0);
glVertex3f (50, 400, 0);
glEnd();

//tocador - delantero - parte media
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (120, 185,0);
glVertex3f (180, 210, 0);
glVertex3f (180, 430, 0);
glVertex3f (120, 410, 0);
glEnd();

//tocador delantero - parte media - parte superior
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (135, 275,0);
glVertex3f (140, 275, 0);
glVertex3f (140, 323, 0);
glVertex3f (135, 323, 0);
glEnd();

//tocador delantero - parte media - manija - abajo
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (130, 328,0);
glVertex3f (140, 328, 0);
glVertex3f (140, 323, 0);
glVertex3f (130, 323, 0);
glEnd();
//tocador delantero - parte media - manija - arriba - abajo
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (130, 275,0);
glVertex3f (140, 275, 0);
glVertex3f (140, 280, 0);
glVertex3f (130, 280, 0);
glEnd();

//tocador - delantero  - parte derecha
glColor3ub (42,23,15);
glBegin(GL_POLYGON);
glVertex3f (185, 213,0);
glVertex3f (240, 235, 0);
glVertex3f (240, 450, 0);
glVertex3f (185, 430, 0);
glEnd();

//tocador - delantero  - parte derecha - manija - arriba
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (200, 300,0);
glVertex3f (205, 300, 0);
glVertex3f (205, 343, 0);
glVertex3f (200, 343, 0);
glEnd();

//tocador - delantero  - parte derecha - manija  - abajo
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (194, 300,0);
glVertex3f (205, 300, 0);
glVertex3f (205, 295, 0);
glVertex3f (194, 295, 0);
glEnd();
//tocador - delantero  - parte derecha - manija - arriba - abajo
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (194, 343,0);
glVertex3f (205, 343, 0);
glVertex3f (205, 348, 0);
glVertex3f (194, 348, 0);
glEnd();

//tocador arriba
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (20, 420,0);
glVertex3f (50, 400, 0);
glVertex3f (245,460, 0);
glVertex3f (215,480, 0);
glEnd();

//marcador de cristal del tocador
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (190, 470, 0);
glVertex3f (48, 427, 0);
glVertex3f (48, 770, 0);
glVertex3f (190, 800, 0);
glEnd();

//cristal del tocador
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (180, 467, 0);
glVertex3f (58, 430, 0);
glVertex3f (58, 750, 0);
glVertex3f (180, 777, 0);
glEnd();

//reflejo del objeto
glColor3ub (158,158,158);
glBegin(GL_POLYGON);
glVertex3f (130, 460, 0);
glVertex3f (150, 460, 0);
glVertex3f (160, 575, 0);
glVertex3f (120, 570, 0);
glEnd();
//reflejo de la flor1
glColor3ub (229,115,115);
glBegin(GL_POLYGON);
glVertex3f (140, 600, 0);
glVertex3f (150, 650, 0);
glVertex3f (130, 650, 0);
glEnd();
//reflejo de la flor4
glColor3ub (255,213,79);
glBegin(GL_POLYGON);
glVertex3f (150, 690, 0);
glVertex3f (140, 740, 0);
glVertex3f (130, 690, 0);
glEnd();

//reflejo de la flor2
glColor3ub (129,199,132);
glBegin(GL_POLYGON);
glVertex3f (130, 690, 0);
glVertex3f (100, 670, 0);
glVertex3f (130, 650, 0);
glEnd();

//reflejo de la flor3
glColor3ub (2,136,209);
glBegin(GL_POLYGON);
glVertex3f (150, 690, 0);
glVertex3f (180, 670, 0);
glVertex3f (150, 650, 0);
glEnd();


//reflejo de la flor5
glColor3ub (206,140,216);
glBegin(GL_POLYGON);
glVertex3f (150, 690, 0);
glVertex3f (130, 690, 0);
glVertex3f (130, 650, 0);
glVertex3f (150, 650, 0);
glEnd();

//objejot flor reflejo
glColor3ub (165,214,167);
glBegin(GL_POLYGON);
glVertex3f (137, 655, 0);
glVertex3f (143, 655, 0);
glVertex3f (143, 570, 0);
glVertex3f (137, 570, 0);
glEnd();


//marco de cristal del tocador - parte inferior
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (190, 470, 0);
glVertex3f (48, 427, 0);
glVertex3f (48, 442, 0);
glVertex3f (190, 485, 0);
glEnd();

//objeto
glColor3ub (117,117,117);
glBegin(GL_POLYGON);
glVertex3f (170, 450, 0);
glVertex3f (190, 455, 0);
glVertex3f (200, 575, 0);
glVertex3f (160, 570, 0);
glEnd();

//soporte de objeto flor 
glColor3ub (76,175,80);
glBegin(GL_POLYGON);
glVertex3f (177, 650, 0);
glVertex3f (183, 650, 0);
glVertex3f (183, 570, 0);
glVertex3f (177, 570, 0);
glEnd();

//objeto flor1
glColor3ub (244,67,54);
glBegin(GL_POLYGON);
glVertex3f (180, 600, 0);
glVertex3f (190, 650, 0);
glVertex3f (170, 650, 0);
glEnd();

//objeto flor2
glColor3ub (27,94,32);
glBegin(GL_POLYGON);
glVertex3f (170, 690, 0);
glVertex3f (140, 670, 0);
glVertex3f (170, 650, 0);
glEnd();

//objeto flor3
glColor3ub (2,136,209);
glBegin(GL_POLYGON);
glVertex3f (190, 690, 0);
glVertex3f (220, 670, 0);
glVertex3f (190, 650, 0);
glEnd();

//objeto flor4
glColor3ub (251,140,0);
glBegin(GL_POLYGON);
glVertex3f (190, 690, 0);
glVertex3f (180, 740, 0);
glVertex3f (170, 690, 0);
glEnd();

//objeto flor15
glColor3ub (123,31,62);
glBegin(GL_POLYGON);
glVertex3f (190, 690, 0);
glVertex3f (170, 690, 0);
glVertex3f (170, 650, 0);
glVertex3f (190, 650, 0);
glEnd();


//cama
//cabecera de cama
glColor3ub (77,40,26);
glBegin(GL_POLYGON);
glVertex3f (550, 650, 0);
glVertex3f (850, 600, 0);
glVertex3f (850, 250, 0);
glVertex3f (550, 300, 0);
glEnd();

//retraso de la cama
glColor3ub (88,40,19);
glBegin(GL_POLYGON);
glVertex3f (250, 200, 0);
glVertex3f (550, 150, 0);
glVertex3f (550, 50, 0);
glVertex3f (250, 100, 0);
glEnd();


//lado derecho de la cama
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (850, 250, 0);
glVertex3f (550, 50, 0);
glVertex3f (550, 150, 0);
glVertex3f (850, 350, 0);
glEnd();

//lado derecho de la cama - caja izquierda
glColor3ub (77,40,26);
glBegin(GL_POLYGON);
glVertex3f (695, 160, 0);
glVertex3f (555, 65, 0);
glVertex3f (555, 140, 0);
glVertex3f (695, 235, 0);
glEnd();

//lado derecho de la cama - caja izquierda

glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (650, 160, 0);
glVertex3f (600, 125, 0);
glVertex3f (600, 140, 0);
glVertex3f (650, 175, 0);
glEnd();

//lado derecho de la cama - 2nd caja
glColor3ub (77,40,26);
glBegin(GL_POLYGON);
glVertex3f (845, 260, 0);
glVertex3f (705, 165, 0);
glVertex3f (705, 240, 0);
glVertex3f (845, 335, 0);
glEnd();

//lado derecho de la cama - 2nd caja-

glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (800, 260, 0);
glVertex3f (750, 225, 0);
glVertex3f (750, 240, 0);
glVertex3f (800, 275, 0);
glEnd();

//plataforma de cama 
glColor3ub (198,40,40);
glBegin(GL_POLYGON);
glVertex3f (550, 150, 0);
glVertex3f (850, 350, 0);
glVertex3f (850, 400, 0);
glVertex3f (550, 200, 0);
glEnd();

//pierna de la cama izquierda
glColor3ub (177,160,140);
glBegin(GL_POLYGON);
glVertex3f (250, 200, 0);
glVertex3f (250, 250, 0);
glVertex3f (550, 450, 0);
glVertex3f (550, 400, 0);

glEnd();

//parte superior de la cama
glColor3ub (183,28,28);
glBegin(GL_POLYGON);
glVertex3f (250, 200, 0);
glVertex3f (550, 150, 0);
glVertex3f (550, 200, 0);
glVertex3f (250, 250, 0);
glEnd();

//sabana
glColor3ub (244,67,55);
glBegin(GL_POLYGON);
glVertex3f (550, 200, 0.0);
glVertex3f (250, 250, 0.0);
glVertex3f (550, 450, 0.0);
glVertex3f (850, 400, 0.0);
glEnd();

//almohada

//almohada - izquierda
glColor3ub (255,245,157);
glBegin(GL_POLYGON);
glVertex3f (604, 375, 0.0);
glVertex3f (500, 395, 0.0);
glVertex3f (550, 435, 0.0);
glVertex3f (655, 415, 0.0);
glEnd();


//almohada -  lado izquierda 
glColor3ub (255,145,0);
glBegin(GL_POLYGON);
glVertex3f (604, 375, 0.0);
glVertex3f (655, 415, 0.0);
glVertex3f (655, 405, 0.0);
glVertex3f (604, 365, 0.0);
glEnd();

//almohada -  lado- fondo
glColor3ub (255,145,0);
glBegin(GL_POLYGON);
glVertex3f (604, 375, 0.0);
glVertex3f (500, 395, 0.0);
glVertex3f (500, 385, 0.0);
glVertex3f (604, 365, 0.0);
glEnd();

//almohada -  lado derecha
glColor3ub (255,245,157);
glBegin(GL_POLYGON);
glVertex3f (737, 360, 0.0);
glVertex3f (624, 375, 0.0);
glVertex3f (675, 410, 0.0);
glVertex3f (790, 390, 0.0);
glEnd();
//almohada -  lado derecho
glColor3ub (255,145,0);
glBegin(GL_POLYGON);
glVertex3f (737, 360, 0.0);
glVertex3f (790, 390, 0.0);
glVertex3f (790, 380, 0.0);
glVertex3f (737, 350, 0.0);
glEnd();

//almohada fondo
glColor3ub (255,145,0);
glBegin(GL_POLYGON);
glVertex3f (737, 360, 0.0);
glVertex3f (624, 375, 0.0);
glVertex3f (624, 365, 0.0);
glVertex3f (737, 350, 0.0);
glEnd();

//manta de la cam
glColor3ub (94,53,177);
glBegin(GL_POLYGON);
glVertex3f (550, 220, 0.0);
glVertex3f (280, 260, 0.0);
glVertex3f (400, 340, 0.0);
glVertex3f (670, 300, 0.0);
glEnd();

//ventana derecha
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (1000, 500, 0);
glVertex3f (900, 500, 0);
glVertex3f (900, 900,0);
glVertex3f (1000,900, 0);
glEnd();
//venta izquierda - parte inferior
glColor3ub (105,87,62);
glBegin(GL_POLYGON);
glVertex3f (1000, 500, 0);
glVertex3f (900, 500, 0);
glVertex3f (910, 510,0);
glVertex3f (1000,510, 0);
glEnd();
//venta derecho - interior izquierdo
glColor3ub (131,102,92);
glBegin(GL_POLYGON);
glVertex3f (900, 900, 0);
glVertex3f (910, 890, 0);
glVertex3f (910, 510,0);
glVertex3f (900,500, 0);
glEnd();

//venta derecho - interior arriba
glColor3ub (102,87,62);
glBegin(GL_POLYGON);
glVertex3f (900, 900, 0);
glVertex3f (910, 890, 0);
glVertex3f (1000, 890,0);
glVertex3f (1000,900, 0);
glEnd();

//ventana izquierda parrilla abajo-vertical
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (905, 600, 0);
glVertex3f (1000, 600, 0);
glVertex3f (1000, 610,0);
glVertex3f (905,610, 0);
glEnd();

//ventana izquierda parrilla medio-vertical
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (905, 700, 0);
glVertex3f (1000, 700, 0);
glVertex3f (1000, 710,0);
glVertex3f (905,710, 0);
glEnd();

//ventana derecho parrilla arriba-vertical
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (905, 800, 0);
glVertex3f (1000, 800, 0);
glVertex3f (1000, 810,0);
glVertex3f (905,810, 0);
glEnd();

//ventana izquierda parrilla abajo-horizontal
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (965, 505, 0);
glVertex3f (965, 895, 0);
glVertex3f (970, 895,0);
glVertex3f (970,505, 0);
glEnd();
//lado de la cama caja delantera
glColor3ub (60,23,9);
glBegin(GL_POLYGON);
glVertex3f (960, 410,0);
glVertex3f (960, 120,0);
glVertex3f (830, 135,0);
glVertex3f (830, 415, 0);
glVertex3f (820, 435,0);
glVertex3f (970, 435, 0);
glEnd();

//lado de la cama caja frontal - parte inferior de la caja
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (955, 260,0);
glVertex3f (955, 130,0);
glVertex3f (835, 145,0);
glVertex3f (835, 270, 0);
glEnd();

//lado de la cama caja delantera - caja inferior - handel
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (907, 200,0);
glVertex3f (907, 190,0);
glVertex3f (883, 190,0);
glVertex3f (883, 200, 0);
glEnd();

//lado de cama caja delantera - tapa de caja
glColor3ub (128,55,36);
glBegin(GL_POLYGON);
glVertex3f (955, 265,0);
glVertex3f (955, 400,0);
glVertex3f (835, 405,0);
glVertex3f (835, 275, 0);
glEnd();

//lado de cama caja frontal - tapa de caja - handel
glColor3ub (255,255,255);
glBegin(GL_POLYGON);
glVertex3f (907, 337.5,0);
glVertex3f (907, 327.5,0);
glVertex3f (883, 327.5,0);
glVertex3f (883, 337.5, 0);
glEnd();
//lado de la cama lado de la caja
glColor3ub (113,55,34);
glBegin(GL_POLYGON);
glVertex3f (970, 435,0);
glVertex3f (960, 410, 0);
glVertex3f (960, 120,0);
glVertex3f (985, 140, 0);
glVertex3f (985, 430, 0);
glVertex3f (995, 460, 0);
glEnd();

//tapa de la caja lateral de la cama
glColor3ub (192,99,82);
glBegin(GL_POLYGON);
glVertex3f (820, 435,0);
glVertex3f (970, 435,0);
glVertex3f (995, 460,0);
glVertex3f (845, 460,0);
glEnd();

//base de la lámpara de la caja lateral
glColor3ub (0,0,0);
glBegin(GL_POLYGON);
glVertex3f (875, 440,0);
glVertex3f (915, 440,0);
glVertex3f (910, 450,0);
glVertex3f (890, 450,0);
glEnd();

//soporte de lámpara de caja lateral de cama
glColor3ub (77,49,26);
glBegin(GL_POLYGON);
glVertex3f (895, 445,0);
glVertex3f (905, 445,0);
glVertex3f (905, 550,0);
glVertex3f (895, 550,0);
glEnd();

//soporte de lámpara de caja lateral de cama
glColor3ub (244,67,59);
glBegin(GL_POLYGON);
glVertex3f (875, 650,0);
glVertex3f (925, 650,0);
glVertex3f (935, 550,0);
glVertex3f (865, 550,0);
glEnd();

//cama derecha papos - 1
glColor3ub (213,0,249);
glBegin(GL_POLYGON);
glVertex3f (705, 150, 0);
glVertex3f (570, 60, 0);
glVertex3f (680, 60, 0);
glVertex3f (815, 150, 0);
glEnd();


//cama derecha papos - 2
glColor3ub (255,61,0);
glBegin(GL_POLYGON);
glVertex3f (725, 150, 0);
glVertex3f (590, 60, 0);
glVertex3f (660, 60, 0);
glVertex3f (795, 150, 0);
glEnd();


//cama derecha papos - 2
glColor3ub (255,61,0);
glBegin(GL_POLYGON);
glVertex3f (725, 150, 0);
glVertex3f (590, 60, 0);
glVertex3f (660, 60, 0);
glVertex3f (795, 150, 0);
glEnd();

//cama derecha papos - 3
glColor3ub (57,73,171);
glBegin(GL_POLYGON);
glVertex3f (745, 150, 0);
glVertex3f (610, 60, 0);
glVertex3f (640, 60, 0);
glVertex3f (775, 150, 0);
glEnd();


p = 1 - d;
    if (p<0)
    {
        gx = gx+1;
        hy = d;
        p = p + (2*gx)+1;
    }
    else
    {
        gx = gx + 1;
        hy = d - 1;
        p = p + (2*gx)+1-(2*hy) ;
    }
    ha = gx ;
       gb = hy ;
        glColor3f (1.0, 0.0, 0.0);
               glBegin(GL_POLYGON);
        glVertex2i (ha+hxc, gb+gyc);
         glVertex2i ( gb+hxc,ha+gyc);
        glVertex2i (ha+hxc,-1*gb+gyc);
        glVertex2i (-1*ha+hxc,gb+gyc);
        glVertex2i (-1*ha+hxc,-1*gb+gyc);
        glVertex2i ( gb+hxc,-1*ha+gyc);
        glVertex2i ( -1*gb+hxc,ha+gyc);
        glVertex2i ( -1*gb+hxc,-1*ha+gyc);
        glEnd();

        while(gx<hy)
     {
        if (p<0)
        {
            gx = gx+1;
            hy = hy;
            p = p + (2*gx)+1;
        }
        else
        {
            gx = gx + 1;
            hy = hy - 1;
            p = p + (2*gx)+1-(2*hy) ;
        }
        ha = gx ;
       gb = hy ;
        glColor3f (1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2i (ha+hxc, gb+gyc);
         glVertex2i ( gb+hxc,ha+gyc);
        glVertex2i (ha+hxc,-1*gb+gyc);
        glVertex2i (-1*ha+hxc,gb+gyc);
        glVertex2i (-1*ha+hxc,-1*gb+gyc);
        glVertex2i ( gb+hxc,-1*ha+gyc);
        glVertex2i ( -1*gb+hxc,ha+gyc);
        glVertex2i ( -1*gb+hxc,-1*ha+gyc);
        glEnd();
     }

glFlush ();
}
void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1366, 780);
glutInitWindowPosition (10, 10);
glutCreateWindow ("Cuartito");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}


