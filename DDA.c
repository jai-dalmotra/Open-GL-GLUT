#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.2, 0.3, 0.0);
	float x1 = 20;
	float x2 = 120;
	float y1 = 30;
	float y2 = 50;
	float d1 = x2 - x1;
	float d2 = y2 - y1;
	float steps = 1;
	if (d2 > d1) {
		steps = d2;
	}
	else {
		steps = d1;
	}
	float xincr = d1 / steps;
	float yincr = d2 / steps;
	glBegin(GL_POINTS);
	float x = x1;
	float y = y1;
	while (x < x2)
	{
		x = (x + xincr);
		y = (y + yincr);
		glVertex2f(x, y);

	}
	glEnd();
	glFlush();
}
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DDA Line Drawing Algorithm");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}
