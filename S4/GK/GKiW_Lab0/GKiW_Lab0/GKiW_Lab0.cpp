#include "stdafx.h"

void OnRender();

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutCreateWindow("GKiW: Lab 0");
	glutDisplayFunc(OnRender);
	glutMainLoop();

	return 0;
}

void OnRender() {
	glClear(GL_COLOR_BUFFER_BIT);

	glutSolidCube(1.0f);

	glFlush();
	glutSwapBuffers();
}
