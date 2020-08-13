#include "Punto.h"
#include <GL/glut.h>
#include <math.h>
#include "cmath"
class Linea {
	private:
		Punto origen;
		Punto destino;
		GLfloat r=1.0, g=0.0,b=0.5;
	public:
		Linea(Punto o,Punto d){
			origen = o;
			destino = d;				
		}
		Linea(Punto o,Punto d,GLfloat r_,GLfloat g_,GLfloat b_){
			origen = o;
			destino = d;
			r=r_;
			g=g_;
			b=b_;					
		}
		//-------------------------------------------
		void DDA(){
	int x0=origen.getx();
	int y0=origen.gety();
	int x1=destino.getx();
	int y1=destino.gety();

   float x,y,xs,ys;
   float dx,dy,steps;
   dx=x1-x0;
   dy=y1-y0;

   x=x0;
   y=y0;
   if(abs(dx)>abs(dy)){
   	steps=abs(dx);
   }else{
   	steps=abs(dy);
   }

   if(steps==0){
   	//dibujar punto

   Punto z(round(x),round(y));
   z.draw();
   }
   xs=dx/steps;
   ys=dy/steps;
   for(int i=0;i<=steps;i++){
   	//dibujar puntos
   	 Punto h(round(x),round(y));
   h.draw();
   	x=x+xs;
   	y=y+ys;
   }
   }

void Bres(){
	int x0=origen.getx();
	int y0=origen.gety();
	int x1=destino.getx();
	int y1=destino.gety();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,0);


	glPointSize(3);
	glBegin(GL_POINTS);
	int x,y, dx,dy,xfinal,p,inE,inNE;
	dx=abs(x1-x0);
	dy=abs(y1-y0);
	p=2*dy-dx;
	inE=2*dy;
	inNE=2*(dy-dx);

	if(x0>x1){
		x=x1;
		y=y1;
		xfinal=x0;
	}else{
		x=x0;
		y=y0;
		xfinal=x1;
	}
	while(x<=xfinal){
		//dibujar puntos
		Punto d(x,y);
   		d.draw();
		x=x+1;
		if(p<0){
			p=p+inE;
		}else{
			y=y+1;
			p=p+inNE;
		}
	}
	glEnd();
   
}
		
		
		
		
		
		
		//---------------------------------------------
	void draw(){
	glBegin(GL_LINES);
		
		glVertex2i(origen.getx(),origen.gety());
		glVertex2i(destino.getx(),destino.gety());
		
	glEnd();
	}
	Linea trasladar(Punto Tx, Punto Ty){
		Punto origenT = origen.trasladar(Tx.getx(),Tx.gety());
		Punto destinoT = destino.trasladar(Ty.getx(),Ty.gety());
		Linea L = Linea(origenT,destinoT);
		return L;
	}
	Linea escalar(GLfloat Sx,GLfloat Sy){
		Punto origenE=origen.escalar(Sx,Sy);
		Punto destinoE=destino.escalar(Sx,Sy);
		Linea L=Linea(origenE,destinoE);
		return L;
	}
	
	Linea rotar(float theta){
		Punto origenR=origen.rotar(theta);
		Punto destinoR=destino.rotar(theta);
		Linea L = Linea(origenR,destinoR);
		return L;
	}
	
	Linea rotarGeneral(float theta,GLint Xc,GLint Yc){
		Punto origenR=origen.rotarGeneral(theta,Xc,Yc);
		Punto destinoR=destino.rotarGeneral(theta,Xc,Yc);
		Linea L = Linea(origenR,destinoR);
		return L;
	}
	Linea reflejarrecta(Punto we,Punto wi){
				
		//Punto we(320,320*3/4),wi(-320,-320*3/4);
		
		Punto origenre=origen.reflexionejeRecta(we,wi);
		Punto destinore=destino.reflexionejeRecta(we,wi);
		Linea gg(origenre,destinore);
		return gg;	
	}
	
};
		
