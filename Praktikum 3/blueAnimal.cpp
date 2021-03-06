#include<iostream>
#include<GL/freeglut.h>
#include<math.h>

int const ww = 600, wh = 600;
int const centerX = ww / 2, centerY = wh / 2;

float theta;
int angle = 180; //set to 360 to make half circle
float multiplierAngle = 1.5; // 1 to make circle 
GLfloat x, y;

void init() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, ww, 0, wh);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
}

void bodyDraw() {

	glColor3f(0.137255, 0.137255, 0.556863); //navy
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 0) + (140 * cos(theta));
		y = (centerX + 0) + (140 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void headDraw() {

	glColor3f(1.0, 1.0, 1.0); //white
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 0) + (65 * cos(theta));
		y = (centerX + 145) + multiplierAngle * (75 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(0.137255, 0.137255, 0.556863); //navy
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 0) + (64 * cos(theta));
		y = (centerX + 145) + multiplierAngle * (74 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void eyesDraw() {
	
	//left white
	glColor3f(1.0, 1.0, 1.0); //white
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX - 25) + (10 * cos(theta));
		y = (centerX + 160) + multiplierAngle * (10 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	//left brown
	glColor3f(0.36, 0.25, 0.20); //brown
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX - 25) + (7 * cos(theta));
		y = (centerX + 154) + multiplierAngle * (7 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	//right white
	glColor3f(1.0, 1.0, 1.0); //white
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 25) + (10 * cos(theta));
		y = (centerX + 160) + multiplierAngle * (10 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	//right brown
	glColor3f(0.36, 0.25, 0.20); //brown
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 25) + (7 * cos(theta));
		y = (centerX + 154) + multiplierAngle * (7 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void noseDraw() {

	//right
	glColor3f(1.0, 0.0, 0.0); //red
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 6) + (3 * cos(theta));
		y = (centerX + 115) + (3 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	//left
	glColor3f(1.0, 0.0, 0.0); //red
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX - 6) + (3 * cos(theta));
		y = (centerX + 115) + (3 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void mouthDraw() {

	glColor3f(1.0, 0.0, 0.0); //red
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 0) + (18 * cos(theta));
		y = (centerX + 80) + multiplierAngle * (9 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void footDraw() {
	//left
	glColor3f(0.137255, 0.137255, 0.556863); //navy
	glBegin(GL_QUADS);
	glVertex2f(centerX - 50, centerY - 130);
	glVertex2f(centerX - 35, centerY - 130);
	glVertex2f(centerX - 35, centerY - 200);
	glVertex2f(centerX - 50, centerY - 200);
	glEnd();
	//right
	glColor3f(0.137255, 0.137255, 0.556863); //navy
	glBegin(GL_QUADS);
	glVertex2f(centerX + 50, centerY - 130);
	glVertex2f(centerX + 35, centerY - 130);
	glVertex2f(centerX + 35, centerY - 200);
	glVertex2f(centerX + 50, centerY - 200);
	glEnd();
	glFlush();
}

void hornDraw() {

	//right
	glColor3f(0.0, 0.0, 0.0); //black
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 20) + (5 * cos(theta));
		y = (centerX + 258) + multiplierAngle * (5 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	//left
	glColor3f(0.0, 0.0, 0.0); //black
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX - 20) + (5 * cos(theta));
		y = (centerX + 258) + multiplierAngle * (5 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void earDraw() {

	//left
	glColor3f(0.137255, 0.137255, 0.556863); //navy
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX - 60) + (25 * cos(theta));
		y = (centerX + 230) + multiplierAngle * (5 * sin(theta));
		glVertex2f(x, y);
	}
	//right
	glColor3f(0.137255, 0.137255, 0.556863); //navy
	glBegin(GL_POLYGON);
	for (int i = 0; i < 370; i++) {

		theta = (i * 3.142 / 180);
		x = (centerX + 60) + (25 * cos(theta));
		y = (centerX + 230) + multiplierAngle * (5 * sin(theta));
		glVertex2f(x, y);
	}
	glEnd();
	glEnd();
	glFlush();
}

void drawAnimal() {

	bodyDraw();
	headDraw();
	eyesDraw();
	noseDraw();
	mouthDraw();
	footDraw();
	hornDraw();
	earDraw();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutInitWindowPosition(200, 400);
	glutCreateWindow("Blue Animal");
	init();
	glutDisplayFunc(drawAnimal);
	glutMainLoop();
}
