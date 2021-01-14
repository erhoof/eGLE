//
// Created by erhoof on 14.01.2021.
//

#include "../../include/Shaders/ColorShader.h"

#include "../../include/Core/Window.h"
#include "../../include/Managers/RenderSystem.h"
#include "../../include/Components/CameraComponent.h"
#include "../../include/Objects/Material.h"
#include "../../include/Objects/Texture.h"

namespace eGLE
{
    ColorShader *ColorShader::m_instance = nullptr;

    ColorShader *ColorShader::instance()
    {
        if (!m_instance)
            m_instance = new ColorShader();

        return m_instance;
    }

    ColorShader::ColorShader()
    {
        // Load shaders
        loadVertexShaderFile("colorShader.vert");
        loadFragmentShaderFile("colorShader.frag");

        // Set attribs
        setAttribLocation("position", 0);
        setAttribLocation("color", 3);

        // Compile shaders above
        compile();

        // Create Uniforms
        createUniform("model");
        createUniform("view");
        createUniform("projection");
    }

    void ColorShader::updateUniform(Transform &transform, Model &model, RenderSystem *rs)
    {
        // MVP
        setUniform("model", transform.worldMatrix());
        setUniform("projection", rs->mainCamera()->projectionMatrix());
        setUniform("view", rs->mainCamera()->viewMatrix());
    }
}