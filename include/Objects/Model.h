//
// Created by erhoof on 13.01.2021.
//

#ifndef EGLE_MODEL_H
#define EGLE_MODEL_H

#include <string>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/material.h>

/*class aiNode;
class aiMesh;
class aiScene;
class aiMaterial;*/

namespace eGLE
{
    class Mesh;
    class Material;
    class Texture;
    class Shader;

    class Model {
    public:
        Model() = default;
        Model(Mesh *mesh, Material *material);
        ~Model() = default;

        // RUI
        void render();
        void prepareTexture();
        void prepareTexture(Shader *shader);
        void generate();

        // Getters / Setters
        Mesh *mesh();
        void setMesh(Mesh *mesh);
        Material *material();
        void setMaterial(Material *material);
        bool isEx() const;

    private:
        // Old
        Mesh *m_mesh;
        Material *m_material;

        // New
        std::vector <Mesh *> m_meshes;
        std::vector <Texture *> m_texturesLoaded;

        bool m_isEx = false;
        std::string m_directory;

        void processNode(aiNode *node, const aiScene *scene);
        Mesh *processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture *> loadTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    };
}


#endif //EGLE_MODEL_H
