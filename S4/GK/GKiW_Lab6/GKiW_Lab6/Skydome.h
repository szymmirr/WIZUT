#pragma once

// Skydome, czyli oteksturowana pó³kula imituj¹ca niebo.
class CSkydome : public CSceneObject
{
public:
	CSkydome(void);
	~CSkydome(void);
	void Initialize(void);
	void Update(void);
	void Render(void);

protected:
	GLuint _displayListId;
	CTexture * _skyTexture;
};

