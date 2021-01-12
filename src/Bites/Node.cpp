//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Bites/Node.h"
#include "../../include/Components/Component.h"

namespace eGLE
{
    void Node::render(RenderSystem *rs)
    {
        for (auto const &component : m_components)
            component->render(rs);

        for (auto const &child : m_childrens)
            child->render(rs);
    }

    void Node::update(float timeDelta)
    {
        for (auto const &component : m_components)
            component->update(timeDelta);

        for (auto const &child : m_childrens)
            child->update(timeDelta);
    }

    void Node::input(float timeDelta)
    {
        m_transform.update(); // prepare
        for (auto const &component : m_components)
            component->input(timeDelta);

        for (auto const &child : m_childrens)
            child->input(timeDelta);
    }

    void Node::addChild(Node *child)
    {
        child->setParent(this);
        m_childrens.push_back(child);
    }

    void Node::addComponent(Component *component)
    {
        component->setParent(this);
        m_components.push_back(component);
    }

    void Node::updateRS(RenderSystem *rs)
    {
        for (auto const &component : m_components)
            component->updateRS(rs);
    }

    Node *Node::parent()
    {
        return m_parent;
    }

    void Node::setParent(Node *parent)
    {
        m_parent = parent;
    }

    Transform &Node::transform()
    {
        return m_transform;
    }

    std::vector<Node *> Node::childrens()
    {
        return m_childrens;
    }
}