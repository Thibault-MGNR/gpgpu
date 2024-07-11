#include "GPGPU/texture.hpp"
#include <iostream>

Texture::Texture(){
	
}

// ------------------------------------------------------------------------

Texture::~Texture(){
	glDeleteTextures(1, &_index);
}

// ------------------------------------------------------------------------

void Texture::init(TextureParam param){
	_parameters = param;
	glGenTextures(1, &_index);
	glActiveTexture(_parameters.unit);
	glBindTexture(GL_TEXTURE_2D, _index);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, _parameters.param[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, _parameters.param[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, _parameters.param[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, _parameters.param[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, _parameters.dimension[0], _parameters.dimension[1], 0, GL_RGBA, GL_FLOAT, NULL);
	
	glBindImageTexture(_parameters.unit - GL_TEXTURE0, _index, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
}

// ------------------------------------------------------------------------

void Texture::bind(){
	glActiveTexture(_parameters.unit);
	glBindTexture(GL_TEXTURE_2D, _index);
}