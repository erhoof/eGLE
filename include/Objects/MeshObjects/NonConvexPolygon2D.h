//
// Created by erhoof on 14.01.2021.
//

#ifndef EGLE_NONCONVEXPOLYGON2D_H
#define EGLE_NONCONVEXPOLYGON2D_H

#include "../Mesh3D.h"
#include "../Mesh2D.h"

#include "../Vertex.h"

namespace eGLE {
    class NonConvexPolygon2D {
    public:
        NonConvexPolygon2D() = delete;
        ~NonConvexPolygon2D() = delete;

        static Mesh3D *mesh3D();
        static Mesh2D *mesh2D();

    private:
        static std::vector<Vertex> m_vertices;
        static std::vector<unsigned int> m_indices;
    };
}


#endif //EGLE_NONCONVEXPOLYGON2D_H
