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
		
