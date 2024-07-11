#include "GPGPU/GPGPU.hpp"

GPGPU::GPGPU(){

}

void GPGPU::init(const std::string path){
    for (int idx = 0; idx < 3; idx++) {
		glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, idx, &_max_compute_work_group_count[idx]);
		glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, idx, &_max_compute_work_group_size[idx]);
	}	
	glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &_max_compute_work_group_invocations);
    _cs.init(path.c_str());
}

// ------------------------------------------------------------------------

void GPGPU::run(){
    _qRenderer.init();

	while (_window.isNotClosed())
	{	
		_cs.use();
		_cs.setFloat("t", _window.getTime());
		glDispatchCompute((unsigned int)1000/8, (unsigned int)1000/8, 1);

		glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_gs.use();
		
		_qRenderer.renderQuad();

		_window.update();
	}

	glDeleteProgram(_gs.ID);
	glDeleteProgram(_cs.ID);
}

// ------------------------------------------------------------------------

void GPGPU::setRenderView(glm::vec2 target_dim, const int unit){
    _param.screen_dim[0] = int(target_dim.x);
    _param.screen_dim[1] = int(target_dim.y);
	_window.init(_param);
    _glad.init();
    _gs.initVertexShader("../src/shaders/vertexShader.vs");
    _gs.initFragmentShader("../src/shaders/fragmentShader.fs");
    _gs.initProgram();
    _gs.use();
	_gs.setInt("tex", unit);
	_textureParam.unit =  GL_TEXTURE0 + unit;
	_texture.init(_textureParam);
	_texture.bind();
}