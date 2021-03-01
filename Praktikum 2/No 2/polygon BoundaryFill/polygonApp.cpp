#include<iostream>
#include<GL/freeglut.h>
#include<Windows.h>

float x1, x2, x3, x4, x5, x6, x7;
float py1, y2, y3, y4, y5, y6, y7;
int const ww = 500, wh = 500;
int const ww2 = 250, wh2 = 250;

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};



void setPixel(GLint x, GLint y, Color color) {
	
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

Color getPixels(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &color);
	return color;
}

void boundaryFill(int x, int y, Color fillColor, Color boundaryColor){

	Color currentColor = getPixels(x, y);
	if (currentColor.r != boundaryColor.r && currentColor.g != boundaryColor.g && currentColor.b != boundaryColor.b){

		setPixel(x, y, fillColor);
		boundaryFill(x + 1, y, fillColor, boundaryColor);
		boundaryFill(x - 1, y, fillColor, boundaryColor);
		boundaryFill(x, y + 1, fillColor, boundaryColor);
		boundaryFill(x, y - 1, fillColor, boundaryColor);
	}
}

void display() {

	x1 = 20 + ww2; py1 = 10 + wh2;
	x2 = 30 + ww2; y2 = 60 + wh2;
	x3 = 50 + ww2; y3 = 40 + wh2;
	x4 = 80 + ww2; y4 = 80 + wh2;
	x5 = 100 + ww2; y5 = 40 + wh2;
	x6 = 120 + ww2; y6 = 20 + wh2;
	x7 = 20 + ww2; y7 = 10 + wh2;
	Color fillColor = { 1.0f, 0.0f, 0.0f };		
	Color boundaryColor = { 0.0f, 0.0f, 0.0f }; 
	

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, py1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glVertex2f(x5, y5);
	glVertex2f(x6, y6);
	glVertex2f(x7, y7);
	glEnd();

	boundaryFill(x2, y3, fillColor, boundaryColor);

	glFlush();
}

void init() {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glViewport(0, 0, ww, wh);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("Boundary Fill");
	glutDisplayFunc(display);
	init();
	glutMainLoop();

}