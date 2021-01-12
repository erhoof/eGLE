//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_COMPONENT_H
#define EGLE_COMPONENT_H

namespace eGLE
{
    class RenderSystem;
    class Node;

    class Component {
    public:
        virtual Component() = default;
        virtual ~Component() = default;

        virtual void render(RenderSystem *rs) {};
        virtual void update(float timeDelta) {};
        virtual void input(float timeDelta) {};

        // Update properties
        virtual void updateRS(RenderSystem *rs) {};

        // Getters / Setters
        Node *parent();
        void setParent(Node *parent);
        Transform &getTransform();

    private:
        Node *m_parent;
    };
}



#endif //EGLE_COMPONENT_H
