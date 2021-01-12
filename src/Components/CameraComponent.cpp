//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Components/CameraComponent.h"
#include "../../include/Core/Window.h"
#include "../../include/Core/RenderSystem.h"

#include <GLFW/glfw3.h>

namespace eGLE
{
    CameraComponent::CameraComponent(float FOV, float aspectRatio, float zNear, float zFar) :
        m_FOV(FOV),
        m_aspectRatio(aspectRatio),
        m_zNear(zNear),
        m_zFar(zFar),
        m_projectionMatrix(glm::perspective(FOV, aspectRatio, zNear, zFar))
    {}

    void CameraComponent::input(float timeDelta)
    {
        // example
        if (glfwGetKey(Window::instance()->glfwWindow(), GLFW_KEY_W) == GLFW_PRESS)
        {
            transform().position().z += timeDelta;
        }
    }

    void CameraComponent::updateRS(RenderSystem *rs)
    {
        rs->setMainCamera(this);
    }

    glm::mat4 CameraComponent::viewMatrix()
    {
        glm::vec3 position = transform().position();
        glm::vec3 lookAt = transform().position() + transform().sideFront(); // to look forward
        glm::vec3 top = transform().sideTop(); // top side

        m_viewMatrix = glm::lookAt(position, lookAt, top);

        return m_viewMatrix;
    }

    glm::mat4 CameraComponent::projectionMatrix()
    {
        return m_projectionMatrix;
    }

    glm::mat4 CameraComponent::viewProjectionMatrix()
    {
        return m_projectionMatrix * viewMatrix();
    }
}