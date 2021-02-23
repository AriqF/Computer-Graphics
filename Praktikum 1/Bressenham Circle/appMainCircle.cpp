#include<iostream>
#include<GL/freeglut.h>
#include<math.h>
#include<cmath>

int xc = 320, yc = 240;
int radius;

void plot_point(int x, int y) {

	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x); 
	glEnd();
}

void bresenhamCircle(int r) {
	int x = 0, y = r;
	float pk = (5.0 / 4.0) - r;

	//plot the points
	//plot the first points

	plot_point(x, y);
	int k;

	while (x < y) {
		x += 1;
		if (pk < 0) {
			pk += (2 * x + 1);
		}
		else {
			y -= 1;
			pk += (2 * (x - y) + 1);
		}
		plot_point(x, y);
	}
	glFlush();
}

void concentCircle() {
	//clear buffer
	glClear(GL_COLOR_BUFFER_BIT);
	bresenhamCircle(radius);
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0); // set clear color to white
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {

	std::cout << "set radius: ";
	std::cin >> radius;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Bresenham_circle");
	
	
	init();
	glutDisplayFunc(concentCircle);
	glutMainLoop();
}
