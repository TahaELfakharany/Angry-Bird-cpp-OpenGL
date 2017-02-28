#include <windows.h>	// Header file for the Windows Library
#include <gl/gl.h>	// Header file for the OpenGL32 Library
#include <gl/glu.h>	// Header file for the GlU32 Library
#include <glut.h>	// Header file for the Glut32 Library
#include <math.h>	// Header file for the Math Library
#include<cmath>



/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char *argv[]);
void DrawEllipse(GLfloat x, GLfloat y, GLfloat radiusX, GLfloat radiusY)
{
	int i;
	float PI = 3.14;
	glBegin(GL_TRIANGLE_FAN);

	for (i = 0; i<360; i++)
	{
		float rad = i*(PI / 180.0);
		glVertex2f(x + cos(rad)*radiusX,
			y + sin(rad)*radiusY);
	}

	glEnd();
}

void drawHollowEllipse(GLfloat x, GLfloat y, GLfloat radiusX, GLfloat radiusY)
{

	int i;
	float PI = 3.14;
	glBegin(GL_LINE_LOOP);

	for (i = 0; i<360; i++)
	{
		float rad = i*(PI / 180.0);
		glVertex2f(x + cos(rad)*radiusX,
			y + sin(rad)*radiusY);
	}

	glEnd();

}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	float PI = 3.14;
	int i;
	int triangleAmount = 100;
	GLfloat twicePi = 2.0f* PI;
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(x, y);
	for (i = 0; i <= triangleAmount; i++)
	{

		glVertex2f(x + (radius*cos(i*twicePi / triangleAmount)), y + (radius*sin(i*twicePi / triangleAmount)));
	}
	glVertex2f(x + (radius*cos(i*twicePi / triangleAmount)), y + (radius*sin(i*twicePi / triangleAmount)));
	glEnd();
}

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius) {

	float PI = 3.14;
	static const double inc = PI / 12;
	static const double max = 2 * PI;
	glBegin(GL_LINE_LOOP);
	for (double d = 0; d < max; d += inc) {
		glVertex2f(cos(d) * radius + x, sin(d) * radius + y);
	}
	glEnd();
}


/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations();

/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay();

int main(int argc, char* argv[]) {
	InitGraphics(argc, argv);
	return 0;
}

/**
Handles the paint event. This event is triggered whenever
our displayed graphics are lost or out-of-date.
ALL rendering code should be written here.
*/
void OnDisplay() {
	//set the background color to white
	glClearColor(1, 1, 1, 1);
	//fill the whole color buffer with the clear color
	glClear(GL_COLOR_BUFFER_BIT);
	SetTransformations();

	
	
	//body
	glColor3f(0, 0, 0);
	drawFilledCircle(0, 0, 38.25);
	glColor3f(1, 0, 0);
	drawFilledCircle(0, -1, 36.25);
	//feathers
	glLineWidth(20);
	glColor3f(1, 0, 0);
	DrawEllipse(-17, 39, 15, 10);
	glColor3f(0, 0, 0);
	drawHollowEllipse(-17, 39, 15, 10);
	glColor3f(1, 0, 0);
	DrawEllipse(4, 37.5, 9, 20);
	glColor3f(0, 0, 0);
	drawHollowEllipse(4, 37.5, 9, 20);

	//body with the difference color
	glColor3f(1, 1, 0.7);
	drawFilledCircle(0, -32, 24);
	glColor3f(1, 1, 1);
	drawFilledCircle(0, -57, 20.5);
	glColor3f(1, 1, 1);
	drawFilledCircle(22, -52, 21);
	glColor3f(1, 1, 1);
	drawFilledCircle(-22, -52, 21);

	glLineWidth(30);
	glColor3f(0, 0, 0);
	drawHollowCircle(0, 0, 37.5);
	
	//to hide borders of th feather
	glColor3f(1, 0, 0);
	DrawEllipse(-3, 29, 19,14);
	//rest of the body
	
	glColor3f(0.643137254901961, 0.0156862745098039, 0.113725490196078);
	drawFilledCircle(20, -5, 4);
	glColor3f(0.643137254901961, 0.0156862745098039, 0.113725490196078);
	drawFilledCircle(30, -8, 3.25);

	glColor3f(0.643137254901961, 0.0156862745098039, 0.113725490196078);
	drawFilledCircle(-20, -4, 4);
	glColor3f(0.643137254901961, 0.0156862745098039, 0.113725490196078);
	drawFilledCircle(-30, -9, 3.25);
	

	//eye
	glColor3f(.70, 0, .10);
	drawFilledCircle(5.5, -.5, 8);
	glColor3f(.70, 0, .10);
	drawFilledCircle(-5.5, -.5, 8);
	glColor3f(0, 0, 0);
	drawFilledCircle(5.75, 1, 6.5);
	glColor3f(0, 0, 0);
	drawFilledCircle(-5.75, 1, 6.5);
	glColor3f(1, 1, 1);
	drawFilledCircle(4.8, 1, 5.75);
	glColor3f(1, 1, 1);
	drawFilledCircle(-4.9, 1, 5.75);
	//eye black
	glColor3f(0, 0, 0);
	drawFilledCircle(3, 2, 2);
	glColor3f(0, 0, 0);
	drawFilledCircle(-3, 2, 2);
	//eye human
	glColor3f(1, 1, 1);
	drawFilledCircle(2.1, 2, .9);
	glColor3f(1, 1, 1);
	drawFilledCircle(-3.9, 2, .90);
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3f(0, 8, 0);
	glVertex3f(0, -5, 0);
	glEnd();
	//lashes
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3f(0, 8, 0);
	glVertex3f(20, 15, 0);
	glVertex3f(20, 7, 0);
	glVertex3f(0, 2.5, 0);
	glVertex3f(-20, 7, 0);
	glVertex3f(-20, 15, 0);
	glVertex3f(0, 8, 0);
	glEnd();

	

	//mouse
	glColor3f(0, 0, 0);
	drawFilledCircle(0, -13, 4.5);
	glBegin(GL_TRIANGLES);
	glColor3f(.94, 0.68, 0);
	glVertex2f(7, -8);
	glVertex2f(0, -18);
	glVertex2f(-7, -9);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(10, -9, 0);
	glVertex3f(0, -13, 0);
	glVertex3f(-10, -9, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(.90, 0.90, 0);
	glVertex3f(0, -1, 0);
	glVertex3f(8.5, -8, 0);
	glVertex3f(0, -12, 0);
	glVertex3f(-8.5, -8, 0);
	glEnd();
	
	
	
	
	//force previously issued OpenGL commands to begin
	//execution
	glFlush();
}

/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
Initialization is done once at the start of the program.
Rendering is done each time the window needs redrawing
*/
void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	//Create an 800x600 window with its top-left corner at pixel (100, 100)
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults

									  //Opens and displays the screen window, putting the title "OpenGL Lab1" in the title bar
	glutCreateWindow("OpenGL Angry Bird Assignment");
	//OnDisplay will handle the paint event
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
}

/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations() {
	//set up the logical coordinate system of the window: [-100, 100] x [-100, 100]
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//define a 2-D orthographic projection matrix
	//parameters: left, right, bottom, top
	//left, right
	//Specify the coordinates for the left and right vertical clipping planes.
	//bottom, top
	//Specify the coordinates for the bottom and top horizontal clipping planes.
	gluOrtho2D(-100, 100, -100, 100);
}
