#include "GPGPU/GPGPU.hpp"

class App: public GPGPU {
	public:
		void init(){
			setRenderView({1000.f, 1000.f}, 2);

			initComputeShader("../src/shaders/computeShader.cs");
		}

		~App() {

		}

	private:
		virtual void renderFrame() override {
			_cs.use();
			_cs.setFloat("t", _window.getTime());
			glDispatchCompute((unsigned int)1000/8, (unsigned int)1000/8, 1);

			glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
		}
};

int main()
{
	App app;
	app.init();

	app.run();

	return EXIT_SUCCESS;
}