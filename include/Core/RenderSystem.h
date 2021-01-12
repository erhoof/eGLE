//
// Created by erhoof on 11.01.2021.
//

#ifndef EGLE_RENDERSYSTEM_H
#define EGLE_RENDERSYSTEM_H

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

    private:
        CameraComponent *m_mainCamera;
    };
}

#endif //EGLE_RENDERSYSTEM_H
