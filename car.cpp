#include <GL/glut.h>
#include "car.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

//Declaration of global variables

int lastX = 0, lastY = 0;
int rotationX = 0, rotationY = 0;
int menuWidth = 200; 
bool headLightSwitch = false;
int xview = 0, yview = 0, zview = -80;

//-------------------------Lights positions and color----------------------------------------------------------------------------

void CAR::Lights()
{

  float bgcolor[4] = {1, 1, 1, 0.2};
  float bgcolor2[4] = {0, 0, 0, 0};
  float zero[] = {0, 0, 0, 1};

  //LEFT LIGHT
  glPushMatrix();
  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-13.5, 1, 5);
  glBegin(GL_POLYGON); 

  // Making it glow
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
  GLfloat lightColor0[] = {1, 1, 0, 1.0f}; 
  GLfloat lightPos0[] = {-14, 2, 5};      
  glLightfv(GL_LIGHT2, GL_SPECULAR, lightColor0);
  glLightfv(GL_LIGHT2, GL_POSITION, lightPos0);

  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-10, 0, 7);

  //removing glow
  glMaterialfv(GL_FRONT, GL_EMISSION, zero);
  glEnd();

  // Showing effect of headlight

  if (headLightSwitch == true)
  {
    // Headlights lights

    // front face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glVertex3f(-40, 5, 1);
    glVertex3f(-40, -3, 1);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-14, 0, 4);
    glVertex3f(-14, 2, 4);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

    // back face
    glBegin(GL_POLYGON); // RIGHT
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glVertex3f(-40, 5, 10);
    glVertex3f(-40, -3, 10);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-10, 0, 7);
    glVertex3f(-10, 2, 7);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

    // top face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-10, 2, 7);
    glVertex3f(-14, 2, 4);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glVertex3f(-40, 5, 1);
    glVertex3f(-40, 5, 10);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!
    
    // bottom face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-40, -3, 10);
    glVertex3f(-40, -3, 1);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-14, 0, 4);
    glVertex3f(-10, 0, 7);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!
  }

  glPopMatrix();

  // Right Light
  glPushMatrix();
  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-13.5, 1, -5);
  glBegin(GL_POLYGON); 

  //Making it glow
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
  GLfloat lightColor1[] = {1, 1, 0, 1.0f}; // Color (0.5, 0.5, 0.5)
  GLfloat lightPos1[] = {-14, 2, -5};      // Positioned at (4, 0, 8)
  glLightfv(GL_LIGHT3, GL_SPECULAR, lightColor1);
  glLightfv(GL_LIGHT3, GL_POSITION, lightPos1);
  glVertex3f(-14, 0, -4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-10, 2, -7);
  glVertex3f(-10, 0, -7);
  glEnd();
  glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

  //Effect of headlight

  if (headLightSwitch == true)
  {
    // Headlights lights
    // front face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-40, 5, -1);
    glVertex3f(-40, -3, -1);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-14, 0, -4);
    glVertex3f(-14, 2, -4);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

    // back face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-40, 5, -10);
    glVertex3f(-40, -3, -10);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-10, 0, -7);
    glVertex3f(-10, 2, -7);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

    // top face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-10, 2, -7);
    glVertex3f(-14, 2, -4);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glVertex3f(-40, 5, -1);
    glVertex3f(-40, 5, -10);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

    // bottom face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-40, -3, -10);
    glVertex3f(-40, -3, -1);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-14, 0, -4);
    glVertex3f(-10, 0, -7);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

  }
  glPopMatrix();


  // Top Right Light
  glPushMatrix();
  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-12, 3, 5);
  glColor3f(1, 1, 1);
  glBegin(GL_POLYGON); 
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-7, 4, 5);
  glEnd();

  glPopMatrix();

  //Top Left Light

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

  //red color backlights

  float redcolor[4]= {1, 0, 0, 0.2};

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(12.5, 1, 0);

  //making it glow
  glMaterialfv(GL_FRONT, GL_EMISSION, redcolor);

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(12, 0, 3);
  glVertex3f(12, 2, 3);
  glVertex3f(12, 2, -3);
  glVertex3f(12, 0, -3);
  glEnd();

  glPopMatrix();

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(11, 1, 5);

  glBegin(GL_POLYGON); // Left
  glVertex3f(12, 0, 3);
  glVertex3f(12, 2, 3);
  glVertex3f(8, 2, 7);
  glVertex3f(8, 0, 7);
  glEnd();

  glPopMatrix();

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(11, 1, -5);

  glBegin(GL_POLYGON); // Right
  glVertex3f(12, 0, -3);
  glVertex3f(12, 2, -3);
  glVertex3f(8, 2, -7);
  glVertex3f(8, 0, -7);
  glEnd();

  glMaterialfv(GL_FRONT, GL_EMISSION, zero); //removing the glow
  glPopMatrix();
}

//---------------------------------------------------------------Wireframe for Our car----------------------------------------------
// https://github.com/sckorpio/MyCity-CarGame - Acknowledgement for the wireframe code
void CAR::WireFrame()
{
  glColor3f(1, 1, 1);

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

}


// --------------------------draw stroke character---------------------------
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

// ---------------------------Heading showcase-----------------------------

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

 
// --------------------------Painting the car----------------------------------------
// https://github.com/sckorpio/MyCity-CarGame - Acknowledgement for the paint code
void CAR::Paint()
{

  //BASE

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



  glColor3f(0.098, 0.098, 0.439);

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-14, 0, -4);
  glEnd();

  // mettalic part

  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(-14.05, 0.5, 3);
  glVertex3f(-14.05, 1.5, 3);
  glVertex3f(-14.05, 1.5, -3);
  glVertex3f(-14.05, 0.5, -3);
  glEnd();
  glColor3f(1, 1, 1);

  glColor3f(0.286, 0.286, 0.839);
  glBegin(GL_POLYGON); // TOP
  glVertex3f(-14, 0, 4);
  glColor3f(0.051, 0.051, 0.259);
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-10, 0, 7);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-14, 0, -4);
  glVertex3f(-14, 2, -4);

  glVertex3f(-10, 2, -7);
  glColor3f(0.051, 0.051, 0.259);
  glVertex3f(-10, 0, -7);
  glEnd();

  //----------------------BACK BUMPPER-----------
  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(12, 0, 3);
  glVertex3f(12, 3, 3);
glColor4f(0.071, 0.071, 0.212, 1.0);
  glVertex3f(12, 3, -3);
  glVertex3f(12, 0, -3);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // TOP
  glVertex3f(12, 0, 3);
  glVertex3f(12, 3, 3);
glColor4f(0.071, 0.071, 0.212, 1.0);
  glVertex3f(8, 3, 7);
  glVertex3f(8, 0, 7);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // DOWN
  glVertex3f(12, 0, -3);
  glVertex3f(12, 3, -3);
glColor4f(0.071, 0.071, 0.212, 1.0);
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

  // glColor3f(0.098, 0.098, 0.439);
  glColor3f(0.141, 0.141, 0.569);
  

  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(-14, 2, 4);
  glVertex3f(-14, 2, -4);
  glColor3f(0.051, 0.051, 0.259);
  glVertex3f(-7, 4, -5);
  glVertex3f(-7, 4, 5);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // TOP
  glVertex3f(-14, 2, 4);
  glColor3f(0.051, 0.051, 0.259);
  glVertex3f(-10, 2, 7);
  glVertex3f(-7, 4, 5);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-14, 2, -4);
  glColor3f(0.051, 0.051, 0.259);
  glVertex3f(-10, 2, -7);
  glVertex3f(-7, 4, -5);
  glEnd();

  //-------------------------WINDSCREEN-------------

  glColor4f(0.184, 0.310, 0.310, 0.2);
//-------------------------WINDSCREEN-------------

  glColor4f(0.184, 0.310, 0.310, 0.2);
  const float mirdiff[] = {1.0, 1.0, 1.0, 0.5};

  // Giving glass look

  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mirdiff);
  glBegin(GL_POLYGON);
  glVertex3f(-3, 5, 2);
  glVertex3f(-3, 5, -2);
  glColor4f(0.141, 0.231, 0.231, 1.0);
  glVertex3f(-7, 4, -5); // CENTRE
  glVertex3f(-7, 4, 5);

  glEnd();

  glColor4f(0.141, 0.231, 0.231, 1.0);
  glBegin(GL_POLYGON);
  glVertex3f(-3, 5, 2);
  glVertex3f(0, 6, 3);
  glColor4f(0.184, 0.310, 0.310, 0.2);
  glVertex3f(-7, 4, 5); // C U

  glEnd();

  glColor4f(0.141, 0.231, 0.231, 1.0);
  glBegin(GL_POLYGON);
  glVertex3f(-3, 5, -2);
  glColor4f(0.184, 0.310, 0.310, 0.2);
  glVertex3f(0, 6, -3);
  glVertex3f(-7, 4, -5); // C D

  glEnd();

  glColor4f(0.141, 0.231, 0.231, 1.0);
  glBegin(GL_POLYGON); // TOP
  glVertex3f(-7, 4, 5);
  glVertex3f(0, 6, 3);
  glColor4f(0.184, 0.310, 0.310, 0.2);
  glVertex3f(12, 3, 3);
  glEnd();

  glColor4f(0.141, 0.231, 0.231, 1.0);
  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-7, 4, -5);
  glVertex3f(0, 6, -3);
  glColor4f(0.184, 0.310, 0.310, 0.2);
  glVertex3f(12, 3, -3);
  glEnd();

  //-----------------------ROOF-------------------


  glColor4f(0.075, 0.075, 0.231, 1.0);
  glBegin(GL_POLYGON); // CENTRE
  glVertex3f(-3, 5, -2);
  glVertex3f(-3, 5, 2);
  glColor3f(0.141, 0.141, 0.569);
  glVertex3f(12, 3, 3);
  glVertex3f(12, 3, -3);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // TOP
  glVertex3f(-3, 5, 2);
  glVertex3f(12, 3, 3);
  glVertex3f(0, 6, 3);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // DOWN
  glVertex3f(-3, 5, -2);
  glVertex3f(12, 3, -3);
  glVertex3f(0, 6, -3);
  glEnd();

  //-----------------------SIDE BODY-------------------

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // TOP
  glVertex3f(-10, 2, 7);
  glVertex3f(-7, 4, 5);
  glVertex3f(12, 3, 3);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  
  glBegin(GL_POLYGON);
  glVertex3f(8, 3, 7);
  glVertex3f(12, 3, 3);
  glColor4f(0.071, 0.071, 0.212, 1.0);
  glVertex3f(-7, 4, 5);
  glEnd();

  //-------------

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON);
  glVertex3f(-10, 2, -7);
  glVertex3f(-7, 4, -5);
  glColor4f(0.071, 0.071, 0.212, 1.0);
  glVertex3f(12, 3, -3);
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON); // DOWN
  glVertex3f(8, 3, -7);
  glVertex3f(12, 3, -3);
  glColor4f(0.071, 0.071, 0.212, 1.0);
  glVertex3f(-7, 4, -5);
  glEnd();

  //-----------------------SIDE BUMPPER------------------
  glColor3f(0.098, 0.098, 0.439);

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-10, 0, 6);
  glVertex3f(-7, 4, 5);

  glVertex3f(8, 3, 6);
    glColor4f(0.075, 0.075, 0.231, 1.0);

  glVertex3f(8, 0, 6);
  glEnd();

  // side handle front
  glColor3f(1, 1, 0);
  glBegin(GL_POLYGON);
  float radius = 0.5;
  for (int i = 0; i <= 180; i++)
  {
    float angle = i * M_PI / 180.0;
    glVertex3f(-1 + radius * cos(angle), 2.5 + radius * sin(angle), 6);
  }
  glEnd();

  // side handle back
  glColor3f(1, 1, 0);
  glBegin(GL_POLYGON);
  radius = 0.5;
  for (int i = 0; i <= 180; i++)
  {
    float angle = i * M_PI / 180.0;
    glVertex3f(-1 + radius * cos(angle), 2.5 + radius * sin(angle), -6);
  }
  glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON);
  glVertex3f(-10, 0, -6);
  glVertex3f(-7, 4, -5);
    glColor4f(0.075, 0.075, 0.231, 1.0);
  glVertex3f(8, 3, -6);
  glVertex3f(8, 0, -6);
  glEnd();

  //-----------------------------base floor-----------------//
 glPushMatrix();

 //base color
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
  glColor3d(0.333, 0.345, 0.361); // Set color to green

  // Define the radius of the circular base
  radius = 17.0; // Adjust as needed

  // Define the number of segments for the circle
  int segments = 50; // Adjust as needed

  // Define the height of the circular base
  float height = 3.0; // Adjust as needed

  // Draw the top face
  glBegin(GL_POLYGON);
  for (int i = 0; i < segments; ++i)
  {
    float theta = 2.0 * M_PI * i / segments;
    glVertex3f(radius * cos(theta), -1, radius * sin(theta));
  }
  glEnd();

  // Draw the bottom face
  glBegin(GL_POLYGON);
  for (int i = 0; i < segments; ++i)
  {
    float theta = 2.0 * M_PI * i / segments;
    glVertex3f(radius * cos(theta), -1 - height, radius * sin(theta));
  }
  glEnd();

  // Draw the side faceshead
  glColor3f(0.6, 1, 1); // Set color to green

  for (int i = 0; i < segments; ++i)
  {
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
  }



// --------------------------------------Function to draw cylindes for tyre exhaust and audi symbol-----------------

void CAR::Cylinder()
{
  GLUquadricObj *p = gluNewQuadric();

  gluCylinder(p, 10, 10, 1, 100, 100);
  gluDisk(p, 0, 5, 100, 100);
}

void CAR::ExhaustCylinder()
{
  GLUquadricObj *q = gluNewQuadric();
  gluCylinder(q, 5, 5, 7, 100, 100);
  gluDisk(q, 0, 5, 100, 100);
  return;
}

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

// ----------------------------------------using those cylinder function------------------------------------------------

void CAR::ExhaustPipes()
{
  glPushMatrix();
  float s = 0.09;
  glTranslatef(12, 1, 3.1);
  glRotatef(90, 0, 1, 0);
  glScalef(s, s, s);
  glColor3f(1, 1, 1);
  ExhaustCylinder();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(12, 1, 3.1);
  glRotatef(90, 0, 1, 0);
  glScalef(s, s, s);
  glColor3f(1, 1, 1);
  glTranslatef(10, 0, 0);
  ExhaustCylinder();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(12, 1, 3.1);
  glRotatef(90, 0, 1, 0);
  glScalef(s, s, s);
  glColor3f(1, 1, 1);
  glTranslatef(60, 0, 0);
  ExhaustCylinder();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(12, 1, 3.1);
  glRotatef(90, 0, 1, 0);
  glScalef(s, s, s);
  glColor3f(1, 1, 1);
  glTranslatef(70, 0, 0);
  ExhaustCylinder();
  glPopMatrix();
}

//Audi car symbol

void CAR::CarSymbol()
{
  glPushMatrix();
  glTranslatef(-14.5, 1, 1);
  glRotatef(90, 0, 1, 0);
  glColor3f(1, 1, 1);
  glScalef(0.05, 0.05, 0.05);
  Cylinder();
  glTranslatef(10, 0, 0);
  Cylinder();
  glTranslatef(10, 0, 0);
  Cylinder();
  glTranslatef(10, 0, 0);
  Cylinder();

  //reseting the transformnations
  glTranslatef(-30, 0, 0);
  glScalef(20, 20, 20);
  glRotatef(-90, 0, 1, 0);
  glTranslatef(14.5, -1, -1);
  glPopMatrix();
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



void drawCar(void)
{

  glClearColor(0, 0, 0, 1.0); // Set background color to white

  //giving material properties to car body

  GLfloat mat_specular[] = {0.7, 0.8, 0.8, 1.0};
  GLfloat mat_shininess[] = {50.0};

  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  glShadeModel(GL_SMOOTH);


  CAR car;
  car.Lights();
  // car.WireFrame(); //Basic skeleton for car
  car.Paint();
  car.Wheels(0);
  car.CarSymbol();
  car.ExhaustPipes();

  glEnd(); // End drawing the polygon
  glFlush();
  return;
}

void menu(int value)
{
  // Handle menu selections
  switch (value)
  {
  case 1:
    if (headLightSwitch == false)
      headLightSwitch = true;
    else
      headLightSwitch = false;

    glutPostRedisplay();
    break;

  default:
    break;
  }
}

void createMenu()
{
  int mainMenu = glutCreateMenu(menu);
  glutAddMenuEntry("Switch headlights", 1);
  glutAttachMenu(GLUT_RIGHT_BUTTON); // Attach the menu to the right mouse button
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glLoadIdentity();

  //initial translation of objects 
  glTranslatef(0, 2, -90);
  glRotatef(rotationX, 1.0, 0.0, 0.0); // Rotate around x-axis
  glRotatef(rotationY, 0.0, 1.0, 0.0); // Rotate around y-axis

  //Ambient color

  GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; // Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

  if (headLightSwitch == false)
  {

    // Add positioned light
    // GLfloat lightColor0[] = {1, 1, 1, 1.0f};        
    // GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};
    // glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    // glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    // Add another positioned  light
    // GLfloat lightColor1[] = {1, 1, 1 , 1.0f}; 
    // GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    // glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    // glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
  }

  drawCar();

  glFlush();
}

// ------------------------------------mouse rotation----------------------------------

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

// ----------------------------------------viewport transformation-----------------------------

void reshape(int width, int height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, 1, 1.0, 10000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(30, 10, -940, 0, 2, -90, 0, 1, 0);
}


//---------------------------------------- Initializes 3D rendering------------------------
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

// ------------------------------------main function------------------------

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("3D CAR");
  initRendering();
  glEnable(GL_DEPTH_TEST);
  createMenu();
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutMainLoop();
  return 0;
}
