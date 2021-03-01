#include<iostream>
#include<GL/freeglut.h>

float x1, x2, x3, x4, x5, x6, x7;
float py1, y2, y3, y4, y5, y6, y7;
int const ww = 500, wh = 500;
int const ww2 = 250, wh2 = 250;


void drawPixel(int x, int y) {

	glColor3f(0.0, 1.0, 1.0);
	glPointSize(1.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void edgeDetect(float x1, float py1, float x2, float y2, int* le, int* re) {

	float temp, x, mx;
	int i;

	if (py1 > y2) {

		temp = x1, x1 = x2, x2 = temp;
		temp = py1, py1 = y2, y2 = temp;
	}

	if (py1 == y2) {
		mx = x2 - x1;
	}
	else {
		mx = (x2 - x1) / (y2 - py1);
	}
	x = x1;

	for (i = int(py1); i <= int(y2); i++) {
		if (x < (float)le[i]) {
			le[i] = (int)x;
		}
		if (x > (float)re[i]) {
			re[i] = (int)x;
		}
		x += mx;
	}
}

void scanFill(float x1, float py1, float x2, float y2, float x3, float y3, float x4, float y4, float x5, float y5, float x6,  float y6, float x7, float y7) {

	int i, j;
	int le[ww], re[wh];

	for (i = 0; i < ww; i++) {
		le[i] = ww;
		re[i] = 0;
	}

	edgeDetect(x1, py1, x2, y2, le, re);
	edgeDetect(x2, y2, x3, y3, le, re);
	edgeDetect(x3, y3, x4, y4, le, re);
	edgeDetect(x4, y4, x5, y5, le, re);
	edgeDetect(x5, y5, x6, y6, le, re);
	edgeDetect(x6, y6, x7, y7, le, re);
	edgeDetect(x7, y7, x1, py1, le, re);

	for (j = 0; j < ww; j++) {
		if (le[j] <= re[j]) {
			for (i = le[j]; i < re[j]; i++) {
				drawPixel(i, j);
			}
		}
		glFlush();
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

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, py1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glVertex2f(x5, y5);
	glVertex2f(x6, y6);
	glVertex2f(x7, y7);
	glEnd();

	scanFill(x1, py1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7);

	glFlush();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0.0, ww, 0.0, wh);
	
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);

	glutCreateWindow("ScanLine");
	glutDisplayFunc(display);

	init();
	glutMainLoop();
}