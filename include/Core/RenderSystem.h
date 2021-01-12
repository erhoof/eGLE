//
// Created by erhoof on 11.01.2021.
//

#ifndef EGLE_RENDERSYSTEM_H
#define EGLE_RENDERSYSTEM_H

namespace eGLE
{
    class Node;
    class Camera;

    class RenderSystem {
    public:
        RenderSystem() = default;
        ~RenderSystem() = default;

        void prepare();
        void render(Node *root);

        // Camera System
        // TODO: check with inline
        Camera *mainCamera();
        void setMainCamera(Camera *camera);

    private:
        Camera *m_mainCamera;
    };
}

#endif //EGLE_RENDERSYSTEM_H
