#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class TextureParam{
	public:
		struct {
			int dimension[2] = {1000, 1000};
			GLenum unit = GL_TEXTURE0;
			GLint param[2] = {GL_CLAMP_TO_EDGE, GL_LINEAR};
		};
};

class Texture{
	public:
		Texture(TextureParam param);
		~Texture();
		void bind();
	
	private:
		unsigned int index;
		TextureParam parameters;
};