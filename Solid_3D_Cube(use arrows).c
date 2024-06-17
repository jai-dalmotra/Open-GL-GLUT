#include <GL/glut.h>
#include <cstdlib> // for exit()

// Define global variables for rotation
GLfloat rotate_x = 0.0f;
GLfloat rotate_y = 0.0f;

// Function to initialize OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set the background color to black
    glClearDepth(1.0); // Set the depth buffer
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glDepthFunc(GL_LEQUAL); // Type of depth test
    glShadeModel(GL_SMOOTH); // Enable smooth shading
}

// Function to handle window resizing
void reshape(int w, int h) {
    glViewport(0, 0, w, h); // Set the viewport to the current window size
    glMatrixMode(GL_PROJECTION); // Switch to the projection matrix
    glLoadIdentity(); // Reset the projection matrix
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f); // Set the perspective
    glMatrixMode(GL_MODELVIEW); // Switch back to the modelview matrix
    glLoadIdentity(); // Reset the modelview matrix
}

// Function to draw the 3D object
// Function to draw the 3D object
void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glLoadIdentity(); // Reset the current modelview matrix

    glTranslatef(0.0f, 0.0f, -5.0f); // Move object away from camera
    glRotatef(rotate_x, 1.0f, 0.0f, 0.0f); // Rotate around the x-axis
    glRotatef(rotate_y, 0.0f, 1.0f, 0.0f); // Rotate around the y-axis

    // Draw your 3D object here (a colored cube)
    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    // Back face
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    // Top face
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    // Bottom face
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    // Right face
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    // Left face
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();

    glutSwapBuffers(); // Swap the front and back buffers
}

// Function to handle keyboard input
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'q': // Quit the program when 'q' is pressed
        exit(0);
        break;
    }
}

// Function to handle special key input
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        rotate_x += 5;
        break;
    case GLUT_KEY_DOWN:
        rotate_x -= 5;
        break;
    case GLUT_KEY_LEFT:
        rotate_y += 5;
        break;
    case GLUT_KEY_RIGHT:
        rotate_y -= 5;
        break;
    }

    glutPostRedisplay(); // Mark the current window as needing to be redisplayed
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode
    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("Simple 3D Object"); // Create the window with the specified title

    glutDisplayFunc(draw); // Register the display function
    glutReshapeFunc(reshape); // Register the reshape function
    glutKeyboardFunc(keyboard); // Register the keyboard function
    glutSpecialFunc(specialKeys); // Register the special keys function

    init(); // Initialize OpenGL

    glutMainLoop(); // Enter the GLUT event loop

    return 0;
}
