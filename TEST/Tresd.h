#include <GL/glut.h>
GLsizei wh = 800, ww = 800; 
double rotate_y = 0;
double rotate_x = 0;
int iFondo = 0;
int forma=2;
int iDibujo = 3;
int iTipo=0;
void myReshape(GLsizei w, GLsizei h)
{
    /* adjust clipping box */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((GLdouble)w,0.0 ,(GLdouble)h ,0.0 , -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* adjust viewport and clear */
    glViewport(0,0,w,h);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    /* set global size for use by drawing routine */
    ww = w;
    wh = h;
}
void specialKeys(int key,int x,int y){
	// presion en el teclado hacia la derecha
	if(key==GLUT_KEY_RIGHT)
		rotate_y +=5;		
	else if(key==GLUT_KEY_LEFT)// presion en el teclado hacia la izquierda
		rotate_y -=5;	
	else if(key==GLUT_KEY_UP)// presion en el teclado hacia arriba
		rotate_x +=5;	
	else if(key==GLUT_KEY_DOWN)// presion en el teclado hacia abajo
		rotate_x -=5;	
	// actualiza la visualizacion de la patalla
	glutPostRedisplay();
}
void figuras(){
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
 	glMatrixMode(GL_MODELVIEW);
 	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_x,1.0,0.0,0.0);
	glRotatef(rotate_y,0.0,1.0,0.0);
	float colores[6][3] = {
 { 0.00f, 0.00f, 0.00f}, // 0 - negro
 { 0.06f, 0.25f, 0.13f}, // 1 - verde oscuro
 { 0.10f, 0.07f, 0.33f}, // 2 - azul oscuro
 { 1.00f, 1.00f, 1.00f}, // 3 - blanco
 { 0.12f, 0.50f, 0.26f}, // 4 - verde claro
 { 0.20f, 0.14f, 0.66f}, // 5 - azul claro
 };
 glClearColor(colores[iFondo][0], colores[iFondo][1], colores[iFondo][2], 1.0f);
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(colores[iDibujo][0], colores[iDibujo][1], colores[iDibujo][2]);
 if(forma==2){
 	glutWireTeapot(20);
 }
 if(forma==3){
 	glutWireTorus(25,45,40,40);
 }
	
	glFlush();
 	glutSwapBuffers();
}

