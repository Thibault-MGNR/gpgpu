#include "GPGPU/graphicShader.hpp"

GraphicShader::GraphicShader(){
	
}

// ------------------------------------------------------------------------

void GraphicShader::initProgram(){
	ID = glCreateProgram();
	glAttachShader(ID, _vertex);
	glAttachShader(ID, _fragment);
	glLinkProgram(ID);
	checkCompileErrors(ID, "PROGRAM");
	
	glDeleteShader(_vertex);
	glDeleteShader(_fragment);
}

// ------------------------------------------------------------------------

void GraphicShader::initVertexShader(){
	const char* vShaderCode = "#version 460 core\n	\
	layout (location = 0) in vec3 aPos;				\
	layout (location = 1) in vec2 aTexCoords;		\
	out vec2 TexCoords;\n							\
	void main()										\
	{												\
		TexCoords = aTexCoords;						\
		gl_Position = vec4(aPos, 1.0);				\
	}";

	_vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertex, 1, &vShaderCode, NULL);
	glCompileShader(_vertex);
	checkCompileErrors(_vertex, "VERTEX");
}

// ------------------------------------------------------------------------

void GraphicShader::initFragmentShader(){
	const char* fShaderCode = "#version 460 core\n		\
	out vec4 FragColor;									\
	in vec2 TexCoords;									\
	uniform sampler2D tex;\n							\
	void main(){             							\
		vec3 texCol = texture(tex, TexCoords).rgb;      \
		FragColor = vec4(texCol, 1.0);					\
	}";
	
	_fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_fragment, 1, &fShaderCode, NULL);
	glCompileShader(_fragment);
	checkCompileErrors(_fragment, "FRAGMENT");
}