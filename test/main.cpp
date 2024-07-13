#include <GPGPU/GPGPU.hpp>

class App: public GPGPU {
	public:
		void init(){
			setRenderView({1000.f, 1000.f}, 2);

			initGPGPU();
			_cs.init("../src/shaders/computeShader.glsl");
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

		ComputeShader _cs;
};

int main()
{
	App app;
	app.init();

	app.run();

	return EXIT_SUCCESS;
}