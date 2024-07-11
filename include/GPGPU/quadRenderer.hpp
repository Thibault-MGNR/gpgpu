#pragma once

#include "VAO.hpp"
#include "VBO.hpp"

class QuadRenderer {
    public:
        QuadRenderer();

        void init();
        void renderQuad();
    
    private:
        VAO _vao;
        VBO _vbo;
        float quadVertices[5*4] = {
			// positions        // texture Coords
			-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
			 1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		};
};