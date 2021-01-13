//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_BASICSHADER_H
#define EGLE_BASICSHADER_H

#include "Shader.h"
#include "../Objects/Model.h"

namespace eGLE
{
    class BasicShader : public Shader {
    public:
        static BasicShader *instance();

        void updateUniform(Transform &transform, Model &model, RenderSystem *rs);

    private:
        static BasicShader *m_instance;

        BasicShader();
        BasicShader(const BasicShader &) = default;
        BasicShader &operator=(BasicShader &) = default;
    };
}

#endif //EGLE_BASICSHADER_H
