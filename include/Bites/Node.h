//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_NODE_H
#define EGLE_NODE_H

#include <vector>

#include "Transform.h"

namespace eGLE
{
    class RenderSystem;
    class Component;

    class Node {
    public:
        Node() = default;
        ~Node() = default;

        // Core
        void render(RenderSystem *rs);
        void update(float timeDelta);
        void input(float timeDelta);

        // TODO: reformat as ECS
        // Basic ECS / Tree
        void addChild(Node *child);
        void addComponent(Component *component);

        // Update RS (Render System)
        void updateRS(RenderSystem *rs);

        // Setters / Getters
        Node *parent();
        void setParent(Node *parent);

        Transform &transform();
        std::vector<Node *> childrens();

        void moveWithDelta(glm::vec3 delta);

    protected:
        Node *m_parent;
        std::vector<Node *> m_childrens;
        std::vector<Component *> m_components;

        Transform m_transform;
    };
}

#endif //EGLE_NODE_H
