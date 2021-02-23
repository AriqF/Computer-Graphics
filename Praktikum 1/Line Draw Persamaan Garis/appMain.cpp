#include<iostream>
#include<GL/freeglut.h>
#include<cmath>
#include<math.h>

int Xstart, Xend, Ystart, Yend, px1 = 320, py1 = 240;

void slopeIntercept() {

	if (Xstart < 10 && Xend < 10 && Ystart < 10 && Yend < 10) {
		Xstart = Xstart * 10.0;
		Xend = Xend * 10.0;
		Ystart = Ystart * 10.0;
		Yend = Yend * 10.0;
	}

	double dx = (Xend - Xstart) * 1.0;
	double dy = (Yend - Ystart) * 1.0;
	double m = (Yend - Ystart) * 1.0 / (Xend - Xstart) * 1.0;
	double c = (Ystart * 1.0) - m * (Xstart * 1.0);

	int x, y;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);

	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	if (dx > dy) {
		for (x = Xstart; x <= Xend; x++) {
			y = m * x + c;
			glVertex2d(round(x) + px1, round(y) + py1);
		}
	}
	else {
		for (y = Ystart; y < Yend; y++) {
			x = (y - 1) / m;
			glVertex2d(round(x) + px1, round(y) + py1);
		}
	}
	glEnd();
	glFlush();

	//std::cout << "dx: " << dx<<std::endl;
	//std::cout << "dy: " << dy << std::endl;
	//std::cout << "m: " << m << std::endl;
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
	glutCreateWindow("Persamaan Garis");
	gluOrtho2D(0, 600, 0, 480);

	glutDisplayFunc(slopeIntercept);
	glutMainLoop();
}
