//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Objects/Mesh3D.h"
#include "../../include/Core/Debug.h"

#include <glad.h>

#include <utility>

namespace eGLE
{
    Mesh3D::Mesh3D() :
            m_VBO(0),
            m_VAO(0),
            m_IBO(0),
            m_size(0)
    {}

    Mesh3D::Mesh3D(std::vector<Vertex> vertices, std::vector<unsigned int> indices) :
            m_VBO(0),
            m_VAO(0),
            m_IBO(0),
            m_size(0),
            m_vertices(std::move(vertices)),
            m_indices(std::move(indices))
    {}

    Mesh3D::~Mesh3D()
    {
        if (m_VBO) glDeleteBuffers(1, &m_VBO); // Specifies the number of buffer objects to be deleted, buffer
        if (m_VAO) glDeleteBuffers(1, &m_VAO);
        if (m_IBO) glDeleteBuffers(1, &m_IBO);
    }

    void Mesh3D::render() const
    {
        // Prepare VAO
        glBindVertexArray(m_VAO);

        // Turn On Vertex Attribs
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
        glEnableVertexAttribArray(3);

        // Draw by Triangles
        // type of primitive, number of elements to render, type of in indices, indices pointer
        glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);

        // Turn Off Vertex Attribs
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
        glDisableVertexAttribArray(3);

        // Free VAO
        glBindVertexArray(0);
    }

    void Mesh3D::generate()
    {
        if (!m_VAO) glGenVertexArrays(1, &m_VAO);
        if (!m_VBO) glGenBuffers(1, &m_VBO);
        if (!m_IBO) glGenBuffers(1, &m_IBO);
        m_size = m_indices.size(); // count of indices

        // Prepare VAO
        glBindVertexArray(m_VAO);

        // -- VBO --
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        // (buffer, size, data, usage
        /* (The data store contents are modified by the application, and used
         * as the source for GL drawing and image specification commands.)
         * https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBufferData.xhtml*/
        glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

        // -- IBO --
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);

        // Vertex Attribute Pointers (Position, TextureCoord, Normal)
        // (index, size (of components per attrib), type(of attrib data), normalized, stride (offset between attribs),
        // pointer)
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)nullptr);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_textureCoord));
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_normal));
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_color));
    }
}