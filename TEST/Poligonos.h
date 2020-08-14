


void cuadrilatero(Punto a,Punto b,Punto c,Punto d){
	Linea ab(a,b);
	ab.DDA();
	Linea bc(b,c);
	bc.DDA();
	Linea cd(c,d);
	cd.DDA();
	Linea da(d,a);
	da.DDA();
}



