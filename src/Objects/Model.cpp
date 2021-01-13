//
// Created by erhoof on 13.01.2021.
//

#include "../../include/Objects/Model.h"

namespace eGLE
{
    Model::Model(Mesh *mesh, Material *material) :
        m_mesh(mesh),
        m_material(material)
    {}

    Mesh *Model::mesh()
    {
        return m_mesh;
    }

    void Model::setMesh(Mesh *mesh)
    {
        m_mesh = mesh;
    }

    Material *Model::material()
    {
        return m_material;
    }

    void Model::setMaterial(Material *material)
    {
        m_material = material;
    }
}