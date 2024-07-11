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
		GraphicShader();
		void initVertexShader(const GLchar* vertexPath);
		void initFragmentShader(const GLchar* fragmentPath);
		void initProgram();
	
	private:
		std::string getCode(const GLchar* path);
		unsigned int _vertex, _fragment;

};
#endif