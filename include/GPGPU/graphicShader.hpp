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
		void initVertexShader();
		void initFragmentShader();
		void initProgram();
	
	private:
		unsigned int _vertex, _fragment;

};
#endif