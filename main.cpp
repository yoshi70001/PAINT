#include <iostream>
#include <GL/glut.h>
#include "Linea.h"
#include "Curva.h"
#include <windows.h>
#include <math.h>
#include "Poligonos.h"
#include "Circulo.h"
 using namespace std;
 Punto absd[20];
void coordenadas(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,0);// color
  	glBegin (GL_LINES);
  	glVertex2f (400, 0);
	glVertex2f (400, 800);
	glVertex2f (0, 400);
	glVertex2f (800, 400);
	glEnd();	
}

	float Y;
	int a,s,d,f;
	int NUMPOINTS=0;
	
void mi_Mouse(int button, int state, int x, int y) {
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      glColor3f(1,1,0);
    absd[NUMPOINTS].setx((float)(800 -x));
    absd[NUMPOINTS].sety((float)y);
    
    NUMPOINTS++;
    
  }
}int opcion;
void dibujar(){
	glClear(GL_COLOR_BUFFER_BIT);
	coordenadas();
	
	
	if(NUMPOINTS == 2 && opcion==1) {
        glColor3f(1.0,1.0,0.0);
        Linea uwd(absd[0], absd[1]);
           uwd.draw();
        NUMPOINTS = 0;
    }
    if(NUMPOINTS == 5 && opcion==2) {
        glColor3f(1.0,1.0,0.0);
        Curva uwd(absd,5);
           uwd.bezier();
        NUMPOINTS = 0;
    }
    
    glFlush();
}
void iniciar(){
	glClearColor(0,0,0,0);//fondo blanco
	glPointSize(4);//tamaño de punto
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(800,0,800,0);
	
}


int main(int argc, char** argv) {
	cout<<"linea =1 bezier=2";
	cin>>opcion;
	if(opcion==1||opcion==2){
		glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(800,800);
	glutCreateWindow("Paint en OPENGL");
	glutMouseFunc(mi_Mouse);
	glutDisplayFunc(dibujar);
	
		iniciar();
		
	glutMainLoop();
	}
		
	
	
	
}
