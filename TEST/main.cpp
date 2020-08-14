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
int modo=1;
int xd=1;
int i=0;
int opcion=1;
Punto puntos[20];
void prueba();
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
void iniciar(){
	glClearColor(0,0,0,0);//fondo blanco
	glPointSize(4);//tama?o de punto
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(xd==1){
		gluOrtho2D(800,00,800,00);
	}if(xd==2){
		gluOrtho2D(00,800,00,800);
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
        xd=2;
        iniciar();
        barnsleyFern();
        xd=1;
        i = 0;
        iniciar();
    }
    glPointSize(2);
    glFlush();
    glutSwapBuffers();
}

void menu (int id)
{
    switch(id)
    {
        case 1:
            modo=1;
            prueba();
            break;
        case 2:
            modo=2;
            forma=2;
            prueba();
            break;
        case 3:
        	modo=2;
        	forma=3;
        	break;
    }
    glutPostRedisplay();
}
void prueba(){
	if(modo==1){
		
		glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
		glutInitWindowPosition(50,50);
		glutInitWindowSize(800,800);
		glutCreateWindow("Paint en OPENGL");
		glutDisplayFunc(dibujar);
		glutCreateMenu(menu); 
    	glutAddMenuEntry("mode 2d", 1);
    	glutAddMenuEntry("modo 3d", 2);
    	glutAttachMenu(GLUT_RIGHT_BUTTON);
		glutMouseFunc(mi_Mouse);
		
		
		iniciar();
		glutReshapeFunc (myReshape);
	}
	if(modo==2){
		//lee todos los argumentos que suceda en el aplicativo
	//ejemplo presionar un tecla, mover el mouse, etc...
	
	//habilitar la ventana de color y con profundidad
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
	glutInitWindowSize(800,800);
	//creando la ventana de presentacion
	glutCreateWindow("IZQUIERDO ROJAS, Luis Angel");
	//habilita la profundidad
	glEnable(GL_DEPTH_TEST);
	//llamando a la funcion display y specialKeys
	glutDisplayFunc(figuras);
	glutCreateMenu(menu); 
    	glutAddMenuEntry("mode 2d", 1);
    	glutAddMenuEntry("modo 3d", 2);
    	glutAddMenuEntry("toroide", 3);
    	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutSpecialFunc(specialKeys);
	//mostrar la pantalla, y obtener los eventos
	}
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	prueba();
		
		glutMainLoop();
	
	
}
