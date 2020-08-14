#include <iostream>
#include <GL/glut.h>
#include "Layout.h"
#include "Linea.h"
#include "Tresd.h"
#include "Curva.h"
#include <windows.h>
#include <math.h>
#include "Poligonos.h"
#include "Fractales.h"
#include <vector>
int i=0;
int opcion=1;
Punto puntos[20];
void mi_Mouse(int button, int state, int x, int y) {
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      glColor3f(1,1,0);
    puntos[i].setx((float)(800 -x));
    puntos[i].sety((float)y);
    int n1=puntos[i].getx();
	int n2=puntos[i].gety();
    if(n1<=20 && n1>=0 && n2<=20 && n2>=0){//punto
    		opcion=1;
    		i = 0;
	}
	if(n1<=20 && n1>=0 && n2<=50 && n2>=30){//linea
				opcion=2;
				i = 0;
			}
			if(n1<=20 && n1>=0 && n2<=80 && n2>=60){//curva
				opcion=3;
				i = 0;
			}
			if(n1<=20 && n1>=0 && n2<=110 && n2>=90){//poligono
				opcion=4;
				i = 0;
			}
			if(n1<=20 && n1>=0 && n2<=140 && n2>=120){//circulo
				opcion=5;
				i = 0;
			}
	if(n1<=800 && n1>=30){
		i++;
	} 
  }
}

void dibujar(){
	glClear(GL_COLOR_BUFFER_BIT);
	botones();
	area_de_trabajo();
	guardarpuntos();
	
//	Reshape(800,800);
	
	if(i == 1 && opcion==1) {
		Punto p(puntos[0].getx(),puntos[0].gety());
		p.draw();
        i = 0;
    }
	if(i == 2 && opcion==2) {
        glColor3f(1.0,1.0,0.0);
        	Linea uw(puntos[0], puntos[1]);
           uw.DDA();
		
        i = 0;
    }
    if(i == 5 && opcion==3) {
        glColor3f(1.0,0.5,0.0);
        Curva uwd(puntos,5);
         //uwd.bezier();
         uwd.castelljau();
         
        i = 0;
    }
/*    if(i == 4 && opcion == 4){
    	Poligonos ads(puntos,4);
    	ads.dibujarpoligono();
    	i = 0;
	}*/
	if(i == 4 && opcion == 4){
		cuadrilatero(puntos[0],puntos[1],puntos[2],puntos[3]);
    	i = 0;
	}
	if(i == 1 && opcion==5) {
        glColor3f(1.0,0.5,0.0);
        barnsleyFern();
        i = 0;
    }
    glPointSize(2);
    glFlush();
    glutSwapBuffers();
}
void iniciar(){
	glClearColor(0,0,0,0);//fondo blanco
	glPointSize(4);//tama?o de punto
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
		glutReshapeFunc (myReshape);
		glutMainLoop();
	
	
}
