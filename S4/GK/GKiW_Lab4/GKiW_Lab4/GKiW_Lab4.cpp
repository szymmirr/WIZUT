#include "stdafx.h"

#pragma region Zmienne globalne

SCameraState player;

double T = 0.0;

int mouseX = 0; // aktualna pozycja kursora myszy (x)
int mouseY = 0; // aktualna pozycja kursora myszy (y)

bool captureMouse = true; // czy przechwytywaæ kursor myszy?
bool free3DMovement = false; // czy pozwoliæ na ruch w 3D?

float mouseSensitivity = .15f; // czu³oœæ na ruchy kursora myszy

#pragma endregion

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("GKiW: Lab 4");

	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyUp);
	glutPassiveMotionFunc(OnMouseMove);
	glutMotionFunc(OnMouseMove);
	glutTimerFunc(17, OnTimer, 0);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE); // W³¹czenie cullingu - rysowania tylko jednej strony wielok¹tów
	glCullFace(GL_BACK); // Okreœlenie, któr¹ stronê wielok¹tów chcemy ukrywaæ
	glFrontFace(GL_CCW); // Okreœlenie, jaki kierunek definicji wierzcho³ków oznacza przód wielok¹tu (GL_CCW - przeciwnie do ruchu wskazówek zegara, GL_CW - zgodnie)

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	float gl_amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gl_amb);

	player.pos.x = 0.0f;
	player.pos.y = 1.0f;
	player.pos.z = 4.0f;

	player.dir.x = 0.0f;
	player.dir.y = 0.0f;
	player.dir.z = -1.0f;

	player.speed = .4f;

	// Ustawienie obs³ugi myszy
	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2); // Przesuniêcie kursora na œrodek ekranu
	mouseX = glutGet(GLUT_WINDOW_WIDTH) / 2;
	mouseY = glutGet(GLUT_WINDOW_HEIGHT) / 2;
	glutSetCursor(GLUT_CURSOR_NONE); // Ukrycie kursora

	glutMainLoop();

	return 0;
}

#pragma region Obsluga wejscia

bool keystate[255];

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
	if (key == 'm' || key == 'M') { // W³¹czenie/wy³¹czenie przechwytywania kursora myszy - "uwalnia" mysz
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
	if (key == 'l' || key == 'L') { // "Odklejenie" kamery od pod³ogi
		free3DMovement = !free3DMovement;
	}
}

void OnKeyUp(unsigned char key, int x, int y) {
	keystate[key] = false;
}

// Zapamiêtanie pozycji kursora myszy w momencie, gdy nastêpuje jego przesuniêcie.
// Zapamiêtana pozycja jest póŸniej "konsumowana" przez OnTimer().
void OnMouseMove(int x, int y) {
	mouseX = x;
	mouseY = y;
}

#pragma endregion

void OnTimer(int id) {

	glutTimerFunc(17, OnTimer, 0);

#pragma region Ruch kamery

	if (captureMouse) {
		player.velRY = -mouseSensitivity * (glutGet(GLUT_WINDOW_WIDTH) / 2 - mouseX);
		player.velRX = mouseSensitivity * (glutGet(GLUT_WINDOW_HEIGHT) / 2 - mouseY);
		glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
	}

	if (keystate['w']) {
		player.velM = player.speed;
	}
	if (keystate['s']) {
		player.velM = -player.speed;
	}
	if (keystate['a']) {
		player.velS = -player.speed;
	}
	if (keystate['d']) {
		player.velS = player.speed;
	}
	if (keystate['q']) {
		player.velRY = -player.speed;
	}
	if (keystate['e']) {
		player.velRY = player.speed;
	}
	if (keystate['f']) {
		player.velRX = -player.speed;
	}
	if (keystate['c']) {
		player.velRX = player.speed;
	}

	// Obrót kamery (wsp. sferyczne):
	float T = acos(player.dir.y);
	float G = atan2(player.dir.z, player.dir.x);
	T -= player.velRX * .03f;
	G += player.velRY * .03f;
	player.dir.x = sin(T) * cos(G);
	player.dir.y = cos(T);
	player.dir.z = sin(T) * sin(G);

	// Wektor prostopad³y:
	vec3 per;
	per.x = -player.dir.z;
	per.y = 0;
	per.z = player.dir.x;

	// Ruch przod/tyl:
	player.pos.x += player.dir.x * player.velM * .1f;
	if (free3DMovement) {
		player.pos.y += player.dir.y * player.velM * .1f;
	}
	else {
		player.pos.y = 1.0f;
	}
	player.pos.z += player.dir.z * player.velM * .1f;

	// Ruch na boki:
	player.pos.x += per.x * player.velS * .1f;
	if (free3DMovement) {
		player.pos.y += player.dir.y * player.velM * .1f;
	}
	else {
		player.pos.y = 1.0f;
	}
	player.pos.z += per.z * player.velS * .1f;

	// Inercja:
	player.velRX /= 1.2;
	player.velRY /= 1.2;
	player.velM /= 1.2;
	player.velS /= 1.2;

#pragma endregion
}

void OnRender() {

	T = glutGet(GLUT_ELAPSED_TIME);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		player.pos.x, player.pos.y, player.pos.z,
		player.pos.x + player.dir.x, player.pos.y + player.dir.y, player.pos.z + player.dir.z,
		0.0f, 1.0f, 0.0f
	);

#pragma region Swiatlo
	float l0_amb[] = { 0.2f, 0.2f, 0.2f };
	float l0_dif[] = { 0.6f, 0.6f, 0.6f };
	float l0_spe[] = { 1.0f, 1.0f, 1.0f };
	float l0_pos[] = { 1.0f, 5.0f, 4.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, l0_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l0_spe);
	glLightfv(GL_LIGHT0, GL_POSITION, l0_pos);
#pragma endregion

#pragma region Skrzynia

	glPushMatrix();

	glTranslatef(0.0f, 0.5f, 0.0f);
	glScalef(0.2f, 0.2f, 0.2f);

	float m3_amb[] = { 0.8f, 0.8f, 0.2f };
	float m3_dif[] = { 0.8f, 0.8f, 0.2f };
	float m3_spe[] = { 0.0f, 0.0f, 0.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, m3_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m3_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m3_spe);

	glBegin(GL_QUADS);

	// Przod
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	// Tyl
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	// Lewa
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	// Prawa
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	// Gora
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	// Dol
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	glEnd();
	
	int triangleAmount = 50;
	GLfloat radius = 1.0f; //radius
	GLfloat twicePi = 2.0 * PI;

	glBegin(GL_TRIANGLE_FAN);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 0.0f);
	for (int i = 0; i <= triangleAmount; i++)
	{
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(
			2.0f,
			1.0f + (radius * cos(i *  twicePi / triangleAmount)),
			0.0f + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 0.0f);
	for (int i = 0; i <= triangleAmount; i++)
	{
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(
			-2.0f,
			1.0f + (radius * cos(i *  twicePi / triangleAmount)),
			-(0.0f + (radius * sin(i * twicePi / triangleAmount)))
		);
	}
	glEnd();

	glEnd();

	glBegin(GL_QUAD_STRIP);

	//Wieko gora

	for (int i = 0; i <= triangleAmount; i++)
	{
		float x = sin(2.0f * PI * ((float)i / triangleAmount));
		float z = cos(2.0f * PI * ((float)i / triangleAmount));

		glNormal3f((sin(2.0f * PI * ((float)i / triangleAmount))), 0.0f, (0.0f + cos(2.0f * PI * ((float)i / triangleAmount))));
		glVertex3f(
			-2.0f,
			1.0f + sin(2.0f * PI * ((float)i / triangleAmount)),
			0.0f + cos(2.0f * PI * ((float)i / triangleAmount))
		);
		glNormal3f((sin(2.0f * PI * ((float)i / triangleAmount))), 0.0f, (0.0f + cos(2.0f * PI * ((float)i / triangleAmount))));
		glVertex3f(
			2.0f,
			1.0f + sin(2.0f * PI * ((float)i / triangleAmount)),
			0.0f + cos(2.0f * PI * ((float)i / triangleAmount))
		);
	}
	glEnd();
	glPopMatrix();

#pragma endregion

#pragma region Skrzynia2

	glPushMatrix();

	glTranslatef(1.2f, 0.5f, 0.3f);
	glScalef(0.2f, 0.2f, 0.2f);
	glRotatef(30, 0.0, -1.0, 0.0);

	float m4_amb[] = { 0.8f, 0.8f, 0.2f };
	float m4_dif[] = { 0.8f, 0.8f, 0.2f };
	float m4_spe[] = { 0.0f, 0.0f, 0.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, m4_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m4_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m4_spe);

	glBegin(GL_QUADS);

	// Przod
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	// Tyl
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	// Lewa
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	// Prawa
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	// Gora
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	// Dol
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 0.0f);
	for (int i = 0; i <= triangleAmount; i++)
	{
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(
			2.0f,
			1.0f + (radius * cos(i *  twicePi / triangleAmount)),
			0.0f + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 0.0f);
	for (int i = 0; i <= triangleAmount; i++)
	{
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(
			-2.0f,
			1.0f + (radius * cos(i *  twicePi / triangleAmount)),
			-(0.0f + (radius * sin(i * twicePi / triangleAmount)))
		);
	}
	glEnd();

	glEnd();

	glBegin(GL_QUAD_STRIP);

	//Wieko gora

	for (int i = 0; i <= triangleAmount; i++)
	{
		float x = sin(2.0f * PI * ((float)i / triangleAmount));
		float z = cos(2.0f * PI * ((float)i / triangleAmount));

		glNormal3f((sin(2.0f * PI * ((float)i / triangleAmount))), 0.0f, (0.0f + cos(2.0f * PI * ((float)i / triangleAmount))));
		glVertex3f(
			-2.0f,
			1.0f + sin(2.0f * PI * ((float)i / triangleAmount)),
			0.0f + cos(2.0f * PI * ((float)i / triangleAmount))
		);
		glNormal3f((sin(2.0f * PI * ((float)i / triangleAmount))), 0.0f, (0.0f + cos(2.0f * PI * ((float)i / triangleAmount))));
		glVertex3f(
			2.0f,
			1.0f + sin(2.0f * PI * ((float)i / triangleAmount)),
			0.0f + cos(2.0f * PI * ((float)i / triangleAmount))
		);
	}
	glEnd();
	glPopMatrix();

#pragma endregion

#pragma region Skrzynia3

	glPushMatrix();
	glTranslatef(-1.2f, 0.5f, 0.3f);
	glScalef(0.2f, 0.2f, 0.2f);
	glRotatef(30, 0.0, 1.0, 0.0);

	float m5_amb[] = { 0.8f, 0.8f, 0.2f };
	float m5_dif[] = { 0.2f, 0.5f, 0.2f };
	float m5_spe[] = { 0.0f, 0.0f, 0.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, m5_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m5_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m5_spe);

	glBegin(GL_QUADS);

	// Przod
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	// Tyl
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	// Lewa
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	// Prawa
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	// Gora
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	// Dol
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, -1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, 1.0f);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 1.0f, 0.0f);
	for (int i = 0; i <= triangleAmount; i++)
	{
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(
			2.0f,
			1.0f + (radius * cos(i *  twicePi / triangleAmount)),
			0.0f + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 1.0f, 0.0f);
	for (int i = 0; i <= triangleAmount; i++)
	{
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(
			-2.0f,
			1.0f + (radius * cos(i *  twicePi / triangleAmount)),
			-(0.0f + (radius * sin(i * twicePi / triangleAmount)))
		);
	}
	glEnd();

	glEnd();

	glBegin(GL_QUAD_STRIP);

	//Wieko gora

	for (int i = 0; i <= triangleAmount; i++)
	{
		float x = sin(2.0f * PI * ((float)i / triangleAmount));
		float z = cos(2.0f * PI * ((float)i / triangleAmount));

		glNormal3f((sin(2.0f * PI * ((float)i / triangleAmount))), 0.0f, (0.0f + cos(2.0f * PI * ((float)i / triangleAmount))));
		glVertex3f(
			-2.0f,
			1.0f + sin(2.0f * PI * ((float)i / triangleAmount)),
			0.0f + cos(2.0f * PI * ((float)i / triangleAmount))
		);
		glNormal3f((sin(2.0f * PI * ((float)i / triangleAmount))), 0.0f, (0.0f + cos(2.0f * PI * ((float)i / triangleAmount))));
		glVertex3f(
			2.0f,
			1.0f + sin(2.0f * PI * ((float)i / triangleAmount)),
			0.0f + cos(2.0f * PI * ((float)i / triangleAmount))
		);
	}
	glEnd();
	glPopMatrix();

#pragma endregion
	

#pragma region Sciany

	glBegin(GL_QUADS);

#pragma region Przednia sciana
	{
		float m_amb[] = { 1.0f, 1.0f, 1.0f };
		float m_dif[] = { 1.0f, 1.0f, 1.0f };
		float m_spe[] = { 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, m_spe);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-5.0f, 5.0f, -5.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-5.0f, 0.0f, -5.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(5.0f, 0.0f, -5.0f);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(5.0f, 5.0f, -5.0f);
	}
#pragma endregion

#pragma region Lewa sciana
	{
		float m_amb[] = { 1.0f, 0.0f, 0.0f };
		float m_dif[] = { 1.0f, 0.0f, 0.0f };
		float m_spe[] = { 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, m_spe);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-5.0f, 0.0f, -5.0f);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-5.0f, 5.0f, -5.0f);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-5.0f, 5.0f, 5.0f);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-5.0f, 0.0f, 5.0f);
	}
#pragma endregion

#pragma region Prawa sciana
	{
		float m_amb[] = { 0.0f, 1.0f, 0.0f };
		float m_dif[] = { 0.0f, 1.0f, 0.0f };
		float m_spe[] = { 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, m_spe);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(5.0f, 5.0f, -5.0f);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(5.0f, 0.0f, -5.0f);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(5.0f, 0.0f, 5.0f);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(5.0f, 5.0f, 5.0f);
	}
#pragma endregion

#pragma region Tylna sciana
	{
		float m_amb[] = { 1.0f, 1.0f, 1.0f };
		float m_dif[] = { 1.0f, 1.0f, 1.0f };
		float m_spe[] = { 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, m_spe);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(-5.0f, 0.0f, 5.0f);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(-5.0f, 5.0f, 5.0f);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(5.0f, 5.0f, 5.0f);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(5.0f, 0.0f, 5.0f);
	}
#pragma endregion

#pragma region Podloga
	{
		float m_amb[] = { 1.0f, 1.0f, 1.0f };
		float m_dif[] = { 1.0f, 1.0f, 1.0f };
		float m_spe[] = { 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, m_spe);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-5.0f, 0.0f, -5.0f);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-5.0f, 0.0f, 5.0f);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(5.0f, 0.0f, 5.0f);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(5.0f, 0.0f, -5.0f);
	}
#pragma endregion

#pragma region Sufit
	{
		float m_amb[] = { 1.0f, 1.0f, 1.0f };
		float m_dif[] = { 1.0f, 1.0f, 1.0f };
		float m_spe[] = { 0.0f, 0.0f, 0.0f };
		glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, m_dif);
		glMaterialfv(GL_FRONT, GL_SPECULAR, m_spe);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-5.0f, 5.0f, 5.0f);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(-5.0f, 5.0f, -5.0f);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(5.0f, 5.0f, -5.0f);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(5.0f, 5.0f, 5.0f);
	}
#pragma endregion

	glEnd();

#pragma endregion

	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();

}

void OnReshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(60.0f, (float)width / height, .01f, 100.0f);
}