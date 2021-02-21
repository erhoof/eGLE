//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_CAMERACOMPONENT_H
#define EGLE_CAMERACOMPONENT_H

#include <glm/glm.hpp>

#include "Component.h"

namespace eGLE
{
    class RenderSystem;

    class CameraComponent : public Component {
    public:
        CameraComponent(float FOV, float aspectRatio, float zNear, float zFar);
        ~CameraComponent() = default;

        // RUI
        void input(float timeDelta);
        void processMouseMovement(float xOffset, float yOffset);

        // RS
        void updateRS(RenderSystem *rs);

        // Getters / Setters
        glm::mat4 viewMatrix();
        glm::mat4 projectionMatrix();
        glm::mat4 viewProjectionMatrix();
        glm::vec3 front() const;

    private:
        // MVP
        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionMatrix;

        // Camera Transform
        glm::vec3 m_position;
        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec3 m_right;
        glm::vec3 m_worldUp;
        glm::vec2 m_center;

        // TODO: Camera Rotation (yaw, pitch, roll)
        float m_yaw = -90.0f;
        float m_pitch = 0.0f;
        float m_sensitivity = 0.1f;

        // Add-in Properties (sens: 0.005f)
        float m_FOV;
        float m_aspectRatio;
        float m_zNear;
        float m_zFar;

        // Add-ins
        void updateCamera();
    };
}

#endif //EGLE_CAMERACOMPONENT_H
