//
// Created by erhoof on 14.01.2021.
//

#include "../../../include/Objects/MeshObjects/Dot2D.h"

#include "../../../include/Objects/Mesh2D.h"
#include "../../../include/Objects/Mesh3D.h"

#include <cmath>

namespace eGLE
{
    Mesh3D *Dot2D::mesh3D()
    {
        return (new Mesh3D(m_vertices, m_indices));
    }

    Mesh2D *Dot2D::mesh2D()
    {
        return (new Mesh2D(m_vertices, m_indices));
    }
}