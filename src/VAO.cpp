#include "GPGPU/VAO.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

VAO::VAO(){
	glGenVertexArrays(1, &index);
}

// ------------------------------------------------------------------------

VAO::~VAO(){
	glDeleteVertexArrays(1, &index);
}

// ------------------------------------------------------------------------

void VAO::bind(){
	glBindVertexArray(index);
}