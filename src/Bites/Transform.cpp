//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Bites/Transform.h"

#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace eGLE
{
    Transform::Transform(const glm::vec3 &position,
                         const glm::quat &rotation,
                         const glm::vec3 &scale) :
         m_position(position),
         m_rotation(rotation),
         m_scale(scale),
         m_parent(nullptr)
    {}

    void Transform::update()
    {
        if (changed()) {
            m_oldPosition = m_position;
            m_oldRotation = m_rotation;
            m_oldScale = m_scale;

            if (m_parent)
                m_parentMatrix = m_parent->worldMatrix();
        }
    }

    bool Transform::changed() const
    {
        if (m_parent && m_parent->changed())
            return true;

        return (m_position != m_oldPosition ||
                m_rotation != m_oldRotation ||
                m_scale    != m_oldScale);
    }

    void Transform::rotate(glm::vec3 &axis, float angle)
    {
        rotate(glm::angleAxis(angle, axis));
    }

    void Transform::rotate(glm::quat rotation)
    {
        m_rotation = glm::normalize(rotation * m_rotation);
    }

    glm::vec3 Transform::rotate(glm::vec3 axis, glm::quat rotation)
    {
        glm::quat tempQ = glm::conjugate(rotation);
        glm::quat tempW = rotation * glm::quat(0, axis) * tempQ;

        return glm::normalize(glm::vec3(tempW[0], tempW[1], tempW[2]));
    }

    glm::vec3 Transform::sideTop()
    {
        return rotate(glm::vec3(0, 1, 0), m_rotation);
    }

    glm::vec3 Transform::sideBottom()
    {
        return rotate(glm::vec3(0, -1, 0), m_rotation);
    }

    glm::vec3 Transform::sideLeft()
    {
        return rotate(glm::vec3(1, 0, 0), m_rotation);
    }

    glm::vec3 Transform::sideRight()
    {
        return rotate(glm::vec3(-1, 0, 0), m_rotation);
    }

    glm::vec3 Transform::sideFront()
    {
        return rotate(glm::vec3(0, 0, 1), m_rotation);
    }

    glm::vec3 Transform::sideBack()
    {
        return rotate(glm::vec3(0, 0, -1), m_rotation);
    }

    glm::mat4 Transform::worldMatrix() const
    {
        glm::mat4 positionMatrix = translate(m_position);
        glm::mat4 scaleMatrix = scale(m_scale);
        glm::mat4 rotationMatrix = glm::mat4_cast(glm::normalize(m_rotation));

        return m_parentMatrix * positionMatrix * rotationMatrix * scaleMatrix;
    }

    glm::vec3 Transform::transformedPosition()
    {
        return transform(m_parentMatrix, m_position);
    }

    glm::quat Transform::transformedRotation()
    {
        glm::quat parentRotation;

        // TODO: remove nullptr (but check it before!)
        if (m_parent != nullptr)
            parentRotation = m_parent->transformedRotation();
        else
            parentRotation = glm::quat(0, 0, 0, 1);

        return parentRotation * m_rotation;
    }

    glm::vec3 &Transform::position()
    {
        return m_position;
    }

    void Transform::setPosition(const glm::vec3 &position)
    {
        m_position = position;
    }

    glm::quat &Transform::rotation()
    {
        return m_rotation;
    }

    void Transform::setRotation(const glm::quat &rotation)
    {
        m_rotation = rotation;
    }

    glm::vec3 &Transform::scale()
    {
        return m_scale;
    }

    void Transform::setScale(const glm::vec3 &scale)
    {
        m_scale = scale;
    }

    Transform *Transform::parent()
    {
        return m_parent;
    }

    void Transform::setParent(Transform *parent)
    {
        m_parent = parent;
    }

    glm::mat4 Transform::translate(const glm::vec3 &value) const
    {
        glm::mat4 matrix;

        for (unsigned int i = 0; i < 4; i++)
            for (unsigned int j = 0; j < 4; j++)
                if (i == 3 && j != 3)
                    matrix[i][j] = value[j];

        return matrix;
    }

    glm::quat Transform::multiplicate(glm::quat q, glm::vec3 v)
    {
        float w = -q.x * v.x - q.y * v.y - q.z * v.z;
        float x = q.w * v.x + q.y * v.z - q.z * v.y;
        float y = q.w * v.y + q.z * v.x - q.x * v.z;
        float z = q.w * v.z + q.x * v.y - q.y * v.x;

        // TODO: check for Z (w,x,y,x)
        return glm::quat(w, x, y, z);
    }

    glm::mat4 Transform::scale(const glm::vec3 &value) const
    {
        glm::mat4 matrix;

        for (unsigned int i = 0; i < 3; i++)
            for (unsigned int j = 0; j < 3; j++)
                if (i == j && i != 3)
                    matrix[i][j] = value[i];

        return matrix;
    }

    glm::vec3 transform(glm::mat4 m, glm::vec3 r)
    {
        return glm::vec3(
                m[0][0] * r.x + m[0][1] * r.y + m[0][2] * r.z + m[0][3],
                m[1][0] * r.x + m[1][1] * r.y + m[1][2] * r.z + m[1][3],
                m[2][0] * r.x + m[2][1] * r.y + m[2][2] * r.z + m[2][3]
        );
    }
}