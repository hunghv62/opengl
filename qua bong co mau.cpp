#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static int day= 0;
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
	glTranslatef(-1.5,0.0,0.0);
	glRotatef(45,0,0,1);
	glScalef(15,0.6,5);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse_do);
	glutSolidCube(1.0);
	glPopMatrix();
//	glutSwapBuffers();
	
	glPushMatrix();
	glTranslatef(3.2,7,0);
	glTranslatef( (GLfloat) day/40 , (GLfloat) day/40 , 0);		// bu?c3: t?o chuy?n d?ng, phép t?nh ti?n tru?c
	glRotatef (((GLfloat) day)*(-1), 0, 0, 1);	
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse_xanh);
	glutSolidSphere(1.0,20,20);
	glPopMatrix();
	glutSwapBuffers();
   glFlush ();
}
void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case '.': // (>)
			day = (day + 1)/1.1; // lan lên ch?m d?n
			glutPostRedisplay();
			break;
		case ',': // (<)
			day = (day - 1)*1.1; // lan xu?ng nhanh d?n
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

