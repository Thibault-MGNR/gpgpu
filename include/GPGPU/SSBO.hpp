#pragma once

#include <glad/glad.h>
#include <vector>

class SSBO{
    public:
        SSBO(){

        }

        ~SSBO(){
            glDeleteBuffers(1, &_ID);
        }
    
        template<typename T>
        void init(const std::vector<T>& data, const unsigned int index){
            glGenBuffers(1, &_ID);
            glBindBuffer(GL_SHADER_STORAGE_BUFFER, _ID);
            glBufferData(GL_SHADER_STORAGE_BUFFER, data.size() * sizeof(T), data.data(), GL_DYNAMIC_COPY);
            glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, _ID);
            glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
        }
    
    private:
        GLuint _ID;
};