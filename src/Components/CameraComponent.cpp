//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Components/CameraComponent.h"
#include "../../include/Core/Window.h"
#include "../../include/Managers/RenderSystem.h"

//#include <glad.h>
#include <GLFW/glfw3.h>

namespace eGLE
{
    CameraComponent::CameraComponent(float FOV, float aspectRatio, float zNear, float zFar) :
        m_FOV(FOV),
        m_aspectRatio(aspectRatio),
        m_zNear(zNear),
        m_zFar(zFar),
        m_projectionMatrix(glm::perspective(FOV, aspectRatio, zNear, zFar)),
        m_front(transform().sideFront()),
        m_up(glm::vec3(0.0f, 1.0f, 0.0f)),
        m_worldUp(m_up)
    {
        updateCamera();
    }

    void CameraComponent::input(float timeDelta)
    {
        // example
        /*if (glfwGetKey(Window::instance()->glfwWindow(), GLFW_KEY_W) == GLFW_PRESS)
        {
            //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            transform().position().z += timeDelta;
        }*/
    }

    void CameraComponent::processMouseMovement(float xOffset, float yOffset)
    {
        xOffset *= m_sensitivity;
        yOffset *= m_sensitivity;

        m_yaw += xOffset;
        m_pitch += yOffset;

        // Check bounds
        if (m_pitch > 89.0f)
            m_pitch = 89.0f;
        if (m_pitch < -89.0f)
            m_pitch = -89.0f;

        updateCamera();
    }

    void CameraComponent::updateRS(RenderSystem *rs)
    {
        rs->setMainCamera(this);
    }

    glm::mat4 CameraComponent::viewMatrix()
    {
        glm::vec3 position = transform().position();
        glm::vec3 lookAt = transform().position() + m_front; // to look forward
        glm::vec3 top = m_up; // top side
        m_viewMatrix = glm::lookAt(position, lookAt, top);

        /*glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
        glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
        m_viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);*/

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

    void CameraComponent::updateCamera()
    {
        glm::vec3 front;
        front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        front.y = sin(glm::radians(m_pitch));
        front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        m_front = glm::normalize(front);

        m_right = glm::normalize(glm::cross(m_front, m_worldUp));
        m_up = glm::normalize(glm::cross(m_right, m_front));
    }
}