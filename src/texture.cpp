#include "GPGPU/texture.hpp"
#include <iostream>

Texture::Texture(TextureParam param): parameters(param){
	glGenTextures(1, &index);
	glActiveTexture(parameters.unit);
	glBindTexture(GL_TEXTURE_2D, index);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, parameters.param[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, parameters.param[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, parameters.param[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, parameters.param[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, parameters.dimension[0], parameters.dimension[1], 0, GL_RGBA, GL_FLOAT, NULL);
	
	glBindImageTexture(parameters.unit - GL_TEXTURE0, index, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
}

// ------------------------------------------------------------------------

Texture::~Texture(){
	glDeleteTextures(1, &index);
}

// ------------------------------------------------------------------------

void Texture::bind(){
	glActiveTexture(parameters.unit);
	glBindTexture(GL_TEXTURE_2D, index);
}