#include "iostream"
using namespace std;
class Curva
{
	private:
		Punto puntos[20];
		int npuntos=0;
		GLfloat x=0,y=0;
		Punto pt;
		void dibujarlineas(){
			glBegin(GL_LINES);
				for(int i=0;i<npuntos-1;i++){
					glVertex2i(puntos[i].getx(),puntos[i].gety());
					glVertex2i(puntos[i+1].getx(),puntos[i+1].gety());
				}
			glEnd();	
			
		}
		int factorial(int n){
			int salida = 1;
			for(int i=1;i<=n;i++){
				salida=salida*i;
			}
			return salida;
		}
		int combinacion(int n,int i){
			int salida=0;
			if(i==0||n==i){
				return 1;
			}else{
				salida=(factorial(n)/(factorial(i)*factorial(n-i)));
			}
			return salida;
		}
		double pot(double b,int e){
			if(e==0)
			return 1;
			if(e==1)
			return b;
			if(e>1){
				double salida=1;
				for(int i=0;i<e;i++){
					salida =salida*b;
				}
				return salida;
			}
		}
		double bernstein(int n,double i,double t){
			return combinacion(n,i)*pot(t,i)*pot(1-t,n-i);
		}
		
		
		
public:
		Curva(Punto *pts,int n_){
			npuntos=n_;
			for(int i=0;i<npuntos;i++){
				puntos[i]=pts[i];
			}
			dibujarlineas();
		}
		void bezier(){
			for(int j=0;j<=100;j++){
				float t=(float)j/100;
				x=0;y=0;
				for(int i=0;i<npuntos;i++){
					GLfloat B=bernstein(npuntos-1,i,t);
					x=x+puntos[i].getx()*B;
					y=y+puntos[i].gety()*B;
				}
				pt.set(x,y);
				pt.draw();
			}
		}
		void bezier1(){
			for(int j=0;j<=100;j++){
				float t=(float)j/100;
				pt.set(100*(2*t-t*t),100*t*t);
				pt.draw();
			}
		}

		// Castelljau 4 puntos
  /*  void castelljau(){
        Punto P;
    	for(double j = 0.0;j <= 1.0; j+=0.01){
    		
	         float hg= pow((1 - j), 3) * puntos[0].getx() + 3 * j * pow((1 -j), 2) * puntos[1].getx() + 3 * (1-j) * pow(j, 2)* puntos[2].getx() + pow (j, 3)* puntos[3].getx();
	         float gh= pow((1 - j), 3) * puntos[0].gety() + 3 * j * pow((1 -j), 2) * puntos[1].gety() + 3 * (1-j) * pow(j, 2)* puntos[2].gety() + pow (j, 3)* puntos[3].gety();
	    	
			
			P.setx(hg);
	    	P.sety(gh);
			P.draw();
            }
    }*/
    void castelljau(){
    	int tamano=npuntos;
        Punto P;
    	for(double j = 0.0;j <= 1.0; j+=0.01){
    		float hg=0;
    		float gh=0;
    		hg=pow((1-j),tamano-1)*puntos[0].getx();
    		gh=pow((1-j),tamano-1)*puntos[0].gety();
    		
    		for(int grado=1;grado<=tamano-2;grado++){
    			hg=hg+((tamano-1)*pow((1-j),tamano-1-grado)*pow(j,grado)*puntos[grado].getx());
	            gh=gh+((tamano-1)*pow((1-j),tamano-1-grado)*pow(j,grado)*puntos[grado].gety());
	    	
			}
	         hg=hg+(pow(j,tamano-1)*puntos[tamano-1].getx());
	         gh=gh+(pow(j,tamano-1)*puntos[tamano-1].gety());
			cout<<"\ninteracion nro "<<j;
			cout<<"\nvalor de x "<<hg;
			cout<<"\nvalor de y "<<gh;
			P.setx(hg);
	    	P.sety(gh);
			P.draw();
            }
    }
    //-----------------------------------------B-Spline Cuadratica--------------------------------------
    
    void bsplineCubica(){
			GLfloat x0 = 0, y0 = 0;
			GLfloat x1 = 0, y1 = 0;
			GLfloat x2 = 0, y2 = 0;
			float a0 = 40;
			float a1 = 40;
			float a2 = 60;
			float c0 = 0;
			float b2 = 1.880672269;
			float c2 = -0.050420168;
			float d2 = 0.000336134;
			float b0 = -0.867226891;
			float d0 = 0.000542017;
			float b1 = 1.734453782;
			float c1 = 0.065042017;
			float d1 = -0.003848739;
			for	(int j = 0; j <= 1000; j++){
				float t = (float)j/1000;
				//graficamos P0 
				x0 = 50 + t*(90-50);
				y0 = a0 + b0*(x0-50)+c0*(x0-50)*(x0-50)+d0*(x0-50)*(x0-50)*(x0-50);
				pt.setx(GLint(x0));
				pt.sety(GLint(y0));
				pt.setRGB(1,0,0);
				pt.draw();
				//graficamos P1
				x1 = 90 + t*(100-90);
				y1 = a1 + b1*(x1-90)+c1*(x1-90)*(x1-90)+d1*(x1-90)*(x1-90)*(x1-90);
				pt.setx(GLint(x1));
				pt.sety(GLint(y1));
				pt.setRGB(0,1,0);
				pt.draw();
				//graficamos P2
				x2 = 100 + t*(150-100);
				y2 = a2 + b2*(x2-100)+c2*(x2-100)*(x2-100)+d2*(x2-100)*(x2-100)*(x2-100);
				pt.setx(GLint(x2));
				pt.sety(GLint(y2));
				pt.setRGB(0,0,1);
				pt.draw();
			}
		}

    
    	
};

