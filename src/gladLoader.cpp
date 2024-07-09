#include <iostream>
#include "GPGPU/gladLoader.hpp"
#include <GLFW/glfw3.h>

Glad::Glad(){
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(EXIT_FAILURE);
	}
}