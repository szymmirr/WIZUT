#include "StdAfx.h"

// Zmienne statyczne pozwalaj¹ce na jednokrotne za³adowanie tekstury.
bool CWall::_isLoaded = false;
CTexture * CWall::_wallTexture = NULL;

// Konstruktor - wywo³ujemy konstruktor CSceneObject oraz ustawiamy wartoœci pocz¹tkowe
// na podstawie zadanych wspó³rzêdnych.
CWall::CWall(vec3 a, vec3 b, vec3 c, vec3 d) : CSceneObject()
{
	_displayListId = -1; // Na razie displaylisty jeszcze nie ma, utworzymy j¹ podczas inicjalizacji.
	v[0] = a;
	v[1] = b;
	v[2] = c;
	v[3] = d;
	collisionPolygon = new CCollisionPolygon(v, 4); // Stworzenie polygonu, który bêdzie wykorzystywany do wykrywania kolizji.
	collisionPolygon->parent = this; // Niech polygon pamiêta, do kogo przynale¿y.
	vec3::Cross((c-b), (a-b), n); // Obliczenie wektora normalnego œciany...
	n.Normalize(); // ...i jego normalizacja.
}

// Destruktor - sprz¹tamy po sobie.
CWall::~CWall(void)
{
	delete collisionPolygon;
}

// Inicjalizacja segmentu œciany.
void CWall::Initialize(void)
{
	_displayListId = glGenLists(1);
	
	// Utworzenie displaylisty na podstawie wspó³rzêdnych.
	glNewList(_displayListId, GL_COMPILE);
		glBegin(GL_QUADS);
		
			// Wektor normalny jest taki sam dla wszystkich wierzcho³ków.
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

	// Tekstura jest dla wszystkich instancji CWall taka sama - nie ma sensu ³adowaæ jej wielokrotnie do pamiêci.
	if (_isLoaded) {
		return;
	}
	_isLoaded = true;

	_wallTexture = new CTexture("Resources\\Box.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
	_wallTexture->Load();
}

// Aktualizacja stanu œciany.
void CWall::Update(void)
{
	// Œciana stoi i ma siê dobrze niezale¿nie od okolicznoœci.
}

// Rysowanie segmentu œciany.
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

	// Wywo³anie displaylisty.
	glCallList(_displayListId);

	glDisable(GL_TEXTURE_2D);

	// Narysuj wektor normalny dla tego segmentu œciany, jeœli u¿ytkownik sobie tego za¿yczy³ (klawisz "N").
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
