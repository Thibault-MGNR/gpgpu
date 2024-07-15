#include <iostream>
#include <GLFW/glfw3.h>
#include "GPGPU/window.hpp"

Window::Window(){

}

// ------------------------------------------------------------------------

void Window::init(WindowParam param){
	_windowParameters = param;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, param.context_version[0]);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, param.context_version[0]);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	_window = glfwCreateWindow(param.screen_dim[0], param.screen_dim[0], param.title.c_str(), NULL, NULL);
	if (_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(_window);

	GLFWframebuffersizefun *win;
	
	glfwSetFramebufferSizeCallback(_window, _framebufferSizeCallBack);
	glfwSwapInterval(1);

	_fCounter = 0;
	_lastFrame = 0;
	_deltaTime = 0;
}

// ------------------------------------------------------------------------

Window::~Window(){
	glfwTerminate();
}

// ------------------------------------------------------------------------

void Window::_framebufferSizeCallBack(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

// ------------------------------------------------------------------------

int Window::isNotClosed(){
	return !glfwWindowShouldClose(_window);
}

// ------------------------------------------------------------------------

void Window::update(){
	float currentFrame = glfwGetTime();

	_deltaTime = currentFrame - _lastFrame;
	_lastFrame = currentFrame;
	if(_fCounter > 500) {
		std::cout << "FPS: " << 1 / _deltaTime << std::endl;
		_fCounter = 0;
	} else {
		_fCounter++;
	}	
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

// ------------------------------------------------------------------------

float Window::getTime(){
	return glfwGetTime();
}

// ------------------------------------------------------------------------

glm::vec2 Window::getCurrentCursorPos(){
	double posX, posY;
	glfwGetCursorPos(_window, &posX, &posY);
	return glm::vec2{float(posX), float(_windowParameters.screen_dim[1]) - float(posY)};
}