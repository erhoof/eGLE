//
// Created by erhoof on 14.01.2021.
//

#include "../../../include/Objects/MeshObjects/Polygon2D.h"
#include "../../../include/Objects/Mesh2D.h"
#include "../../../include/Objects/Mesh3D.h"

#include <cmath>

namespace eGLE
{
    Polygon2D::Polygon2D(int count, float radius, bool borderStyle) :
        m_count(count),
        m_radius(radius),
        m_borderStyle(borderStyle)
    {}

    Mesh3D *Polygon2D::mesh3D()
    {
        prepare3D();
        auto v = m_vertices;
        auto i = m_indices;

        return (new Mesh3D(m_vertices, m_indices));
    }

    Mesh2D *Polygon2D::mesh2D()
    {
        if (m_borderStyle)
            prepare2D();
        else
            prepare3D();

        return (new Mesh2D(m_vertices, m_indices));
    }

    void Polygon2D::prepare2D()
    {
        double PI = 3.14159265359;

        for (int i = 0; i < m_count; i++) {
            m_vertices.emplace_back(glm::vec3(m_radius * cos(2 * PI * i / m_count),
                                                  m_radius * sin(2 * PI * i / m_count),
                                                  0.5f));
            m_indices.push_back(i);
        }
    }

    void Polygon2D::prepare3D()
    {
        double PI = 3.14159265359;

        std::vector<Vertex> dots;
        dots.emplace_back(glm::vec3(0.0f, 0.0f, 0.5f)); // center
        for (int i = 0; i < m_count; i++) {
            dots.emplace_back(glm::vec3(m_radius * cos(2 * PI * i / m_count),
                                              m_radius * sin(2 * PI * i / m_count),
                                              0.5f));
        }
        m_vertices = dots;

        for (int i = 1; i <= m_count; i++) {
            if (i == (m_count)) {
                m_indices.push_back(0);
                m_indices.push_back(i);
                m_indices.push_back(1);
                continue;
            }

            m_indices.push_back(0);
            m_indices.push_back(i);
            m_indices.push_back(i+1);
        }
    }
}