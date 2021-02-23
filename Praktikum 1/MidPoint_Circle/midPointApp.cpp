#include<iostream>
#include<GL/freeglut.h>
#include<math.h>
#include<cmath>

int px1 = 320, py1 = 240, r;

void plot(int x, int y) {
	
	glBegin(GL_POINTS);
	glVertex2i(x + px1, y + py1);
	glEnd();
}

void init(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircle() {

	int x = 0, y = r;
	float p = 1 - r;
	plot(x, y);
	while (y > x) {
		if (p < 0) {
			x++;
			p += (2 * x + 1);
		}
		else {
			y--;
			x++;
			p += (2 * (x - y) + 1);
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
}

void drawCircle() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	midPointCircle();
	glFlush();
}

int main(int argc, char** argv) {

	std::cout << "enter radius: ";
	std::cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 150);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Mid Point Circle");
	glutDisplayFunc(drawCircle);
	init();
	glutMainLoop();
}
