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

 //Punto puntos[20];

 Punto absd[20];
  int opcion;
 std:: vector<Punto>puntos(100);
 std:: vector<Curva>cur;
 std:: vector<Linea>lin;
  int tmpx, tmpy;
  bool isSecond = false;

void area_de_trabajo(){
	glColor3f(1.0,1.0,1.0);
	glBegin (GL_POLYGON);
  		glVertex2f (800,800);
		glVertex2f (30, 800);
		glVertex2f (30, 0);
		glVertex2f (800, 0);
  	glEnd ();
}
  
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
	glColor3f(0.5,0.5,0.3);
	glBegin (GL_POLYGON);
  	glVertex2f (0,20+150);
	glVertex2f (20, 20+150);
	glVertex2f (20, 0+150);
	glVertex2f (0,0+150);
	glEnd();
	
}

	float Y;
	int a,s,d,f;
	int i=0;
	
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
	//glutSolidSphere(100,100, 100);
	glBegin(GL_POINTS);
	for (unsigned int i = 0; i < /*20*/puntos.size(); i++)
	{
		glColor3f(0.0,0.5,0.6);
		glVertex2i(puntos[i].getx(), puntos[i].gety());
	}
	glEnd();
	
	
	if(i == 1 && opcion==1) {


        Punto p(puntos[0].getx(),puntos[0].gety());
        
		puntos.push_back(p);
        i = 0;

    }
	if(i == 2 && opcion==2) {


        glColor3f(1.0,1.0,0.0);
        
        	Linea uw(puntos[0], puntos[1]);
           uw.DDA();
		lin.push_back(uw);
        i = 0;
		
        

    }
    if(i == 5 && opcion==3) {
        glColor3f(1.0,0.5,0.0);
        Curva uwd(puntos,5);
         //uwd.bezier();
         uwd.castelljau();
         cur.push_back(uwd);
        i = 0;
    }

/*    if(i == 4 && opcion == 4){
    	Poligonos ads(puntos,4);
    	ads.dibujarpoligono();
    	i = 0;
	}*/
	if(i == 2 && opcion == 4){
		float distancia=sqrt(abs(pow(puntos[0].getx()-puntos[1].getx(),2)-pow(puntos[0].gety()-puntos[1].gety(),2)));
		cout<<distancia;
    	Circulo ads(puntos[0].getx(),puntos[0].gety(),distancia,200);
    	ads.dibujarcirculo();
    	cout<<puntos[0].getx()<<" "<<puntos[1].gety()<<"\n";
    	i = 0;
	}
	if(i == 4 && opcion==5) {
        glColor3f(1.0,0.5,0.0);
        Curva uwd(puntos,5);
           uwd.bezier();
         // uwd.castelljau();
        i = 0;
    }
    glPointSize(2);
    glFlush();
    glutSwapBuffers();
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
