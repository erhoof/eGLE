//
// Created by erhoof on 13.01.2021.
//

#ifndef EGLE_RENDERCOMPONENT_H
#define EGLE_RENDERCOMPONENT_H

#include "Component.h"

namespace eGLE
{
    class Model;
    class Shader;

    class RenderComponent : public Component {
    public:
        RenderComponent(Model *model, Shader *shader);
        ~RenderComponent() = default;

        // RUI (try virtual)
        void render(RenderSystem *rs);

    private:
        Model *m_model;
        Shader *m_shader;
    };
}

#endif //EGLE_RENDERCOMPONENT_H
