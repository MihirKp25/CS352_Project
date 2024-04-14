#include <GL/glut.h>

GLfloat light_position[] = { 0.0, 0.0, 1.0, 0.0 }; // Position of the light
GLfloat light_direction[] = { 0.0, 0.0, -1.0 };    // Direction of the light
GLfloat yellow_color[] = { 1.0, 1.0, 0.0, 1.0 };   // Yellow color

void init(void) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);

    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Draw the surface
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glBegin(GL_QUADS);
        glVertex3f(-5.0, -5.0, 0.0);
        glVertex3f(5.0, -5.0, 0.0);
        glVertex3f(5.0, 5.0, 0.0);
        glVertex3f(-5.0, 5.0, 0.0);
    glEnd();

    // Draw the headlight as a sphere
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glColor4fv(yellow_color);
    glPushMatrix();
    glTranslatef(light_position[0], light_position[1], light_position[2]);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // Eye position
              0.0, 0.0, 0.0,  // Look-at position
              0.0, 1.0, 0.0); // Up direction
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Car Headlight and Surface");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
