//
// Created by erhoof on 14.01.2021.
//

#include "../../../include/Objects/MeshObjects/Triangle2D.h"

#include <cmath>

namespace eGLE
{
    Mesh3D *Triangle2D::mesh3D()
    {
        return (new Mesh3D(m_vertices, m_indices));
    }

    Mesh2D *Triangle2D::mesh2D()
    {
        return (new Mesh2D(m_vertices, m_indices));
    }

    std::vector<Vertex> Triangle2D::m_vertices = {
            Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
            Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)),
            Vertex(glm::vec3( 0.0f,  0.5f,  0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f))
    };

    std::vector<unsigned int> Triangle2D::m_indices = {
            0,  1,  2    // front
    };
}