//
// Created by Pavel Bibichenko on 02.11.2020.
//

#ifndef EGLE_NODE_H
#define EGLE_NODE_H

#include <glm/glm.hpp>

namespace eGLE
{
    class Node {
    public:
        glm::vec3 &position() const;
        glm::vec3 &scale() const;
        glm::vec3 &rotation() const;

        void setPosition(glm::vec3 &position);
        void setScale(glm::vec3 &scale);
        void setRotation(glm::vec3 &rotation);

    private:
        /* Pos / Rot / Scale
         * MVP inverted is Projection * View * Model */
        glm::vec3 m_position;
        glm::vec3 m_scale;
        glm::vec3 m_rotation; // Euler Angles
    };
}

#endif //EGLE_NODE_H
