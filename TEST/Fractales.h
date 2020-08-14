#include <time.h>
int points=5000;
int xf,yf; 
void mouseMove(int x, int y)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   int dx = xf-x;
   int dy = yf-y;

   gluOrtho2D( dx, dx + ww, -dy, -dy + wh);

   glMatrixMode(GL_MODELVIEW);

   glutPostRedisplay();
}

int number(void)
{
   int x=0;
   srand ( time(NULL) );
   x = rand();
   x = x%9+1;
   return x;
}
void barnsleyFern(void)
{

	typedef GLfloat point2[2];
	point2 p = {0.0,50.0},newPoint;

	/*Probability table of the 3 transformations*/
	double probability[3] = {85, 92, 99};

	glClear ( GL_COLOR_BUFFER_BIT );

	/*main drawing loop*/
    for(int i=0; i<points; i++)
	{
	   GLfloat prevx=p[0];
	   GLfloat randnum=rand()%100 +1;
	   if (randnum<probability[0])
       {
            p[0]=p[0]*0.85+0.04*p[1];
            p[1]=prevx*(-0.04)+0.85*p[1]+1.6;
	   }
	   else if(randnum<probability[1])
	   {
            p[0]=0.2*p[0]-0.26*p[1];
            p[1]=0.23*prevx+0.22*p[1]+1.6;
	   }
	   else if(randnum<probability[2])
	   {
            p[0]=-0.15*p[0]+0.28*p[1];
            p[1]=0.26*prevx+0.24*p[1]+0.44;
	   }
	   else
	   {
            p[0]=0.0;
            p[1]=0.16*p[1];
	   }

	   newPoint[0]=p[0]*50+250;
	   newPoint[1]=p[1]*50;
	   if(i>100)
	   {
		  /*Plot new point*/
		  glBegin(GL_POINTS);
               glVertex2fv(newPoint);
          glEnd();
	   }
  }
	//  Clear all buffers.
	glFlush ( );
	glutSwapBuffers();
}
