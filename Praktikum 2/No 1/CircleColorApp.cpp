#include<iostream>
#include <math.h>
#include <GL/freeglut.h>

GLfloat radius;
int midPosX = 0, midPosY = 0;

struct Point {
	GLint x;
	GLint y;
};

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();

}

void BoundaryFill(int x, int y, Color fillColor, Color boundaryColor) {
	Color currentColor = getPixelColor(x, y);
	if (currentColor.r != boundaryColor.r && currentColor.g != boundaryColor.g && currentColor.b != boundaryColor.b) {
		setPixelColor(x, y, fillColor);
		BoundaryFill(x + 1, y, fillColor, boundaryColor);
		BoundaryFill(x - 1, y, fillColor, boundaryColor);
		BoundaryFill(x, y + 1, fillColor, boundaryColor);
		BoundaryFill(x, y - 1, fillColor, boundaryColor);
	}
}

void draw_circle(Point points, GLfloat radius) {
	GLfloat step = 1 / radius;
	GLfloat x, y;

	for (GLfloat theta = 0; theta <= 360; theta += step) {
		x = points.x + (radius * cos(theta));
		y = points.y + (radius * sin(theta));
		glVertex2i(x, y);
	}
}

void display(void) {

	if (radius < 10) {
		radius = radius * 10;
	}
	if (radius > 47) {
		radius = 46;
	}
	if (midPosX < 10) {
		midPosX = midPosX * 10;
	}
	if (midPosY < 10) {
		midPosY = midPosY * 10;
	}
	Point pt = { 320 + midPosX, 240 + midPosY };
	Color fillColor = { 1.0f, 0.0f, 0.0f };		
	Color boundaryColor = { 0.0f, 0.0f, 0.0f }; 

	Point p = { 321 + midPosX, 241 + midPosY }; 

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	draw_circle(pt, radius);
	BoundaryFill(p.x, p.y, fillColor, boundaryColor);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	std::cout << "radius: ";
	std::cin >> radius;
	std::cout << "position x: ";
	std::cin >> midPosX;
	std::cout << "position y: ";
	std::cin >> midPosY;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Open GL");
	init();
	glutDisplayFunc(display);
	//glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}