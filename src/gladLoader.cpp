#include <iostream>
#include "GPGPU/gladLoader.hpp"
#include <GLFW/glfw3.h>

Glad::Glad(){
}

void Glad::init(){
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(EXIT_FAILURE);
	}
}