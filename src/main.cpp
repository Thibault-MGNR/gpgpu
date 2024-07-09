#include "GPGPU/gladLoader.hpp"
#include "GPGPU/window.hpp"

#include "GPGPU/VAO.hpp"
#include "GPGPU/VBO.hpp"

#include "GPGPU/texture.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "GPGPU/shader.hpp"
#include "GPGPU/compute_shader.hpp"

#include <iostream>

void renderQuad();

const unsigned int TEXTURE_WIDTH = 1000, TEXTURE_HEIGHT = 1000;

int main()
{
	WindowParam param;
	Window window(param);
	Glad glad;

	int max_compute_work_group_count[3];
	int max_compute_work_group_size[3];
	int max_compute_work_group_invocations;

	for (int idx = 0; idx < 3; idx++) {
		glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, idx, &max_compute_work_group_count[idx]);
		glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, idx, &max_compute_work_group_size[idx]);
	}	
	glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &max_compute_work_group_invocations);
	
	Shader screenQuad("../src/shaders/vertex_shader.vs", "../src/shaders/fragment_shader.fs");
	ComputeShader computeShader("../src/shaders/computeShader.cs");

	screenQuad.use();
	screenQuad.setInt("tex", 2);

	TextureParam textParam;
	textParam.unit = GL_TEXTURE2;
	Texture texture(textParam);
	texture.bind();

	while (window.isNotClosed())
	{	
		computeShader.use();
		computeShader.setFloat("t", window.getTime());
		glDispatchCompute((unsigned int)TEXTURE_WIDTH/8, (unsigned int)TEXTURE_HEIGHT/8, 1);

		glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		screenQuad.use();
		
		renderQuad();

		window.update();
	}

	glDeleteProgram(screenQuad.ID);
	glDeleteProgram(computeShader.ID);

	return EXIT_SUCCESS;
}

unsigned int quadVAO = 0;
unsigned int quadVBO;
void renderQuad()
{
	if (quadVAO == 0)
	{
		float quadVertices[] = {
			// positions        // texture Coords
			-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
			 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		};
		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &quadVBO);
		glBindVertexArray(quadVAO);
		glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	}
	glBindVertexArray(quadVAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}