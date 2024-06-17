#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to draw an ellipse
void drawEllipse(float x, float y, float radiusX, float radiusY, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * PI * float(i) / float(segments);
        float xPos = x + radiusX * cosf(theta);
        float yPos = y + radiusY * sinf(theta);
        glVertex2f(xPos, yPos);
    }
    glEnd();
}

// Function to draw a fish
void drawFish() {
    // Body
    glColor3f(1.0f, 0.5f, 0.5f); // Pink
    drawEllipse(0.0f, 0.0f, 1.0f, 0.5f, 100);

    // Tail
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(-2.0f, -0.5f);
    glEnd();

    // Eye
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    drawEllipse(0.6f, 0.2f, 0.1f, 0.1f, 100);

    // Mouth
    glBegin(GL_LINES);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.2f, 0.0f);
    glEnd();
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-2.5, 2.5, -1.5, 1.5);

    drawFish(); // Draw the fish

    glFlush();
}

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 1.0, 1.0);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Fish");

    init(); // Initialize OpenGL settings

    glutDisplayFunc(display); // Set the display callback function

    glutMainLoop(); // Enter the GLUT event processing loop

    return 0;
}
