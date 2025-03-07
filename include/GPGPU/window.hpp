#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>

struct WindowParam {
	std::vector<unsigned int> screen_dim = {1000, 1000};
	std::vector<unsigned int> context_version = {4, 6};
	std::string title = "Window";
	unsigned int MAX_FPS = 60;
	bool showFPS = false;
};

class Window{
	public:
        Window();
		~Window();
		void init(WindowParam param);
		int isNotClosed();
		void update();
		float getTime();
		glm::vec2 getCurrentCursorPos();
	
	private:
		WindowParam _windowParameters;
		int _fCounter;
		float _deltaTime;
		float _lastFrame;
		GLFWwindow* _window;
		static void _framebufferSizeCallBack(GLFWwindow* window, int width, int height);
};