//
// Created by erhoof on 13.01.2021.
//

#include "../../include/Objects/Model.h"
#include "../../include/Objects/Mesh3D.h"
#include "../../include/Objects/Texture.h"
#include "../../include/Objects/Material.h"
#include "../../include/Core/Debug.h"

namespace eGLE
{
    Model::Model(Mesh *mesh, Material *material) :
        m_mesh(mesh),
        m_material(material)
    {}

    Model::Model(std::string filepath) :
        m_isEx(true)
    {
        Assimp::Importer importer;
        //const aiScene *scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_FlipUVs);
        const aiScene *scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_FlipUVs);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
            Debug::msg("[ModelLoader] error", importer.GetErrorString());
            return;
        }

        m_directory = filepath.substr(0, filepath.find_last_of('/'));

        processNode(scene->mRootNode, scene);
    }

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

    void Model::render()
    {
        if (m_isEx) {
            for (auto & mesh : m_meshes)
                mesh->render();
        } else {
            mesh()->render();
        }
    }

    void Model::processNode(aiNode *node, const aiScene *scene)
    {
        aiMesh *mesh;
        for (unsigned int i = 0; i < node->mNumMeshes; i++) {
            mesh = scene->mMeshes[node->mMeshes[i]];
            m_meshes.push_back(processMesh(mesh, scene));
        }

        for (unsigned int i = 0; i < node->mNumChildren; i++) {
            processNode(node->mChildren[i], scene);
        }
    }

    Mesh *Model::processMesh(aiMesh *mesh, const aiScene *scene)
    {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture *> textures;

        // Vertices
        Vertex vertex;
        glm::vec3 v3;
        glm::vec2 v2;
        for (unsigned int i = 0; i < mesh->mNumVertices; i++) {

            // pos
            v3.x = mesh->mVertices[i].x;
            v3.y = mesh->mVertices[i].y;
            v3.z = mesh->mVertices[i].z;
            vertex.m_position = v3;

            // normal
            v3.x = mesh->mNormals[i].x;
            v3.y = mesh->mNormals[i].y;
            v3.z = mesh->mNormals[i].z;
            vertex.m_normal = v3;

            // tex coords
            if (mesh->mTextureCoords[0]) { // check if has any texcoords
                v2.x = mesh->mTextureCoords[0][i].x;
                v2.y = mesh->mTextureCoords[0][i].y;

                vertex.m_textureCoord = v2;
            } else {
                vertex.m_textureCoord = glm::vec2(0.0f, 0.0f);
            }

            vertices.push_back(vertex);
        }

        // Indices
        aiFace face;
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            face = mesh->mFaces[i];

            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }

        // Material
        if (mesh->mMaterialIndex >= 0) {
            aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
            std::vector<Texture *> diffuses = loadTextures(material, aiTextureType_DIFFUSE, "diffuse");
            textures.insert(textures.end(), diffuses.begin(), diffuses.end());

            std::vector<Texture *> speculars = loadTextures(material, aiTextureType_SPECULAR, "specular");
            textures.insert(textures.end(), speculars.begin(), speculars.end());
        }

        auto retMesh = new Mesh3D(vertices, indices, textures);
        return retMesh;
    }

    std::vector<Texture *>
    Model::loadTextures(aiMaterial *mat, aiTextureType type, std::string typeName)
    {
        std::vector<Texture *> textures;

        Texture *tex;
        bool skip = false;
        for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
            aiString str;
            mat->GetTexture(type, i, &str);
            skip = false;

            for (unsigned int j = 0; j < m_texturesLoaded.size(); j++) {
                if (std::strcmp(m_texturesLoaded[j]->path().data(), str.C_Str()) == 0) {
                    textures.push_back(m_texturesLoaded[j]);
                    skip = true;
                    break;
                }
            }

            if (!skip) { // if it was not loaded already
                tex = new Texture(str.C_Str(), m_directory.c_str());
                tex->setType(typeName);
                tex->setPath(str.C_Str());

                textures.push_back(tex);
                m_texturesLoaded.push_back(tex);
            }
        }

        return textures;
    }

    bool Model::isEx() const
    {
        return m_isEx;
    }

    void Model::prepareTexture()
    {
        material()->prepareTexture();
    }

    void Model::prepareTexture(Shader *shader)
    {
        for (auto const &mesh : m_meshes)
            material()->prepareTextureEx(mesh, shader);
    }

    void Model::generate()
    {
        for (auto const &mesh : m_meshes) {
            mesh->generate();
        }
    }
}