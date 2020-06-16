
class Circulo{
	
	private:
		float cx,cy,r;
		int num_segments;
		
		
	public:
		Circulo(float cx_,float cy_,float r_,int num_segments_){
			cx=cx_;
			cy=cy_;
			r=r_;
			num_segments=num_segments_;
		}
	void dibujarcirculo(){
		
   // glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);

        float x = r * cosf(theta);
        float y = r * sinf(theta);
        
		Punto hj((x + cx),( y + cy));
		hj.draw();
		
        Punto hi((x + cx),( y + cy));
        hi.draw();
        Linea of(hj,hi);
        of.draw();
       // glVertex2f(300-(x + cx),300-( y + cy));//output vertex
		
    }
    //glEnd();
	}
};
