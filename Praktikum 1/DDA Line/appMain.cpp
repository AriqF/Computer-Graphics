#include<iostream>
#include<GL/freeglut.h>
#include<cmath>
#include<math.h>

int Xstart, Xend, Ystart, Yend, px1 = 320, py1 = 240;

void drawingLine() {

	if (Xstart < 10 && Xend < 10 && Ystart < 10 && Yend < 10) {
		Xstart = Xstart * 10.0;
		Xend = Xend * 10.0;
		Ystart = Ystart * 10.0;
		Yend = Yend * 10.0;
	}

	//std::cout << Xstart << " , " << Ystart << std::endl;
	//std::cout << Xend << " , " << Yend << std::endl;

	int dx = Xend - Xstart;
	int dy = Yend - Ystart;
	int steps = dx;
	if (abs(dy) > abs(dx)) {
		steps = dy;
	}
	double x = 1.0 * Xstart;
	double y = 1.0 * Ystart;

	double incX = 1.0 * dx / steps;
	double incY = 1.0 * dy / steps;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2d(x + px1, y + py1);
	for (int i = 1; i <= steps; i++) {
		x += incX;
		y += incY;
		glVertex2d(round(x) + px1, round(y) + py1);
	}
	glEnd();
	glFlush();
}

void init() {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {

	std::cout << "x0: ";
	std::cin >> Xstart;
	std::cout << "y0: ";
	std::cin >> Ystart;

	std::cout << "x1: ";
	std::cin >> Xend;
	std::cout << "y1: ";
	std::cin >> Yend;

	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("DDA Draw Line");
	
	init();
	glutDisplayFunc(drawingLine);
	glutMainLoop();
}
