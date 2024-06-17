#include<stdio.h>
#include<GL/glut.h>

void writepoints(int x, int y, int pntX1, int pnty1)
{
	glBegin(GL_POINTS);
	glVertex2i(x + pntX1, y + pnty1);
	glEnd();
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircle(int pntX1, int pntY1, int radius)
{
	int x = 0;
	int y = radius;
	float p = 1 - radius;
	writepoints(x, y, pntX1, pntY1);
	while (y > x)
	{
		if (p < 0)
		{
			x = x + 1;
			p = p + 2 * x + 3;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + 2 * x - 2 * y + 5;
		}
		writepoints(x, y, pntX1, pntY1);
		writepoints(x, -y, pntX1, pntY1);
		writepoints(-x, y, pntX1, pntY1);
		writepoints(-x, -y, pntX1, pntY1);
		writepoints(y, x, pntX1, pntY1);
		writepoints(-y, x, pntX1, pntY1);
		writepoints(y, -x, pntX1, pntY1);
		writepoints(-y, -x, pntX1, pntY1);
	}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	midPointCircle(320, 240, 100);
	glFlush();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Mid Point Circle");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
