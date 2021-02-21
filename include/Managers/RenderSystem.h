//
// Created by erhoof on 11.01.2021.
//

#ifndef EGLE_RENDERSYSTEM_H
#define EGLE_RENDERSYSTEM_H

#include <vector>

namespace eGLE
{
    class Node;
    class CameraComponent;

    class RenderSystem {
    public:
        RenderSystem() = default;
        ~RenderSystem() = default;

        void prepare();
        void render(Node *root);

        // Camera System
        // TODO: check with inline
        CameraComponent *mainCamera();
        void setMainCamera(CameraComponent *camera);

        // Light
        void addPointLight(Node *node);
        std::vector<Node *> &pointLights();

    private:
        CameraComponent *m_mainCamera;

        // Light
        std::vector<Node *> m_pointLights;
    };
}

#endif //EGLE_RENDERSYSTEM_H
