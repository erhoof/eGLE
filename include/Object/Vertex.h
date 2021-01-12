//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_VERTEX_H
#define EGLE_VERTEX_H

#include <glm/glm.hpp>

namespace eGLE
{
    struct Vertex {
        glm::vec3 m_position;
        glm::vec3 m_textureCoord;
        glm::vec3 m_normal;

        Vertex(glm::vec3 position = glm::vec3(0, 0, 0),
               glm::vec2 textureCoord = glm::vec2(0, 0),
               glm::vec3 normal = glm::vec3(0, 0, 0)) :
               m_position(position),
               m_textureCoord(textureCoord),
               m_normal(normal)
        {}
    };
}

#endif //EGLE_VERTEX_H
