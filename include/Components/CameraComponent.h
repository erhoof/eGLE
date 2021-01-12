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

        // RS
        void updateRS(RenderSystem *rs);

        // Getters / Setters
        glm::mat4 viewMatrix();
        glm::mat4 projectionMatrix();
        glm::mat4 viewProjectionMatrix();

    private:
        // MVP
        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionMatrix;

        // Camera Transform
        glm::vec3 m_position;
        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec2 m_center;

        // TODO: Camera Rotation (yaw, pitch, roll)

        // Add-in Properties (sens: 0.005f)
        float m_FOV;
        float m_aspectRatio;
        float m_zNear;
        float m_zFar;
    };
}

#endif //EGLE_CAMERACOMPONENT_H
