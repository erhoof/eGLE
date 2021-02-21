//
// Created by erhoof on 13.01.2021.
//

#include "../../include/Objects/Material.h"
#include "../../include/Objects/Texture.h"
#include "../../include/Objects/Mesh.h"
#include "../../include/Shaders/Shader.h"
#include "../../include/Core/Debug.h"

#include <glad.h>

namespace eGLE
{
    Material::Material(glm::vec3 color) :
        m_color(color)
    {}

    Material::Material() :
            m_diffuseMap(nullptr),
            m_normalMap(nullptr)
    {}

    Material::Material(Texture *diffuseMap, Texture *normalMap) :
        m_diffuseMap(diffuseMap),
        m_normalMap(normalMap)
    {}

    glm::vec3 Material::getColor() const
    {
        return m_color;
    }

    void Material::setColor(glm::vec3 color)
    {
        m_color = color;
    }

    Texture *Material::diffuseMap() const
    {
        return m_diffuseMap;
    }

    Texture *Material::normalMap() const
    {
        return m_normalMap;
    }

    void Material::setDiffuseMap(Texture *diffuseMap)
    {
        m_diffuseMap = diffuseMap;
    }

    void Material::setNormalMap(Texture *normalMap)
    {
        m_normalMap = normalMap;
    }

    void Material::prepareTexture() const
    {
        if (m_diffuseMap)
            m_diffuseMap->enable();

        if (m_normalMap)
            m_normalMap->enable();
    }

    void Material::prepareTextureEx(Mesh *mesh, Shader *shader) const
    {
        unsigned int diffuseN = 1;
        unsigned int specularN = 1;

        auto textures = mesh->textures();
        std::string number;
        std::string name;
        for (unsigned int i=0; i < textures.size(); i++) {
            glActiveTexture(GL_TEXTURE0 + i);

            name = textures[i]->type();
            if (name == "diffuse")
                number = std::to_string(diffuseN++);
            else if (name == "specular")
                number = std::to_string(specularN++);

            std::string line = "material.";
            line += name;
            //line += number;


            shader->setUniform(line.c_str(), i);
            //Debug::msg("set uniform:", line, "-", i);

            glBindTexture(GL_TEXTURE_2D, textures[i]->textureID());
        }

        glActiveTexture(GL_TEXTURE0);
    }
}