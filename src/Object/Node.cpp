//
// Created by Pavel Bibichenko on 06.11.2020.
//

#include "../../include/Object/Node.h"

namespace eGLE
{
    glm::vec3 &Node::position() {
        return m_position;
    }

    glm::vec3 &Node::scale() {
        return m_scale;
    }

    glm::quat &Node::rotation() {
        return m_rotation;
    }
}