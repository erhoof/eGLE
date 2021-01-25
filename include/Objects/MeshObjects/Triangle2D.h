//
// Created by erhoof on 14.01.2021.
//

#ifndef EGLE_TRIANGLE2D_H
#define EGLE_TRIANGLE2D_H

#include "../Mesh3D.h"
#include "../Mesh2D.h"

#include "../Vertex.h"

namespace eGLE {
    class Triangle2D {
    public:
        Triangle2D() = delete;
        ~Triangle2D() = delete;

        static Mesh3D *mesh3D();
        static Mesh2D *mesh2D();

    private:
        static std::vector<Vertex> m_vertices;
        static std::vector<unsigned int> m_indices;
    };
}


#endif //EGLE_TRIANGLE2D_H
