#include <iostream>
#include <GL/glut.h>
#include "Linea.h"
#include "Curva.h"
#include <windows.h>
#include <math.h>
#include "Poligonos.h"
#include "Circulo.h"
 using namespace std;
 Punto absd[4];
void coordenadas(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,0);// color
  	glBegin (GL_LINES);
  	glVertex2f (300, 0);
	glVertex2f (300, 600);
	glVertex2f (0, 300);
	glVertex2f (600, 300);
	glEnd();	
}

	float Y;
	int a,s,d,f;
	int NUMPOINTS=0;
	
void mi_Mouse(int button, int state, int x, int y) {
  
   
   
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      
    absd[NUMPOINTS].setx((float)x);
    absd[NUMPOINTS].sety((float)(800 - y));
    
    NUMPOINTS++;

    
    if(NUMPOINTS == 2) {
        glColor3f(1.0,1.0,0.0);
        cout<<"x1 "<<absd[0].getx()<<" y1 "<<absd[0].gety()<<"\n";
        cout<<"x2 "<<absd[1].getx()<<" y2 "<<absd[1].gety()<<"\n";
        Linea uwd(absd[0], absd[1]);
        
           uwd.draw();
           
        
        NUMPOINTS = 0;
    }
  }
}
void dibujar(){
	glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void iniciar(){
	glClearColor(0,0,0,0);//fondo blanco
	glPointSize(3);//tamaño de punto
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(800,0,800,0);
	
}


int main(int argc, char** argv) {
	
	
		glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(800,800);
	glutCreateWindow("Paint en OPENGL");
	glutMouseFunc(mi_Mouse);
	glutDisplayFunc(dibujar);
	
		iniciar();
		
	glutMainLoop();
	
	
	
}
