#include "GPGPU/GPGPU.hpp"

GPGPU::GPGPU(){
	_hasRenderView = false;
}

// ------------------------------------------------------------------------

void GPGPU::initGPGPU(){
    for (int idx = 0; idx < 3; idx++) {
		glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, idx, &_maxComputeWorkGroupCount[idx]);
		glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, idx, &_maxComputeWorkGroupSize[idx]);
	}	
	glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &_maxComputeWorkGroupInvocations);
}

// ------------------------------------------------------------------------

void GPGPU::run(){
    _qRenderer.init();

	while (_window.isNotClosed())
	{	
		renderFrame();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		_gs.use();
		_qRenderer.renderQuad();
		_window.update();
	}
}

// ------------------------------------------------------------------------

void GPGPU::setRenderView(glm::vec2 target_dim, const int unit){
    _param.screen_dim[0] = int(target_dim.x);
    _param.screen_dim[1] = int(target_dim.y);
	_window.init(_param);
	_hasRenderView = true;
    _glad.init();
    _gs.initVertexShader();
    _gs.initFragmentShader();
    _gs.initProgram();
    _gs.use();
	_gs.setInt("tex", unit);
	_textureParam.unit =  GL_TEXTURE0 + unit;
	_texture.init(_textureParam);
	_texture.bind();
}