#include <math.h>
#include<vector>
std:: vector<float>px;
std:: vector<float>py;
void guardarpuntos(){
	glPointSize(5);
	glBegin(GL_POINTS);
			for (unsigned int i = 0; i < px.size(); i++)
			{
				glColor3f(0.0,0.5,0.6);
				glVertex2i(px[i], py[i]);
			}
			glEnd();
}


class Punto {
	private:
  		GLint x=0,y=0;
  		GLfloat r=1.0,g=0.0,b=0.5;
		float PI = 3.14159265375;
		std:: vector<Punto>puntos;	
	public:
		Punto(){
			x = 0; y = 0;//posicion			
		}
		Punto(GLint x_,GLint y_){
			x = x_; y = y_;//posicion			
		}
		Punto(GLint x_,GLint y_,GLfloat r_,GLfloat g_,GLfloat b_){
			x = x_;	y = y_;//posicion
			r = r_; g = g_; b = b_;// color
		}
		GLint getx(){
			return x;
		}
		GLint gety(){
			return y;
		}
		GLint setx(GLint x_){
			x = x_;
		}
		GLint sety(GLint y_){
			y = y_;
		}
		GLint set(GLint x_,GLint y_){
			x = x_;
			y = y_;
		}
		void setRGB(GLfloat r_,GLfloat g_,GLfloat b_){
			r = r_; g = g_; b = b_;// color	
		}
		
		
  		void draw() {
  			glPointSize(5);
  			
  			px.push_back(x);
  			py.push_back(y);
  			glBegin(GL_POINTS);
				glColor3f(r,g,b);// color del punto
  				glVertex2d (x,y);
  			glEnd ();
  		}/*
  		void draw(){
  			glPointSize(5);
  			glBegin(GL_POINTS);
			for (unsigned int i = 0; i < puntos.size(); i++)
			{
				glColor3f(0.0,0.5,0.6);
				glVertex2i(puntos[i].getx(), puntos[i].gety());
			}
			glEnd();
		}*/
  		
  		
  		
  		Punto rotar(float theta){
  			theta = theta*PI/180;
  			Punto p=Punto(x,y);
  			p.setx(x*cos(theta)-y*sin(theta));
			p.sety(x*sin(theta)+y*cos(theta));
  			return p;	
		}
  		Punto rotarGeneral(float theta,GLint Xc,GLint Yc ){
  			theta = theta*PI/180;
  			Punto p=Punto(x,y);
  			p.setx(Xc+(x-Xc)*cos(theta)-(y-Yc)*sin(theta));
			p.sety(Yc+(x-Xc)*sin(theta)+(y-Yc)*cos(theta));
  			return p;	
		}
		Punto escalar(GLfloat Sx,GLfloat Sy){
			Punto p = Punto(x,y);
			p.setx(x*Sx);
			p.sety(y*Sy);
			return p;
		}
  		Punto trasladar(GLint Tx,GLint Ty) {
  			Punto p=Punto(x,y);
  			/*int T[3][3]={	{1,0,0},
			  				{0,1,0},
							{Tx,Ty,1}
						};
  			MPunto[1][3] = {x,y,1};
  			MPuntop[1][3] = multiplicacion(MPunto,T);*/
			p.setx(x+Tx);
			p.sety(y+Ty);
  			return p;
  		}
  	 Punto reflexionejeX(){
  		Punto p=Punto(x,y);
  		p.setx(x);
  		p.sety(-y);
  		return p;
	  }	
	  Punto reflexionejeXY(){
  		Punto p=Punto(x,y);
  		p.setx(-x);
  		p.sety(-y);
  		return p;
	  }	
	  Punto reflexionejeY(){
  		Punto p=Punto(x,y);
  		p.setx(-x);
  		p.sety(y);
  		return p;
	  }	
	  Punto reflexionejeRecta(Punto o ,Punto p){
	  	float a,b,c,d,h,k;
	  	a=o.getx();
	  	b=o.gety();
	  	c=p.getx();
	  	d=p.gety();
	  	h=x;
		k=y;	
  		float m =((d-b)/(c-a));
  		float X=(((m*a)-b+(h/m)+k)/((1/m)+m));
  		float Y=((m*X)-(m*a)+b);
  		
  		float coorx=2*X-h;
  		float coory=2*Y-k;
  		
		Punto u=Punto(coorx,coory);
  		u.setx(coorx);
  		u.sety(coory);
  		return u;
	  }	
  		
  		
  		
};


