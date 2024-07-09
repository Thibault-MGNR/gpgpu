#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> 
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "GPGPU/shader.hpp"

class GraphicShader : public Shader{
	public:
		GraphicShader(const GLchar* vertexPath, const GLchar* fragmentPath);
};

#endif