#include<GL/glut.h>
#include<GL/gl.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	//glEnd();
	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 200.0);
}

void main(int argc,char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
