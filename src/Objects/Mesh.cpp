//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Objects/Mesh.h"

#include <glad.h>

namespace eGLE
{
    Mesh::Mesh() :
            m_VBO(0),
            m_VAO(0),
            m_IBO(0),
            m_size(0)
    {}

    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
    {
        generate(vertices, indices);
    }

    Mesh::~Mesh()
    {
        if (m_VBO) glDeleteBuffers(1, &m_VBO); // Specifies the number of buffer objects to be deleted, buffer
        if (m_VAO) glDeleteBuffers(1, &m_VAO);
        if (m_IBO) glDeleteBuffers(1, &m_IBO);
    }

    void Mesh::draw() const
    {
        // Prepare VAO
        glBindVertexArray(m_VAO);

        // Turn On Vertex Attribs
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        // Draw by Triangles
        // type of primitive, number of elements to render, type of in indices, indices pointer
        glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, nullptr);

        // Turn Off Vertex Attribs
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);

        // Free VAO
        glBindVertexArray(0);
    }

    void Mesh::generate(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
    {
        if (!m_VBO) glGenBuffers(1, &m_VBO);
        if (!m_VAO) glGenVertexArrays(1, &m_VAO);
        if (!m_IBO) glGenBuffers(1, &m_IBO);
        m_size = indices.size(); // count of indices

        // Prepare VAO
        glBindVertexArray(m_VAO);

        // -- VBO --
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        // (buffer, size, data, usage
        /* (The data store contents are modified by the application, and used
         * as the source for GL drawing and image specification commands.)
         * https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBufferData.xhtml*/
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

        // -- IBO --
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // Vertex Attribute Pointers (Position, TextureCoord, Normal)
        // (index, size (of components per attrib), type(of attrib data), normalized, stride (offset between attribs),
        // pointer)
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)nullptr);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_textureCoord));
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_normal));
    }
}