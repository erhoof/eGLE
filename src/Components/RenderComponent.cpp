//
// Created by erhoof on 13.01.2021.
//

#include "../../include/Components/RenderComponent.h"
#include "../../include/Objects/Model.h"
#include "../../include/Shaders/Shader.h"

namespace eGLE
{
    RenderComponent::RenderComponent(Model *model, Shader *shader) :
        m_model(model),
        m_shader(shader)
    {}

    void RenderComponent::render(RenderSystem *rs)
    {
        m_shader->enable();

        m_shader->updateUniform(transform(), *m_model, rs);
    }
}