#include "GPGPU/GPGPU.hpp"

int main()
{
	GPGPU app;

	app.setRenderView({1000.f, 1000.f}, 2);

	app.init("../src/shaders/computeShader.cs");

	app.run();

	return EXIT_SUCCESS;
}