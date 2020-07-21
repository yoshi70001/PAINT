#include <iostream>
#include <GL/glut.h>
#include "Linea.h"
#include "Curva.h"
#include <windows.h>
#include <math.h>
#include "Poligonos.h"
#include "Circulo.h"
#include <vector>

 using namespace std;
 Punto absd[20];
  int opcion;
  vector  <int>memoria;
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
void botones(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,0.5);// color
  	glBegin (GL_POLYGON);
  	glVertex2f (0,20);
	glVertex2f (20, 20);
	glVertex2f (20, 0);
	glVertex2f (0,0);
	glEnd();
	glColor3f(1,1,0);// color
  	glBegin (GL_POLYGON);
  	glVertex2f (0,20+30);
	glVertex2f (20, 20+30);
	glVertex2f (20, 0+30);
	glVertex2f (0,0+30);
	glEnd();
	glColor3f(1,0.5,0);// color
	glBegin (GL_POLYGON);
  	glVertex2f (0,20+60);
	glVertex2f (20, 20+60);
	glVertex2f (20, 0+60);
	glVertex2f (0,0+60);
	glEnd();
	glColor3f(1,0,0);// color
	glBegin (GL_POLYGON);
  	glVertex2f (0,20+90);
	glVertex2f (20, 20+90);
	glVertex2f (20, 0+90);
	glVertex2f (0,0+90);
	glEnd();
	glColor3f(0.5,0,0);// color
	glBegin (GL_POLYGON);
  	glVertex2f (0,20+120);
	glVertex2f (20, 20+120);
	glVertex2f (20, 0+120);
	glVertex2f (0,0+120);
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
    int n1=absd[NUMPOINTS].getx();
	int n2=absd[NUMPOINTS].gety();
    if(n1<=20 && n1>=0 && n2<=20 && n2>=0){
    	opcion=1;
    	NUMPOINTS = 0;
	}
	if(n1<=20 && n1>=0 && n2<=50 && n2>=30){
		opcion=2;
		NUMPOINTS = 0;
	}
	if(n1<=20 && n1>=0 && n2<=80 && n2>=60){
		opcion=3;
		NUMPOINTS = 0;
	}
	if(n1<=20 && n1>=0 && n2<=110 && n2>=90){
		opcion=4;
		NUMPOINTS = 0;
	}
	if(n1<=800 && n1>=30){
		NUMPOINTS++;
	}
    
    
  }
}






void dibujar(){
	glClear(GL_COLOR_BUFFER_BIT);
	botones();	
	glutSolidSphere(100,100, 100);
	if(NUMPOINTS == 2 && opcion==1) {
        glColor3f(1.0,1.0,0.0);
        Linea uw(absd[0], absd[1]);
           uw.DDA();
        NUMPOINTS = 0;
    }
    if(NUMPOINTS == 5 && opcion==2) {
        glColor3f(1.0,0.5,0.0);
        Curva uwd(absd,5);
         //uwd.bezier();
         uwd.castelljau();
        NUMPOINTS = 0;
    }
    if(NUMPOINTS == 4 && opcion == 3){
    	Poligonos ads(absd,4);
    	ads.dibujarpoligono();
    	NUMPOINTS = 0;
	}
	if(NUMPOINTS == 2 && opcion == 4){
		float distancia=sqrt(abs(pow(absd[0].getx()-absd[1].getx(),2)-pow(absd[0].gety()-absd[1].gety(),2)));
		cout<<distancia;
    	Circulo ads(absd[0].getx(),absd[0].gety(),distancia,200);
    	ads.dibujarcirculo();
    	cout<<absd[0].getx()<<" "<<absd[1].gety()<<"\n";
    	NUMPOINTS = 0;
	}
	if(NUMPOINTS == 4 && opcion==5) {
        glColor3f(1.0,0.5,0.0);
        Curva uwd(absd,5);
           uwd.bezier();
         // uwd.castelljau();
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
