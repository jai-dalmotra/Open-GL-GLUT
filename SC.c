#include <GL/glut.h>
#include<math.h>
int xc, yc;
void drawPoint(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + xc, y + yc);
	glEnd();
}
void drawPointForLine(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);

	glEnd();
}
void circle(int r)
{
	int x, y, p;
	y = r;
	x = 0;
	p = 1 - r;
	drawPoint(x, y);
	while (x <= y)
	{
		if (p < 0)
		{
			p += 2 * x + 3;
		}
		else
		{
			p += 2 * (x - y) + 5;
			y--;
		}
		x++;
		drawPoint(x, y);
		drawPoint(x, -y);
		drawPoint(-x, y);
		drawPoint(-x, -y);
		drawPoint(y, x);
		drawPoint(-y, x);
		drawPoint(y, -x);
		drawPoint(-y, -x);
	}
}
void line(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int steps, k;
	if (abs(dx) > abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);

	}
	float xIncrement = dx / (float)steps;
	float yIncrement = dy / (float)steps;
	float x = x1;
	float y = y1;
	for (k = 0; k <= steps; k++)
	{
		drawPointForLine(x, y);
		x += xIncrement;
		y += yIncrement;
	}
}
void drawFigure(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6,
	int r)
{
	glColor3f(0, 0, 0);
	glPointSize(1.0);
	line(x1, y1, x2, y2);
	line(x3, y3, x4, y4);
	line(x5, y5, x6, y6);
	circle(r);
}
void scale(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int r)
{
	float scale = 2.0;
	x1 = x1 * scale;
	y1 = y1 * scale;
	x2 = x2 * scale;
	y2 = y2 * scale;
	x3 = x3 * scale;
	y3 = y3 * scale;
	x4 = x4 * scale;
	y4 = y4 * scale;
	x5 = x5 * scale;
	y5 = y5 * scale;
	x6 = x6 * scale;
	y6 = y6 * scale;
	r = r * scale;
	xc = xc * scale;
	yc = yc * scale;
	drawFigure(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, r);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glPointSize(1.0);
	drawFigure(100, 200, 200, 200, 120, 200, 120, 110, 190, 200, 190, 100, 10);
	scale(100, 200, 200, 200, 120, 200, 120, 110, 190, 200, 190, 100, 10);
	// line(100, 200, 200, 200);
	// line(120, 200, 120, 110);
	// line(190, 200, 190, 100);
	// circle(10);
	glFlush();
}
void init()
{
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}
int main(int argc, char** argv)
{
	xc = 120;
	yc = 100;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Lab Eval");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
