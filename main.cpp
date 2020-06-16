#include <iostream>
#include <GL/glut.h>
#include "Linea.h"
#include "Curva.h"
#include <windows.h>
#include <math.h>
#include "Poligonos.h"
#include "Circulo.h"
 using namespace std;
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


void dibujar(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	


	
	glFlush();
	glutSwapBuffers();
}
void iniciar(){
	glClearColor(0,0,0,0);//fondo blanco
	glPointSize(3);//tamaño de punto
	
	gluOrtho2D(600,0,600,0);
	
}


int main(int argc, char** argv) {
	
	
		glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1900,1000);
	glutCreateWindow("Paint en OPENGL");
	
	glutDisplayFunc(dibujar);
		iniciar();
		
	glutMainLoop();
	
	
	
}
