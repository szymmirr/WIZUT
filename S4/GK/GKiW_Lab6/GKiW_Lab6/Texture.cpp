#include "StdAfx.h"
#include "Texture.h"


CTexture::CTexture(char * file)
{
	IsLoaded = false;
	_id = -1;
	_file = file;
	_magFilter = GL_LINEAR;
	_minFilter = GL_LINEAR;
}

CTexture::CTexture(char * file, int magFilter, int minFilter)
{
	IsLoaded = false;
	_id = -1;
	_file = file;
	_magFilter = magFilter;
	_minFilter = minFilter;
}

bool CTexture::Load(void)
{
	Bitmap *tex = new Bitmap();
	if (!tex->loadBMP(_file)) {
		printf("ERROR: Cannot read texture file \"%s\".\n", _file);
		return false;
	}

	glGenTextures(1, &_id);

	glBindTexture(GL_TEXTURE_2D, _id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _magFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _minFilter);

	if (_minFilter == GL_LINEAR_MIPMAP_LINEAR || _minFilter == GL_LINEAR_MIPMAP_NEAREST) {
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, tex->width, tex->height, GL_RGB, GL_UNSIGNED_BYTE, tex->data);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex->data);
	}

	delete tex;

	IsLoaded = true;

	return true;
}


CTexture::~CTexture(void)
{
}


GLuint CTexture::GetId(void)
{
	if (!IsLoaded) {
		Load();
	}
	return _id;
}
