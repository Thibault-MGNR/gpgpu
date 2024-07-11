#include "GPGPU/VBO.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VBO::VBO(){
	
}

void VBO::init(){
	glGenBuffers(1, &_index);
}

// ------------------------------------------------------------------------

VBO::~VBO(){
	glDeleteBuffers(1, &_index);
}

// ------------------------------------------------------------------------

void VBO::bind(){
	glBindBuffer(GL_ARRAY_BUFFER, _index);
}