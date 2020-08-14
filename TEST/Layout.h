
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
void buton(){
	
}

