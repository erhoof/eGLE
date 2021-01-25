//
// Created by erhoof on 14.01.2021.
//

#ifndef EGLE_CUBE_H
#define EGLE_CUBE_H

#include <vector>

#include "../Vertex.h"

namespace eGLE {
    class Mesh3D;

    class Cube {
    public:
        Cube();
        ~Cube() = delete;

        Mesh3D *mesh3D();

    private:
        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;
    };
}


#endif //EGLE_CUBE_H
