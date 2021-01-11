//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_TRANSFORM_H
#define EGLE_TRANSFORM_H

#include <glm/glm.hpp>

namespace eGLE
{
    class Transform {
    public:
        Transform(const glm::vec3& position = glm::vec3(0.0f, 0.0f, 0.0f),
                  const glm::quat& rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f),
                  const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f));
        ~Transform() = default;

        // Update fields
        void update();
        bool changed() const;

        // Operations
        void rotate(glm::vec3 &axis, float angle);
        void rotate(glm::quat rotation);
        glm::vec3 rotate(glm::vec3 axis, glm::quat rotation); // to predict from sides

        // Get Sides
        glm::vec3 sideTop();
        glm::vec3 sideBottom();
        glm::vec3 sideLeft();
        glm::vec3 sideRight();
        glm::vec3 sideFront();
        glm::vec3 sideBack();

        // World params
        glm::mat4 worldMatrix() const;
        glm::vec3 transformedPosition();
        glm::quat transformedRotation();

        // -- Getters / Setters --
        glm::vec3 &position();
        void setPosition(const glm::vec3& position);
        glm::quat &rotation();
        void setRotation(const glm::quat& rotation);
        glm::vec3 &scale();
        void setScale(const glm::vec3& scale);

        // Parents
        Transform *parent();
        void setParent(Transform *parent);

    private:
        glm::vec3 m_position;
        glm::quat m_rotation;
        glm::vec3 m_scale;

        // to change from const (safe)
        mutable glm::mat4 m_parentMatrix;
        mutable glm::vec3 m_oldPosition;
        mutable glm::quat m_oldRotation;
        mutable glm::vec3 m_oldScale;

        Transform *m_parent;

        glm::mat4 translate(const glm::vec3& value) const;
        glm::quat multiplicate(glm::quat q, glm::vec3 v);
        glm::mat4 scale(const glm::vec& value) const;
    };

    // Add-in functions
    glm::vec3 transform(glm::mat4 m, glm::vec3 r);
}



#endif //EGLE_TRANSFORM_H
