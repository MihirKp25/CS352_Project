#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "SOIL/SOIL.h"
#include "imageio.h"

using namespace std;

double rotate_x = 0, rotate_y = 0, zoom = 1;

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

// Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Escape key
		exit(0);
	}
}

// Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); // Enable lighting
	// you can have upto 8 lighting
	// Enable light #1
	glEnable(GL_NORMALIZE);	 // Automatically normalize normals
	glShadeModel(GL_SMOOTH); // Enable smooth shading
}

// Called when the window is resized
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = -70.0f;

// Draws the 3D scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

	// Transformations on the cube
	glLoadIdentity();
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glScalef(zoom, zoom, zoom);


	// Eabling Texture Environment
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Defining faces of the cube and also the texture to be binded on the face
	// ref. https://www.wikihow.com/Make-a-Cube-in-OpenGL

	// Front
	glBegin(GL_QUADS);
		glVertex3f( 0.5, -0.5, -0.5);
		glVertex3f( 0.5,  0.5, -0.5);
		glVertex3f(-0.5,  0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Back
	glBegin(GL_QUADS);
		glVertex3f( 0.5, -0.5, 0.5);
		glVertex3f( 0.5,  0.5, 0.5);
		glVertex3f(-0.5,  0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// Top
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0.5, -0.5, -0.5);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(0.5,  0.5, -0.5);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(0.5,  0.5,  0.5);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0.5, -0.5,  0.5);
	glEnd();

	// Bottom
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(-0.5, -0.5,  0.5);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(-0.5,  0.5,  0.5);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(-0.5,  0.5, -0.5);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Right
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex3f( 0.5,  0.5,  0.5);
		glTexCoord2f(1.0, 0.0);
		glVertex3f( 0.5,  0.5, -0.5);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(-0.5,  0.5, -0.5);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5,  0.5,  0.5);
	glEnd();

	// Left
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);
		glVertex3f( 0.5, -0.5, -0.5);
		glTexCoord2f(1.0, 0.0);
		glVertex3f( 0.5, -0.5,  0.5);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(-0.5, -0.5,  0.5);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

int axis_x = 0, axis_y = 0;


// captures Scrollwhe

// Captures Idleness
// Adds motion to the cube
void idleCallBack(){
    // Spins the cube around the set axis.
	if(axis_x == 0)	rotate_x += 0.5;
	if(axis_x == 1)	rotate_x -= 0.5;
	if(axis_y == 0)	rotate_y += 0.5;
	if(axis_y == 1)	rotate_y -= 0.5;
    glutPostRedisplay();
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
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	// Create the window
	glutCreateWindow("Lighting ");
	load_texture();
	initRendering();
	// Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutIdleFunc(idleCallBack);

	// glutTimerFunc(25, update, 0); // Add a timer

	glutMainLoop();
	return 0;
}