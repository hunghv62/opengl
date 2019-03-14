#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

   float x=0,y=0,z=0,dich=0;
   float spin=0;
void init(void) 
{
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   GLfloat light_diffuse[]={0.0,0.0,1.0,0.0};
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   //glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}
void display(void)
{

   GLfloat mat_diffuse_y[]={1.0,1.0,0.0};
     GLfloat mat_diffuse_m[]={1.0,0.0,1.0};
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
   	glTranslatef(dich,0,0);
	glRotatef(spin,x,1,z);
	glTranslatef(-dich,0,0);
	glTranslatef(-1.5,0,0);
   glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse_y);
   glutSolidTeapot(1.0);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse_m);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(3,0.0,0.0);
   glutSolidTeapot (1.0);
   glPopMatrix();
   glFlush ();
   
}
void keyboard(unsigned char key ,int x,int y){
	switch (key){
		case 'a':
			x=0;
			y=0;
			z=1;
			dich=-1.5;
			spin=spin+5;
			if(spin>360.0)
				spin=spin-360;
				glutPostRedisplay();
		break;		
	}
}
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
   glOrtho (-4.5, 4.5, -4.5*(GLfloat)h/(GLfloat)w, 4.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
   glOrtho (-4.5*(GLfloat)w/(GLfloat)h,
         4.5*(GLfloat)w/(GLfloat)h, -4.5, 4.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
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

