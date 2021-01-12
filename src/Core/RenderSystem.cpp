//
// Created by erhoof on 11.01.2021.
//

#include "../../include/Core/RenderSystem.h"
#include "../../include/Core/Debug.h"
#include "../../include/Core/Window.h"
#include "../../include/Bites/Node.h"
#include <glad.h>

namespace eGLE
{
    void RenderSystem::prepare()
    {
        Debug::msg("[Render] RenderSystem - init.");

        glEnable(GL_DEPTH_TEST);
    }

    void RenderSystem::render(Node *root)
    {
        root->updateRS(this);

        if (!m_mainCamera)
            Debug::halt("There is no main camera in core RS");

        // Clear window before render
        Window::instance()->clear();

        // Render Scene Graph
        root->render(this);
    }

    Camera *RenderSystem::mainCamera()
    {
        return m_mainCamera;
    }

    void RenderSystem::setMainCamera(Camera *camera)
    {
        m_mainCamera = camera;
    }
}