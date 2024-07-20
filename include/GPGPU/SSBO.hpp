#pragma once

#include <glad/glad.h>
#include <vector>
#include <iostream>

class SSBO{
    public:
        SSBO(){

        }

        ~SSBO(){
            glDeleteBuffers(1, &_ID);
        }

        void setUsage(GLenum usage){
            _usage = usage;
        }
    
        template<typename T>
        void init(const std::vector<T>& data, const unsigned int index){
            int dataSize = data.size();

            glGenBuffers(1, &_ID);

            glBindBuffer(GL_SHADER_STORAGE_BUFFER, _ID);
            glBufferData(GL_SHADER_STORAGE_BUFFER, dataSize * sizeof(T), nullptr, _usage);
            glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, dataSize * sizeof(T), data.data());

            glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, _ID);
            glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
        }
    
    private:
        GLuint _ID;
        GLenum _usage;
};