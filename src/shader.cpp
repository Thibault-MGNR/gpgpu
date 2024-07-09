#include "GPGPU/shader.hpp"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath){
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	try {
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		
		vShaderFile.close();
		fShaderFile.close();
		
		vertexCode   = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure& e){
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();
	
	unsigned int vertex, fragment;
	
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, "VERTEX");
	
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, "FRAGMENT");
	
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");
	
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

// ------------------------------------------------------------------------

Shader::~Shader(){
	glDeleteProgram(ID);
}

// ------------------------------------------------------------------------


void Shader::use(){ 
	glUseProgram(ID); 
}

// ------------------------------------------------------------------------

void Shader::setBool(const std::string &name, bool value) const{         
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

// ------------------------------------------------------------------------

void Shader::setInt(const std::string &name, int value) const{ 
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

// ------------------------------------------------------------------------

void Shader::setFloat(const std::string &name, float value) const{ 
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
}

// ------------------------------------------------------------------------

void Shader::checkCompileErrors(unsigned int shader, std::string type){
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}
