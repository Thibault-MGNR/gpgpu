#include "GPGPU/graphicShader.hpp"

GraphicShader::GraphicShader(){
	
}

void GraphicShader::initProgram(){
	ID = glCreateProgram();
	glAttachShader(ID, _vertex);
	glAttachShader(ID, _fragment);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");
	
	glDeleteShader(_vertex);
	glDeleteShader(_fragment);
}

void GraphicShader::initVertexShader(const GLchar* vertexPath){
	std::string stdStrCode = getCode(vertexPath);
	const char* vShaderCode = stdStrCode.c_str();

	_vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertex, 1, &vShaderCode, NULL);
	glCompileShader(_vertex);
	checkCompileErrors(_vertex, "VERTEX");
}

void GraphicShader::initFragmentShader(const GLchar* fragmentPath){
	std::string stdStrCode = getCode(fragmentPath);
	const char* fShaderCode = stdStrCode.c_str();
	
	_fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_fragment, 1, &fShaderCode, NULL);
	glCompileShader(_fragment);
	checkCompileErrors(_fragment, "FRAGMENT");
}

std::string GraphicShader::getCode(const GLchar* path){
	std::string code;
	std::ifstream file;

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		file.open(path);
		std::stringstream shaderStream;

		shaderStream << file.rdbuf();
		
		file.close();
		
		code = shaderStream.str();
	}
	catch (std::ifstream::failure& e){
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
	}

	return code;
}