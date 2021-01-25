//
// Created by erhoof on 14.01.2021.
//

#ifndef EGLE_DOT2D_H
#define EGLE_DOT2D_H

#include <vector>
#include "../Vertex.h"

namespace eGLE {
    class Mesh3D;
    class Mesh2D;
    class Vertex;

    class Dot2D {
    public:
        Dot2D() = delete;
        ~Dot2D() = delete;

        static Mesh3D *mesh3D();
        static Mesh2D *mesh2D();

    private:
        static std::vector<Vertex> m_vertices;
        static std::vector<unsigned int> m_indices;
    };

    std::vector<Vertex> Dot2D::m_vertices = {
            Vertex(glm::vec3(0.0f, 0.0f,  0.5f))
    };

    std::vector<unsigned int> Dot2D::m_indices = {
            0
    };
}


#endif //EGLE_DOT2D_H
