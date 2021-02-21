//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_LIGHTSHADER_H
#define EGLE_LIGHTSHADER_H

#include "Shader.h"
#include "../Objects/Model.h"

namespace eGLE
{
    class LightShader : public Shader {
    public:
        static LightShader *instance();

        void updateUniform(Transform &transform, Model &model, RenderSystem *rs);

    private:
        static LightShader *m_instance;

        LightShader();
        LightShader(const LightShader &) = default;
        LightShader &operator=(LightShader &) = default;
    };
}

#endif //EGLE_LIGHTSHADER_H
