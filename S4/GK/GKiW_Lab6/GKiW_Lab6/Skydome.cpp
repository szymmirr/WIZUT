#include "StdAfx.h"
#include "Skydome.h"


CSkydome::CSkydome(void) : CSceneObject()
{
}


CSkydome::~CSkydome(void)
{
}

void CSkydome::Initialize(void)
{
	_skyTexture = new CTexture("Resources\\Skydome.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
	_skyTexture->Load();

	_displayListId = glGenLists(1);

	int Np = 36;
	float radius = 20.0f;
	
	glNewList(_displayListId, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
			for (int j = -1; j < Np / 2; ++j) {
				for (int i = 0; i <= Np; ++i) {

					float t1 = PI * j / Np - PI / 2;
					float t2 = PI * (j+1) / Np - PI / 2;
					float p = PI * 2.0f * i / Np;

					float tx1 = sin(t1) * cos(p);
					float tx2 = sin(t2) * cos(p);
					float tz1 = sin(t1) * sin(p);
					float tz2 = sin(t2) * sin(p);
					float ty1 = cos(t1);
					float ty2 = cos(t2);
					
					float tr1 = -sin(t1);
					float tr2 = -sin(t2);

					float x1 = radius * tx1;
					float x2 = radius * tx2;
					float z1 = radius * tz1;
					float z2 = radius * tz2;
					float y1 = radius * ty1;
					float y2 = radius * ty2;

					glTexCoord2f(.5f + .5f * tr2 * tx2, .5f + .5f * tr2 * tz2);
					glNormal3f(x2, y2, z2);
					glVertex3f(x2, y2, z2);
					
					glTexCoord2f(.5f + .5f * tr1 * tx1, .5f + .5f * tr1 * tz1);
					glNormal3f(x1, y1, z1);
					glVertex3f(x1, y1, z1);

				}
			}
		glEnd();
	glEndList();
}

void CSkydome::Update(void)
{
	Rotation.y += .05f;
}

void CSkydome::Render(void)
{
	glPushMatrix();

	glTranslatef(Position.x, Position.y, Position.z);
	glRotatef(Rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(Rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(Rotation.z, 0.0f, 0.0f, 1.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _skyTexture->GetId());
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glCallList(_displayListId);

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}
