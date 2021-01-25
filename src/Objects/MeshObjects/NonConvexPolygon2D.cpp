//
// Created by erhoof on 14.01.2021.
//

#include "../../../include/Objects/MeshObjects/NonConvexPolygon2D.h"

#include <cmath>

namespace eGLE
{
    Mesh3D *NonConvexPolygon2D::mesh3D()
    {
        return (new Mesh3D(m_vertices, m_indices));
    }

    Mesh2D *NonConvexPolygon2D::mesh2D()
    {
        return (new Mesh2D(m_vertices, m_indices));
    }

    std::vector<Vertex> NonConvexPolygon2D::m_vertices = {
            Vertex(glm::vec3(-0.5f, -0.5f,  0.5f)),
            Vertex(glm::vec3( 0.5f, -0.5f,  0.5f)),
            Vertex(glm::vec3( 1.0f,  0.5f,  0.5f)),
            Vertex(glm::vec3( 1.0f,  -1.5f,  0.5f))
    };

    std::vector<unsigned int> NonConvexPolygon2D::m_indices = {
            0,  1,  2,
            0,  1,  3
    };
}