#include "StdAfx.h"

// Zmienne statyczne pozwalaj�ce na jednokrotne za�adowanie tekstury.
bool CWall::_isLoaded = false;
CTexture * CWall::_wallTexture = NULL;

// Konstruktor - wywo�ujemy konstruktor CSceneObject oraz ustawiamy warto�ci pocz�tkowe
// na podstawie zadanych wsp�rz�dnych.
CWall::CWall(vec3 a, vec3 b, vec3 c, vec3 d) : CSceneObject()
{
	_displayListId = -1; // Na razie displaylisty jeszcze nie ma, utworzymy j� podczas inicjalizacji.
	v[0] = a;
	v[1] = b;
	v[2] = c;
	v[3] = d;
	collisionPolygon = new CCollisionPolygon(v, 4); // Stworzenie polygonu, kt�ry b�dzie wykorzystywany do wykrywania kolizji.
	collisionPolygon->parent = this; // Niech polygon pami�ta, do kogo przynale�y.
	vec3::Cross((c-b), (a-b), n); // Obliczenie wektora normalnego �ciany...
	n.Normalize(); // ...i jego normalizacja.
}

// Destruktor - sprz�tamy po sobie.
CWall::~CWall(void)
{
	delete collisionPolygon;
}

// Inicjalizacja segmentu �ciany.
void CWall::Initialize(void)
{
	_displayListId = glGenLists(1);
	
	// Utworzenie displaylisty na podstawie wsp�rz�dnych.
	glNewList(_displayListId, GL_COMPILE);
		glBegin(GL_QUADS);
		
			// Wektor normalny jest taki sam dla wszystkich wierzcho�k�w.
			glNormal3f( n.x, n.y, n.z);

			glTexCoord2f( 1.0f, 0.0f );
			glVertex3f(v[0].x, v[0].y, v[0].z);
				
			glTexCoord2f( 1.0f, 1.0f );
			glVertex3f(v[1].x, v[1].y, v[1].z);
			
			glTexCoord2f( 0.0f, 1.0f );
			glVertex3f(v[2].x, v[2].y, v[2].z);

			glTexCoord2f( 0.0f, 0.0f );
			glVertex3f(v[3].x, v[3].y, v[3].z);
			
		glEnd();
	glEndList();

	// Tekstura jest dla wszystkich instancji CWall taka sama - nie ma sensu �adowa� jej wielokrotnie do pami�ci.
	if (_isLoaded) {
		return;
	}
	_isLoaded = true;

	_wallTexture = new CTexture("Resources\\Box.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
	_wallTexture->Load();
}

// Aktualizacja stanu �ciany.
void CWall::Update(void)
{
	// �ciana stoi i ma si� dobrze niezale�nie od okoliczno�ci.
}

// Rysowanie segmentu �ciany.
void CWall::Render(void)
{
	glPushMatrix();

	float mA[] = { 1.0f, 1.0f, 1.0f };
	float mS[] = { 0.0f, 0.0f, 0.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mA);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mS);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _wallTexture->GetId());
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Wywo�anie displaylisty.
	glCallList(_displayListId);

	glDisable(GL_TEXTURE_2D);

	// Narysuj wektor normalny dla tego segmentu �ciany, je�li u�ytkownik sobie tego za�yczy� (klawisz "N").
	if (Scene->DrawNormals) {
		glDisable(GL_LIGHTING);
		vec3 c = (v[0] + v[1] + v[2] + v[3]) * .25f;
		glColor3f(1.0f, 1.0f, 0.0f);
		glLineWidth(3.0f);
		glBegin(GL_LINES);
			glVertex3f(c.x, c.y, c.z);
			glVertex3f(c.x + n.x * .5f, c.y + n.y * .5f, c.z + n.z * .5f);
		glEnd();
		glEnable(GL_LIGHTING);
	}

	glPopMatrix();
}
