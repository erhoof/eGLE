//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_MESH_H
#define EGLE_MESH_H

#include <vector>

#include "Vertex.h"

namespace eGLE
{
    class Mesh {
    public:
        Mesh();
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
        ~Mesh();

        // RUI
        void draw() const;

    private:
        // Vertex Array Objects (designed to store the information for a complete rendered object)
        unsigned int m_VAO;

        /* Vertex Buffer Objects (memory buffer in the high speed memory of your
         * video card designed to hold information about vertices) */
        unsigned int m_VBO;

        // Index Buffer Objects (to reuse the same vertex over and over again)
        unsigned int m_IBO;

        int m_size; // Index Size

        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;

        void generate(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    };
}

#endif //EGLE_MESH_H
