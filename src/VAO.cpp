#include "GPGPU/VAO.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

VAO::VAO(){
	
}

// ------------------------------------------------------------------------

void VAO::init(){
	glGenVertexArrays(1, &_index);
}

// ------------------------------------------------------------------------

VAO::~VAO(){
	glDeleteVertexArrays(1, &_index);
}

// ------------------------------------------------------------------------

void VAO::bind(){
	glBindVertexArray(_index);
}