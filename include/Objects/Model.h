//
// Created by erhoof on 13.01.2021.
//

#ifndef EGLE_MODEL_H
#define EGLE_MODEL_H

namespace eGLE
{
    class Mesh;
    class Material;

    class Model {
    public:
        Model() = default;
        Model(Mesh *mesh, Material *material);
        ~Model() = default;

        // Getters / Setters
        Mesh *mesh();
        void setMesh(Mesh *mesh);
        Material *material()
        void setMaterial(Material *material);

    private:
        Mesh *m_mesh;
        Material *m_material;
    };
}


#endif //EGLE_MODEL_H
