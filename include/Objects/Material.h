//
// Created by erhoof on 13.01.2021.
//

#ifndef EGLE_MATERIAL_H
#define EGLE_MATERIAL_H

#include <glm/glm.hpp>

namespace eGLE
{
    class Texture;
    class Mesh;
    class Shader;

    class Material {
    public:
        Material();
        explicit Material(glm::vec3 color);
        Material(Texture *diffuseMap, Texture *normalMap);
        ~Material() = default;

        // -- Getters / Setters --

        // color
        glm::vec3 getColor() const;
        void setColor(glm::vec3 color);

        // texture maps
        Texture *diffuseMap() const;
        Texture *normalMap() const;
        void setDiffuseMap(Texture *diffuseMap);
        void setNormalMap(Texture *normalMap);
        void prepareTexture() const;
        void prepareTextureEx(Mesh *mesh, Shader *shader) const;

    private:
        // Color
        glm::vec3 m_color{};

        // Texture Maps
        Texture *m_diffuseMap;
        Texture *m_normalMap;
    };
}


#endif //EGLE_MATERIAL_H
