#include "stdafx.h"

#pragma region Zmienne globalne

	int mouseX = 0;
	int mouseY = 0;

	bool captureMouse = true;
	bool free3DMovement = false;

	float mouseSensitivity = .15f;

	CScene * Scene;

	bool keystate[255];

#pragma endregion

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("GKiW: Lab 6");

	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyUp);
	glutPassiveMotionFunc(OnMouseMove);
	glutMotionFunc(OnMouseMove);
	glutTimerFunc(17, OnTimer, 0);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_NORMALIZE);

	glEnable(GL_LIGHTING);
	
	float gl_amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gl_amb);
	
	mouseX = glutGet(GLUT_WINDOW_WIDTH) / 2;
	mouseY = glutGet(GLUT_WINDOW_HEIGHT) / 2;
	glutWarpPointer(mouseX, mouseY);
	glutSetCursor(GLUT_CURSOR_NONE);

	// Inicjalizacja sceny.
	Scene = new CScene();
	Scene->Initialize();

	glutMainLoop();

	return 0;
}

#pragma region Obsluga wejscia

	void OnKeyPress(unsigned char key, int x, int y) {
		if (!keystate[key]) {
			keystate[key] = true;
			OnKeyDown(key, x, y);
		}
	}

	void OnKeyDown(unsigned char key, int x, int y) {
		if (key == 27) {
			glutLeaveMainLoop();
		}
		if (key == 'm' || key == 'M') {
			if (captureMouse) {
				captureMouse = false;
				glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			}
			else {
				captureMouse = true;
				glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
				glutSetCursor(GLUT_CURSOR_NONE);
			}
		}
		if (key == 'l' || key == 'L') {
			free3DMovement = !free3DMovement;
		}
		if (key == 'k' || key == 'K') {
			// Rysowanie kolizji.
			Scene->DrawCollisions = !Scene->DrawCollisions;
		}
		if (key == 'n' || key == 'N') {
			// Rysowanie wektorów normalnych.
			Scene->DrawNormals = !Scene->DrawNormals;
		}
	}

	void OnKeyUp(unsigned char key, int x, int y) {
		keystate[key] = false;
	}

	void OnMouseMove(int x, int y) {
		mouseX = x;
		mouseY = y;
	}

#pragma endregion

void OnTimer(int id) {
	glutTimerFunc(17, OnTimer, 0);
	
	// Aktualizacjê œwiata przenieœliœmy do obiektu klasy CScene
	// (lub dziedzicz¹cej po niej, gdy scen bêdzie kilka):
	Scene->Update();
}

void OnRender() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Rysowanie w³aœciwej sceny przenieœliœmy do obiektu klasy CScene
	// (lub dziedzicz¹cej po niej, gdy scen bêdzie kilka):
	Scene->Render();

	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();

}

void OnReshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(50.0f, (float) width / height, .01f, 100.0f);
}
