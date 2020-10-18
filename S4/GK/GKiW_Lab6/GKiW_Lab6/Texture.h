#pragma once

// Tekstura.
class CTexture
{
public:
	bool IsLoaded;

	CTexture(char *);
	CTexture(char *, int, int);
	~CTexture(void);
	bool Load(void);
	GLuint GetId(void);

protected:
	int _magFilter;
	int _minFilter;
	char * _file;
	GLuint _id;
};

