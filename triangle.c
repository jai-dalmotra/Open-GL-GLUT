#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);  // Red color
    glVertex2f(-0.5, -0.5); // Bottom left vertex
    glColor3f(0.0, 1.0, 0.0);  // Green color
    glVertex2f(0.5, -0.5);  // Bottom right vertex
    glColor3f(0.0, 0.0, 1.0);  // Blue color
    glVertex2f(0.0, 0.5);  // Top vertex
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Set window size
    glutCreateWindow("2D Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
