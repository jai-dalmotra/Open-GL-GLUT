#include<stdio.h>
#include<GL/glut.h>
int rx, ry;
int xcen, ycen;
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void plotpt(int x, int y, int xcen, int ycen)
{
	glBegin(GL_POINTS);
	glVertex2i(x + xcen, y + ycen);
	glEnd();
}

void ellipseMidpoint(int xcen, int ycen, int rx, int ry)
{
	float x = 0;
	float y = ry;
	float p1 = ry * ry - rx * rx * ry + 0.25 * rx * rx;//decision parameter of region 1
	float dx = 2 * ry * ry * x;
	float dy = 2 * rx * rx * y;
	while (dx < dy)
	{
		plotpt(x, y, xcen, ycen);
		plotpt(-x, y, xcen, ycen);
		plotpt(x, -y, xcen, ycen);
		plotpt(-x, -y, xcen, ycen);
		if (p1 < 0)
		{
			x++;
			dx = dx + 2 * ry * ry;
			p1 = p1 + dx + ry * ry;
		}
		else
		{
			x++;
			y--;
			dx = dx + 2 * ry * ry;
			dy = dy - 2 * rx * rx;
			p1 = p1 + dx - dy + ry * ry;
		}
	}
	float p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;//decision parameter of region 2
	while (y > 0)
	{
		plotpt(x, y, xcen, ycen);
		plotpt(-x, y, xcen, ycen);
		plotpt(x, -y, xcen, ycen);
		plotpt(-x, -y, xcen, ycen);
		if (p2 > 0)
		{
			y--;
			dy = dy - 2 * rx * rx;
			p2 = p2 + rx * rx - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + 2 * ry * ry;
			dy = dy - 2 * rx * rx;
			p2 = p2 + dx - dy + rx * rx;
		}
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0);
	ellipseMidpoint(300,300,80,30);
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Ellipse Midpoint Algorithm");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	return 0;
}
