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

        void initComputeShader(const std::string path);
        void run();
        void setRenderView(const glm::vec2 target_dim, const int unit);
        virtual void renderFrame() = 0;
    
    protected:
        Window _window;
        ComputeShader _cs;

    private:
        WindowParam _param;
        GraphicShader _gs;
        QuadRenderer _qRenderer;
        Glad _glad;
        TextureParam _textureParam;
        Texture _texture;
        bool _hasRenderView;

        int _maxComputeWorkGroupCount[3];
        int _maxComputeWorkGroupSize[3];
        int _maxComputeWorkGroupInvocations;
};