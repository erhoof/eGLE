//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Objects/Mesh.h"
#include "../../include/Core/Debug.h"

#include <glad.h>

#include <utility>

namespace eGLE
{
    Mesh::Mesh() :
            m_VBO(0),
            m_VAO(0),
            m_IBO(0),
            m_size(0)
    {}

    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices) :
            m_VBO(0),
            m_VAO(0),
            m_IBO(0),
            m_size(0),
            m_vertices(std::move(vertices)),
            m_indices(std::move(indices))
    {}

    void Mesh::setColor(glm::vec3 color)
    {
        for (auto &vertex : m_vertices) {
            vertex.m_color = color;
        }
    }
}