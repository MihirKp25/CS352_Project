#include <GL/glut.h>
#include "car.h"
#include "road.h"
#include <stdio.h>
#include "imageio.h"
#include <string.h>
#include <math.h>

using namespace std;

int lastX = 0, lastY = 0;
int rotationX = 0, rotationY = 0;
unsigned char *image;
int width, height, bpp;

int texImageWidth;
int texImageHeight;

GLubyte *makeTexImage(char *file)
{
  int width, height;
  GLubyte *texImage;
  texImage = loadImageRGBA((char *)file, &width, &height);
  texImageWidth = width;
  texImageHeight = height;
  return texImage;
}

void CAR::SetM(float a, float b, float c)
{
  M[0] = a;
  M[1] = b;
  M[2] = c;
}

void CAR::SetG(float a, float b, float c)
{
  G[0] = a;
  G[1] = b;
  G[2] = c;
  G[3] = 0.5;
}

void CAR::SetB(float a, float b, float c)
{
  B[0] = a;
  B[1] = b;
  B[2] = c;
}

void CAR::SetL(float a, float b, float c)
{
  L[0] = a;
  L[1] = b;
  L[2] = c;
}

//-----------------------models------------------------

void CAR::Model1()
{
  SetM(1, 0, 0);
  SetG(0.184, 0.310, 0.310);
  SetB(0.698, 0.133, 0.133);
  SetL(1, 1, 0);
}

void CAR::Model2()
{
  SetM(0, 0, 0);
  SetG(0.184, 0.310, 0.310);
  SetB(0, 0, 0);
}

void CAR::Model3()
{
  SetM(0.753, 0.753, 0.753);
  SetG(0.690, 0.769, 0.871);
  SetB(0.663, 0.663, 0.663);
  SetL(0.878, 1, 1);
}

void CAR::Model4()
{
  SetM(0.098, 0.098, 0.439);
  SetG(0.184, 0.310, 0.310);
  SetB(0.098, 0.098, 0.439);
  SetL(0.69, 0.769, 0.871);
}

void CAR::Lights()
{

  // glColor3f(1, 0, 1); // Set color to white
  // glBegin(GL_POLYGON); // Begin drawing a polygon
  // glVertex3f(-1, -1, 0); // Bottom-left vertex
  // glVertex3f(1, -1, 0); // Bottom-right vertex
  // glVertex3f(1, 1, 0); // Top-right vertex
  // glVertex3f(-1, 1, 0); // Top-left vertex
  // glEnd(); // End drawing the polygon
  // LEFT

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-13.5, 1, 5);

  glBegin(GL_POLYGON); // LEFT
  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-10, 0, 7);
  glEnd();

  glPopMatrix();

  //--------------

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-13.5, 1, -5);

  glBegin(GL_POLYGON); // RIGHT
  glVertex3f(-14, 0, -4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-10, 2, -7);
  glVertex3f(-10, 0, -7);
  glEnd();

  glPopMatrix();

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-12, 3, 5);

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-7, 4, 5);
  glEnd();

  glPopMatrix();

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-12, 3, -5);

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-14, 2, -4);
  glVertex3f(-10, 2, -7);
  glVertex3f(-7, 4, -5);
  glEnd();

  glPopMatrix();

  //-------------------------------BACKLIGHT------------------------------------------

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(12.5, 1, 0);

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(12, 0, 3);
  glVertex3f(12, 3, 3);
  glVertex3f(12, 3, -3);
  glVertex3f(12, 0, -3);
  glEnd();

  glPopMatrix();

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(11, 1, 5);

  glBegin(GL_POLYGON); // TOP
  glVertex3f(12, 0, 3);
  glVertex3f(12, 3, 3);
  glVertex3f(8, 3, 7);
  glVertex3f(8, 0, 7);
  glEnd();

  glPopMatrix();

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(11, 1, -5);

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(12, 0, -3);
  glVertex3f(12, 3, -3);
  glVertex3f(8, 3, -7);
  glVertex3f(8, 0, -7);
  glEnd();

  glPopMatrix();
}

void CAR::WireFrame()
{
  glColor3f(0, 0, 0);

  glBegin(GL_LINE_LOOP); // CENTRE
  glVertex3f(-10, 0, 6);
  glVertex3f(-10, 0, -6);
  glVertex3f(8, 0, -6);
  glVertex3f(8, 0, 6);
  glEnd();

  glBegin(GL_LINE_LOOP); // FRONT BASE
  glVertex3f(-10, 0, 7);
  glVertex3f(-10, 0, -7);
  glVertex3f(-14, 0, -4);
  glVertex3f(-14, 0, 4);
  glEnd();

  glBegin(GL_LINE_LOOP); // REAR BASE
  glVertex3f(8, 0, 7);
  glVertex3f(8, 0, -7);
  glVertex3f(12, 0, -3);
  glVertex3f(12, 0, 3);
  glEnd();

  //-------------------------- FRONT BUMPER--------------

  glBegin(GL_LINE_LOOP); // CENTRE
  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-14, 0, -4);
  glEnd();

  glBegin(GL_LINE_LOOP); // TOP
  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-10, 0, 7);
  glEnd();

  glBegin(GL_LINE_LOOP); // DOWN
  glVertex3f(-14, 0, -4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-10, 2, -7);
  glVertex3f(-10, 0, -7);
  glEnd();

  //----------------------BACK BUMPPER-----------

  glBegin(GL_LINE_LOOP); // CENTRE
  glVertex3f(12, 0, 3);
  glVertex3f(12, 3, 3);
  glVertex3f(12, 3, -3);
  glVertex3f(12, 0, -3);
  glEnd();

  glBegin(GL_LINE_LOOP); // TOP
  glVertex3f(12, 0, 3);
  glVertex3f(12, 3, 3);
  glVertex3f(8, 3, 7);
  glVertex3f(8, 0, 7);
  glEnd();

  glBegin(GL_LINE_LOOP); // DOWN
  glVertex3f(12, 0, -3);
  glVertex3f(12, 3, -3);
  glVertex3f(8, 3, -7);
  glVertex3f(8, 0, -7);
  glEnd();
  //----------------------Back fender-----------

  glBegin(GL_LINE_LOOP);
  glVertex3f(12, 3, 3);
  glVertex3f(12, 5, 3);
  glVertex3f(12, 5, -3);
  glVertex3f(12, 3, -3);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3f(11, 3, 3);
  glVertex3f(11, 4.5, 3);
  glVertex3f(11, 4.5, -3);
  glVertex3f(11, 3, -3);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3f(11, 4.5, 5);
  glVertex3f(12, 5, 5);
  glVertex3f(11, 4.5, -5);
  glVertex3f(12, 5, -5);
  glEnd();
  //----------------------BONET-----------

  glBegin(GL_LINE_LOOP); // CENTRE
  glVertex3f(-14, 2, 4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-7, 4, -5);
  glVertex3f(-7, 4, 5);
  glEnd();

  glBegin(GL_LINE_LOOP); // TOP
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-7, 4, 5);
  glEnd();

  glBegin(GL_LINE_LOOP); // DOWN
  glVertex3f(-14, 2, -4);
  glVertex3f(-10, 2, -7);
  glVertex3f(-7, 4, -5);
  glEnd();

  //-------------------------WINDSCREEN-------------

  glBegin(GL_LINE_LOOP);
  glVertex3f(-3, 5, 2);
  glVertex3f(-3, 5, -2);
  glVertex3f(-7, 4, -5); // CENTRE
  glVertex3f(-7, 4, 5);

  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3f(-3, 5, 2);
  glVertex3f(0, 6, 3);
  glVertex3f(-7, 4, 5); // C U

  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3f(-3, 5, -2);
  glVertex3f(0, 6, -3);
  glVertex3f(-7, 4, -5); // C D

  glEnd();

  glBegin(GL_LINE_LOOP); // TOP
  glVertex3f(-7, 4, 5);
  glVertex3f(0, 6, 3);
  glVertex3f(12, 3, 3);
  glEnd();

  glBegin(GL_LINE_LOOP); // DOWN
  glVertex3f(-7, 4, -5);
  glVertex3f(0, 6, -3);
  glVertex3f(12, 3, -3);
  glEnd();

  //-----------------------ROOF-------------------

  glBegin(GL_LINE_LOOP); // CENTRE
  glVertex3f(-3, 5, 2);
  glVertex3f(12, 3, 3);
  glVertex3f(12, 3, -3);
  glVertex3f(-3, 5, -2);
  glEnd();

  glBegin(GL_LINE_LOOP); // TOP
  glVertex3f(-3, 5, 2);
  glVertex3f(12, 3, 3);
  glVertex3f(0, 6, 3);
  glEnd();

  glBegin(GL_LINE_LOOP); // DOWN
  glVertex3f(-3, 5, -2);
  glVertex3f(12, 3, -3);
  glVertex3f(0, 6, -3);
  glEnd();

  //-----------------------SIDE BODY-------------------

  glBegin(GL_LINE_LOOP); // TOP
  glVertex3f(-10, 2, 7);
  glVertex3f(-7, 4, 5);
  glVertex3f(12, 3, 3);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3f(8, 3, 7);
  glVertex3f(12, 3, 3);
  glVertex3f(-7, 4, 5);
  glEnd();

  //-------------

  glBegin(GL_LINE_LOOP);
  glVertex3f(-10, 2, -7);
  glVertex3f(-7, 4, -5);
  glVertex3f(12, 3, -3);
  glEnd();

  glBegin(GL_LINE_LOOP); // DOWN
  glVertex3f(8, 3, -7);
  glVertex3f(12, 3, -3);
  glVertex3f(-7, 4, -5);
  glEnd();

  //-----------------------SIDE BUMPPER------------------

  glBegin(GL_LINE_LOOP); // TOP
  glVertex3f(-10, 0, 6);
  glVertex3f(-7, 4, 5);
  glVertex3f(8, 3, 6);
  glVertex3f(8, 0, 6);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3f(-10, 0, -6);
  glVertex3f(-7, 4, -5);
  glVertex3f(8, 3, -6);
  glVertex3f(8, 0, -6);
  glEnd();
}

void drawText(float x, float y, const char *text) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text);
        ++text;
    }
}

void drawStrokeCharacter(float x, float y, float z, char *string) {
    char *c;
    glPushMatrix();
    glScalef(0.02, 0.02, 1); // Adjust scale for 50px text size
    glLineWidth(10.0); // Set line width for extra bold effect
    glTranslatef(x, y, z / 1000);
    for (c = string; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}

void drawStrokeCharacter1(float x, float y, float z, char *string) {
    char *c;
    glPushMatrix();
    glScalef(0.01, 0.01, 1); // Adjust scale for 50px text size
    glLineWidth(10.0); // Set line width for extra bold effect
    glTranslatef(x, y, z / 1000);
    for (c = string; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();
}

void showScore()
{
    glDisable(GL_LIGHTING);
    char *tempString = new char[40];
    snprintf(tempString, 40, "CS352 Project");
    glColor3d(1, 1, 1);
    drawStrokeCharacter(-200, 1000, -20000, tempString);

    snprintf(tempString, 40, "Mihir Jayant Samip");
    glColor3d(1, 1, 1);
    drawStrokeCharacter1(-200, 1800, -20000, tempString);
    delete tempString;
    glEnable(GL_LIGHTING);
}
void CAR::Paint()
{

  // glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

  glColor3f(0, 0, 0);

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(-10, 0, 6);
  glVertex3f(-10, 0, -6);
  glVertex3f(8, 0, -6);
  glVertex3f(8, 0, 6);
  glEnd();

  glBegin(GL_POLYGON); // FRONT BASE
  glVertex3f(-10, 0, 7);
  glVertex3f(-10, 0, -7);
  glVertex3f(-14, 0, -4);
  glVertex3f(-14, 0, 4);
  glEnd();

  glBegin(GL_POLYGON); // REAR BASE
  glVertex3f(8, 0, 7);
  glVertex3f(8, 0, -7);
  glVertex3f(12, 0, -3);
  glVertex3f(12, 0, 3);
  glEnd();

  //-------------------------- FRONT BUMPER--------------

  glColor3fv(B);

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-14, 0, -4);
  glEnd();

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-10, 0, 7);
  glEnd();

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-14, 0, -4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-10, 2, -7);
  glVertex3f(-10, 0, -7);
  glEnd();

  //----------------------BACK BUMPPER-----------
  glColor3f(1.0, 0.0, 1.0);

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(12, 0, 3);
  glVertex3f(12, 3, 3);
  glVertex3f(12, 3, -3);
  glVertex3f(12, 0, -3);
  glEnd();

  glBegin(GL_POLYGON); // TOP
  glVertex3f(12, 0, 3);
  glVertex3f(12, 3, 3);
  glVertex3f(8, 3, 7);
  glVertex3f(8, 0, 7);
  glEnd();

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(12, 0, -3);
  glVertex3f(12, 3, -3);
  glVertex3f(8, 3, -7);
  glVertex3f(8, 0, -7);
  glEnd();

  //----------------------back fender-----------

  glBegin(GL_POLYGON);
  glVertex3f(12, 3, 3);
  glVertex3f(12, 5, 3);
  glVertex3f(11, 4.5, 3);
  glVertex3f(11, 3, 3);

  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(12, 3, -3);
  glVertex3f(12, 5, -3);
  glVertex3f(11, 4.5, -3);
  glVertex3f(11, 3, -3);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(11, 4.5, 5);
  glVertex3f(12, 5, 5);
  glVertex3f(12, 5, -5);
  glVertex3f(11, 4.5, -5);
  glEnd();

  //----------------------BONET-----------

  glColor3fv(M);

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(-14, 2, 4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-7, 4, -5);
  glVertex3f(-7, 4, 5);
  glEnd();

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-7, 4, 5);
  glEnd();

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-14, 2, -4);
  glVertex3f(-10, 2, -7);
  glVertex3f(-7, 4, -5);
  glEnd();

  //-------------------------WINDSCREEN-------------

  glColor4fv(G);

  glBegin(GL_POLYGON);
  glVertex3f(-3, 5, 2);
  glVertex3f(-3, 5, -2);
  glVertex3f(-7, 4, -5); // CENTRE
  glVertex3f(-7, 4, 5);

  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(-3, 5, 2);
  glVertex3f(0, 6, 3);
  glVertex3f(-7, 4, 5); // C U

  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(-3, 5, -2);
  glVertex3f(0, 6, -3);
  glVertex3f(-7, 4, -5); // C D

  glEnd();

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-7, 4, 5);
  glVertex3f(0, 6, 3);
  glVertex3f(12, 3, 3);
  glEnd();

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-7, 4, -5);
  glVertex3f(0, 6, -3);
  glVertex3f(12, 3, -3);
  glEnd();

  //-----------------------ROOF-------------------
  glColor3fv(M);

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(-3, 5, 2);
  glVertex3f(12, 3, 3);
  glVertex3f(12, 3, -3);
  glVertex3f(-3, 5, -2);
  glEnd();

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-3, 5, 2);
  glVertex3f(12, 3, 3);
  glVertex3f(0, 6, 3);
  glEnd();

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-3, 5, -2);
  glVertex3f(12, 3, -3);
  glVertex3f(0, 6, -3);
  glEnd();

  //-----------------------SIDE BODY-------------------
  glColor3fv(M);

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-10, 2, 7);
  glVertex3f(-7, 4, 5);
  glVertex3f(12, 3, 3);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(8, 3, 7);
  glVertex3f(12, 3, 3);
  glVertex3f(-7, 4, 5);
  glEnd();

  //-------------

  glBegin(GL_POLYGON);
  glVertex3f(-10, 2, -7);
  glVertex3f(-7, 4, -5);
  glVertex3f(12, 3, -3);
  glEnd();

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(8, 3, -7);
  glVertex3f(12, 3, -3);
  glVertex3f(-7, 4, -5);
  glEnd();

  //-----------------------SIDE BUMPPER------------------
  glColor3fv(M);

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-10, 0, 6);
  glVertex3f(-7, 4, 5);
  glVertex3f(8, 3, 6);
  glVertex3f(8, 0, 6);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex3f(-10, 0, -6);
  glVertex3f(-7, 4, -5);
  glVertex3f(8, 3, -6);
  glVertex3f(8, 0, -6);
  glEnd();

 //-----------------------------base floor-----------------//
 glPushMatrix();
glColor3d(0.333, 0.345, 0.361);
glTranslatef(0, -2.0, 0.0);

// Define the new length and width
float length = 45.0; // Adjust as needed
float width = 45.0;  // Adjust as needed

// Draw the top face
glBegin(GL_POLYGON);
glVertex3f(length / 2, -1, width / 2);   // c
glVertex3f(-length / 2, -1, width / 2);  // br
glVertex3f(-length / 2, -1, -width / 2); // a
glVertex3f(length / 2, -1, -width / 2);  // d
glEnd();

// Draw the bottom face
glBegin(GL_POLYGON);
glVertex3f(length / 2, -2, width / 2);   // c'
glVertex3f(-length / 2, -2, width / 2);  // br'
glVertex3f(-length / 2, -2, -width / 2); // a'
glVertex3f(length / 2, -2, -width / 2);  // d'
glEnd();

// Draw the front face
glBegin(GL_POLYGON);
glVertex3f(length / 2, -1, width / 2);  // c
glVertex3f(length / 2, -2, width / 2);  // c'
glVertex3f(length / 2, -2, -width / 2); // d'
glVertex3f(length / 2, -1, -width / 2); // d
glEnd();

// Draw the back face
glBegin(GL_POLYGON);
glVertex3f(-length / 2, -1, width / 2);  // br
glVertex3f(-length / 2, -2, width / 2);  // br'
glVertex3f(-length / 2, -2, -width / 2); // a'
glVertex3f(-length / 2, -1, -width / 2); // a
glEnd();

// Draw the left face
glBegin(GL_POLYGON);
glVertex3f(-length / 2, -1, width / 2); // br
glVertex3f(-length / 2, -2, width / 2); // br'
glVertex3f(length / 2, -2, width / 2);  // c'
glVertex3f(length / 2, -1, width / 2);  // c
glEnd();

// Draw the right face
glBegin(GL_POLYGON);
glVertex3f(-length / 2, -1, -width / 2); // a
glVertex3f(-length / 2, -2, -width / 2); // a'
glVertex3f(length / 2, -2, -width / 2);  // d'
glVertex3f(length / 2, -1, -width / 2);  // d
glEnd();

glPopMatrix();


//-----------------------------base floor-----------------//

glPushMatrix();
glColor3d(0.333, 0.345, 0.361);

// Define the radius of the circular base
float radius = 17.0; // Adjust as needed

// Define the number of segments for the circle
int segments = 50; // Adjust as needed

// Define the height of the circular base
float height = 3.0; // Adjust as needed

// Draw the top face
glBegin(GL_POLYGON);
for (int i = 0; i < segments; ++i) {
    float theta = 2.0 * M_PI * i / segments;
    glVertex3f(radius * cos(theta), -1, radius * sin(theta));
}
glEnd();

// Draw the bottom face
glBegin(GL_POLYGON);
for (int i = 0; i < segments; ++i) {
    float theta = 2.0 * M_PI * i / segments;
    glVertex3f(radius * cos(theta), -1 - height, radius * sin(theta));
}
glEnd();

// Draw the side faces
glColor3f(0.6, 1, 1); // Set color to green

for (int i = 0; i < segments; ++i) {
    float theta1 = 2.0 * M_PI * i / segments;
    float theta2 = 2.0 * M_PI * (i + 1) / segments;
    
    // Draw each side face
    glBegin(GL_POLYGON);
    glVertex3f(radius * cos(theta1), -1, radius * sin(theta1));
    glVertex3f(radius * cos(theta1), -1 - height, radius * sin(theta1));
    glVertex3f(radius * cos(theta2), -1 - height, radius * sin(theta2));
    glVertex3f(radius * cos(theta2), -1, radius * sin(theta2));
    glEnd();
}
glPopMatrix();


showScore();
  // //--------------------SIGNBOARD--------------------

  // glPushMatrix(); // Save the current matrix
  // glTranslatef(15, 10.0, 0.0);
  // glRotatef(90, 0.0, 1.0, 0.0); // Rotate around the y-axis by 'angle' degrees

  // glColor3f(1.0, 1.0, 1.0); // Set color to white for the signboard

  // // Define the height of the signboard
  // float signboardHeight = 15.0; // Adjust as needed

  // // Draw the front face of the signboard with increased height
  // glBegin(GL_POLYGON);
  // glVertex3f(-15, 8, 4);               // Top left
  // glVertex3f(-15, signboardHeight, 4); // Top right
  // glVertex3f(15, signboardHeight, 4);  // Bottom right
  // glVertex3f(15, 8, 4);                // Bottom left
  // glEnd();

  // // Draw the rest of the signboard with the adjusted height
  // // Draw the back face of the signboard
  // glBegin(GL_POLYGON);
  // glVertex3f(-15, 8, 3.8);               // Top left
  // glVertex3f(-15, signboardHeight, 3.8); // Top right
  // glVertex3f(15, signboardHeight, 3.8);  // Bottom right
  // glVertex3f(15, 8, 3.8);                // Bottom left
  // glEnd();

  // // Draw the left side of the signboard
  // glBegin(GL_POLYGON);
  // glVertex3f(-15, 8, 4);                 // Top
  // glVertex3f(-15, signboardHeight, 4);   // Bottom
  // glVertex3f(-15, signboardHeight, 3.8); // Bottom
  // glVertex3f(-15, 8, 3.8);               // Top
  // glEnd();

  // // Draw the right side of the signboard
  // glBegin(GL_POLYGON);
  // glVertex3f(15, 8, 4);                 // Top
  // glVertex3f(15, signboardHeight, 4);   // Bottom
  // glVertex3f(15, signboardHeight, 3.8); // Bottom
  // glVertex3f(15, 8, 3.8);               // Top
  // glEnd();

  // // Draw the top face of the signboard
  // glBegin(GL_POLYGON);
  // glVertex3f(-15, signboardHeight, 4);   // Top left
  // glVertex3f(15, signboardHeight, 4);    // Top right
  // glVertex3f(15, signboardHeight, 3.8);  // Bottom right
  // glVertex3f(-15, signboardHeight, 3.8); // Bottom left
  // glEnd();

  // // Draw the bottom face of the signboard
  // glBegin(GL_POLYGON);
  // glVertex3f(-15, 8, 4);   // Top left
  // glVertex3f(15, 8, 4);    // Top right
  // glVertex3f(15, 8, 3.8);  // Bottom right
  // glVertex3f(-15, 8, 3.8); // Bottom left
  // glEnd();

  // glPopMatrix(); // Restore the previous matrix

  // glPushMatrix();
  // glTranslatef(20, 12, -7);
  // glRotatef(90, 1.0, 0.0, .0); // Rotate around the y-axis by 'angle' degrees
  // // Draw the cylindrical support
  // GLUquadricObj *cylinder = gluNewQuadric();    // Create a new quadric object for the cylinder
  // gluQuadricDrawStyle(cylinder, GLU_FILL);      // Set the drawing style to fill
  // gluQuadricNormals(cylinder, GLU_SMOOTH);      // Enable smooth normals for shading
  // glColor3f(0.5, 0.5, 0.5);                     // Set color to gray for the cylinder
  // glTranslatef(0.0, signboardHeight / 2, -7.0); // Translate to the midpoint of the signboard height
  // gluCylinder(cylinder, 1.0, 1.0, 20, 20, 20);  // Draw the cylinder as the support

  // glPopMatrix(); // Restore the previous matrix
}

//-----------------------------base floor-----------------//
void CAR::Tyre()
{

  GLUquadricObj *p = gluNewQuadric();

  glColor3f(0.04, 0.04, 0.04);
  gluCylinder(p, 10, 10, 5, 100, 100);

  glColor3f(0.02, 0.02, 0.02);
  gluDisk(p, 7, 10, 100, 100);

  glTranslatef(0, 0, -0.2);

  glColor3f(0.439, 0.502, 0.565);
  gluDisk(p, 0, 3, 100, 100);

  // WHEEL SPOILERS
  glColor3f(0.439, 0.502, 0.565);
  gluPartialDisk(p, 0, 7, 100, 100, 0, 40);
  gluPartialDisk(p, 0, 7, 100, 100, 72, 40);
  gluPartialDisk(p, 0, 7, 100, 100, 144, 40);
  gluPartialDisk(p, 0, 7, 100, 100, 216, 40);
  gluPartialDisk(p, 0, 7, 100, 100, 288, 40);

  glTranslatef(0, 0, -0.2); // TUBE PATTERN
  glColor3f(0.439, 0.502, 0.565);
  gluPartialDisk(p, 8, 9, 100, 100, 0, 60);
  gluPartialDisk(p, 8, 9, 100, 100, 120, 60);
  gluPartialDisk(p, 8, 9, 100, 100, 240, 60);
}

void CAR::Wheels(float Aw)
{
  glPushMatrix();
  glTranslatef(-7.5, 1, -7);
  glScalef(0.2, 0.2, 0.2);
  glRotatef(Aw, 0, 0, 1);
  Tyre();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5.5, 1, -7.5);
  glScalef(0.2, 0.2, 0.2);
  glRotatef(Aw, 0, 0, 1);
  Tyre();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-7.5, 1, 7);
  glScalef(0.2, 0.2, 0.2);
  glRotatef(180, 0, 1, 0);
  glRotatef(-Aw, 0, 0, 1);
  Tyre();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5.5, 1, 7.5);
  glScalef(0.2, 0.2, 0.2);
  glRotatef(180, 0, 1, 0);
  glRotatef(-Aw, 0, 0, 1);
  Tyre();
  glPopMatrix();
}


void CAR::SelectModel(int i)
{
  if (i == 1)
    this->Model1();
  if (i == 2)
    this->Model2();
  if (i == 3)
    this->Model3();
  if (i == 4)
    this->Model4();
}

void drawCar(void)
{

  glClearColor(0, 0, 0, 1.0); // Set background color to white

  CAR car;
  car.SelectModel(1);
  car.Lights();
  // car.WireFrame();
  car.Paint();
  car.Wheels(0);
  // RoadSlab();
  // FloorMaker();

  glEnd(); // End drawing the polygon
  glFlush();
  glutSwapBuffers();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glLoadIdentity();

  // glTranslatef(10.0, 10.0, -10.0); // Move the cube back along z-axis
  glTranslatef(0, 2, -90);
  // glRotatef(90, 0, 1, 0);
  glRotatef(rotationX, 1.0, 0.0, 0.0); // Rotate around x-axis
  glRotatef(rotationY, 0.0, 1.0, 0.0); // Rotate around y-axis

  GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; // Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

  // Add positioned light
  GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; // Color (0.5, 0.5, 0.5)
  GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};   // Positioned at (4, 0, 8)
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
  glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

  // Add directed light
  GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; // Color (0.5, 0.2, 0.2)
  // Coming from the direction (-1, 0.5, 0.5)
  //  0 because direced light source
  GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
  glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
  glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

  // drawCube();
  drawCar();

  glFlush();
}

void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    lastX = x;
    lastY = y;
  }
}

void motion(int x, int y)
{
  rotationX += (y - lastY);
  rotationY += (x - lastX);

  lastX = x;
  lastY = y;

  glutPostRedisplay();
}

void reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, 1, 1.0, 10000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(300, -1000, -1940, 0, -200, 5000, 1, 0, 0);
}
// Initializes 3D rendering
void initRendering()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_LIGHTING); // Enable lighting
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_COLOR_MATERIAL);

  // you can have upto 8 lighting
  glEnable(GL_LIGHT0);     // Enable light #0
  glEnable(GL_LIGHT1);     // Enable light #1
  glEnable(GL_NORMALIZE);  // Automatically normalize normals
  glShadeModel(GL_SMOOTH); // Enable smooth shading
}
void load_texture()
{
  // image = stbi_load("texture.jpg", &width, &height, &bpp, 3);
  unsigned int texture;
  glGenTextures(1, &texture);
  GLubyte *texImage = makeTexImage((char *)"color.png");
  if (!texImage)
  {
    printf("\nError reading image \n");
    return;
  }
  glBindTexture(GL_TEXTURE_2D, texture);
  // set the texture wrapping/filtering options (on the currently bound texture object)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texImageWidth, texImageWidth, 0, GL_RGBA, GL_UNSIGNED_BYTE, texImage);
  delete texImage;
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("3D CAR");
  load_texture();
  initRendering();
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutMainLoop();
  return 0;
}
