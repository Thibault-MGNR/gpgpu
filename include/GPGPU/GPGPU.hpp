#pragma once

#include "GPGPU/gladLoader.hpp"
#include "GPGPU/window.hpp"

#include "GPGPU/texture.hpp"

#include "GPGPU/graphicShader.hpp"
#include "GPGPU/computeShader.hpp"

#include "GPGPU/quadRenderer.hpp"

class GPGPU{
    public:
        GPGPU();
        // virtual ~GPGPU() = 0;

        void init(const std::string path);
        void run();
        void setRenderView(glm::vec2 target_dim, const int unit);
        // virtual void renderFrame() = 0;
    
    private:
        WindowParam _param;
        Window _window;
        Glad _glad;
        ComputeShader _cs;
        GraphicShader _gs;
        TextureParam _textureParam;
        Texture _texture;
        QuadRenderer _qRenderer;
        bool _hasRenderView;

        int _max_compute_work_group_count[3];
        int _max_compute_work_group_size[3];
        int _max_compute_work_group_invocations;
};