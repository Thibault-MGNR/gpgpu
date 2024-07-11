#pragma once
#include <GLFW/glfw3.h>
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
	
	private:
		int fCounter;
		float deltaTime;
		float lastFrame;
		GLFWwindow* window;
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};