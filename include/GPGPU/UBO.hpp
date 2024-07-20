#pragma once

#include <glad/glad.h>
#include <vector>

class UBO{
    public:
        UBO(){

        }

        ~UBO(){
            glDeleteBuffers(1, &_ID);
        }

        void setUsage(GLenum usage){
            _usage = usage;
        }
    
        template<typename T>
        void init(const T* data, const unsigned int index){
            glGenBuffers(1, &_ID);
            glBindBuffer(GL_UNIFORM_BUFFER, _ID);
            glBufferData(GL_UNIFORM_BUFFER, sizeof(T), data, _usage);
            glBindBufferBase(GL_UNIFORM_BUFFER, index, _ID);
            glBindBuffer(GL_UNIFORM_BUFFER, 0);
        }

        void subData(unsigned int offset, unsigned int size, const GLvoid* data){
            glBindBuffer(GL_UNIFORM_BUFFER, _ID);
            glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
        };
    
    private:
        GLuint _ID;
        GLenum _usage;
};