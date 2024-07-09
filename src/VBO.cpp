#include "GPGPU/VBO.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VBO::VBO(){
	glGenBuffers(1, &index);
}

// ------------------------------------------------------------------------

VBO::~VBO(){
	glDeleteBuffers(1, &index);
}

// ------------------------------------------------------------------------

void VBO::bind(){
	glBindBuffer(GL_ARRAY_BUFFER, index);
}