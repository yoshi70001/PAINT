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
	
	coordenadas();
	/*
	glPointSize(5);
	//Implementar las funciones de rotación y traslación del punto y línea
    //en dev C++ con OpenGL.
    glColor3f(1,0,0);
    Punto g(150,200);
    g.draw();
    glColor3f(1,0.5,0.5);
    Punto f=g.rotar(90);//---------------punto rotar
    f.draw();
    //-----------------punto trasladar
    //Punto nani=g.trasladar(180,200);
    //nani.draw();
    glColor3f(1,0,0);
    Punto t(-150,-150);
	Punto e(-180,-180);
    Linea w(t,e);
    w.draw();
    glColor3f(1,0.5,0.5);
    //---------------linea rotar
    Linea q=w.rotar(60);
    q.draw();
    Punto u(-200,-300);
    Punto l(-100,-200);
    //--------------linea trasladar
    
    //Linea k=w.trasladar(u,l);
    //k.draw();
    
    
	//ejercicio 2 Implementar el reflejo de una línea 
	//( de los puntos P1(1,7) , P2(5,10)) multiplique los puntos por 10 para que se visible
	//a partir de la línea y = 3x/4.
	
	Punto uwu(10,70),owo(50,100);
	Linea ewe(uwu,owo);
	ewe.draw();
	Linea reflejada=ewe.reflejar();
	reflejada.draw();
	
	
	Punto we(320,320*3/4),wi(-320,-320*3/4);
	Linea referen(we,wi);
		referen.draw();
		
		
		
		
		//-----------funcionamiento interno
	/*Punto uwurefle=uwu.reflexionejeRecta(we,wi);
	Punto oworefle=owo.reflexionejeRecta(we,wi);
		
	Linea reflejada(uwurefle,oworefle);	
	reflejada.draw();
	*/
	//------------------------curva
Punto c0(30,30),c1(-30,30),c2(-30,-30),c3(30,-30);
	Punto puntos[]={c0,c1,c2,c3};
Circulo uwwu(30,30,30,20);
uwwu.dibujarcirculo();
//	Punto c0(30,30),c1(40,100),c2(50,30),c3(200,200);
//	Punto puntos[]={c0,c1,c2,c3};
//	Poligonos fu(puntos,4);
//	fu.dibujarpoligono();
//	fu.rotarpli(270);
	//fu.reflejoejex();
	//fu.reflejoejexy();
//	Curva c(puntos,5);
	//c.bezier();
//	c.castelljau();
//	Punto c0(50,40),c1(90,40),c2(100,60),c3(150,70);
//	Punto puntos[]={c0,c1,c2,c3};
//	Curva uwu(puntos,4);
//	uwu.bsplineCubica();
	
	glFlush();
	glutSwapBuffers();
}
void iniciar(){
	glClearColor(1,1,1,0);//fondo blanco
	glPointSize(3);//tamaño de punto
	
	gluOrtho2D(600,0,600,0);
	
}


int main(int argc, char** argv) {
	
	
		glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600,600);
	glutCreateWindow("UWU");
	
	glutDisplayFunc(dibujar);
		iniciar();
		
	glutMainLoop();
	
	
	
}
