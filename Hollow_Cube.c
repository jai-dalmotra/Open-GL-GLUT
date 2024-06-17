#include <GL/glut.h>

void displayMe(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0); // Set the line width for drawing the cube

    glBegin(GL_LINES);
    // Front face
    glVertex2f(0.0, 0.0);
    glVertex2f(0.5, 0.0);

    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, 0.5);

    glVertex2f(0.5, 0.5);
    glVertex2f(0.0, 0.5);

    glVertex2f(0.0, 0.5);
    glVertex2f(0.0, 0.0);

    // Back face
    glVertex2f(0.25, 0.25);
    glVertex2f(0.75, 0.25);

    glVertex2f(0.75, 0.25);
    glVertex2f(0.75, 0.75);

    glVertex2f(0.75, 0.75);
    glVertex2f(0.25, 0.75);

    glVertex2f(0.25, 0.75);
    glVertex2f(0.25, 0.25);

    // Connecting lines between front and back faces
    glVertex2f(0.0, 0.0);
    glVertex2f(0.25, 0.25);

    glVertex2f(0.5, 0.0);
    glVertex2f(0.75, 0.25);

    glVertex2f(0.5, 0.5);
    glVertex2f(0.75, 0.75);

    glVertex2f(0.0, 0.5);
    glVertex2f(0.25, 0.75);
    glEnd();

    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0); // Adjusted the orthographic projection to fit the cube in the viewport
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // window size
    glutInitWindowPosition(100, 100); // distance from the top-left screen
    glutCreateWindow("Cube"); // message displayed on top bar window
    glutDisplayFunc(displayMe);
    myinit();
    glutMainLoop();
    return 0;
}
