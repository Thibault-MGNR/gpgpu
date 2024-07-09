#include <iostream>
#include <GLFW/glfw3.h>
#include "GPGPU/window.hpp"

Window::Window(WindowParam param){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, param.context_version[0]);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, param.context_version[0]);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(param.screen_dim[0], param.screen_dim[0], param.title.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	GLFWframebuffersizefun *win;
	
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSwapInterval(0);

	fCounter = 0;
	lastFrame = 0;
	deltaTime = 0;
}

// ------------------------------------------------------------------------

Window::~Window(){
	glfwTerminate();
}

// ------------------------------------------------------------------------

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

// ------------------------------------------------------------------------

int Window::isNotClosed(){
	return !glfwWindowShouldClose(window);
}

// ------------------------------------------------------------------------

void Window::update(){
	float currentFrame = glfwGetTime();

	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
	if(fCounter > 500) {
		std::cout << "FPS: " << 1 / deltaTime << std::endl;
		fCounter = 0;
	} else {
		fCounter++;
	}	
	glfwSwapBuffers(window);
	glfwPollEvents();
}

// ------------------------------------------------------------------------

float Window::getTime(){
	return glfwGetTime();
}