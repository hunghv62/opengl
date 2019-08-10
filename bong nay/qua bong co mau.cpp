#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
double bong= 1.5;
double thanh = 0;
double dau = 1;
void init(void) 
{
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   GLfloat light_diffuse[] = {0.0,0.0,1.0,0.0};
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}
void display(void)
{	
	GLfloat mat_diffuse_do[] = {1.0,0.0,0.0};
    GLfloat mat_diffuse_xanh[] = {0.0,1.0,0.0};
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glPushMatrix();
	glTranslatef(thanh,0.0,0.0);
	glScalef(3,1,1);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse_do);
	glutSolidCube(1.0);
	glPopMatrix();
//	glutSwapBuffers();
	
	glPushMatrix();
	glTranslatef(0,bong,0);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse_xanh);
	glutSolidSphere(1.0,20,20);
	glPopMatrix();
	glutSwapBuffers();
   glFlush ();
}
void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 'm': 
			
			//thanh dich chuyen
			if(thanh >=-10 && thanh <= 10) thanh+=0.2;
			else if(thanh = 10) thanh = -10;
				
			//bong dich chuyen
			if(bong >=1.5 && bong <= 5){
				bong += 0.1*dau;
				if(bong == 5 ) dau = -1;
				else if(bong == 1.5) dau = 1;
			} 
			
			
			glutPostRedisplay();
			break;
		default:
			break;
	}
}
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0, 1, 0);  // nhìn ngang t? tr?c Z.
//	gluLookAt (0, 10, 10, 0.0, 0.0, 0.0, 0, 1, 0); // di?m nhìn khác: A(0,10,10), hu?ng d?u theo Oy, nhìn v? g?c t?a d?

}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}

