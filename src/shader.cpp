#include "GPGPU/shader.hpp"


void Shader::use(){
    glUseProgram(ID); 
}

// ------------------------------------------------------------------------

void Shader::setBool(const std::string &name, const bool value) const {         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

// ------------------------------------------------------------------------

void Shader::setInt(const std::string &name, const int value) const { 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

// ------------------------------------------------------------------------

void Shader::setFloat(const std::string &name, const float value) const { 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
}

// ------------------------------------------------------------------------

void Shader::setVec2(const std::string &name, const glm::vec2 &value) const { 
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}

// ------------------------------------------------------------------------

void Shader::setVec2(const std::string &name, const float x, const float y) const { 
    glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y); 
}

// ------------------------------------------------------------------------

void Shader::setVec3(const std::string &name, const glm::vec3 &value) const { 
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}

// ------------------------------------------------------------------------

void Shader::setVec3(const std::string &name, const float x, const float y, const float z) const { 
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z); 
}

// ------------------------------------------------------------------------

void Shader::setVec4(const std::string &name, const glm::vec4 &value) const { 
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
}

// ------------------------------------------------------------------------

void Shader::setVec4(const std::string &name, float x, const float y, const float z, const float w) { 
    glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w); 
}

// ------------------------------------------------------------------------

void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const {
    glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

// ------------------------------------------------------------------------

void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const {
    glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

// ------------------------------------------------------------------------

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

// ------------------------------------------------------------------------

void Shader::checkCompileErrors(const GLuint shader, const std::string type){
    GLint success;
    GLchar infoLog[1024];
    if(type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

// ------------------------------------------------------------------------

Shader::~Shader(){
    glDeleteProgram(ID);
}

// ------------------------------------------------------------------------

std::string Shader::getCode(const GLchar* path){
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