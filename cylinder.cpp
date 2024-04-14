#include <GL/glut.h>
#include <math.h>

void drawCylinder(float radius, float halfLength, int slices) {
//     float radius, halfLength;
// int slices;
for(int i=0; i<slices; i++) {
float theta = ((float)i)*2.0*M_PI;
float nextTheta = ((float)i+1)*2.0*M_PI;
glBegin(GL_TRIANGLE_STRIP);
/*vertex at middle of end */ glVertex3f(0.0, halfLength, 0.0);
/*vertices at edges of circle*/ glVertex3f(radius*cos(theta), halfLength, radius*sin(theta));
                                          glVertex3f (radius*cos(nextTheta), halfLength, radius*sin(nextTheta));
/* the same vertices at the bottom of the cylinder*/
 glVertex3f (radius*cos(nextTheta), -halfLength, radius*sin(nextTheta));
glVertex3f(radius*cos(theta), -halfLength, radius*sin(theta));
glVertex3f(0.0, -halfLength, 0.0);
glEnd();
}
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f); // White color

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 0, 1); // Set the camera position and orientation

    glTranslatef(0, 0, 0); // Translate to the cylinder position
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    drawCylinder(1, 3, 20); // Draw a cylinder with radius 1, height 3, and 20 segments

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Cylinder");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
