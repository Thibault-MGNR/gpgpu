#include "GPGPU/quadRenderer.hpp"
#include <glad/glad.h>

QuadRenderer::QuadRenderer(){
    
}

void QuadRenderer::init(){
    _vao.init();
    _vbo.init();
    
    _vao.bind();
    _vbo.bind();

    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
}

void QuadRenderer::renderQuad(){
    _vao.bind();
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}