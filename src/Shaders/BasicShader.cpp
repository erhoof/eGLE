//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Shaders/BasicShader.h"
#include "../../include/Core/Window.h"
#include "../../include/Managers/RenderSystem.h"
#include "../../include/Components/CameraComponent.h"
#include "../../include/Objects/Material.h"
#include "../../include/Objects/Texture.h"

namespace eGLE
{
    BasicShader *BasicShader::m_instance = nullptr;

    BasicShader *BasicShader::instance()
    {
        return nullptr;
    }

    BasicShader::BasicShader()
    {
        // Load shaders
        loadVertexShaderFile("basicVertex.vert");
        loadFragmentShaderFile("basicFragment.frag");

        // Set attribs
        setAttribLocation("position", 0);
        setAttribLocation("textureCoord", 1);

        // Compile shaders above
        compile();

        // Core store
        createUniform("sampler"); // texture store
        createUniform("model");
        createUniform("view");
        createUniform("projection");

        // Light
        createUniform("light.ambient");
        createUniform("light.directional");
        createUniform("light.diffuse");
    }

    void BasicShader::updateUniform(Transform &transform, Model &model, RenderSystem *rs)
    {
        glm::mat4 projection = glm::perspective(glm::radians(60.0f),
                                                (float)Window::instance()->width() / (float)Window::instance()->height(),
                                                0.1f, 1000.0f);

        glm::mat4 view = glm::translate(view, rs->mainCamera()->transform().position());

        // Prepare textures
        model.material()->diffuseMap()->enable();

        // -- Uniforms --
        // Setup Texturing
        setUniform("sampler", model.material()->diffuseMap()->textureID());

        // MVP
        setUniform("model", transform.worldMatrix());
        setUniform("view", rs->mainCamera()->viewMatrix());
        setUniform("projection", rs->mainCamera()->projectionMatrix());

        // Light
        // TODO: setup params
        setUniform("light.ambient", glm::vec3(0.2f, 0.2f, 0.2f));
        setUniform("light.directional", glm::vec3(0.6f, 0.6f, 0.6f));
        setUniform("light.diffuse", glm::vec3(0.0f, 0.0f, 1.0f));
    }
}