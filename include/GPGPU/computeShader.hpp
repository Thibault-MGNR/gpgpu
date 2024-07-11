#ifndef COMPUTE_SHADER_H
#define COMPUTE_SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "GPGPU/shader.hpp"

class ComputeShader : public Shader{
    public:
        ComputeShader();
        void init(const char* computePath);
};
#endif