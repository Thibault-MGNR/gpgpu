#include "GPGPU/computeShader.hpp"

ComputeShader::ComputeShader(){
    
}

// ------------------------------------------------------------------------

void ComputeShader::init(const char* computePath){
    // 1. retrieve the vertex/fragment source code from filePath
    std::string computeCode = getCode(computePath);

    const char* cShaderCode = computeCode.c_str();
    // 2. compile shaders
    unsigned int compute;
    // compute shader
    compute = glCreateShader(GL_COMPUTE_SHADER);
    glShaderSource(compute, 1, &cShaderCode, NULL);
    glCompileShader(compute);
    Shader::checkCompileErrors(compute, "COMPUTE");
    
    // shader Program
    ID = glCreateProgram();
    glAttachShader(ID, compute);
    glLinkProgram(ID);
    Shader::checkCompileErrors(ID, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(compute);
}
