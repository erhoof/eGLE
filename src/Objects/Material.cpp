//
// Created by erhoof on 13.01.2021.
//

#include "../../include/Objects/Material.h"

namespace eGLE
{
    Material::Material(glm::vec3 color) :
        m_color(color)
    {}

    Material::Material(Texture *diffuseMap) :
        m_diffuseMap(diffuseMap)
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
}