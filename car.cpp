#include <GL/glut.h>
#include "car.h"
#include "road.h"
#include <math.h>

using namespace std;

int lastX = 0, lastY = 0;
int rotationX = 0, rotationY = 0;
int menuWidth = 200; // Width of the menu
bool headLightSwitch=false;
int xview = 0, yview = 0, zview = -80;


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

  

  float bgcolor[4] = { 1, 1, 1, 0.2 };
  float bgcolor2[4] = { 0, 0, 0, 0.5 };
  float zero[] = { 0, 0, 0, 1 };

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-13.5, 1, 5);

  glBegin(GL_POLYGON); // LEFT
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glVertex3f(-10, 2, 7);
  glVertex3f(-10, 0, 7);
  glMaterialfv(GL_FRONT, GL_EMISSION, zero);
  glEnd();

  if(headLightSwitch==true){
    //Headlights lights
  //front face
  glBegin(GL_POLYGON); // RIGHT
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
  glVertex3f(-40, 5, 1);
  glVertex3f(-40, -3, 1);
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
  glVertex3f(-14, 0, 4);
  glVertex3f(-14, 2, 4);
  glEnd();
  glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!
  //back face
  glBegin(GL_POLYGON); // RIGHT
  glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
  glVertex3f(-40, 5, 10);
  glVertex3f(-40, -3, 10);
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
  glVertex3f(-10, 0, 7);
  glVertex3f(-10, 2, 7);
  glEnd();
  glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!
  //top face
  glBegin(GL_POLYGON); // RIGHT
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
  glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glVertex3f(-10, 2, 7);
  glVertex3f(-14, 2, 4);
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
  glVertex3f(-40, 5, 1);
  glVertex3f(-40, 5, 10);
  glEnd();
  glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!
  //bottom face
  glBegin(GL_POLYGON); // RIGHT
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
  glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glVertex3f(-40, -3, 10);
  glVertex3f(-40, -3, 1);
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
  glVertex3f(-14, 0, 4);
  glVertex3f(-10, 0, 7);
  glEnd();
  glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

  }
  

  glPopMatrix();

  //--------------

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-13.5, 1, -5);

  


  glBegin(GL_POLYGON); // RIGHT
  glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
  glVertex3f(-14, 0, -4);
  glVertex3f(-14, 2, -4);
  glVertex3f(-10, 2, -7);
  glVertex3f(-10, 0, -7);
  glEnd();
  glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

  if(headLightSwitch==true){
      //Headlights lights
    //front face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-40, 5, -1);
    glVertex3f(-40, -3, -1);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-14, 0, -4);
    glVertex3f(-14, 2, -4);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!
    //back face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-40, 5, -10);
    glVertex3f(-40, -3, -10);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-10, 0, -7);
    glVertex3f(-10, 2, -7);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!
    //top face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-10, 2, -7);
    glVertex3f(-14, 2, -4);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glVertex3f(-40, 5, -1);
    glVertex3f(-40, 5, -10);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!
    //bottom face
    glBegin(GL_POLYGON); // RIGHT
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor2);
    glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glVertex3f(-40, -3, -10);
    glVertex3f(-40, -3, -1);
    glMaterialfv(GL_FRONT, GL_EMISSION, bgcolor);
    glVertex3f(-14, 0, -4);
    glVertex3f(-10, 0, -7);
    glEnd();
    glMaterialfv(GL_FRONT, GL_EMISSION, zero); // Turn off emission color!

  }
  
  glPopMatrix();

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(-12, 3, 5);

  
  glColor3f(1, 1, 1);
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
  glColor3f(1, 0, 0);
  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(12.5, 1, 0);

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

  glBegin(GL_POLYGON); // TOP
  glVertex3f(12, 0, 3);
  glVertex3f(12, 2, 3);
  glVertex3f(8, 2, 7);
  glVertex3f(8, 0, 7);
  glEnd();

  glPopMatrix();

  glPushMatrix();

  glScalef(0.5, 0.5, 0.5);
  glTranslatef(11, 1, -5);

  glBegin(GL_POLYGON); // DOWN
  glVertex3f(12, 0, -3);
  glVertex3f(12, 2, -3);
  glVertex3f(8, 2, -7);
  glVertex3f(8, 0, -7);
  glEnd();

  glPopMatrix();
}

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


// glColor4f(1.0, 1.0, 1.0, 0.2);
const float mirdiff[] = {1.0,1.0,1.0,0.5};

  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mirdiff);
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

void CAR::Paint()
{

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

  glColor3f(0.098, 0.098, 0.439);
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
  glColor3f(0.098, 0.098, 0.439);

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

  glColor3f(0.098, 0.098, 0.439);

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

  glColor4f(0.184, 0.310, 0.310, 0.2);

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
  glColor3f(0.098, 0.098, 0.439);

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
  glColor3f(0.098, 0.098, 0.439);

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
  glColor3f(0.098, 0.098, 0.439);

  glBegin(GL_POLYGON); // TOP
  glVertex3f(-10, 0, 6);
  glVertex3f(-7, 4, 5);
  glVertex3f(8, 3, 6);
  glVertex3f(8, 0, 6);
  glEnd();

  //side handle front
  glColor3f(1, 1, 0);
glBegin(GL_POLYGON);
float radius = 0.5;
for (int i = 0; i <= 180; i++) {
    float angle = i * M_PI / 180.0;
    glVertex3f(-1 + radius * cos(angle), 2.5 + radius * sin(angle), 6);
}
glEnd();
  //side handle back
  glColor3f(1, 1, 0);
glBegin(GL_POLYGON);
radius = 0.5;
for (int i = 0; i <= 180; i++) {
    float angle = i * M_PI / 180.0;
    glVertex3f(-1 + radius * cos(angle), 2.5 + radius * sin(angle), -6);
}
glEnd();

  glColor3f(0.098, 0.098, 0.439);
  glBegin(GL_POLYGON);
  glVertex3f(-10, 0, -6);
  glVertex3f(-7, 4, -5);
  glVertex3f(8, 3, -6);
  glVertex3f(8, 0, -6);
  glEnd();

  //-----------------------------base floor-----------------//
 glPushMatrix();
glColor3f(0, 1, 0); // Set color to green
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
glColor3f(0, 1, 1); // Set color to green

// Define the radius of the circular base
radius = 17.0; // Adjust as needed

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
}

void Cylinder(){
  GLUquadricObj *p = gluNewQuadric();
  
  gluCylinder(p, 10, 10, 1, 100, 100);
  gluDisk(p, 0, 5, 100, 100);

}

void CAR::ExhaustCylinder(){
  GLUquadricObj *q = gluNewQuadric();
  gluCylinder(q, 5, 5, 7, 100, 100);
  gluDisk(q, 0, 5, 100, 100);
  return;
}

void CAR::ExhaustPipes(){
  glPushMatrix();
  float s=0.09;

  glTranslatef(12, 1, 3.1);
  glRotatef(90, 0, 1, 0);
  glScalef(s, s, s);
  glColor3f(1,1,1);
  ExhaustCylinder();

  glPopMatrix();

  glPushMatrix();
  s=0.09;
  glTranslatef(12, 1, 3.1);
  glRotatef(90, 0, 1, 0);
  glScalef(s, s, s);
  glColor3f(1,1,1);
  glTranslatef(10, 0, 0);
  ExhaustCylinder();

  glPopMatrix();

  glPushMatrix();
  s=0.09;
  glTranslatef(12, 1, 3.1);
  glRotatef(90, 0, 1, 0);
  glScalef(s, s, s);
  glColor3f(1,1,1);
  glTranslatef(60, 0, 0);
  ExhaustCylinder();

  glPopMatrix();

  glPushMatrix();
  s=0.09;
  glTranslatef(12, 1, 3.1);
  glRotatef(90, 0, 1, 0);
  glScalef(s, s, s);
  glColor3f(1,1,1);
  glTranslatef(70, 0, 0);
  ExhaustCylinder();

  glPopMatrix();

}

void CarSymbol(){
  glPushMatrix();
  glTranslatef(-14.5, 1, 1);
  glRotatef(90, 0, 1, 0);
  glColor3f(1,1,1);
  glScalef(0.05, 0.05, 0.05);
  Cylinder();
  glTranslatef(10, 0, 0);
  Cylinder();
  glTranslatef(10, 0, 0);
  Cylinder();
  glTranslatef(10, 0, 0);
  Cylinder();

  glTranslatef(-30, 0, 0);
  glScalef(20, 20, 20);
  glRotatef(-90, 0, 1, 0);
  glTranslatef(14.5, -1, -1);
  glPopMatrix();
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
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0, 0, 0, 1.0); // Set background color to white

  GLfloat mat_specular[] = { 0.7, 0.8, 0.8, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };

    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glShadeModel (GL_SMOOTH);
  CAR car;
  // car.SelectModel(4);
  car.Lights();
  // car.WireFrame();
  car.Paint();
  car.Wheels(0);
  CarSymbol();
  car.ExhaustPipes();
  // RoadSlab();

  glEnd(); // End drawing the polygon
  glFlush();
  return;
}

void menu(int value) {
    // Handle menu selections
    switch (value)
    {
    case 1:
      if(headLightSwitch==false)
      headLightSwitch=true;
      else
      headLightSwitch=false;

      glutPostRedisplay();
      break;
    
    default:
      break;
    }
}

void createMenu() {
    int mainMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Light headlights", 1);
    glutAddMenuEntry("Option 2", 2);
    glutAddMenuEntry("Option 3", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON); // Attach the menu to the right mouse button
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(0, 0, -90);
  // glRotatef(90, 0, 1, 0);
  glRotatef(rotationX, 1.0, 0.0, 0.0); // Rotate around x-axis
  glRotatef(rotationY, 0.0, 1.0, 0.0); // Rotate around y-axis

  GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; // Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

 if(headLightSwitch==false)
 {

  // Add positioned light
  GLfloat lightColor0[] = {1, 1, 1, 1.0f}; // Color (0.5, 0.5, 0.5)
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
 }

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
  gluPerspective(45, 1, 1.0, 10000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(30, 10, -940, 0, 0, -90, 0, 1, 0);
}
// Initializes 3D rendering
void initRendering()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING); // Enable lighting
  // you can have upto 8 lighting
  glEnable(GL_LIGHT0);     // Enable light #0
  glEnable(GL_LIGHT1);     // Enable light #1
  glEnable(GL_NORMALIZE);  // Automatically normalize normals
  glShadeModel(GL_SMOOTH); // Enable smooth shading
}
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
