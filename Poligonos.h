#include "iostream"
using namespace std;
class Poligonos{
	private:
	Punto matriz[20];
	int nvertices;
	public:
		Poligonos(Punto *pts,int n_){
			nvertices=n_;
			for(int i=0;i<nvertices;i++){
				matriz[i]=pts[i];
			}
			
		}
							
		void dibujarpoligono(){
			Punto origen;
			
			for(int u=0;u<nvertices-1;u++){
				Punto aux(0,0);
				
				for(int iter=0;iter<2;iter++){
					Punto aux2(matriz[u+iter].getx(),matriz[u+iter].gety());
				origen=aux2;
				if(aux.getx()==0 or aux.gety()==0 ){
					aux=origen;
				}
			}
			
			Linea ij(aux,origen);
			ij.draw();
			}
			Linea final(matriz[nvertices-1],matriz[0]);
			final.draw();
			
			
		}
		
		void trasladar(Punto *aux){
			for(int i=0;i<sizeof(aux);i++){
				matriz[i]=aux[i];
			}
			dibujarpoligono();
		}
		void reflejoejex(){
			Punto aux[20];
			for(int i=0 ;i<20;i++){
				aux[i]=matriz[i].reflexionejeX();
			}
			Poligonos fuf(aux,nvertices);
			fuf.dibujarpoligono();
		}
		void reflejoejexy(){
			Punto aux[20];
			for(int i=0 ;i<20;i++){
				aux[i]=matriz[i].reflexionejeXY();
			}
			for(int i=0;i<nvertices;i++){
				matriz[i]=aux[i];
			}
			dibujarpoligono();
		}
		void rotarpli(float theta){
			Punto aux[20];
			for(int i=0 ;i<20;i++){
				aux[i]=matriz[i].rotar(theta);
			}
			Poligonos fuf(aux,nvertices);
			fuf.dibujarpoligono();
		}
		
};
