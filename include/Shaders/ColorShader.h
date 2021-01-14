//
// Created by erhoof on 14.01.2021.
//

#ifndef EGLE_COLORSHADER_H
#define EGLE_COLORSHADER_H

#include "Shader.h"
#include "../Objects/Model.h"

namespace eGLE
{
    class ColorShader : public Shader {
    public:
        static ColorShader *instance();

        void updateUniform(Transform &transform, Model &model, RenderSystem *rs) override;

    private:
        static ColorShader *m_instance;

        ColorShader();
        ColorShader(const ColorShader &) = default;
        ColorShader &operator=(ColorShader &) = default;
    };
}

#endif //EGLE_COLORSHADER_H
