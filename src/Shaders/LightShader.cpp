//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Shaders/LightShader.h"
#include "../../include/Core/Window.h"
#include "../../include/Managers/RenderSystem.h"
#include "../../include/Components/CameraComponent.h"
#include "../../include/Objects/Material.h"
#include "../../include/Objects/Texture.h"
#include "../../include/Objects/Mesh.h"
#include "../../include/Bites/Node.h"

namespace eGLE
{
    LightShader *LightShader::m_instance = nullptr;

    LightShader *LightShader::instance()
    {
        if (!m_instance)
            m_instance = new LightShader();

        return m_instance;
    }

    LightShader::LightShader()
    {
        // Load shaders
        loadVertexShaderFile("lightShader.vert");
        loadFragmentShaderFile("lightShader.frag");

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

    void LightShader::updateUniform(Transform &transform, Model &model, RenderSystem *rs)
    {
        // Prepare textures
        if (model.isEx()) {
            model.prepareTexture(this);

        } else {
            model.prepareTexture();

            setUniform("material.diffuse", model.material()->diffuseMap()->textureID());
            setUniform("material.specular", model.material()->normalMap()->textureID());
        }

        // -- Uniforms --
        // Setup Material
        setUniform("material.shininess", 32.0f);

        // MVP + Pos
        setUniform("viewPos", rs->mainCamera()->transform().position());
        setUniform("model", transform.worldMatrix());
        setUniform("projection", rs->mainCamera()->projectionMatrix());
        setUniform("view", rs->mainCamera()->viewMatrix());

        // -- LIGHT --
        // Directional
        setUniform("dirLight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
        //setUniform("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
        setUniform("dirLight.ambient", glm::vec3(0.35f, 0.35f, 0.35f));
        setUniform("dirLight.diffuse", glm::vec3(0.4f, 0.4f, 0.4f));
        setUniform("dirLight.specular", glm::vec3(0.5f, 0.5f, 0.5f));

        // Point
        std::string line;
        for (int i=0; i < rs->pointLights().size(); i++) {
            line = "pointLights[" + std::to_string(i) + "].";
            auto item = rs->pointLights()[i];

            setUniform((line + "position").c_str(), item->transform().position());
            setUniform((line + "ambient").c_str(), glm::vec3(0.05f, 0.05f, 0.05f));
            setUniform((line + "diffuse").c_str(), glm::vec3(0.8f, 0.8f, 0.8f));
            setUniform((line + "specular").c_str(), glm::vec3(1.0f, 1.0f, 1.0f));
            setUniform((line + "constant").c_str(), 1.0f);
            setUniform((line + "linear").c_str(), 0.09f);
            setUniform((line + "quadratic").c_str(), 0.032f);
        }

        // Spotlight (FlashLight)
        setUniform("spotLight.position", rs->mainCamera()->transform().position());
        setUniform("spotLight.direction", rs->mainCamera()->front());
        setUniform("spotLight.ambient", glm::vec3(0.0f, 0.0f, 0.0f));
        setUniform("spotLight.diffuse", glm::vec3(1.0f, 1.0f, 1.0f));
        setUniform("spotLight.specular", glm::vec3(1.0f, 1.0f, 1.0f));
        setUniform("spotLight.constant", 1.0f);
        setUniform("spotLight.linear", 0.09f);
        setUniform("spotLight.quadratic", 0.032f);
        setUniform("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        setUniform("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
    }
}