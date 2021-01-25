//
// Created by erhoof on 14.01.2021.
//

#ifndef EGLE_Polygon2D_H
#define EGLE_Polygon2D_H

#include "../Vertex.h"

#include <vector>

namespace eGLE {
    class Mesh3D;
    class Mesh2D;

    class Polygon2D {
    public:
        Polygon2D(int count, float radius, bool borderStyle);
        ~Polygon2D() = delete;

        Mesh3D *mesh3D();
        Mesh2D *mesh2D();

    private:
        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;
        float m_radius;
        int m_count;
        bool m_borderStyle;

        void prepare2D();
        void prepare3D();
    };
}


#endif //EGLE_Polygon2D_H
