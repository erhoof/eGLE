//
// Created by Pavel Bibichenko on 02.11.2020.
//

#ifndef EGLE_NODE_H
#define EGLE_NODE_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace eGLE
{
    class Node {
    public:
        glm::vec3 &position();
        glm::vec3 &scale();
        glm::quat &rotation();

    private:
        /* Pos / Rot / Scale
         * MVP inverted is Projection * View * Model */
        glm::vec3 m_position;
        glm::vec3 m_scale;
        glm::quat m_rotation;
    };
}

#endif //EGLE_NODE_H
