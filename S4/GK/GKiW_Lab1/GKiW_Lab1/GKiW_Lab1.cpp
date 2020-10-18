#include "stdafx.h"

// Deklaracje funkcji, ktore beda uzyte do obslugi roznych zdarzen.
void OnRender();
void OnReshape(int, int);

// Punkt wejscia do programu.
int main(int argc, char * argv[])
{
	// Inicjalizacja biblioteki GLUT. Nalezy przekazac parametry
	// wywolania programu.
	glutInit(&argc, argv);

	// Ustawienie parametrow okna i kontekstu OpenGL.
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // bufor klatki w formacie RGBA, double-buffered, z buforem glebokosci

															   // Utworzenie wlasciwego okna i nadanie mu tytulu.
	glutCreateWindow("NO CO ZA PAJAC");

	// Ustawienie funkcji Render() jako tej, ktora jest wykonywana
	// kazdorazowo gdy potrzeba przerysowac zawartosc okna.
	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);

	// Wlaczenie testu glebokosci.
	glEnable(GL_DEPTH_TEST);

	// Rozpoczecie wykonywania petli glownej. Od tego momentu
	// wplyw na przebieg dzialania programu maja wylacznie zarejestrowane
	// uprzednio callbacki.
	glutMainLoop();

	return 0;
}

// Licznik klatek - uzyteczny przy prostym ruchu kamery.
int frame = 0;
float kat = -50.0f;
int up = 1;
float dlonx = -2.8f;
float dlony = -0.9f;

// Callback przerysowujacy klatke.
void OnRender() {

	// Wyczysc zawartosc bufora koloru i glebokosci.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Wybor macierzy, ktora od tej pory bedziemy modyfikowac
	// - macierz Modelu/Widoku.
	glMatrixMode(GL_MODELVIEW);

	// Zaladowanie macierzy jednostkowej.
	glLoadIdentity();

	// Przesuniecie swiata (przeciwienstwo przesuniecia kamery).
	glTranslatef(0.0f, 0.0f, -9.0f);

	// Obrot kamery - aby zatrzymac ja w miejscu, nalezy zakomentowac.
	glRotatef(frame, 0.0f, 1.0f, 0.0f);


	// Rysowanie obiektow na scenie.

	// Prostopadloscian
	/*glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(-3.0f, -0.5f, 0.0f);
	glScalef(4.0f, 0.5f, 0.5f);
	glutSolidCube(1.0f);
	glPopMatrix();*/

	// Tulow
	glColor3f(0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(2.0f, 4.0f, 2.0f);
	glutSolidSphere(.5f, 24, 24);
	glPopMatrix();

	// Glowa
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0.0f, 2.5f, 0.0f);
	//glScalef(0.5f, 1.0f, 0.5f);
	glutSolidSphere(.5f, 24, 24);
	glPopMatrix();

	// Czapka
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0.0f, 3.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glScalef(1.5f, 1.5f, 0.7f);
	glutSolidCone(.5f, 1.0f, 14, 14);
	glPopMatrix();

	//Lewa dlon
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(dlonx, dlony, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glutSolidSphere(.5f, 24, 24);
	glPopMatrix();

	//Prawa dlon
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(2.5f, -1.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glutSolidSphere(.5f, 24, 24);
	glPopMatrix();

	//Lewa stopa
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(-1.7f, -4.5f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glutSolidSphere(.5f, 24, 24);
	glPopMatrix();

	//Prawa stopa
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(1.7f, -4.5f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glutSolidSphere(.5f, 24, 24);
	glPopMatrix();

	//Lewa reka
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(-1.0f, 0.5f, 0.0f);
	glRotatef(kat, 0.0f, 0.0f, -0.5f);
	glScalef(3.5f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//Prawa reka
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(1.0f, 0.5f, 0.0f);
	glRotatef(-45.0f, 0.0f, 0.0f, 0.5f);
	glScalef(3.5f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//Lewa noga
	glColor3f(0.4f, 0.2f, 0.3f);
	glPushMatrix();
	glTranslatef(-1.0f, -2.5f, 0.0f);
	glRotatef(-70.0f, 0.0f, 0.0f, -0.5f);
	glScalef(3.5f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//Prawa noga
	glColor3f(0.4f, 0.2f, 0.3f);
	glPushMatrix();
	glTranslatef(1.0f, -2.5f, 0.0f);
	glRotatef(-70.0f, 0.0f, 0.0f, 0.5f);
	glScalef(3.5f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Stozek
	/*glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(3.0f, -1.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glutSolidCone(.5f, 1.0f, 14, 14);
	glPopMatrix();*/


	// Jesli instrukcje w danej implementacji OpenGL byly buforowane,
	// w tym momencie bufor zostanie oprozniony a instrukcje wykonane.
	glFlush();

	// Zamien front-buffer z back-bufferem (double buffering).
	glutSwapBuffers();

	// Nakaz wyswietlic kolejna klatke.
	glutPostRedisplay();

	// Inkrementacja licznika klatek.
	frame++;
	if (up == 1)
	{
		kat += 2.0f;
		//dlonx -= 0.01f;
		dlony += 0.05f;
	}
	else
	{
		kat -= 2.0f;
		//dlonx += 0.01f;
		dlony -= 0.05f;
	}
	
	if (kat == 50.0f || kat == -50.0f)
	{
		up = !up;
	}
}

// Callback obslugujacy zmiane rozmiaru okna.
void OnReshape(int width, int height) {
	// Wybor macierzy - macierz Projekcji.
	glMatrixMode(GL_PROJECTION);

	// Zaladowanie macierzy jednostkowej.
	glLoadIdentity();

	// Okreslenie obszaru renderowania - caly obszar okna.
	glViewport(0, 0, width, height);

	// Chcemy uzyc kamery perspektywicznej o kacie widzenia 60 stopni
	// i zasiegu renderowania 0.01-100.0 jednostek.
	gluPerspective(60.0f, (float)width / height, .01f, 100.0f);
}